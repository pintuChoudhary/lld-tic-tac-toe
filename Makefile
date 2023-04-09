CXX = g++
CXXFLAGS = -std=c++20 -Wall
SRCS = exceptions/outOfBoundMove.cpp exceptions/illigalMoveException.cpp src/move.cpp src/board.cpp src/player.cpp driver/main.cpp 
OBJS = $(SRCS:.cpp=.o)
INCLUDE = -I includes

all: tictactoe

tictactoe: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o tictactoe

%.o: %.cpp
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@

clean:
	rm -f ${OBJS} tictactoe
