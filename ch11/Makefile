# TODO: CAN break when parallelized

OBJS := strarr.o
OBJS += c11_018.o
BINS := c11_018

OBJS += sllist.o
OBJS += sllistmn.o
BINS += sllistmn

OBJS += dllist.o
OBJS += dllistmn.o dllisteg.o
BINS += dllistmn dllisteg

OBJS += clist.o
OBJS += clistmn.o clistmn2.o
BINS += clistmn clistmn2

OBJS += stack.o
OBJS += stackmn.o
BINS += stackmn

OBJS += queue.o
OBJS += queuemn.o
BINS += queuemn

OBJS += deque.o
OBJS += dequemn.o
BINS += dequemn

OBJS += heap.o
OBJS += heapmn.o
BINS += heapmn

# NOTE: These targets DON'T WORK: c11_015 C11_016.o
BINS += C11_010 c11_017 c11_020 c11_021 c11_022


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)


stack.o: sllist.o

queue.o: sllist.o

deque.o: dllist.o

c11_018: c11_018.o  strarr.o

sllistmn: sllistmn.o  sllist.o

dllistmn: dllistmn.o  dllist.o
dllisteg: dllisteg.o  dllist.o

clistmn: clistmn.o  clist.o
clistmn2: clistmn2.o  clist.o

stackmn: stackmn.o  strarr.o sllist.o stack.o

queuemn: queuemn.o  sllist.o queue.o

dequemn: dequemn.o  dllist.o deque.o

heapmn: heapmn.o  heap.o
