# TODO: Makefile is buggy (invoke it twice deletes binaries  "Circular dependency dropped")

OBJS := adjlist.o adjmatrix.o dfsfuncs.o dfsfuncs.o graphs.o mstree.o pqueue.o shpath.o topsort.o
BINS := testing1 testing2 testing3 testing4 testing5


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)


adjlist.o: graphs.o
adjmatrix.o: graphs.o
dfsfuncs.o: graphs.o
mstree.o: dfsfuncs.o graphs.o pqueue.o
graphs.o: adjlist.o adjmatrix.o
shpath.o: pqueue.o graphs.o
topsort.o: graphs.o

testing1: graphs.o adjlist.o adjmatrix.o  shpath.o pqueue.o graphs.o
testing2: graphs.o adjlist.o adjmatrix.o  shpath.o pqueue.o graphs.o
testing4: graphs.o adjlist.o adjmatrix.o  topsort.o
testing5: graphs.o adjlist.o adjmatrix.o  mstree.o dfsfuncs.o graphs.o pqueue.o
