
OBJS := cgi.o Proto.o
BINS := Proto


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)


Proto: cgi.o Proto.o
