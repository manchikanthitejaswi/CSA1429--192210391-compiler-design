#include <stdio.h>

void generateCode(char operation, char operand1, char operand2, char result) {
    printf("%c %c, %c, %c\n", operation, result, operand1, operand2);
}

int main() {
    char op1 = 'a';
    char op2 = 'b';
    char result = 't';

    // Example: a = b + c
    generateCode('+', op1, op2, result);

    return 0;
}
