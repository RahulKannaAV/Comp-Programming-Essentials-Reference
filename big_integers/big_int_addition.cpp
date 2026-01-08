#include<iostream>
#include<string.h>
using namespace std;

void big_int_addition(string num1, string num2) {
    string result = "";
    int carry = 0;


    for(int i=0; i<num2.length(); i++) {
        if(i >= num1.length()) {
            int revIdx = num2.length() - i - 1;
            int digitAddition = num2[revIdx] + carry - 48;
            int nextDigitInt = digitAddition % 10;
            carry = digitAddition/10;

            string nextDigit = to_string(nextDigitInt);
            result.append(nextDigit);
        } else {
            int num2_revIdx = num2.length() - i - 1;
            int num1_revIdx = num1.length() - i - 1;

            int digitNum1 = num1[num1_revIdx] - 48;
            int digitNum2 = num2[num2_revIdx] - 48;

            int digitSums = digitNum1 + digitNum2 + carry;
            int nextDigitInt = digitSums % 10;
            carry = digitSums / 10;

            string nxtDigit = to_string(nextDigitInt);
            result.append(nxtDigit);

        }
    }

    for(int j=result.length()-1; j>=0; j--) {
        cout << result[j];
    }
    cout << endl;
}

int main() {
    // bigger number at num2
    // smaller number at num1
    string a = "3333311111111111";
    string b = "44422222221111";

    //CARRY: 0 1 1 0
    //       4 2 3 1
    //       6 7
    //       +
    //       0 0 4 1

    if(a.length() > b.length()) {
        string temp = b;
        b = a;
        a = temp;
        cout << "Swapped" << endl;
    }

    big_int_addition(a, b);
    
    return 0;
}