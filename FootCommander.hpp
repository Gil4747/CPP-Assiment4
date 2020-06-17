#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include <iostream>

using namespace std;

class FootCommander: public Solider{

FootCommander(int PID):(Hp(100),Dp(50),cur_Hp(100),PlayerID(PID)){}
void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second].getPID();
     FootSolider::specialAttack(Board,location);
     int i=0,j=0;
     for(;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j].getPID()!=nullptr && Board[i][j].getPID()==myID){
                  if((FootSolider* x=dynamic_cast<FootSolider*>(Board[i][j]))!=NULL){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     FootSolider::specialAttack(Board,s);
                  }
              }
              
          }
     }
}
          }