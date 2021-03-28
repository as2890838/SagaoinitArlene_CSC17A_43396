/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 27, 2021, 7:29 PM
 * Purpose: Generate credit cards and determine if card is valid after flipping two digits or 
 * transposing two digits
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Enumeration for the card type
enum CrdCard{
    VISA,MASTER,AMERICAN_EXPRESS,DISCOVER
}cards;

char rndDgit(); //gets random char digits
void genCC(CrdCard,char[],int &); //Generates random numbers to credit cards
void Luhn(char[],int); //calculates and appends Luhn digit
int cnvrt(char); //converts char to integer
char cnvrt(int); //converts integer to char
void flipDig(char[],int); //flips two digits in the card
void trnpose(char[],int); //transposes two digits adjacent to each other in the card
bool validCC(char[],int); //Determine if card is valid


int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    int numValid=0;//Accumulator for number of valid credit cards
    int numInvalid=0;//Accumulator for number of invalid credit cards
    int SIZE=20;//Set credit card size
    
    //Create static array for cc
    char card[SIZE];
    CrdCard cardType=AMERICAN_EXPRESS; //Set credit card type
    
    //Generate each card by assigning random digits to the set
    genCC(cardType, card, SIZE);
    Luhn(card,SIZE);//Attach luhn number to end of credit card for evalutation
    while (!validCC(card,SIZE)){ //Determine if card is valid
        genCC(cardType,card,SIZE); //Generate new card until valid
        Luhn(card,SIZE);
    }
    
    //Save and output the valid credit card without the attached luhn number
    char validCrd[SIZE];
    for(int i =0; i<SIZE;i++)
        validCrd[i]= card[i];//copy each element of valid card to new array without luhn number
    
    for(int i=SIZE;i<SIZE+1;i++)//Set null terminator
        validCrd[i]='\0';
    cout<<validCrd<<endl;//Output valid card
 
    for(int i=0;i<10000;i++){//Loop 10000 times for valid and invalid count
        //flipDig(validCrd,SIZE);//Flips two digits in the card
        //OR transpose
        trnpose(validCrd,SIZE);//Swaps two digits next to each other
        Luhn(validCrd,SIZE);//Attach luhn number to evaluate
        if(validCC(validCrd,SIZE))//Evaluate and record number of valid and invalid
            numValid++;
        else
            numInvalid++;
    }
    //Output number of valid and invalid
    cout<<"Num valid: "<<numValid<<endl;
    cout<<"Num Invalid: "<<numInvalid<<endl;

    return 0;
}

char rndDgit(){
    return rand()%10+48; //Add 48 to get characters '0' - '9'
}

void genCC(CrdCard card,char cc[],int &size){
    for(int i=0;i<size;i++)//Grab random digit place in card
        cc[i]=rndDgit();
    
    if(card==VISA){
        cc[0]='4';//Set first element to '4' for visa card
        size=16;//Set size for visa card
    }
    if(card==MASTER){
        cc[0]='5';//Set first element to '5' for master card
        size=16;//Set size for master card
        if(cc[1]<'1'||cc[1]>'5')//Set next element as digit between '1' and '5' for master card
            cc[1]=rand()%6+48;
    }
    if(card==AMERICAN_EXPRESS){
        cc[0]='3';//Set first element to '3' for american express card
        cc[1]='4';//Set second element to '4' for american express card
        size=15;//Set size for american express card
    }
    if(card==DISCOVER){
        //Set first four elements to '6011' for discover card
        cc[0]='6';
        cc[1]='0';
        cc[2]='1';
        cc[3]='1';
        size=16;//Set size for discover card
    }
    for(int i=size;i<=size+1;i++)
        cc[i]='\0';//Attach null terminator at the end
}

void Luhn(char cc[],int size){
    int sum=0; //Set sum to 0
    for(int i=0;i<size;i++){
        if(i%2==1){ //takes every other number in array
            int value=cnvrt(cc[i])*2; //convert char to int and double it
            if(value>9)
                sum+=1+(value%10); //add first and second digit of value and add to sum
            else
                sum+=value; //also add values less than 9 to sum
        }
        if(i%2==0)
            sum+=cnvrt(cc[i]); //convert char to int and add even numbers to sum
    }
    cc[size]=cnvrt((sum*9)%10); //convert last digit back to char and append to array
}

void flipDig(char cc[],int size){
    int num=rand()%(size-1);//Get a number from 0 to size of credit card minus 1
    cc[num]=rndDgit();//Assign element to a random digit from '0' to '9'
    num=rand()%(size-1);//Get another random number 
    cc[num]=rndDgit();//Assign another element to a random digit from '0' to '9'
}

void trnpose(char cc[],int size){
    int num=rand()%(size-1);//Get a number from 0 to size of credit card minus 1
    char temp=cc[num];//Create temporary char value to hold first digit to transpose
    
    //If element number happens to be the last element(num==size-1), set value to element before it(num-1)
    //Otherwise set value to element after it(num+1)
    cc[num]=(num==(size-1))?cc[num-1]:cc[num+1];
    cc[num+1]=temp;//set second value to the first value
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

bool validCC(char cc[],int size){
    int sum=0;//Set sum to 0
    
    for(int i=0;i<size+1;i++)
        sum += cnvrt(cc[i]);//convert char to integer and add to sum
    if (sum % 10 == 0)//if sum mod 10 is 0, card is valid
        return true;
    else //not 0, card invalid
        return false;
}
