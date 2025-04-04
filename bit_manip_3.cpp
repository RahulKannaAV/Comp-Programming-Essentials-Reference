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

int main() {
    int num = 156;
    int second = 256;

    cout << power_of_two(num) << endl; // returns false (0)
    cout << power_of_two(second) << endl; // returns true (1)

    return 0;
}