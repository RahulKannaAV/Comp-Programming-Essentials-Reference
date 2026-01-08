#include<iostream>
#include<string.h>
using namespace std;

void big_int_addition(string num1, string num2) {
    string result = "";
    int carry = 0;


    for(int i=0; i<num2.length(); i++) {
        if(i >= num1.length()) {
            int revIdx = num2.length() - i - 1; // Going in reverse order

            int digitAddition = num2[revIdx] + carry - 48;
            int nextDigitInt = digitAddition % 10; // Taking only the last digit to add in the result. Remaining to the carry
            carry = digitAddition/10;

            string nextDigit = to_string(nextDigitInt);
            result.append(nextDigit);
        } else {
            int num2_revIdx = num2.length() - i - 1; // Going in reverse order
            int num1_revIdx = num1.length() - i - 1;

            int digitNum1 = num1[num1_revIdx] - 48; // ASCII Char to digit
            int digitNum2 = num2[num2_revIdx] - 48;

            int digitSums = digitNum1 + digitNum2 + carry;
            int nextDigitInt = digitSums % 10; // Taking the last digit for result
            carry = digitSums / 10; // Remaining as carry

            string nxtDigit = to_string(nextDigitInt);
            result.append(nxtDigit);

        }
    }

    if(carry == 1) {
        result.push_back('1'); // At the end, if there's a value in carry other than 0 (i.e 1), add it in the result
    }

    for(int j=result.length()-1; j>=0; j--) { // Since, the result will be in reverse order, printing it in our desired order
        cout << result[j];
    }
    cout << endl;
}

int main() {
    // bigger number at num2
    // smaller number at num1
    string a = "99";
    string b = "1";

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