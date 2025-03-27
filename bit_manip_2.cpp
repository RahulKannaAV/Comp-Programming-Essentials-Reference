#include<iostream>
using namespace std;

void update_ith_bit(int &num, int pos, int bitValue) {
    int temp = ~(1 << pos);

    int clearedBit = num & temp;

    int setTemp = 0;
    if(bitValue == 1) {
        setTemp = 1 << pos;
    } 
    num = clearedBit | setTemp;
}

int main() {
    // 0 1 0 1 0 1 = 21
    int num = 21, second = 21;
    update_ith_bit(num,0,0);
    cout << num << endl; // Should return 20

    update_ith_bit(second, 1, 1); 
    cout << second << endl; // should return 23
}