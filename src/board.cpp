#include<iostream>
#include"board.h"
#include<cstdlib>
#include"outOfBoundMove.h"
#include"illigalMoveException.h"

Board::Board(int boardSize){
    this->boardSize = boardSize;
    
    
    for(int row = 0; row < boardSize; row++){
        for(int col = 0; col< boardSize; col++){
           board[row][col] = 2;
        }
    }

    this->moveRemaining = (boardSize * boardSize);
    this->marker = 0;
}

Board::~Board(){
    std::cout<<"Bye"<<std::endl;
}

bool Board::canMakeMove(Move move){
    if(this->board[move.getX()-1][move.getY()-1] != 2){
        return false;
    }
    return true;
}

bool Board::won(int marker, Move &move){
    if(board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) {
        return true;
    }
    if(board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) {
        return true;
    }

    int moveX = move.getX() - 1;
    int moveY = move.getY() - 1;

    if(board[moveX][0] == marker && board[moveX][1] == marker && board[moveX][2] == marker) {
        return true;
    }
    if(board[0][moveY] == marker && board[1][moveY] == marker && board[2][moveY] == marker) {
        return true;
    }
    return false;
}

BoardResult Board::move(Player *player,Move move){
    if(this->moveRemaining == 0){
        player->setStatus(PlayerStatus::PLAYER_DRAW);
        return BoardResult::GAME_DRAW;
    }

    if(player->getMarker() == 2){
        player->setMarker(this->marker);
        this->marker = (1+ this->marker)%2;
        player->setStatus(PlayerStatus::PLAYER_PLAYING);
    }
    
    int moveX = move.getX();
    int moveY = move.getY();
    if(moveX <=0 || moveX > boardSize || moveY <=0 || moveY> boardSize){
        throw OutOfBoundMoveException("Invalid Move");
    }

    if(!canMakeMove(move)){
        throw IlligalMoveException("Already Marked");
    }

    this->board[moveX-1][moveY -1] = player->getMarker();
    this->moveRemaining--;
    
    if(won(player->getMarker(),move)){
        player->setStatus(PlayerStatus::PLAYER_WON);
        return BoardResult::GAME_OVER;
    }
    
    if(this->moveRemaining == 0){
        player->setStatus(PlayerStatus::PLAYER_DRAW);
        return BoardResult::GAME_DRAW;
    }

    return BoardResult::ONGOING;
}

char Board::getMarker(int val){
    char rv;
    switch(val){
        case 0:
            rv = 'X';
            break;
        case 1:
            rv = 'O';
            break;
        default:
            rv = '-';
    }
    return rv;
}

void Board::display(){
    system("clear");
    std::cout<<" 11  12  13"<<std::endl;
    std::cout<<" 21  22  23"<<std::endl;
    std::cout<<" 31  32  33"<<std::endl;
    std::cout<<std::endl;
    std::cout<<" "<<getMarker(board[0][0])<<"  "<<getMarker(board[0][1])<<"  "<<getMarker(board[0][2])<<std::endl;
    std::cout<<" "<<getMarker(board[1][0])<<"  "<<getMarker(board[1][1])<<"  "<<getMarker(board[1][2])<<std::endl;
    std::cout<<" "<<getMarker(board[2][0])<<"  "<<getMarker(board[2][1])<<"  "<<getMarker(board[2][2])<<std::endl;

}