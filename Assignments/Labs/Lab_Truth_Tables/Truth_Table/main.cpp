/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 10, 2021, 9:11 PM
 * Purpose: To tell the truth
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void table(bool, bool);

int main(int argc, char** argv)
{
    //Variable declarations
    bool x,y;
    
    //Display heading
    cout<<"X Y\t!X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    // First row
    x=true;
    y=true;
    table(x,y);
    
    // Second row
    x=true;
    y=false;
    table(x,y);
    
    //Third row
    x=false;
    y=true;
    table(x,y);
    
    //Fourth row
    x=false;
    y=false;
    table(x,y);
    
    

    
 
    
    

    return 0;
}

void table(bool x, bool y){
    cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"\t"
        <<(!x?'T':'F')<<" "
        <<(!y?'T':'F')<<" "
        <<(x&&y?'T':'F')<<" "
        <<(x||y?'T':'F')<<" "
        <<(x&&y?'T':'F')<<" "
        <<((x&&y)&&x?'T':'F')<<" "
        <<((x&&y)&&y?'T':'F')<< " "
        <<((x&&y)&&x?'T':'F')<< " "
        <<(!(x&&y)?'T':'F')<<" "
        <<(!x||!y?'T':'F')<<" "
        <<(!(x||y)?'T':'F')<<" "
        <<(!x&&!y?'T':'F')<<" "
        <<endl;
}

