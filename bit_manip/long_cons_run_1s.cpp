#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int cons=0;
    int tempCons=0;
    
    while(n > 0) {
        int lastBit = n&1;
        if(lastBit == 1) {
            tempCons++;
        } else {
            cons = max(cons, tempCons);
            tempCons = 0;
        }
        
        n = n >> 1;
    }
    
    cons = max(cons, tempCons);
    return cons;
}

int main() {
    cout << solve(15);
    return 0;
}