CC=g++
CFLAGS=-Iinclude -Wall -g -O
TARGET=shell
DEPS=$(wildcard *.h)

SRC_DIR=src
SRC=$(wildcard $(SRC_DIR)/*.cpp)
OBJ=$(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.o, $(SRC))
DEP_SRC=$(filter-out src/$(TARGET).cpp, $(SRC))
DEP_OBJ=$(filter-out src/$(TARGET).o, $(OBJ))

CXX=g++
TEST_SRC_DIR=test
TEST_SRC=$(wildcard $(TEST_SRC_DIR)/*_test.c)
TEST=test/all_test
TEST_FLAGS=-lgtest -pthread -std=c++11 -I$(TEST_SRC_DIR)/include
TEST_UTIL=$(wildcard $(TEST_SRC_DIR)/*_Util.c)
TEST_UTIL_INCLUE=$(wildcard $(TEST_SRC_DIR)/include/*.h)

all: $(TARGET)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< -c $(CFLAGS)

shell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

check: $(TEST)
	-$(TEST)
	find test/ -name "*.db" -delete

$(TEST): $(TEST_SRC) $(DEP_SRC) $(DEPS) $(TEST_UTIL) $(TEST_UTIL_INCLUE)
	$(CXX) -o $@ $(TEST_SRC) $(DEP_SRC) $(TEST_UTIL) $(CFLAGS) $(TEST_FLAGS)

.PHONY: clean check

clean:
	rm .\src\*.o
