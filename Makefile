#Makefile
OBJECT=jsonlearn.o 
		
CPP=g++ -g -std=c++11


IJSONPATH=
LJSON=./json/libjson_linux-gcc-5.3.1_libmt.so

INDEBUG=-I. 
LIBFLAG=-lpthread -ldl 

all: jsonlearn

$(OBJECT):%.o:%.cpp
	$(CPP) ${INDEBUG} ${LIBFLAG} -c $< -o $@

jsonlearn:$(OBJECT)
	$(CPP) -o jsonlearn ${OBJECT} ${INDEBUG} ${LIBFLAG} $(LJSON)
clean:
	$(RM) *.o  jsonlearn
