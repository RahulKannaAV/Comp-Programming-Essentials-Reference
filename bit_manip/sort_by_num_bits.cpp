#include<bits/stdc++.h>
using namespace std;

int countBits(int num) {
    int cnt = 0;
    
    while(num > 0) {
        num = (num & (num-1));
        cnt++;
    }
    
    return cnt;
}

bool comparator(int a, int b) {
    int bitsA = countBits(a);
    int bitsB = countBits(b);

    if(bitsA == bitsB) {
        return a < b;
    }

    return bitsA < bitsB;
}

vector<int> sortByBits(vector<int> arr) {
    sort(arr.begin(), arr.end(), comparator);

    for(int x: arr) {
        cout << x << endl;
    }
    
    return arr;
}

int main() {
    vector<int> arr = { 658, 433, 518, 322, 685, 688, 258, 767, 480, 216, 88, 315, 520, 186, 818, 506, 963 };

    vector<int> result = sortByBits(arr);

    return 0;
}