IDIR = ../
CXX		  := g++
CXX_FLAGS := -I$(IDIR) -Wswitch -Wall -Wextra -std=c++17 -ggdb -Wno-return-type 

EXECUTABLE	:= ejercicio4

.PHONY: all
_OBJ = ejercicio4.o
OBJ = $(patsubst %,$(IDIR)/%,$(_OBJ))

all: $(EXECUTABLE)

$(IDIR)/ejercicio4.o: $(IDIR)/ejercicio4.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(IDIR)/*.o
	rm -f $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)
