/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 8, 2021, 1:29 AM
 * Purpose: Calculates company's sales tax report for the month
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{
    // Variable declarations
    string month;
    int year;
    float totAmnt; //User input: total amount collected from register
    float sales, cSales, sSales; //Total sales, county sales, and state sales
    
    //Constants
    const float cTax=0.02; //County tax in percent
    const float sTax=0.04; //State tax in percent
    
    //User prompts and input
    cout<<"Enter month for monthly sales tax report: ";
    cin>>month;
    cout<<"Enter the year: ";
    cin>>year;
    cout<<"Total amount collected from register: ";
    cin>>totAmnt;
    
    sales=totAmnt/1.06; //Calculates product sales from total amount
    cSales=sales*cTax;
    sSales=sales*sTax;
    
    cout<<fixed<<setprecision(2)<<showpoint; //Set results with 2 digits after decimal
    //Display results
    cout<<"Month: "<<month<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Total collected:\t$"<<totAmnt<<endl;
    cout<<"Sales:\t\t\t$"<<sales<<endl;
    cout<<"County Sales Tax:\t$"<<cSales<<endl;
    cout<<"State Sales Tax:\t$"<<sSales<<endl;
    cout<<"Total Sales Tax:\t$"<<cSales+sSales<<endl;
    
    return 0;
}

