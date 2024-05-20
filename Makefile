
LIBOBJS := $(shell find -type f -wholename "./src/*.c" -print \
		   | sed "s/\.c/.o/")
TESTOBJS := $(shell find -type f -wholename "./tests/*.c" -print \
			| sed "s/\.c/\.o/")

CC := $(shell which gcc)
TEST_FLAGS := -std=c11 -O3
NOSTD_FLAG := -nostdlib \
				-DNOSTDLIB_BUILD \
				-s \
				-fno-stack-protector \
				-fdata-sections \
				-fno-unwind-tables \
				-fno-asynchronous-unwind-tables \
				-ffunction-sections \
				-Wl,-n \
				-Wl,--gc-sections \
				-Wl,--build-id=none

TARGET := minh
TEST_BIN_DIR := tests/bin
SHARED_DIR := lib/shared
STATIC_DIR := lib/static

ALL: $(TESTOBJS)

$(LIBOBJS): %.o: %.c
	$(CC) -c -g -fPIC -Os $(NOSTD_FLAG) -o $@ $<

shared: $(LIBOBJS)
	@mkdir -p $(SHARED_DIR)
	$(CC) -shared -Os $(NOSTD_FLAG) -o $(SHARED_DIR)/lib$(TARGET).so $^

static: $(LIBOBJS)
	@mkdir -p $(STATIC_DIR)
	@ar rcs $(STATIC_DIR)/lib$(TARGET).a $^

$(TESTOBJS): %.o: %.c static shared
	@mkdir -p $(TEST_BIN_DIR)/static
	@mkdir -p $(TEST_BIN_DIR)/shared
	$(CC) -g -c $< -o $@
	$(CC) $@ -L$(STATIC_DIR) -l$(TARGET) -g $(TEST_FLAGS) -o \
		$(TEST_BIN_DIR)/static/$(shell echo $(patsubst %.c,%.out,$<) | \
		sed "s/tests\///")
	$(CC) $@ -L$(SHARED_DIR) -l$(TARGET) -g $(TEST_FLAGS) -o \
		$(TEST_BIN_DIR)/shared/$(shell echo $(patsubst %.c,%.out,$<) | \
		sed "s/tests\///")

clean:
	@rm $(shell find -type f \( -wholename "*.o" \
		-o -wholename "*.a" -o -wholename "*.so" \))

