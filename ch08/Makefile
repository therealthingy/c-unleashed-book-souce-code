
OBJS := memtrack.o memtrkmn.o
BINS := memtrkmn

CFLAGS += -DMEMTRACK


PHONY: all
all: $(OBJS) $(BINS) $(LIBS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)   MEMTRACK.TXT


memtrkmn: memtrack.o  memtrkmn.o
