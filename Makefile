
SRC = src/

SOURCE_FILES = $(SRC)Processor.cc $(SRC)ProcessorUtil.cc $(SRC)Register8bit.cc $(SRC)Register16bit.cc $(SRC)Memory.cc

TEST_DIR = tests/
TEST_SOURCE = tests/TestUtils.cc tests/TestAddition.cc tests/TestCPUFunctions.cc tests/TestRegister8bit.cc tests/TestRegister16bit.cc
TEST_MAIN = $(TEST_DIR)test_main.cc

CCFLAGS = -g -std=c++17 -Wall -Wextra -Weffc++ -pedantic -Wsuggest-attribute=const

BUILD = build/

OUT_FILE = emulator
OUT_FILE_TEST = $(OUT_FILE)_test

GCC_FILTER = gccfilter -c

all: main.o processor.o processorutil.o register8bit.o register16bit.o memory.o
	cd $(BUILD); g++ $(CCFLAGS) main.o processor.o register8bit.o register16bit.o memory.o processorutil.o -o $(OUT_FILE); cd ..

main.o: $(SRC)main.cc $(SRC)Constants.hh
	g++ $(CCFLAGS) -c $(SRC)main.cc -I$(SRC) -o $(BUILD)main.o

processor.o: $(SRC)Processor.cc $(SRC)Processor.hh $(SRC)Constants.hh
	g++ $(CCFLAGS) -c $(SRC)Processor.cc -I$(SRC) -o $(BUILD)processor.o

processorutil.o: $(SRC)ProcessorUtil.cc
	g++ $(CCFLAGS) -c $(SRC)ProcessorUtil.cc -I$(SRC) -o $(BUILD)processorutil.o

register8bit.o: $(SRC)Register8bit.cc $(SRC)Register8bit.hh $(SRC)Constants.hh
	g++ $(CCFLAGS) -c $(SRC)Register8bit.cc -I$(SRC) -o $(BUILD)register8bit.o

register16bit.o: $(SRC)Register16bit.cc $(SRC)Register16bit.hh $(SRC)Constants.hh 
	g++ $(CCFLAGS) -c $(SRC)Register16bit.cc -I$(SRC) -o $(BUILD)register16bit.o

memory.o: $(SRC)Memory.cc $(SRC)Memory.hh $(SRC)Constants.hh
	g++ $(CCFLAGS) -c $(SRC)Memory.cc -I$(SRC) -o $(BUILD)memory.o

test:
	$(GCC_FILTER) g++ $(CCFLAGS) -o $(OUT_FILE_TEST) $(TEST_MAIN) $(SOURCE_FILES) $(TEST_SOURCE) -I$(TEST_DIR) -I$(SRC)
	

clean:
	$(RM) $(OUT_FILE)
	$(RM) $(OUT_FILE_TEST)
	$(RM) *.o
	$(RM) *.out
	$(RM) $(BUILD)*