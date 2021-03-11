/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 10, 2021, 9:57 PM
 * Purpose: To prove statements as equal 
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void table(bool, bool);

int main(int argc, char** argv)
{
    //Variable declarationsS
    bool x, y;
    
    //Display heading
    cout << "Prove that (X&&Y)||!(x||y) = !(x&&y)" << endl
         << "also that (X||Y)&&!(X&&Y) =  X&&Y " << endl
         << "X Y\tX&&Y X||Y !(X&&Y) !(X||Y) (X&&Y)||!(X||Y) (X||Y)&&!(X&&Y)" << endl;
    
    x=false;
    y=false;
    table(x,y);
            

    return 0;
}
void table(bool x, bool y){
    cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"\t"
        <<(x&&y?'T':'F')<<" "
        <<(x||y?'T':'F')<<" "
        <<(!(x&&y)?'T':'F')<<" "
        <<(!(x||y)?'T':'F')<<" "
        <<((x&&y)||!(x||y)?'T':'F')<<" "
        <<((x||y)&&!(x&&y)?'T':'F')<<" "
        <<endl;
}
