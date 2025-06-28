CXX = g++
CXXFLAGS = -std=c++17 -I.

SRC = $(wildcard Classes/*/*.cpp) \
      $(wildcard Controller/*.cpp) \
      $(wildcard Repositories/*.cpp) \
      $(wildcard Services/*.cpp) \
      $(wildcard utils/*.cpp) \
      main.cpp

OBJS = $(SRC:.cpp=.o)
TARGET = slem

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARGET)
