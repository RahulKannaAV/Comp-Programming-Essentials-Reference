// Given string, find possible subsets from the string using Bit manipulation
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> generateSubsets(string input){
    vector<string> subsetVector; // Vector for storing all the possible subsets

    int low=0; // Lower bound of number for deciding subset
    int high=1 << input.size(); // Higher bound (actually 1 less than this. Rectified with for loop)

    for(int i=low; i<high; i++){
        int num = i; // Copy of the iterating number
        int idx=0; // Index of the string to be included/excluded based on the bit
        string temp = ""; // Similar to tempSum variable. But for strings

        while(num>0){
            int lastBit = num&1;
            if(lastBit == 1){ // If the last bit is 1, include the character that is present in the index 'idx'. Save it in temp string
                temp += input[idx];
            }

            idx++; // Move to next index (based on input string)
            num = num >> 1; // Bitwise left shift the copy
        }
        subsetVector.push_back(temp); // After the iteration ends, store the temp string inside the vector
    }
    return subsetVector;
}

int main() {
    string sample = "abc";
    vector<string> subsets = generateSubsets(sample);
    cout << subsets.size() << endl;
    for(string s: subsets){
        cout << s << ", ";
    }

    return 0;
}