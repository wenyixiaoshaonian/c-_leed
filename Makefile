#AR 库文件维护程序的名称。默认值为ar
#AS 汇编程序的名称，默认值为as
#CPP C预编译器的名称，默认值为$(CC) -E
#CXX C++编译器的名称，默认值为g++
#FC   FORTRAN编译器的名称，默认值为f77
#ARFLAGS   库文件维护的程序选项，无默认值
#ASFLAGS   汇编程序的选项，无默认值
#CFLAGS     C编译器的选项，无默认值
#CPPFLAGS C预编译的选项，无默认值
#CXXFLAGS C++编译器的选项，无默认值
#FFLAGS      FORTRAN编译器的选项，无默认值

CC ?= gcc
CXX ?= g++
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

INC_CLUDE = -Imkfile_dir

objects = test.o

test : $(objects)
	$(CXX) -o  $@ -g $(objects)

$(objects) : %.o:%.cpp
	$(CXX) -c -g  $< -o $@ $(INCLUDE)

clean :
	rm *.o test