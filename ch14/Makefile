
OBJS := trie.o trie_extra.o test_trie.o
BINS := test_trie


PHONY: all
all: $(OBJS) $(BINS)

PHONY: clean
clean:
	@$(RM) $(OBJS) $(BINS)


test_trie: trie.o trie_extra.o test_trie.o
