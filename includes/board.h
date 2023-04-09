#ifndef BOARD_H
#define BOARD_H

#include"player.h"
#include"move.h"

enum BoardResult {
    ONGOING , GAME_OVER , GAME_DRAW
};

class Board{
    private:
    int boardSize;
    int moveRemaining;
    int board[10][10];
    int marker;

    bool canMakeMove(Move move);
    bool won(int marker, Move &move);
    char getMarker(int val);

    public:
    Board(int boardSize);
    ~Board();
    BoardResult move(Player *player,Move move);
    void display();
};

#endif