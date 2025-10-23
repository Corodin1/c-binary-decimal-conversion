#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isBinary(long long num) {
    while (num > 0) {
        if (num % 10 > 1)
            return 0;
        num /= 10;
    }
    return 1;
}

long long binaryToDecimal(long long binary) {
    long long decimal = 0;
    int i = 0;
    
    while (binary != 0) {
        int digit = binary % 10;
        decimal += digit * pow(2, i);
        binary /= 10;
        i++;
    }
    return decimal;
}

long long decimalToBinary(long long decimal) {
    long long binary = 0;
    long long i = 1;
    
    while (decimal != 0) {
        binary += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }
    return binary;
}

int main() {
    int choice;
    long long input, output;
    
    printf("Choose conversion type:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a binary number: ");
            scanf("%lld", &input);
            if (!isBinary(input)) {
                printf("Error: Not a valid binary number!\n");
                return 1;
            }
            output = binaryToDecimal(input);
            printf("Decimal equivalent: %lld\n", output);
            break;
        
        case 2:
            printf("Enter a decimal number: ");
            scanf("%lld", &input);
            output = decimalToBinary(input);
            printf("Binary equivalent: %lld\n", output);
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

