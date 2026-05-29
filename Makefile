CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET   = cybertools
SRCS     = main.cpp password_checker.cpp caesar_cipher.cpp file_hasher.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
