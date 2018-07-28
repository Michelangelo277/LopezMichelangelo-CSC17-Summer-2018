/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   playVals.h
 * Author: miche
 *
 * Created on July 27, 2018, 12:09 PM
 */

#ifndef PLAYVALS_H
#define PLAYVALS_H
#include <iostream>
#include <string>

using namespace std;



class maxInfo{
private:
    char job;
    int strength;
    int maxMana;
    int hltPnts;
    
public:
    maxInfo();
    maxInfo(char,int,int,int);
    void setJob(char);
    char getJob()const;
    void setStr(int);
    int getStr()const;
    void setMana(int);
    int getMana()const;
    void setHlth(int);
    int getHlth()const;    
};

#endif /* PLAYVALS_H */

