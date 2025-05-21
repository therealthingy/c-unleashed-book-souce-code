
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
SHARED_LIB_EXTENSION := dylib
endif
ifeq ($(UNAME), Linux)
SHARED_LIB_EXTENSION := so
endif

OBJS := cfollow.o cfollowd.o
BINS := cfollowd  ch07s001 ch07s003 ch07s016 ch07s017 ch07s018 ch07s019 ch07s020 ch07s021 ch07s024 ch07s027 ch07s037 #ch07s048

LIB_CFOLLOW := libcfollow.$(SHARED_LIB_EXTENSION)
LIBS := $(LIB_CFOLLOW)


PHONY: all
all: $(OBJS) $(BINS) $(LIBS)

$(LIB_CFOLLOW): cfollow.o
	$(CC) $(LDFLAGS) -shared $^ -o $@

cfollowd: cfollowd.o $(LIB_CFOLLOW)
	$(CC) $(CFLAGS) $<  -L. -lcfollow  -o $@

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS) $(LIBS)
