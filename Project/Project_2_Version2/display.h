/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   display.h
 * Author: miche
 *
 * Created on July 27, 2018, 7:21 PM
 */

#ifndef DISPLAY_H
#define DISPLAY_H
#include "playVals.h"

class display: public maxInfo{
public:
    display();
    display(string);
    void setTitle(string);
    string getTitle()const;
protected:
    string title="Hero";
};

#endif /* DISPLAY_H */

