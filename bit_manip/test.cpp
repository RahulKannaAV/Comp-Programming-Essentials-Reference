#include<iostream>
using namespace std;

void clearIthBit(int &n, int pos) {
    int mask = ~(1 << pos);
    n = n&mask;
}

void setIthBit(int &n, int pos) {
    int mask = 1<<pos;

    n = n | mask;
}

void updateIthBit(int &n, int pos, int val) {
    if(val == 0) {
        int clearMask = ~(1 << pos);
        n = n&clearMask;

    } else if(val == 1) {
        int setMask = 1 << pos;
        n = n|setMask;
    }
}

void clearLastIBits(int &n, int count) {
    int mask = (~0)<<count;

    n = n&mask;
}

void clearBitRanges(int &n, int i, int j){
    int mask1 = (1<<(i)) - 1;
    int mask2 = ~(1<<(j));

    int full_mask = mask1 | mask2;

    n = n & full_mask;

}

// Time Complexity: O(log N) 
// Eg: 64: 2^6 (atmost 7 bits)
int countBits(int num){
    int count = 0;

    while(num > 0) {
        count += (num&1); // Taking the last bit (if 1, increment)
        num = num>>1; // Leftshifting: 16->8->4->2
    }

    return count;
}

int countBitsHack(int n) {
    int cnt = 0;

    while(n > 0) {
        n = (n & (n-1));
        cnt++;
    }

    return cnt;
}

int main() {
    

    cout << countBits(14) << endl; // 4
    cout << countBitsHack(14) << endl; // 4
}