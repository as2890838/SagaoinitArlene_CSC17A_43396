/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 8, 2021, 2:28 AM
 * Purpose: Calculates the assessment value of a property as well as its property tax
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
    //Variable declarations
    float pValue, aValue, propTax; //Property value, assessment value, property tax
    
    //Constants
    const float TAX=0.6; // Percent tax for property 
    
    //User prompt and input
    cout<<"Please enter value of property for assessment: ";
    cin>>pValue;
    
    aValue=pValue*TAX;//Assessment value (60% of property value)
    propTax=(aValue/100)*0.64;//Property tax (64 cents per $100 of assessment value)
    
    cout<<fixed<<setprecision(2)<<showpoint; //Display 2 digits after decimal
    //Display output
    cout<<"Assessment value of property: $"<<aValue<<endl;
    cout<<"Property tax: $"<<propTax<<endl;
    

    return 0;
}

