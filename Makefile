all: compiler

OBJS =  codeGen.o \
		main.o	 \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cxxflags --ldflags`
LIBS = `$(LLVMCONFIG) --system-libs --libs core`

clean:
	$(RM) -rf $(OBJS) compiler


%.o: %.cpp
	clang++ -fmodules -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	clang++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS)