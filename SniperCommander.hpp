#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Sniper.hpp"

using std namespace;
class SniperCommander: public Solider{

SniperCommander(int PID):(Hp(120),Dp(100),cur_Hp(120),PlayerID(PID)){}
void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second].getPID();
     Sniper::specialAttack(Board, location);
     int i=0,j=0;
     for(;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j].getPID()!=nullptr && Board[i][j].getPID()==myID){
                  if((Sniper* x=dynamic_cast<Sniper*>(Board[i][j]))!=NULL){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     Sniper::specialAttack(Board,s);
                  }
              }
          }
     }
}
}