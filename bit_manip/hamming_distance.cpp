#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y){
    int hDist = 0;
    while(x > 0 && y > 0){
        int lastBitX = x&1;
        int lastBitY = y&1;

        if(lastBitX != lastBitY) {
            hDist++;
        }

        x = x>>1;
        y = y>>1;
    }

    if(x == 0) {
        while(y > 0) {
            if(y&1 == 1) {
                hDist++;
            }
            y = y >> 1;
        }
    }

    if(y == 0) {
        while(x > 0){
            if(x&1 == 1) {
                hDist++;
            }
            x = x >> 1;
        }
    }

    cout << x << " " << y << endl;

    return hDist;
}

int main() {
    cout << hammingDistance(15, 15);
    return 0;
}