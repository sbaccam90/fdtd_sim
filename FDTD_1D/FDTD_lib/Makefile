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
SRCS = gridinit3.c update3.c abc.c ezinc3.c tfsf.c snapshot.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

HEADERS = fdtd3.h

# define the executable file 
MAIN = fdtd_1d_lib

.PHONY: all clean

all: $(MAIN)
	@echo "----------------------------------------------------------------------------"
	@echo "COMPLETE!!! "
	@echo "----------------------------------------------------------------------------"
	@echo "Simple example of FDTD in 1D library"
	@echo "----------------------------------------------------------------------------"
	$(RM) sim*
	@echo "Running simulation..."
	@./$(MAIN)
	@echo "Simulation complete"

$(MAIN): $(OBJS) $(HEADERS) improved3.c
	$(CC) $(CFLAGS) $(INCLUDES) improved3.c -o $(MAIN) $(OBJS) $(HEADERS) $(LFLAGS) $(LIBS)

gridinit3.o: gridinit3.c fdtd3.h
	$(CC) $(CFLAGS) $(INCLUDES) -c gridinit3.c fdtd3.h $(LFLAGS) $(LIBS)

update3.o: update3.c fdtd3.h
	$(CC) $(CFLAGS) $(INCLUDES) -c update3.c fdtd3.h $(LFLAGS) $(LIBS)

abc.o: abc.c fdtd3.h
	$(CC) $(CFLAGS) $(INCLUDES) -c abc.c fdtd3.h $(LFLAGS) $(LIBS)

tfsf.o: tfsf.c fdtd3.h ezinc3.h ezinc3.o
	$(CC) $(CFLAGS) $(INCLUDES) -c tfsf.c fdtd3.h ezinc3.h $(LFLAGS) $(LIBS)

snapshot.o: snapshot.c fdtd3.h
	$(CC) $(CFLAGS) $(INCLUDES) -c snapshot.c fdtd3.h $(LFLAGS) $(LIBS)

ezinc3.o: ezinc3.c fdtd3.h ezinc3.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ezinc3.c fdtd3.h ezinc3.h $(LFLAGS) $(LIBS)

clean:
	$(RM) *.o *~ $(MAIN) sim*



#fdtd_1d.o:  fdtd_1d.c
#       $(CC) $(CFLAGS) $(INCLUDES) -c fdtd_1d.c -o $@ $(LIBS)


