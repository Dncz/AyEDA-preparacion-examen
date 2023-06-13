IDIR = ../
CXX		  := g++
CXX_FLAGS := -I$(IDIR) -Wswitch -Wall -Wextra -std=c++17 -ggdb -Wno-return-type 

EXECUTABLE	:= polimorfismo2

.PHONY: all
_OBJ = polimorfismo2.o
OBJ = $(patsubst %,$(IDIR)/%,$(_OBJ))

all: $(EXECUTABLE)

$(IDIR)/polimorfismo2.o: $(IDIR)/polimorfismo2.cpp
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
