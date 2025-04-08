#include<iostream>
using namespace std;

bool power_of_two(int num) {
    int result = num & (num - 1);

    if(result) {
        return false;
    } else {
        return true;
    }
}

bool power_of_four(int num) {
    if(num <= 3) {
        return false;
    }

    if(power_of_two(num)) {
        int mask = 21845;
        int res = mask & num;
        if(res == num) {
            return true;
        } else {
            return false;
        }
    } 

    return false;
    
}

int main() {
    int num = 156;
    int second = 256;

    cout << power_of_four(num) << endl; // returns false (0)
    cout << power_of_four(second) << endl; // returns true (1)

    return 0;
}