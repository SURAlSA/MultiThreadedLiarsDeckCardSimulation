CXX = g++

TARGET = MultiThreadedLiarsDeckValidCardSimulation.exe

SRCS = src/main.cpp src/util.cpp src/Simulate.cpp

OBJS = obj/main.o obj/util.o obj/Simulate.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

obj/%.o: src/%.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(TARGET) obj/*.o
