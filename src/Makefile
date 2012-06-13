#Makefile
#Edit for your compiler

# Requires Boost. Change path to where Boost libraries are kept such
# that $(BOOST)include/ contain boost headers and $(BOOST)lib/ contain 
# BOOST libraries.
BOOST = /usr/local/

# Intel compiler
CPP = icpc
CFLAGS = -openmp -O2 -ip -W0 -WB -fpp2 -vec_report0 -I$(BOOST)include/

#Gfortran compiler: if pre v4.3 add -D__GFORTRAN__
CPP = g++
CFLAGS = -O2  -I$(BOOST)include/ -I../include  

CPPFLAGS      = $(CFLAGS)
CC            = $(CPP)
CLSLIB  = 
OBJ       =  stock.o main.o 

default: quant
all: quant

quant: $(OBJ) 
	$(CPP) -o ../quant $(OBJ)  $(CLSLIB) 

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $*.cpp
%.o: %.c
	$(CPP) $(CPPFLAGS) -c $*.c

clean:
	-rm -f *.o *.a *.dat ../quant *.mod 
cleaner:
	-rm -f *.o *.a *.dat ../quant core *.mod ../output/*.txt
