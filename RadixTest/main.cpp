//
//  main.cpp
//  RadixTest
//
//  Created by JFRE74708 on 2017-11-22.
//  Copyright © 2017 JFRE74708. All rights reserved.
//

#include <vector>
#include <iostream>
#include <math.h>

// so I don't have to use std in the thing
using namespace std;


// global variables
vector<int> sArray;

// return the number at the digit for instance (342, 2) would return 4
int numberAtDigit(int number, int digit){
    number=number-((number)/((int)pow(10,digit))*pow(10,digit)); //truncate numbers above
    number=number/pow(10,digit-1); //truncate numbers below
    return number;
}

// Function to determine the most amount of digits in any number
int numberOfDigits(vector<int> numbers){
    // declare the number
    int digits=0;
    int largestNumber=0;
    
    // for loop that goes through the numbers to determine the most digits
    for(int i=0; i<=numbers.size()-1; i++){
        if(abs(numbers.at(i))>largestNumber){
            largestNumber=abs(numbers.at(i));
        }
    }
    
    // determine the number of digits using the largest number
    while(largestNumber!=0){
        digits++;
        largestNumber=largestNumber/10;
    }
    
    return digits;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "radix\n";
    
    // Initialize the array and vector of "random" numbers
    vector<int> vNumbers = {44,7,3,84,1,455,3456,346,34, 7467,34,23,4765,235,235,6751,2756,3867,10};
    vector<int> vNumbers2;
    
    // print the numbers
    for (int i = 0 ; i <= vNumbers.size()-1; i++)
        cout << vNumbers.at(i) << "\n";
    cout << "\n";
    
    // array of vectors example
    vector<int> arrayOfVectors[vNumbers.size()-1];
    
    
    //SORT THE NUMBERS -------------------
    // for every digit (from the ones digit to the greatest digit)
    for(int a=1; a<=numberOfDigits(vNumbers); a++){

        // for every bucket (from the zeroth bucket to the 9th)
        for(int b=0; b<=9; b++){
            
            // for the number of numbers in the vector
            for(int c=0; c<vNumbers.size(); c++){
                
                // if the number at the specified digit equals the current bucket
                if(numberAtDigit(vNumbers.at(c),a)==b){
                    
                    // add the number to the array of buckets at the specified bucket
                    arrayOfVectors[b].push_back(vNumbers.at(c));
                }
            }//c
        }//b
        
        // for every bucket
        for(int c2=0; c2<vNumbers.size(); c2++){
            
            // if the bucket in the array of buckets is empty
            if(!arrayOfVectors[c2].empty()){
                
                // for the size of the bucket
                for(int d=0; d<arrayOfVectors[c2].size(); d++){
                    
                    // add the elements of the bucket to a vector
                    vNumbers2.push_back(arrayOfVectors[c2].at(d));
                }//d
                
                // clear the array of buckets
                arrayOfVectors[c2].clear();
            }
        }//c2
        
        vNumbers=vNumbers2;
        vNumbers2.clear();
    }//a
    
    // print the numbers
    for (int i = 0 ; i <= vNumbers.size()-1; i++){
        cout << vNumbers.at(i) << "\n";
    }
    
    cout << "\n";
    cout << vNumbers.size() << "=vNumbers.size()"<<"\n"<<vNumbers2.size()<<"=vNumbers2.size";
    cout << numberOfDigits(vNumbers);
    
    return 0;
}
