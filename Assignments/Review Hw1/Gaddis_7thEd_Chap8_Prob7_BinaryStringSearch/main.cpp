/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 8, 2021, 6:22 AM
 * Purpose: Searches through an array of strings for user's input and returns location of input
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void selSort(string[],int);//Selection sort to put names in alphabetical order
int bnarySrch(string[],int,string);//Searches for user input and returns location int
int main(int argc, char** argv)
{
    string name;//For user input
    int size=10;//Size of array
    string names[size]={"Bill","Bart","Jim","Allen","Isabel","Cecilia","Karthik",
                          "David","Aaron","Angel"};
    
    selSort(names, size);//Sorts contents of array to be displayed in alphabetical order
    //Display names in array after sorted
    for(int i=0;i<size;i++)
        cout<<names[i]<<" ";
    
    //Prompt user to enter a name to find
    cout<<endl<<"Enter string name: ";
    cin>>name;
    
    int location=bnarySrch(names, size, name);//Searches array for input and returns location
    //Display result
    if(location==-1)
        cout<<"That number was not found!"<<endl;
    else
        cout<<"The name is located at: "<<location<<endl;

    return 0;
}

void selSort(string a[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;//Set first element in array as first name in order
        //Compare next element to first element, if less than first element, 
        //update as next name in order
        for(int j=i;j<size;j++){
            if (a[j]<a[min])
                min = j;
        }
        swap(a[i], a[min]); //Swap previous element with new name
    }
}

int bnarySrch(string a[],int size, string name)
{
    int low=0;//First element in array
    int high=size-1;//Last element in array
    int middle=(low+high)/2;//Starting location for guess
    string guess=a[middle];
    
    while(guess!=name && low<=high){//Keep guessing until guess is correct
        if(guess<name){
            low=middle+1;//Set new low, search to the right of it
            middle=(low+high)/2;//Update new middle
            guess=a[middle];//Update new guess
        }
        else{//Guessed to the right of name
            high=middle-1;//Set new high, search to the left of it
            middle=(low+high)/2;//Update new middle
            guess=a[middle];//Update new guess
        }
    }
    
    if(low>high)//Went out of range, name not found
        return -1;
    else
        return middle;//Location of name
}