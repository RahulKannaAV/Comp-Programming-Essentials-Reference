#include<iostream>
using namespace std;

int* uniqueNumbers(int* numbers, int arrSize) {
    int result_xor = 0;
    // Finding XOR of the whole array
    for(int i=0; i<arrSize; i++) {
        result_xor = result_xor ^ numbers[i];
    }

    int setBitPosition = 0;
    int idx = 0;
    int copyResult = result_xor;

    // From the XOR result, finding the position where the set bit has changed 
    // (in XOR, same bit will be 0, diff bit will be 1). So, finding where it is 1 (differed)
    while(copyResult > 0){
        int lastBit = copyResult&1;

        if(lastBit == 1){
            setBitPosition = idx;
            break;
        }

        copyResult = copyResult >> 1; // Bitwise right shift to check the bit as  0 or 1
        idx++;
    }

    static int resultArray[2]; // Array to store 1st and 2nd unique number
    // 1st unique number: Where the set bit value is 1
    // 2nd Unique number: where the set bit value is 0

    for(int i=0; i<arrSize; i++){ 
        int copyNum = numbers[i] >> setBitPosition; // Getting setBitPosition's bit as the last bit

        // If it is 1, grouping them as unique number 1
        if(copyNum & 1 == 1) {
            resultArray[0] = resultArray[0] ^ numbers[i];
        }
    }

    // Finding 2nd Unique number by XOR of overall XOR and 1st Unique number
    resultArray[1] = result_xor ^ resultArray[0];

    return resultArray;
}

int main() {
    int nums[10] = { 2, 3, 4, 5, 4, 8, 5, 2, 6, 6};
    int size = sizeof(nums)/sizeof(int);
    int *uniqueNos = uniqueNumbers(nums, size);

    cout << "Unique Number 1: " << uniqueNos[0] << endl;
    cout << "Unique Number 2: " << uniqueNos[1] << endl;
    return 0;
}