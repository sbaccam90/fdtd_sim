#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
#INCLUDES = -I/home/newhall/include  -I../include
INCLUDES = 

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
#LFLAGS = -L/home/newhall/lib  -L../lib
LFLAGS =

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lm

# define the C source files
SRCS = gridtmz.c updatetmz.c ricker.c snapshot2d.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

HEADERS = fdtd-alloc1.h fdtd-macro-tmz.h fdtd-proto1.h ezinc.h

# define the executable file 
MAIN = fdtd_2d_tmz

.PHONY: all clean

all: $(MAIN)
	@echo "----------------------------------------------------------------------------"
	@echo "COMPLETE!!! "
	@echo "----------------------------------------------------------------------------"
	@echo "Simple example of FDTD in 2D library"
	@echo "----------------------------------------------------------------------------"
	$(RM) sim*
	@echo "Running simulation..."
	@./$(MAIN)
	@echo "Simulation complete"

$(MAIN): $(OBJS) $(HEADERS) tmzdemo1.c
	$(CC) $(CFLAGS) $(INCLUDES) tmzdemo1.c -o $(MAIN) $(OBJS) $(HEADERS) $(LFLAGS) $(LIBS)

gridtmz.o: gridtmz.c fdtd-macro-tmz.h fdtd-alloc1.h
	$(CC) $(CFLAGS) $(INCLUDES) -c gridtmz.c fdtd-macro-tmz.h fdtd-alloc1.h $(LFLAGS) $(LIBS)

updatetmz.o: updatetmz.c fdtd-macro-tmz.h
	$(CC) $(CFLAGS) $(INCLUDES) -c updatetmz.c fdtd-macro-tmz.h $(LFLAGS) $(LIBS)

ricker.o: ricker.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c ricker.c $(HEADERS) $(LFLAGS) $(LIBS)

snapshot2d.o: snapshot2d.c fdtd-macro-tmz.h
	$(CC) $(CFLAGS) $(INCLUDES) -c snapshot2d.c fdtd-macro-tmz.h $(LFLAGS) $(LIBS)

clean:
	$(RM) *.o *~ $(MAIN) sim*



#fdtd_1d.o:  fdtd_1d.c
#       $(CC) $(CFLAGS) $(INCLUDES) -c fdtd_1d.c -o $@ $(LIBS)


