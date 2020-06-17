#include <iostream>
#include <vector>
using namespace std;

class Soldier {

protected:

int PlayerID;

public:

int Hp; 
int Dp;
int cur_Hp;

Soldier(){}

Soldier(int Hp,int Dp,int PID):Hp(Hp),Dp(Dp),cur_Hp(Hp),PlayerID(PID)){}
    
virtual void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) = 0;
int getPID(){
    return this->PlayerID;
}

~Soldier(){}

}