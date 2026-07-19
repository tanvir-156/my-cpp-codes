#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void print() {
    if (top == -1) {
        printf("Error: Stack Empty.\n");
        return;
    }
    for(int i=0; i<=top; i++)
    {
        printf("%d", stack[i]);
    }
    printf("\n");
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Error: Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Error: Stack Underflow\n");
        return -1;
    } else {
        int poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

int main() {
    int dec, del;
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
        while(dec!=0) {
            push(dec%2);
            dec/=2;
        }
        printf("Binary: ");
        while (1)
        {
            del=pop();
            printf("%d",del);
            if (top==-1){
                break;
            }
        }
    return 0;
}
