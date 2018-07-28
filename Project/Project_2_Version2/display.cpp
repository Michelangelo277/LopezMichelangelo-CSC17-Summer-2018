/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   display.cpp
 * Author: miche
 * 
 * Created on July 27, 2018, 7:21 PM
 */

#include "display.h"



display::display(){
    title="Hero";
}
display::display(string t){
    title=t;
}
string display::getTitle()const{
    return title;
}