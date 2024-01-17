#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 26

//スタック構造体
typedef struct {
    char items[STACK_SIZE];
    int top;
} Stack;

//スタックの初期化
void initializeStack(Stack* stack) {
    stack->top = -1;
}

//スタックが空かどうかをチェック
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

//スタックが満杯かどうかをチェック
int isFull(Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

//スタックに要素をプッシュ
void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack is full.\n");
    } else {
        stack->items[++stack->top] = item;
        //プッシュした文字とスタックを出力
        printf("Push: %c | Stack: ", item);
        for (int i = 0; i <= stack->top; i++) {
            printf("%c ", stack->items[i]);
        }
        printf("\n");
    }
}

// スタックから要素をポップ
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return '\0';
    } else {
        char popped = stack->items[stack->top--];
        //ポップした文字とスタックを出力
        printf("Pop: %c | Stack: ", popped);
        for (int i = 0; i <= stack->top; i++) {
            printf("%c ", stack->items[i]);
        }
        printf("\n");
        return popped;
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    srand((unsigned int)time(NULL));

    //AからZまでの文字をランダムな順番でプッシュ
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        push(&stack, ch);
    }

    //スタックが空になるまでポップ
    while (!isEmpty(&stack)) {
        pop(&stack);
    }

    return 0;
}