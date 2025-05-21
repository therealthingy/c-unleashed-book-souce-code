
MAKEFILES := $(shell find . -mindepth 2 -type f -name Makefile | sort)
SUBDIRS := $(filter-out ./,$(dir $(MAKEFILES)))


.PHONY: all
all:
	@for dir in $(SUBDIRS) ; do\
		$(MAKE) -C $$dir    $(MAKEOVERRIDES)  || exit 1 ;\
		echo ;\
	done

# .PHONY: devel
# devel: clean                 # Requires `clean` (as mtime may not have changed  => empty compiledb)
# 	@for dir in $(SUBDIRS) ; do\
# 		$(MAKE) -C $$dir $@ $(MAKEOVERRIDES) ;\
# 		echo ;\
# 	done

.PHONY: clean
clean:
	@for dir in $(SUBDIRS) ; do\
		$(MAKE) -C $$dir $@ $(MAKEOVERRIDES) ;\
		echo ;\
	done

