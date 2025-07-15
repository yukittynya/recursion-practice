CFLAGS = -Werror -O3 -ffast-math -flto
CC = clang
TOPICS = math string arrays trees lists

build/bin/%: build/%/main.o | build/bin
	$(CC) $(CFLAGS) $? -o $@
	chmod +x $@
	
build/%/main.o: src/%/main.c | build/%/
	$(CC) $(CFLAGS) -c $? -o $@

build/bin:
	mkdir -p build/bin

build/%/: 
	mkdir -p build/$*

.PRECIOUS: build/%/main.o

.PHONY: $(TOPICS)
$(TOPICS): %: build/bin/%

.PHONY: run
ifdef topic 
run: clean build/bin/$(topic)
	./build/bin/$(topic)
else
run:
	@echo "Usage: make run topic=<topic>"
	@echo "Topics: $(TOPICS)"
endif

.PHONY: clean
clean:
	rm -rvf build

.PHONY: help 
help:
	@echo "Usage: make run topic=<topic>"
	@echo "Topics: $(TOPICS)"
