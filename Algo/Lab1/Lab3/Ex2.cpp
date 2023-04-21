#include<iostream>
#define max_stack_size 100

using namespace std;

struct Stack{
    char data[max_stack_size];
    int top;
};

void init_stack(Stack* s){
    s->top = -1;
}

int isempty(Stack *s){
    if (s->top < 0){
        return 1;
    }
    return 0;
}

int size(Stack *s) {
    return (s -> top + 1);
}

int fullsize(Stack* s) {
    if(s -> top > max_stack_size - 1 ){
        return 1;
    }
    return 0;
}

void push(Stack *s, char n){
    if (fullsize(s) == 1) {
        cout << "Stack is full!\n";
    }
    else{
        s->top++;
        s->data[s->top] = n;
        return;
    }
}

void pop(Stack *s1, Stack *s2, int times){
    if (isempty(s1) == 1 && isempty(s2) == 1){
        cout << "Stack is empty\n";
        return;
    }
    else {
        for (int i = 0; i < times; i++){
            push(s2, s1->data[s1->top]);
            s1->top--;
        }
        return;
    }
}

int length(Stack *s) {
    return (s->top + 1);
}

void display(Stack *s){
    if (isempty(s) == 1){
        cout << "Stack is empty\n";
    }
    if (fullsize(s) == 1) {
        cout << "Stack is full\n";
    }
    else {
        for(int i = 0; i < length(s) ; i++) {
            cout << s->data[i] << " ";
        } 
    }
}

int main(){
    Stack undo, redo;
    init_stack(&undo);
    init_stack(&redo);
    push(&undo, 'a');
    push(&undo, 'b');
    push(&undo, 'c');
    push(&undo, 'd');
    push(&undo, 'e');
    display(&undo);
     cout << "\n";
    pop(&undo, &redo, 2);
    display(&undo);
    cout << "\n";
    display(&redo);
    cout << "\n";
    push(&undo, 'f');
    display(&undo);
    return 0;
}