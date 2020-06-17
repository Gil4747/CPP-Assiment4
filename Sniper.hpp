#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
 

class Sniper: public Solider{

Sniper(int PID):(Hp(100),Dp(50),cur_Hp(100),PlayerID(PID)){}
void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second].getPID();
     int i=0,j=0;
     int max_power=0;
     pair<int, int> s_enemy;
     for(;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j].getPID()!=nullptr && Board[i][j].getPID()!=myID){
                 if(Board[i][j].cur_Hp>max_power){
                  max_power=Board[i][j].cur_Hp;
                  s_enemy.first=i;
                  s_enemy.second=j;
                 }
              }
          }
     }

      Board[s_enemy.first][s_enemy.second].cur_Hp-=50;

}
}