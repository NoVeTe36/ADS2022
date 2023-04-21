/* Pseudocode:
    Function num_even (input: n, count_even)
        if n = 0
            return false
        else 
        if (n%10) % 2 = 0
            count_even++ 
        return num_even(n/10, count_even)

    Function num_odd (input: n, count_odd)
        if n = 0
            return false
        else 
        if (n%10) % 2 = 1
            count_odd ++
        return num_odd(n/10, count_odd)

    Main function: 
        Input n
        count_even <- 0
        count_odd <- 0
        num_even(n, count_even)
        num_odd(n, count_odd)
        Output: count_odd, count_even
*/

#include <bits/stdc++.h>
using namespace std;

int num_even (int n, int &count_even){
    if (n == 0){
        return 0;
    } else {
        if ((n%10) % 2 == 0){
            count_even++;
        } 
        return num_even(n/10, count_even);
    }
} /*    Time complexity: function is end when n / 10^m = 1, with m is number of loops
        => n = 10^m => m = log n 
        Best case: Omega(log n)
        Avarage: Theta(log n)
        Worst case: O(log n)
*/
int num_odd (int n, int &count_odd){
    if (n == 0){
        return 0;
    } else {
        if ((n%10) % 2 == 1){
            count_odd++;
        } 
        return num_odd(n/10, count_odd);
    }
}/*    Time complexity: function is end when n / 10^m = 1, with m is number of loops
        => n = 10^m => m = log n 
        Best case: Omega(log n)
        Avarage: Theta(log n)
        Worst case: O(log n)
*/

int main(){
    int n;
    cin >> n;
    int count_even = 0, count_odd = 0;
    num_even(n, count_even);
    num_odd(n, count_odd);
    cout << "Number of odd digits is " << count_odd << endl;
    cout << "Number of even digits is " << count_even;
}