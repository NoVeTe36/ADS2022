#include <iostream>

using namespace std;

struct _List{
    int data[20];
    int front, back;
};
typedef struct _List List;

void init (List *l){
    l->front = 0;
    l->back = 0;
}

int isEmpty(List *l){
    return (l->back == 0);
} 

int length(List *l){
    int i = l->back - l->front;
    return i;
}

void display (List *l){
    for (int i=1; i<length(l)+1; i++){
        cout << l->data[i] << " ";
    }
}

void add(List *l, int val){
    if (length(l) == 20){
        cout << "Maxed!";
    }
    if (isEmpty(l)){
        l->data[0]=val;
    }
    else{
        int idx = l->back;
        l->data[idx] = val;
    }
    l->back++;
}

void sort(List *l){
    int first = l->front ;
    int last = l->back;
    int temporary;
    int swapped = 1;
    while(swapped =1){
        swapped = 0;
        for(int i = first ; i < last; i++){
            if(l->data[i] > l->data[i+1]){
                temporary = l->data[i];
                l->data[i] = l->data[i + 1];
                l->data[i + 1] = temporary;
                swapped = 1;
            }
        }
        if(swapped == 0){ 
            break;
        }
        last--;
        swapped = 0;
        for(int i = last  ; i > first ; i--){
            if(l->data[i] < l->data[i-1]){
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
    init(&l);
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i=0; i<n; i++){
        int x;
        cout << "Enter element " << i+1 << ": ";
        cin >> x;
        add(&l, x);
    }
    sort(&l);
    cout << "Sorted list: ";
    display(&l);
}