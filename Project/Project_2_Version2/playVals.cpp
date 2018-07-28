/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enemyVals.cpp
 * Author: miche
 * 
 * Created on July 27, 2018, 12:09 PM
 */

#include "playVals.h"

maxInfo::maxInfo(){
    job='0';
    strength=0;
    maxMana=0;
    hltPnts=0;
}
maxInfo::maxInfo(char jo,int st,int ma,int he){
    job=jo;
    strength=st;
    maxMana=ma;
    hltPnts=he;
}

void maxInfo::setJob(char jo){
    jo=job;
}
char maxInfo::getJob()const{
    return job;
}
void maxInfo::setStr(int st){
    st=strength;
}
int maxInfo::getStr()const{
    return strength;
}
void maxInfo::setMana(int ma){
    ma=maxMana;
}
int maxInfo::getMana()const{
    return maxMana;
}
void maxInfo::setHlth(int he){
    he=hltPnts;
}
int maxInfo::getHlth()const{
    return hltPnts;
}   

