#include <stdio.h>

void decimaltobinary(int num, int bit, int *arr){
    int magnitude;
    // Get only the magnitude, Don't care about the positive or negative number
    if(num<0){
        magnitude = -num;
    }else{
        magnitude = num;
    }
    // change to binary
    for(int i =0 ; i < bit; i++){
        arr[i] = magnitude % 2 ;
        magnitude = magnitude / 2;
    }
}

void firstcomplement(int *arr, int bit){
    // exclude the sign bit , we flip all the bit
    for(int i =0; i< bit - 1; i++){
        if(arr[i] == 0){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }
}

void secondcomplement(int *arr, int bit){
    int carry = 1; // In the second comlement , we need to +1 least significant bit
    for(int i =0 ; i < bit ; i++){
        int sum;
        sum = arr[i]+ carry;
        arr[i] = sum % 2;
        carry = sum / 2;
    }
}

void printBinary(int *arr, int bit) {
    // print array in reverse order
    for (int i = bit - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int num,bit;
    printf("Enter bit: ");
    scanf("%d", &bit);
    int maxrange, minrange;
    // use bit count to calculate max and min range but we have 0 so, max range has to -1
    maxrange = (1 <<(bit - 1)) - 1;
    minrange = -(1<< (bit -1));

    printf("The range is between %d and %d : ", maxrange, minrange);
    scanf("%d", &num);
    // if it not in the range between max amd min, it out of range
    if (num > maxrange || num < minrange){
        printf("Error, number can't be out of range");
    }
    // set arr = 0
    int binary[bit];
    for(int i = 0 ; i < bit; i++){
        binary[i] = 0;
    }
    // if it negative number , sign bit =1
    if(num < 0){
        binary[bit-1] = 1 ;
    }
    // Change decimal number to binary number
    decimaltobinary(num, bit-1, binary);
    printf("Sign and Magnitude:\t");
    printBinary(binary, bit);
    // Change to 1's Complement
    if(num < 0){
        firstcomplement(binary, bit);
    }
    printf("First complement:\t");
    printBinary(binary, bit);
    //change to 2's complement
    if(num < 0){
        secondcomplement(binary, bit);
    }
    printf("Second complement:\t");
    printBinary(binary,bit);
    return 0;
}