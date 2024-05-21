.PHONY: ALL clean

CC := $(shell which gcc)
OBJS := $(shell find -type f -wholename "./*/*.c" \
        -print | sed "s/\.c/.o/")
LIBDIR := "../lib/static"
ARCH ?= $(shell uname -m)
FLAG := -L$(LIBDIR) -lminh \
        -ggdb \
        -Wall \
        -static \
        -no-pie \
        -nostdlib \
        -s \
        -fno-stack-protector \
        -fdata-sections \
        -fno-unwind-tables \
        -fno-asynchronous-unwind-tables \
        -ffunction-sections \
        -Wl,-n \
        -Wl,--gc-sections \
        -Wl,--build-id=none

ifeq ($(ARCH), x86_64)
	ARCH_SUFFIX := _amd64
else ifeq ($(ARCH), aarch64)
	ARCH_SUFFIX := _aarch64
else ifeq ($(ARCH), loongarch64)
	ARCH_SUFFIX := _la64
endif

ALL: $(OBJS)

$(OBJS): %.o: %.c
	$(CC) -ggdb -c $< -o $@
	$(CC) $< $(patsubst %.c,%$(ARCH_SUFFIX).S,$<) \
        $(FLAG) \
        -o $(shell echo $(patsubst %.c,%.out,$<))

clean:
	@rm $(shell find -type f \( -wholename "*.o" -o -wholename "*.out" \))
