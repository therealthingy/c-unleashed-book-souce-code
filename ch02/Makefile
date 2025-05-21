#C_XX_FLAGS := -I ../include/
C_XX_FLAGS += -O0
C_XX_FLAGS += -Wall -pedantic
CFLAGS = $(C_XX_FLAGS)        # NOTE: `=` = variable which will be recursively expanded, `:=` = variable which will be expanded once and 4 all
CXXFLAGS = $(C_XX_FLAGS)
#CXXFLAGS += -std=c++23

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
#CC := gcc
#CXX := g++
SHARED_LIB_EXTENSION := dylib
endif
ifeq ($(UNAME), Linux)
#CC := gcc
#CXX := g++
#CFLAGS += -D_GNU_SOURCE
SHARED_LIB_EXTENSION := so
endif


SRCS += $(wildcard *.c)
SRCS += $(wildcard *.cpp)
OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SRCS)))
DEPS := $(patsubst %.c,%.d,$(patsubst %.cpp,%.d,$(SRCS)))
BINS := $(patsubst %.c,%,$(patsubst %.cpp,%,$(filter-out lib%,$(SRCS))))
LIBS := $(patsubst %.c,%.$(SHARED_LIB_EXTENSION),$(patsubst %.cpp,%.$(SHARED_LIB_EXTENSION),$(filter lib%,$(SRCS))))



.PHONY: all
all: $(DEPS)
	@$(MAKE) $(BINS) $(LIBS)


.PHONY: clean
clean:
	@$(RM) $(DEPS) $(OBJS) $(BINS) $(LIBS) a.out
	@$(RM) compile_commands.json
	@$(RM) -r *.dSYM


ifneq ($(filter clean,$(MAKECMDGOALS)),clean)
-include $(DEPS)                                                  # NOTE: `-` = ignore errors (when files don't exist)
endif

%.d: %.c
	$(info GEN $@)
	@$(CC) -MM $(CFLAGS) $< -MF "$@"

%.d: %.cpp
	$(info GEN $@)
	@$(CXX) -MM $(CXXFLAGS) $< -MF "$@"

%: %.d


.PHONY: devel              # ALWAYS run (despite no file changing)
devel:
	@bear -- $(MAKE) $(MAKEOVERRIDES)


## >>> `CFLAGS` / Linkge is determined by lib prefix OR filename suffix
## >> `CFLAGS`
## > Shared libs
#lib%.o: lib%.c
#	$(CC) $(CFLAGS) -fPIC -c $< -o $@
#
#lib%.o: lib%.cpp
#	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@
#
## > OpenMP
#%-omp.o: %-omp.c
#	$(CC) $(CFLAGS) -fopenmp -c $< -o $@
#
#%-omp.o: %-omp.cpp
#	$(CXX) $(CXXFLAGS) -fopenmp -c $< -o $@
#
## >> Linkage
## > Shared libs
#lib%.$(SHARED_LIB_EXTENSION): lib%.o
#	$(CXX) $(CXXFLAGS) -shared -fPIC $< -o $@ -ldl
#
## > OpenMP
#%-omp: %-omp.o
#	$(CXX) -fopenmp $< -o $@
#
## > pThreads
#%-pthread: %-pthread.o
#	$(CXX) -lpthread $< -o $@

# > DEFAULT: Always use `g++` 4 linking   ???
%: %.o
	$(CXX) $< -o $@
