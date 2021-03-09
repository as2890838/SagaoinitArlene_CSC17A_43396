/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arlene Sagaoinit
 * Created on March 8, 2021, 5:12 AM
 * Purpose: Compute the lowest and highest number, total, and average of random numbers in a file
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//Function prototypes
int lowest(int a[], int); //Search for lowest number in array, returns int
int highest(int a[], int); //Search for highest number in array, returns int
int total(int a[], int); //Compute sum of numbers in array, returns int
double average(int a[], int); //Compute the average of values in array, returns double

int main(int argc, char** argv)
{
    ifstream fin; //Read from file
    fin.open("Numbers.txt"); //Existing file consisting of random numbers
    
    //Declare array and size of array
    int size=8; 
    int a[size];
    
    //Checking for file open error
    if(!fin)
        cout<<"File not successfully opened!";
    //Transfer contents of file to array
    for(int i=0;i<size;i++)
        fin>>a[i];
    //Close file
    fin.close();
    
    //Output contents of array/numbers in file
    cout<<"Numbers in file: "<<endl;
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";

    //Display results
    cout<<endl<<"Lowest: "<<lowest(a, size)<<endl
        <<"highest: "<<highest(a, size)<<endl
        <<"Total: "<<total(a, size)<<endl
        <<"Average: "<<average(a, size)<<endl;
    
    return 0;
}

int lowest(int a[], int size){
    int lowest=a[0]; //Set lowest to first element in array
    
    for(int i=0;i<size;i++)
        if(a[i]<lowest)
            lowest=a[i]; //Update if element i is less than previous element
    return lowest;
}

int highest(int a[], int size){
    int highest=a[0]; //Set highest to first element in array
    
    for(int i=0;i<size;i++)
        if (a[i]>highest)
            highest=a[i]; //Update if element i is greater than previous element
    return highest;
}

int total(int a[], int size){
    int total=0;
    
    for(int i=0;i<size;i++)
        total+=a[i];
    return total;
}

double average(int a[], int size){
    return static_cast<double>(total(a, size))/size;
}