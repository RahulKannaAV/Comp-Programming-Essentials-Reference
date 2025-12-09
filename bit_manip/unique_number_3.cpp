// Given set of numbers where numbers are repeated thrice except one which occurs only once. Find that number
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int unique_number3(int* arr, int size) {

    vector<int> bitSums; // Vector to store the sum of ith bit of all numbers

    bool shouldContinue = true; // Decides whether we should iterate further

    while(shouldContinue){
        int zeroCounts = 0; // Counting how many numbers becomes zero after bitwise right shifts
        int tempSum = 0; // Counts that position bit's sum of all numbers

        for(int i=0; i<size; i++){
            if(arr[i] == 0){
                zeroCounts++; // Number becomes zero, keep track of it to decide on further iteration
                continue;
            }

            int lastBit = arr[i]&1; // Otherwise keep note of the last bit value. If 1, add to the sum
            if(lastBit == 1) {
                tempSum++;
            }

            arr[i] = arr[i] >> 1; // Bitwise right shift the number
        }

        if(zeroCounts == size) { // If all elements become zero, stop the iteration
            shouldContinue = false;
        }
        bitSums.push_back(tempSum%3); // Adding the sum of that position bit to the vector
        // Reason for tempSum%3: Except one, all the unique numbers present in the array are repeated thrice
        // Therefore, occurs same atleast three times. Therefore that one unique number alone causes some disturbance
        // to the sum. Therefore we have to find the location of disturbances and try to construct the number from those locations alone
        // If mod result == 1, disturbance formed there. Otherwise, no disturbances there
    }

    int number = 0;
    double power = 0.0;
    // Reconstruction of binary result (obtained from vector) to decimal
    for(int x: bitSums) {
        number += (x*pow(2.0, power));
        power++;
    }

    cout << number;
    return number;

}

int main() {
    int arr[10]= {7, 5, 4, 7, 5, 4, 7, 3, 4, 5};
    int arrSize = sizeof(arr)/sizeof(int);
    unique_number3(arr, arrSize);

    return 0;
}