#include"move.h"

Move::Move(int x,int y): x(x), y(y){};

int Move::getX(){
    return x;
}

int Move::getY(){
    return y;
}