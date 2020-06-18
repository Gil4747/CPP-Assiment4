#include <string>
#include <vector>
#include <stdexcept>
#include<limits.h>

using namespace std;

class SniperCommander: public Sniper{

public:

SniperCommander(){}

SniperCommander(int PID){
     this->Hp=120;
    this->Dp=100;
    this->cur_Hp=120;
    this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second]->getPID();
     Sniper::specialAttack(Board, location,2);
     int i=0,j=0;
     for(;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()==myID){
                  if(Sniper* x=dynamic_cast<Sniper*>(Board[i][j])){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     Sniper::specialAttack(Board,s);
                  }
              }
          }
     }
}
};