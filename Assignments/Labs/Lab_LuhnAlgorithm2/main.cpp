/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: arlen
 *
 * Created on March 27, 2021, 3:53 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum CrdCard{
    VISA,MASTER,AMERICAN_EXPRESS,DISCOVER
}cards;

char rndDgit(); //gets random char digits
void Luhn(char[],int,int&); //calculates and appends Luhn digit
int cnvrt(char); //converts char to integer
char cnvrt(int); //converts integer to char
void genCC(CrdCard,char [], int &);
bool validCC(char[], int);
void flipDig(char [],int);

int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    int sum=0;
    
    //Set credit card size
    int SIZE=20;
    //Create static array for cc number of size 12
    char card[SIZE]; //={'4','9','2','9','4','7','9','8','5','3','7','1','9','8','1','9'};
    CrdCard cardType=AMERICAN_EXPRESS;
    //Prepare for Luhn encoding
    //cout<<"A random number created in Prep for Luhn digit"<<endl;
    //prpLuhn(crdCard,SIZE-2);
    genCC(cardType, card, SIZE);
    
    //Output the preLuhn credit card
    cout<<card<<endl;
    
    //Flip single digit
    flipDig(card,SIZE);
    cout << "New card: " << endl;
    cout <<card<<endl;
    
    //Fill last digit of cc using Luhn Algorithm
    //Luhn algorithm
    Luhn(card,SIZE,sum);
    cout<<card<<endl;
    if(validCC(card, SIZE))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "NOT Valid" << endl;
    }

    return 0;
}

void genCC(CrdCard card,char cc[], int &size)
{
    for(int i = 0; i < size; i++)
    {
        cc[i] = rndDgit();
    }
    if(card==VISA){
        cc[0] = '4';
        size = 16;
    }
    if(card==MASTER){
        cc[0] = '5';
        size = 16;
        if(cc[1]<'1'||cc[1]>'5')
        {
            cc[1] = rand()%6+48; //assign digit to character from '1' to '5'
        }
    }
    if(card==AMERICAN_EXPRESS){
        cc[0] = '3';
        cc[1] = '4';
        size = 15;
    }
    if(card==DISCOVER){
        cc[0] = '6';
        cc[1] = '0';
        cc[2] = '1';
        cc[3] = '1';
        size = 16;
    }
    for(int i=size;i<=size+1;i++){
        cc[i]='\0';
    }
}

void flipDig(char cc[],int size)
{
    int num = rand()%(size-1);//get a number from 0 to size of credit card minus 1
    cc[num] = rndDgit();
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


bool validCC(char cc[], int size)
{
    int sum = 0;
    for(int i = 0; i < size+1; i++)
    {
        sum += cnvrt(cc[i]);
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    if(sum % 10 !=0)
    {
        return false;
    }
}
