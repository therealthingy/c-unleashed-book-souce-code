
OBJS := memtrack.o memtrkmn.o
BINS := memtrkmn

CFLAGS += -DMEMTRACK


PHONY: all
all: $(OBJS) $(BINS) $(LIBS)

memtrkmn: memtrkmn.o  memtrack.o

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)   MEMTRACK.TXT
