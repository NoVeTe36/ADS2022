#include<iostream>

using namespace std;

bool co_prime(int a, int b){
    if(a==0 || b==0){
        return false;
    }
    if(a==1 || b==1){
        return true;
    }
    if(a==b){
        return false;
    }
    if(a>b){
        return co_prime(a-b,b);
    }
    return co_prime(a,b-a);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ; i < n; i++){
        cin >> arr[i];
    }
    for(int i=0 ; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "Co-prime numbers are: \n";
    for(int i=0 ; i < n; i++){
        for(int j=i+1 ; j < n; j++){
            if(co_prime(arr[i],arr[j])){
                cout << arr[i] << " and " << arr[j] << endl;
            }
        }
    }
}