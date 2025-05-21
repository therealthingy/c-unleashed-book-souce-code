
# CUPS TCP
OBJS := cups.o
OBJS += cts.o   # server
BINS := cts
OBJS += ctc.o   # client
BINS += ctc

# CUPS UDP
OBJS += cus.o   # server
BINS += cus
OBJS += cuc.o   # client
BINS += cuc

# Unix TCP
OBJS += uts.o   # server
BINS += uts
OBJS += utc.o   # client
BINS += utc

# Unix UDP
OBJS += uus.o   # server
BINS += uus
OBJS += uuc.o   # client
BINS += uuc


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)


cts: cts.o cups.o
ctc: ctc.o cups.o

cus: cus.o cups.o
cuc: cuc.o cups.o
