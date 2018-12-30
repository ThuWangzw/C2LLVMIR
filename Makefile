all: compiler lex yacc

OBJS =  codeGen.o \
		main.o	 \
		AST.o   \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cxxflags --ldflags`
LIBS = `$(LLVMCONFIG) --system-libs --libs core`

clean:
	$(RM) -rf $(OBJS) compiler
	$(RM) -rf compiler.out y.tab.cpp y.tab.hpp lex.yy.cpp y.output

%.o: %.cpp
	clang++ -fmodules -c $(CPPFLAGS) -o $@ $<

lex:
	lex -o lex.yy.cpp compiler.l

yacc:
	yacc -dy -o y.tab.cpp -v compiler.y

compiler: $(OBJS)
	clang++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS)