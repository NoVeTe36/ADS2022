#include <iostream>

using namespace std;

void findMax(int &max, int num) {
    if(num > max) max = num;
}

int main()
{
    int numberOfTests = 0;
    int testVessel = 0;
    int max = testVessel;
    cin >> numberOfTests;
    for(int i = 0; i < numberOfTests; i++) {
        cin >> testVessel;
        findMax(max,testVessel);
    }
    cout << max;

    return 0;
}