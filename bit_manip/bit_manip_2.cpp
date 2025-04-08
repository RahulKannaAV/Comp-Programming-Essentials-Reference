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

void replace_bits(int &m, int n, int i, int j) {
    clear_range_bits(m, i, j); // Step 1
    int mask = n << i; // Step 2

    m = m | mask; // Step 3
}

int main() {       //   j     i
    int num = 127; // 1 1 1 1 1 1 1 
    int n = 9;
    int i = 2, j = 5;

    replace_bits(num, n, i, j);
    cout << num << endl; // Should return 103
}