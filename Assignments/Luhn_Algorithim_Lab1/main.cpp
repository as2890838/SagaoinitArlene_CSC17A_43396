/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 2, 2021, 3:48 PM
 * Purpose: Luhn algorithm: program that attaches a number to the end of 
 * a credit card number for error checking
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char rndDgit(); //gets random char digits
void prpLuhn(char[],int); //prepares Luhn sequence
void Luhn(char[],int,int&); //calculates and appends Luhn digit
int cnvrt(char); //converts char to integer
char cnvrt(int); //converts integer to char

int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    int sum=0;
    
    //Set credit card size
    int SIZE=12;
    //Create static array for cc number of size 12
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    
    //Fill last digit of cc using Luhn Algorithm
    //Luhn algorithm
    Luhn(crdCard,SIZE-2,sum);
    cout<<crdCard<<endl;

    return 0;
}

void Luhn(char cc[],int n,int &sum){
    for(int i=0;i<n;i++){
        if(i%2==1){ //takes every other number in array
            int value=cnvrt(cc[i])*2; //convert char to int and double it
            if(value>9){ 
                sum+=1+(value%10); //add first and second digit of value and add to sum
            }
            else{
                sum+=value; //also add values less than 9 to sum
            }   
        }
        if(i%2==0){
            sum+=cnvrt(cc[i]); //convert char to int and add even numbers to sum
        }   
    }
    cc[n]=cnvrt((sum*9)%10); //convert last digit back to char and append to array
}

int cnvrt(char digit){
    if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit-'0';
}

char cnvrt(int digit){
    if(digit<0||digit>9){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
    }
    return digit+48;
}

char rndDgit(){
    return rand()%10+48; // Add 48 to get characters '0' - '9'
}

void prpLuhn(char cc[],int n){
    //Create random cc number
    for(int i=0;i<n;i++){
        cc[i]=rndDgit(); //grabs random digit, places in cc array
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

