#Makefile
#Edit for your compiler


# Intel compiler
CPP = icpc
CFLAGS = -openmp -O2 -ip -W0 -WB -fpp2 -vec_report0 

#Gfortran compiler: if pre v4.3 add -D__GFORTRAN__
CPP = g++
CFLAGS = -O2  

CPPFLAGS      = $(CFLAGS)
CC            = $(CPP)
CLSLIB  = #-L../../camb -lcamb 
OBJ       =  main.o

default: quant
all: quant

quant: $(OBJ) 
	$(CPP) -o quant $(OBJ) $(CPPFLAGS) $(CLSLIB) 

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $*.cpp
%.o: %.c
	$(CPP) $(CPPFLAGS) -c $*.c

clean:
	-rm -f *.o *.a *.dat quant *.mod 
cleaner:
	-rm -f *.o *.a *.dat ../halo core *.mod ../output/*.dat
