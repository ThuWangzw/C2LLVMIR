all: lex yacc parser compiler 

OBJS =  codeGen.o \
		main.o	 \
		AST.o   \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cxxflags --ldflags`
LIBS = `$(LLVMCONFIG) --system-libs --libs core`

clean:
	$(RM) -rf $(OBJS) compiler
	$(RM) -rf parser.out y.tab.cpp y.tab.hpp lex.yy.cpp y.output 
	$(RM) -rf output.ll output.bc output.o output.out output.json

%.o: %.cpp
	clang++ -fmodules -c $(CPPFLAGS) -o $@ $<

lex:
	flex -o lex.yy.cpp compiler.l

yacc:
	yacc -dy -o y.tab.cpp -v compiler.y

parser: lex yacc
	clang++ -std=c++11 $(CPPFLAGS) $(LIBS) -o parser.out y.tab.cpp lex.yy.cpp AST.cpp codeGen.cpp parser.cpp

compiler: lex yacc $(OBJS)
	clang++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS) y.tab.cpp lex.yy.cpp

output:
	llvm-as output.ll
	llc -filetype=obj output.bc
	gcc output.o -o output.out
	