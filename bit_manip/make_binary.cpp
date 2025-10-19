#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log N) where N: Number of bits in binary format
int makeItBinary(int num) {
    int powerVal = 0;
    int inBinary = 0;

    while(num > 0) {
        int lastBit = num&1;
        inBinary += lastBit * pow(10, powerVal);
        powerVal++;
        num = num >> 1;
    }

    return inBinary;
}

int main() {
    cout << makeItBinary(16); // 1001
}