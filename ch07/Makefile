
OBJS := cfollow.o
OBJS += cfollowd.o
BINS := cfollowd

BINS += ch07s001 ch07s003 ch07s016 ch07s017 ch07s018 ch07s019 ch07s020 ch07s021 ch07s024 ch07s027 ch07s037 #ch07s048


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)


cfollowd: cfollowd.o  cfollow.o
