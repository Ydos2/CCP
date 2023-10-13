##
## UCSB PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC = 		src/calc.cpp										\

CXX			:=	g++

OBJ			:=	$(patsubst %.cpp,%.o,$(SRC))

CXXFLAGS =  -Wall -Wextra

VFLAGS = --leak-check=full

EXE = calc

all: $(OBJ)
	$(CXX) -o $(EXE) $(CXXFLAGS) $(OBJ)

gdb:
	g++ $(SRC) -o $(EXE) $(CXXFLAGS) -g3
	gdb ./$(EXE)

debug:
	g++ $(SRC) -o $(EXE) $(CXXFLAGS) -g3
	valgrind $(VFLAGS) ./$(EXE)

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean: clean
	rm -f $(EXE)

re: fclean all

.PHONY: all debug clean fclean re