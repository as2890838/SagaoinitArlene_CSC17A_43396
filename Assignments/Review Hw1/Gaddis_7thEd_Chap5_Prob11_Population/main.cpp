/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 8, 2021, 3:42 AM
 * Purpose: Predict the size of a population of organisms throughout a number of days
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    //Variable Declarations
    int numOrg; //Starting number of organisms
    float popInc; //Daily population increase (percent)
    int numDays; //Number of days organisms will multiply
    int dailyPop; //Number of organisms increased per day
    
    //User prompt and input
    cout<<"Please enter the starting number of organisms: ";
    cin>>numOrg;
    while(numOrg<2){ //Input validation, needs to be 2 or greater
        cout<<"Please enter valid starting population size (2 or greater): ";
        cin>>numOrg;
    }
    cout<<"Please enter organisms active daily population increase (percent): ";
    cin>>popInc;
    while (popInc<0){ //Input validation, needs to be 0 or greater
        cout<<"Plese enter valid daily population increase (0 or greater): ";
        cin>>popInc;
    }
    cout<<"Enter number of days to report: ";
    cin>>numDays;
    while(numDays<1){ //Input validation, needs to be 1 or greater
        cout<<"Please enter valid number of days (1 or greater): ";
        cin>>numDays;
    }
    dailyPop=numOrg*popInc; //Calculate number of organisms multiplied per day
    
    //Display results for each day
    for(int i=0;i<numDays;i++){
        numOrg+=dailyPop;
        cout<<"Day "<<i+1
             <<" Population size: "<<numOrg<<endl;
    }

    return 0;
}

