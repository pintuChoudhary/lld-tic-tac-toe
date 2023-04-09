#include"player.h"

Player::Player(std::string name):name(name) , status(PlayerStatus::PLAYER_IDLE), marker(2){}

int Player::getMarker(){
    return marker;
}

void Player::setMarker(int marker){
    this->marker = marker;
}

PlayerStatus Player::getStatus(){
   return status;
}

void Player::setStatus(PlayerStatus status){
    this->status = status;
}