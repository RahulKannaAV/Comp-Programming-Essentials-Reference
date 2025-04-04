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

void clear_range_bits(int &num, int i, int j) {
    int a = -1 << (j+1); // otherwise, (~0) << (j+1)
    int b = (1 << i) - 1;

    int mask = a | b;

    num = num & mask; 
}

int main() {       //   j     i
    int num = 127; // 1 1 1 1 1 1 1 
    int i = 2, j = 5;

    clear_range_bits(num, i, j);

    cout << num << endl; // Should return 67
}