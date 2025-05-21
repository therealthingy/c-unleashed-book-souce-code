
OBJS := dllist.o
OBJS += argproc.o genargs.o
BINS := argproc

BINS += tee DataGen hd maxline sandra limn


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)


argproc: argproc.o genargs.o dllist.o
