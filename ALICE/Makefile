TARGET=ALICE
TEST_TARGET=testStack
FUNC=stack.o
HEADERS=stack.h
MAIN=$(TARGET).o
TEST_MAIN=$(TEST_TARGET).o
TEST_COMMON=testCommon.o
LIBS=-lm
CFLAGS=-Wall -g

$(TARGET): $(MAIN) $(FUNC) $(HEADERS)
	$(CC) -o $@ $(CFLAGS) $(MAIN) $(FUNC) $(LIBS)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_MAIN) $(FUNC) $(TEST_COMMON) $(HEADERS)
	$(CC) -o $@ $(CFLAGS) $(TEST_MAIN) $(FUNC) $(TEST_COMMON) $(LIBS)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(TEST_MAIN) $(MAIN) $(FUNC) $(TEST_COMMON)
