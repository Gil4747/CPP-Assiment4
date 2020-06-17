#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Paramedic.hpp"
#include <iostream>

using namespace std;
class ParamedicCommander: public Solider{

ParamedicCommander(int PID):(Hp(100),Dp(50),cur_Hp(100),PlayerID(PID)){}
void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second].getPID();
     Paramedic::specialAttack(Board,location);
     int i=0,j=0;
     for(;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j].getPID()!=nullptr && Board[i][j].getPID()==myID){
                  if((Paramedic* x=dynamic_cast<Paramedic*>(Board[i][j]))!=NULL){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     Paramedic::specialAttack(Board,s);
                  }
              }
          }
     }
}
}