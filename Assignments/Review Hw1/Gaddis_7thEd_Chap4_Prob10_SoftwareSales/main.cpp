/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 8, 2021, 2:54 AM
 * Purpose: Calculates total cost after discount of number of packages company has sold
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    //Variable Declarations
    int units;
    int cost;
    float total;
    
    //User prompt and input
    cout<<"Enter the number of units sold: ";
    cin>>units;
    
    //Input validation (needs > 0)
    while(units<0){
        cout<<"Please enter a valid amount: ";
        cin>>units;
    }
    cost=units*99; //Compute cost ($99 per unit sold)
        
    //Compute total with discount and display total
    if(units>=0 && units<=9){ //No discount
        cout<<"No discounts applied for amount of units sold"<<endl;
        total=units*99;
        cout<<"Total cost of purchase: $"<<total<<endl;
    }else if(units>=10 && units<=19){ //Take 20% off cost
        total=(cost-(cost*0.2));
        cout<<"Total cost of purchase: $"<<total<<endl;
    }else if (units>= 20 && units<=49){ //Take 30% off cost
        total=(cost-(cost*0.3));
        cout<<"Total cost of purchase: $"<<total<<endl;
    }else if (units>= 50 && units<=99){ //Take 40% off cost
        total=(cost-(cost*0.4));
        cout<<"Total cost of purchase: $"<<total<<endl;
    }else{ //100 units or more sold, take 50% off cost
        total=(cost-(cost*0.5));
        cout<<"Total cost of purchase: $"<<total<<endl;
    }

    return 0;
}

