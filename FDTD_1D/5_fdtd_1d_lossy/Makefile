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
SRCS = fdtd_1d_lossy.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file 
MAIN = fdtd_1d_lossy

.PHONY: all clean

all: $(MAIN)
	@echo "----------------------------------------------------------------------------"
	@echo "COMPLETE!!! "
	@echo "----------------------------------------------------------------------------"
	@echo "Simple example of FDTD in 1D hardwire feed by a impulse has been compiled. The program save files with time snapshots of the electric field each 10 time iterations, and it transmit energy through the source node using the current density (J). In addition, a TSFS boundary condition is implemented, so the excitation Gaussian pulse will propagate to the right only. This is achieved using t-x/c instead of t in the feed function. There is a lossy interface matched (sigma_m/miu = sigma/epsilon)"
	@echo "----------------------------------------------------------------------------"
	@echo "Running simulation..."
	@./$(MAIN)
	@echo "Simulation complete"

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN) sim*



#fdtd_1d.o:  fdtd_1d.c
#       $(CC) $(CFLAGS) $(INCLUDES) -c fdtd_1d.c -o $@ $(LIBS)


