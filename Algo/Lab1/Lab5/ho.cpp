#include <iostream>
#include <stdlib.h>

using namespace std;

struct _List{
    int data[20];
    _List* front,* back;
};
typedef struct _List List;

void init(List &l){
    l.front = l.back = NULL;
}

int isEmpty(List *l){
    return (l->back == 0);
} 

int length(List *l){
    int i = l->back - l->front;
    return i;
}

void display (List *l){
    for (int i=0; i<length(l); i++){
        cout << l->data[i] << " ";
    }
}

void insert(int x, List *l){
    if (l->back == 0){
        l->data[0] = x;
        l->back = l->front = NULL;
    } else {
        l->data[l->back] = x;
        l->back ++;
    }
}

void sort(List *l){
    int first = 0;
    int last = length(l);
    int temporary;
    int swapped = 1;
    while(swapped =1){
        swapped = 0;
        for(int i = first; i < last; i++){
            if(l->data[i -1] > l->data[i]){
                temporary = l->data[i];
                l->data[i] = l->data[i - 1];
                l->data[i - 1] = temporary;
                swapped = 1;
            }
        }
        if(swapped == 0){ 
            break;
        }
        last--;
        swapped = 0;
        for(int i = last +1 ; i >= first -1; i--){
            if(l->data[i - 1] > l->data[i]){
                temporary = l->data[i];
                l->data[i] = l->data[i - 1];
                l->data[i - 1] = temporary;
                swapped = 1;
            }
        }
        first ++;
    }
}

int main(){
    List l;
    init(l);
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        insert(x, &l);
    }
    sort(&l);
    display(&l);
    return 0;
}