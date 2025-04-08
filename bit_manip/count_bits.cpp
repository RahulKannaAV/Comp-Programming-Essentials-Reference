#include<bits/stdc++.h>
using namespace std;

int count_bits(int n) {
    int count = 0;

    while(n > 0) {
        count += (n&1);
        n = n>>1;
    }

    return count;
}

int main() {
    int num = 10;
    int bits = count_bits(num);

    cout << bits; // should return 2
}