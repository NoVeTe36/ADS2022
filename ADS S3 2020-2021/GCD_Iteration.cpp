#include<iostream>

using namespace std;

int min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int count = 0;
            for(int k = 2; k <= min(arr[i], arr[j]); k++){
                if(arr[i] % k == 0 && arr[j] % k == 0){
                    count++;
                }
            }
            if (count == 0){
                cout << arr[i] << "," << arr[j] << endl;
            }
        }
    }
    return 0;
}