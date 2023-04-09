#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include"move.h"

enum PlayerStatus{
    PLAYER_IDLE, PLAYER_PLAYING, PLAYER_WON, PLAYER_LOOSE, PLAYER_DRAW
};

class PlayerStatusEnumConvertor{
    public:
    inline static std::string toString(PlayerStatus status) {
        std::string enumToString;
        switch (status)
        {
        case PLAYER_IDLE:
            enumToString = "IDLE";
            break;
        case PLAYER_PLAYING:
            enumToString = "PLAYING";
            break;
        case PLAYER_WON:
            enumToString = "WON";
            break;
        case PLAYER_LOOSE:
            enumToString = "LOOSE";
            break;
        case PLAYER_DRAW:
            enumToString = "DRAW";
            break;
        
        default:
            enumToString = "";
            break;
        }
        return enumToString;
    }
};

class Player{
    private:
    std::string name;
    PlayerStatus status;
    int marker;
    public:
    Player(std::string name);
    int getMarker();
    void setMarker(int marker);
    PlayerStatus getStatus();
    void setStatus(PlayerStatus status);
    inline std::string getName(){ return name;}
};

#endif