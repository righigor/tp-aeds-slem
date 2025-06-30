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
	rm -f $(TARGET) tests/test_pedido

test-pedido:
	$(CXX) $(CXXFLAGS) \
		tests/test_pedido.cpp \
		Classes/Local/Local.cpp \
		Classes/Pedido/Pedido.cpp \
		-o tests/test_pedido
	./tests/test_pedido
