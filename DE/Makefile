CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

OBJDIR = obj
SRCS = main.cpp DE.cpp TestBed_1.cpp TestBed_2.cpp TestBed_3.cpp a_DE.cpp TestBed_Modern.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: %.cpp TestBed_1.hpp TestBed_2.hpp TestBed_3.hpp DE.hpp a_DE.hpp TestBed_Modern.hpp result_struct.hpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)