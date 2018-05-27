###########################################################################
#4/13/2018, Maosen Zhou
###########################################################################

# Root variables
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs) -lHtml -lMinuit 
# Programs
CXX          = g++
CXXFLAGS     = -g -Wall -fPIC -Wno-deprecated 
LDFLAGS      = -g 
SOFLAGS      = -shared 
# Local Includes
INCDIR      += -I./
# Assign or Add variables
CXXFLAGS    += $(ROOTCFLAGS)
CXXFLAGS    += $(INCDIR)
LIBS        += $(ROOTLIBS)

# Analysis tools and main code
CXXSRCS     +=  myRun.cxx

CXXOBJS      = $(CXXSRCS:.cxx=.o)
TARGETS      = $(CXXSRCS:.cxx=)
GARBAGE      = lib/*.so lib/*.o ./*/*.o ./*.o 

############################################################################
# Build main.c compiling only the first prereq: ($<) means main.c
############################################################################
${TARGETS}                       :        ${CXXOBJS} 
##########################################################################
# General rules. The first two need not be specified due to implicit rules, 
# but redefined for the "echo"
############################################################################
%.o : %.cxx %.h
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< 

%.o : %.cxx 
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $<
%    : %.o
	@echo "compiling and linking $@"
	@$(CXX) $(LDFLAGS) $^ $(ROOTLIBS) -o $@
	@if [ `ls | grep "\.so"$ | wc -l` != 0 ]; then mv *.so lib/; fi
	@if [ `ls | grep "\.o"$  | wc -l` != 0 ]; then mv *.o  lib/; fi
	@mv $@ bin/

############################################################################
# Phony rules (no prerequisites)
############################################################################

.PHONY: clean print

clean :
	@rm -f $(GARBAGE)
print :
	@echo compiler  : $(CXX)
	@echo c++ srcs  : $(CXXSRCS)
	@echo c++ objs  : $(CXXOBJS)
	@echo c++ flags : $(CXXFLAGS)
	@echo libs      : $(LIBS)
	@echo so flags  : $(SOFLAGS)
	@echo rootlibs  : $(ROOTLIBS)
