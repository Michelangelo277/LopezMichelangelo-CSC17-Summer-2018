/* 
 * File:   main.cpp
 * Author: Michelangelo Lopez
 * Created on July 16, 2018, 8;00 PM
 * Purpose:  Text Adventure
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "playVals.h"
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int SIZE=300;
const int ESIZE=7;
struct playerInfo{
    char name[SIZE];
    int str;
    int mana;
    int health;
    int cVal;
};
struct enemyInfo{
    int enStr[ESIZE];
    int enHlth[ESIZE];
};

//Function Prototypes Here

//Player's Input will decide direction and item usage when not in battle
void menu(maxInfo,playerInfo *player,enemyInfo *enemy, int &, bool &, char);

//Will display the north room in the maze
void northRoom(maxInfo,playerInfo *player,enemyInfo *enemy, int &, bool &);

//Will display the south room in the maze
void southRoom(maxInfo,playerInfo *player,enemyInfo *enemy, int &, bool &);

//Will display the east room in the maze
bool eastRoom(maxInfo,playerInfo *player,enemyInfo *enemy, int &, bool &);

//Will display the west room in the maze
void westRoom(maxInfo,playerInfo *player,enemyInfo *enemy, int &, bool &);

//Inputting the Player's Name
char read(playerInfo *player,int ,char);

//Will randomly generate a number to see which enemy will be encountered
int enemies(enemyInfo *enemy, int &);

//Displays combat options
void combat(maxInfo,playerInfo *player,enemyInfo *enemy, int &, bool &);

//Displays the player's combat options
bool choice(playerInfo *player,enemyInfo *enemy, char &, int &, bool &);

//Enemy's attack
void enyAtck(playerInfo *player,enemyInfo *enemy, int &);

//Final Boss 
int fnlBss(enemyInfo *enemy, int &);

//Program Execution Begins Here
int main (int argc, char **argv){
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here :D
    const int SIZEOF=1;
    playerInfo player[SIZEOF]; 
    enemyInfo enemy[ESIZE]; 
    string n;
    char d,j;
    int en,s,m,h;
    bool out=false;
    //Output goes here :D   
    cout<<"Enter your name Traveler!"<<endl;
    cin.getline(player->name, SIZE);
    cout<<"This game has 3 jobs to choose from. \n"
            "Each has its own ability and stats"<<endl;
    cout<<"Knight has the most strength and Health "
            "however cannot use spells"<<endl;
    cout<<"Mage has the most MP(Mana Points) "
            "which can be used to cast spells"<<endl;
    cout<<"Monk has the least Health but has balanced strength "
            "and MP with the ability Scan"<<endl;
    cout<<"Which job would you like to choose?"<<endl;
    cout<<"A->Knight\nS->Mage\nD->Monk"<<endl;
    cin>>d;
    
    if(d=='a'||d=='A'){
        j='a';
        s=20;
        m=0;
        h=200;
        player->str=20;
        player->mana=0;
        player->health=200;
        player->cVal=1;
    }
    if(d=='s'||d=='S'){
        j='s';
        s=0;
        m=300;
        h=50;
        player->str=0;
        player->mana=30;
        player->health=50;
        player->cVal=2;
    }
    if(d=='d'||d=='D'){
        j='d';
        s=15;
        m=15;
        h=150;
        player->str=15;
        player->mana=15;
        player->health=150;
        player->cVal=3;
        cout<<"Scan is the ability to see the enemy's health if you chose to "
                "use a turn to examine the enemy"<<endl;
    }
    maxInfo max(j,s,m,h);
    menu(max,player,enemy,en,out,d);
    //Exit
    
    return 0;
}

void menu(maxInfo max,playerInfo *player,enemyInfo *enemy,int &en, bool &out, char d){
    bool key=false;
    cout<<"Enter a direction using"<<endl;
    cout<<"W->North"<<endl;
    cout<<"A->West, D->East"<<endl;
    cout<<"S->South"<<endl;
    cin>>d;
    if(d=='w'||d=='W'){
        if(key=false){
            cout<<"The door is locked"<<endl;
        }else if(key=true){
            cout<<"You've unlocked the door"<<endl;
            northRoom(max,player,enemy,en,out);
        }
    }else if(d=='a'||d=='A'){
        westRoom(max,player,enemy,en,out);
    }else if(d=='d'||d=='D'){
        out=eastRoom(max,player,enemy,en,out);
    }else if(d=='s'||d=='S'){
        southRoom(max,player,enemy,en,out);
    }
}

void northRoom(maxInfo max,playerInfo *player,enemyInfo *enemy,int &en, bool &out){
    out=false;
    en=fnlBss(enemy,en);
    cout<<"A giant falls from the ceiling and lands before you. Defeat it and leave the dungeon!"<<endl;
    combat(max,player, enemy, en, out);
}

void southRoom(maxInfo max,playerInfo *player,enemyInfo *enemy,int &en, bool &out){
    out=false;
    cout<<"The room is bare except for a sheet in the corner..."<<endl;
    combat(max,player, enemy, en, out);
}
bool eastRoom(maxInfo max,playerInfo *player,enemyInfo *enemy,int &en, bool &out){
    int key=false;
    out=false;
    cout<<"There is a key on the wall! You go towards it to pick it up..."<<endl;
    combat(max,player, enemy, en, out);
    return key;
}
void westRoom(maxInfo max,playerInfo *player,enemyInfo *enemy,int &en, bool &out){
    out=false;
    cout<<"The room makes you feel stronger by just standing in it..."<<endl;
    player->str=10000;
    combat(max,player, enemy, en, out);
}


int enemies(enemyInfo *enemy,int &en){
    if(en!=6){
        en=rand()%5;
    }
    switch(en){
        case 0:cout<<"A Goblin has Appeared!"<<endl;
               enemy->enHlth[en]=40;
               enemy->enStr[en]=15;break;
        case 1: cout<<"An Imp has Appeared!"<<endl;
            enemy->enHlth[en]=20;
            enemy->enStr[en]=5;break;
        case 2: cout<<"An Armored Goblin has Appeared!"<<endl;
            enemy->enHlth[en]=120;
            enemy->enStr[en]=20;break;
        case 3:cout<<"An Armored Imp has Appeared!"<<endl;
            enemy->enHlth[en]=40;
            enemy->enStr[en]=15;break;
        case 4: cout<<"A Slime has Appeared!"<<endl;
            enemy->enHlth[en]=10;break;
            enemy->enStr[en]=5;
        case 5: cout<<"A Hardened Slime has Appeared!"<<endl;
            enemy->enHlth[en]=80;
            enemy->enStr[en]=15;break;
        }      
    return en;
}

void combat(maxInfo max,playerInfo *player,enemyInfo *enemy,int &en, bool &out){
    char d;
    out=false;
    if(en!=6){
    enemies(enemy, en);
    }
    while(enemy->enHlth[en]>0&&player->health!=0&&out==false){
        cout<<"What will you do?"<<endl;
        cout<<player->name<<"'s Current Health:"<<player->health<<"/"<<max.getHlth()<<endl;
        if(max.getHlth()==150){
            cout<<"A->Attack\nD->Run"<<endl;
            cout<<"S->Scan"<<endl;
            cin>>d; 
        }
        if(max.getHlth()==50){
            cout<<"A->Attack\nD->Run"<<endl;
            cout<<"S->Spells"<<endl;
            cin>>d;
        }
        if(max.getHlth()==200){
            cout<<"A->Attack\nD->Run"<<endl;
            cout<<"S->Shield"<<endl;
            cin>>d;
        } 
        choice(player,enemy,d,en,out);
        enyAtck(player,enemy,en);
    }
    if(enemy->enHlth[en]<0){
    cout<<"You've won!"<<endl;
    menu(max,player,enemy,en,out,d);
    }else if(player->health==0){
        cout<<"You've been defeated..."<<endl;
        cout<<"Game Over"<<endl;
    }
    
}

void enyAtck(playerInfo *player,enemyInfo *enemy, int &en){
    cout<<"The enemy attacks!"<<endl;
    player->health-=enemy->enStr[en];
}
bool choice(playerInfo *player,enemyInfo *enemy,char &d, int &en, bool &out){ 
    out=false;
    if(d=='a'&&player->cVal==3||d=='A'&&player->cVal==3){
        cout<<"You punch the creature!"<<endl;
        enemy->enHlth[en]-=player->str;
    }
    if(d=='s'&&player->cVal==3||d=='S'&&player->cVal==3){
        cout<<"You examine the creature"<<endl;
        cout<<"It's health is:"<<enemy->enHlth[en]<<endl;
        player->mana-=5;
        cout<<"You have "<<player->mana<<" remaining"<<endl;
    }
    if(d=='d'&&player->cVal==3||d=='D'&&player->cVal==3){
        cout<<"You ran away!"<<endl;
        out=true;
        return out;
    }
    if(d=='a'&&player->cVal==2||d=='A'&&player->cVal==2){
        cout<<"You swing your staff at the creature!"<<endl;
        enemy->enHlth[en]-=player->str;
        cout<<"You did 0 damage!"<<endl;
    }
    if(d=='s'&&player->cVal==2||d=='S'&&player->cVal==2){
        player->mana-=5;  
    }
    if(d=='d'&&player->cVal==2||d=='D'&&player->cVal==2){
        cout<<"You ran away!"<<endl;
        out=true;
        return out;
    }
    if(d=='a'&&player->cVal==1||d=='A'&&player->cVal==1){
        cout<<"You slash your sword at the creature!"<<endl;
        enemy->enHlth[en]-=player->str;
    }
    if(d=='s'&&player->cVal==1||d=='S'&&player->cVal==1){
        cout<<"You defend yourself"<<endl;
    }
    if(d=='d'&&player->cVal==1||d=='D'&&player->cVal==1){
        cout<<"You ran away!"<<endl;
        out=true;
        return out;
    }
}

int fnlBss(enemyInfo *enemy, int &en){
    en=6;
    cout<<"The Giant Stands in your way to freedom!"<<endl;
    enemy->enHlth[en]=120;
    enemy->enStr[en]=20;        
    return en;
}
