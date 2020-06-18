#include <string>
#include <vector>
#include <stdexcept>
#include <math.h> 
#include<limits.h>

using namespace std;

class FootSoldier: public Soldier{

public:

FootSoldier(){}

FootSoldier(int PID){
    this->Hp=100;
    this->Dp=10;
    this->cur_Hp=100;
    this->PlayerID=PID;
}

double distance (pair<int,int> enemy,pair<int,int>los){
    return(sqrt(pow(enemy.first-los.first,2)+pow(enemy.second-los.second,2)));
}
void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location,int dummy) override{
     int myID=Board[location.first][location.second]->getPID();
     int i=0,j=0;
     pair<int, int> f_enemy, s_enemy;
     f_enemy.first=INT32_MAX; s_enemy.first=INT32_MAX;
      for(i=location.first;i<Board.size();i++){
          for(;j<Board[i].size();j++){
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()!=myID){
              f_enemy.first=i;
              f_enemy.second=j;
              break;
                }
               }
              }

              for(i=location.first;i>=0;i--){
              for(;j<Board[i].size();j++){
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()!=myID){
              s_enemy.first=i;
              s_enemy.second=j;
              break;
              }  
          }
      }
       if(f_enemy.first!=INT32_MAX || s_enemy.first!=INT32_MAX){
      if(distance(s_enemy,location)<=distance(f_enemy,location)){
          auto a=Board[s_enemy.first][s_enemy.second]->cur_Hp-20;
          Board[s_enemy.first][s_enemy.second]->cur_Hp=a;
      }
          else
          {
           auto a=Board[f_enemy.first][f_enemy.second]->cur_Hp-20;
          Board[f_enemy.first][f_enemy.second]->cur_Hp=a;;
          }
           if(Board[s_enemy.first][s_enemy.second]->cur_Hp<=0){
          Board[s_enemy.first][s_enemy.second]=nullptr;
      }
       if(Board[f_enemy.first][f_enemy.second]->cur_Hp<=0){
          Board[f_enemy.first][f_enemy.second]=nullptr;
      }
        } 
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second]->getPID();
     int i=0,j=0;
     //cout<<location.first<<" "<<location.second<<endl;
     cout<<Board.size()<<" "<<Board.front().size()<<endl;
     pair<int, int> f_enemy, s_enemy;
     f_enemy.first=INT32_MAX; s_enemy.first=INT32_MAX;
      for(i=location.first;i<Board.size();i++){
          for(;j<Board[i].size();j++){
               cout<<i<<" "<<j<<endl;
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()!=myID){
              cout<<i<<" "<<j<<endl;
              f_enemy.first=i;
              f_enemy.second=j;
              break;
                }
               }
              }
    //           for(i=location.first;i>=0;i--){
    //           for(;j<Board.front().size();j++){
    //                 cout<<i<<" "<<j<<endl;
    //           if(Board[i][j]!=nullptr && Board[i][j]->getPID()!=myID){
    //           s_enemy.first=i;
    //           s_enemy.second=j;
    //           break;
    //           }  
    //       }
    //   }
       
       if(f_enemy.first!=INT32_MAX || s_enemy.first!=INT32_MAX){
      if(distance(s_enemy,location)<=distance(f_enemy,location)){
          cout<<s_enemy.first<<" "<<s_enemy.second<<endl;
          auto a=Board[s_enemy.first][s_enemy.second]->cur_Hp-10;
          Board[s_enemy.first][s_enemy.second]->cur_Hp=a;
          cout<<s_enemy.first<<" "<<s_enemy.second<<endl;
          cout<<endl; cout<<endl;
      }
          else
          {
           auto a=Board[f_enemy.first][f_enemy.second]->cur_Hp-10;
          Board[f_enemy.first][f_enemy.second]->cur_Hp=a;
          }
           if(Board[s_enemy.first][s_enemy.second]->cur_Hp<=0){
          Board[s_enemy.first][s_enemy.second]=nullptr;
      }
       if(Board[f_enemy.first][f_enemy.second]->cur_Hp<=0){
          Board[f_enemy.first][f_enemy.second]=nullptr;
      }
        } 
}
      ~FootSoldier(){}

};