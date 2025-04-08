#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first) {
    vector<int> array = {first};
    
    for(int i=0; i<encoded.size(); i++){
        int nextArrayValue = array[i] ^ encoded[i];
        array.push_back(nextArrayValue);
    }
    
    return array;
}

int main() {
    vector<int> encoded = {1, 2, 3};
    // here, encoded[i] = arr[i] ^ arr[i+1]
    // we have to find arr[i+1], therefore taking arr[i] XOR on both sides
    // encoded[i] ^ arr[i] = arr[i] ^ arr[i] ^ arr[i+1]
    // here, arr[i] ^ arr[i] = 0 and 0 ^ a = a
    // therefore, arr[i+1] = encoded[i] ^ arr[i]
    int first = 1;

    vector<int> result = decode(encoded, first);

    for(auto x: result) {
        cout << x << " ";
    }// 1 0 2 1 printed successfully
}