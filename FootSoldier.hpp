#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"

using namespace std;

class FootSolider: public Solider{

FootSolider(int PID):(Hp(100),Dp(10),cur_Hp(100),PlayerID(PID)){}

double distance (pair<int,int> enemy,pair<int,int>los){
    return(math.sqrt(math.pow(enemy.first-los.first,2)+math.pow(enemy.second-los.second,2)));
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second].getPID();
     int i=0,j=0;
     pair<int, int> f_enemy, s_enemy;
     f_enemy.first=INT32_MAX; s_enemy.first=INT32_MAX;
      for(i=location.first;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j].getPID()!=nullptr && Board[i][j].getPID()!=myID){
              f_enemy.first=i;
              f_enemy.second=j;
              break;
                }
               }
              }

              for(i=location.first;i>=0;i--){
              for(;j<Board[i].size();j++){
              if(Board[i][j].getPID()!=nullptr && Board[i][j].getPID()!=myID){
              s_enemy.first=i;
              s_enemy.second=j;
              break;
              }  
          }
      }
       if(f_enemy.first!=INT32_MAX || s_enemy.first!=INT32_MAX){
      if(distance(s_enemy,location)<=distance(f_enemy,location)){
          Board[s_enemy.first][s_enemy.second].cur_Hp-=10;
          else
          {
            Board[f_enemy.first][f_enemy.second].cur_Hp-=10;
          }
        } 
      }

      ~FootSolider(){}

}