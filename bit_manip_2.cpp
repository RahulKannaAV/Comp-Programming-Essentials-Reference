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

void clear_i_bits(int &num, int pos) {
    int temp = -1 << pos;

    num = num & temp;
}

int main() {
    // 0 1 0 1 0 1 = 21
    int num = 21, second = 21;
    update_ith_bit(num,0,0);
    cout << num << endl; // Should return 20

    update_ith_bit(second, 1, 1); 
    cout << second << endl; // should return 23

    // 1 1 1 0 1 0 1 =   117
    int n = 117;
    clear_i_bits(n, 3);
    cout << n << endl; // should get 112
}