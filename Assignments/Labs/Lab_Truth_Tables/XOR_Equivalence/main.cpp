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
#include <iomanip>
using namespace std;

void table(bool, bool);

int main(int argc, char** argv)
{
    //Variable declarationsS
    bool x, y;
    
    //Display heading
    cout << "Prove that (X^Y)||!(X||Y) = !(X^Y)" << endl
         << "also that (X||Y)^!(X^Y) =  X^Y " << endl << endl;
    
    cout<<left<<setw(8)<<"X"<<setw(8)<<"Y"<<setw(8)<<"X^Y"<<setw(8)<<"!(X^Y)"<<setw(16)
        <<"(X^Y)||!(X||Y)"<<"(X||Y)^!(X^Y)"<<endl;
    
    x=false;
    y=false;
    table(x,y);
            

    return 0;
}
void table(bool x, bool y){
    cout<<left<<setw(8)
        <<(x?'T':'F')<<setw(8)
        <<(y?'T':'F')<<setw(8)
        <<(x&&y?'T':'F')<<setw(8)
        <<(!(x&&y)?'T':'F')<<setw(16)
        <<((x&&y)||!(x||y)?'T':'F')
        <<((x||y)&&!(x&&y)?'T':'F')<<endl;
}
