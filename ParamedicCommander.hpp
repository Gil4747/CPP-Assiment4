#include <string>
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"
#include <iostream>
#include<limits.h>

using namespace std;

class ParamedicCommander: public Soldier{

public:
ParamedicCommander(){}

ParamedicCommander(int PID){
      this->Hp=100;
      this->cur_Hp=100;
      this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=this->Board[location.first][location.second]->getPID();
     Paramedic::specialAttack(Board,location);
     int i=0,j=0;
     for(;i<this->Board.size();i++){
          for(;j<this->Board[i].size();j++){
              if(Board[i][j]!=nullptr && this->Board[i][j]->getPID()==myID){
                  if(Paramedic* x=dynamic_cast<Paramedic*>(this->Board[i][j])){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     Paramedic::specialAttack(this->Board,s);
                  }
              }
          }
     }
}
};