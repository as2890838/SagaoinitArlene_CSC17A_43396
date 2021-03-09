/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 8, 2021, 4:53 AM
 * Purpose: Convert temperature from fahrenheit to celsius
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//Function Prototypes
float celsius(float); //Converts fahrenheit temp to celsius

int main(int argc, char** argv)
{
    cout<<"Fahrenheit\t"<<"Temperature"<<endl
         <<"---------------------------"<<endl;
    
    for(int i=0;i<=20;i++){ //Display table of conversions from temperatures 0-20
        cout<<i<<"\t\t"<<celsius(i)<<endl; //Call conversion function and display results
    }
    
    return 0;
}

float celsius(float F){ //F = temp in fahrenheit
    return ((5*(F-32))/9);
}
