#include<iostream>
using namespace std;

int get_ith_bit(int num, int pos) {
    int temp = 1 << pos;

    int result = num&temp;
    if(result > 0) {
        return 1;
    } else {
        return 0;
    }
}

void clear_ith_bit(int &num, int pos) {
    int temp = ~(1 << pos);

    num = num & temp;
}

void set_ith_bit(int &num, int pos) {
    int temp = 1 << pos;

    num = num | temp;
}

int main() {
    int num = 10;
    cout << "Original Number : " << num << endl;
    set_ith_bit(num, 0);

    cout << "It returned " << num << endl; // It should return 11

    return 0;
}