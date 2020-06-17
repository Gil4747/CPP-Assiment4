#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include<limits.h>

using namespace std;

class FootCommander: public Soldier{

public:

FootCommander(){}

FootCommander(int PID){
    this->Hp=100;
    this->Dp=50;
    this->cur_Hp=100;
    this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second]->getPID();
     Board[location.first][location.second]->specialAttack(Board,location);
     int i=0,j=0;
     for(;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()==myID){
                  if(FootSoldier* x=dynamic_cast<FootSoldier*>(Board[i][j])){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     Board[location.first][location.second]->specialAttack(Board,s);
                  }
              }
              
          }
     }
}
          };