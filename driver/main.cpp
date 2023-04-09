#include"board.h"
#include"player.h"
#include<iostream>
#include"illigalMoveException.h"
#include"outOfBoundMove.h"

Player *switchPlayer(Player *p1,Player *p2,int i){
    if(i==0){
        return p1;
    }
    return p2;
}

int main(){
    Board board(3);
    Player p1("Player 1");
    Player p2("Player 2");
    Player *p = &p1;
    int marker = 0;

    BoardResult result = BoardResult::ONGOING;
    int x,y;
    while(result == BoardResult::ONGOING){
        board.display();
        std::cout<<p->getName()<<" Move :";
        
        std::cin>>x>>y;
        try{
            result = board.move(p,{x,y});
            marker = (marker + 1)%2;
            p = switchPlayer(&p1,&p2,marker);
        } catch(const OutOfBoundMoveException &e){
            std::cout<<e.what()<<std::endl;
        } catch(const IlligalMoveException &e){
            std::cout<<e.what()<<std::endl;
        }

        
        
        
        if(result == BoardResult::GAME_DRAW) {
            board.display();
            p->setStatus(PlayerStatus::PLAYER_DRAW);
            std::cout<<p1.getName()<<" : "<<PlayerStatusEnumConvertor::toString(p1.getStatus())<<std::endl;
            std::cout<<p2.getName()<<" : "<<PlayerStatusEnumConvertor::toString(p2.getStatus())<<std::endl;
        }

        if(result == BoardResult::GAME_OVER){
            board.display();
            p->setStatus(PlayerStatus::PLAYER_LOOSE);
            std::cout<<p1.getName()<<" : "<<PlayerStatusEnumConvertor::toString(p1.getStatus())<<std::endl;
            std::cout<<p2.getName()<<" : "<<PlayerStatusEnumConvertor::toString(p2.getStatus())<<std::endl;
        }

    }

    return 0;
}