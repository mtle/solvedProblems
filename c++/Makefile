CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-g -std=c++11 -std=gnu++11 -DDEBUG=0
CXXFLAGS=-g -std=c++11 -std=gnu++11 -DDEBUG=0
LDFLAGS=-g -std=c++11 -std=gnu++11
LDLIBS=

#OBJS=*.o
#OBJS=$(subst .cpp,.o,$(SRCS))

EXE=mysort
### Makefile macro:
#  For a target such as:  %.o:%.cpp
#  $@ is whatever on the left of :
#  $^ is whatever on the left of :
#
#
#all: ${EXE}
all: ALL

ALL: *.cpp
	    $(CXX) $(CXXFLAGS) $(LDFLAGS) $< $(LDLIBS) 

	    $(CXX) $(CFLAGS) $(CXXFLAGS) $^
#$(OBJS):$(SRCS) $(DEPS)
%.o : %.cpp $(DEPS)
	    $(CXX) -c $(CFLAGS) $(CXXFLAGS) $< -o $@

%.o: %.c
	    $(CC) -c $(CFLAGS) $(CXXFLAGS) $< -o $@
.PHONY: clean
clean:
	    $(RM) $(OBJS) *.o *.cpp~ *.h~ *.gch a.out ${EXE}

dist-clean: clean
	    $(RM) ${EXE}

#############################################################
#  Before issuing any command in a target rule set there are 
#  certain special macros predefined.

#  $@ is the name of the file to be made.

#  $? is the names of the changed dependents.

#  So, for example, we could use a rule

#  hello: main.cpp hello.cpp factorial.cpp
#  		$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

#  alternatively:

#  hello: main.cpp hello.cpp factorial.cpp
#  	        $(CC) $(CFLAGS) $@.cpp $(LDFLAGS) -o $@
#  In this example $@ represents hello and $? or $@.cpp will pickup all the changed source files.

#  There are two more special macros used in the implicit rules. They are

#  $< the name of the related file that caused the action.

#  $* the prefix shared by target and dependent files.
