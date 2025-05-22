
add_library(prng STATIC)
target_sources(prng COCKUS.C)
target_include_directories(prng PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})  # `mtrand.h`


OBJS := DISTRIBS.o KEYXFRM.o SINT.o DOUBLE.o STRINGS.o COCKUS.o
BINS := BAR TEST


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)
