/* Pseudocode:
    Function num_even_odd (input: n, count_even, count_odd)
        if n = 0
            return false
        else 
        if (n%10) % 2 = 0
            count_even++ 
        else 
            count_odd++
        return num_even_odd(n/10, count_even, count_odd)

    Main function: 
        Input n
        count_even <- 0
        count_odd <- 0
        num_even_odd(n, count_even, count_odd)
        Output: count_odd, count_even
*/

#include <bits/stdc++.h>
using namespace std;

int num_even_odd (int n, int &count_even, int &count_odd){
    if (n == 0){
        return 0;
    } else {
        if ((n%10) % 2 == 0){
            count_even++;
        } else {
            count_odd++;
        }
        return num_even_odd(n/10, count_even, count_odd);
    }
} /*    Time complexity: function is end when n / 10^m = 1, with m is number of loops
        => n = 10^m => m = log n 
        Best case: Omega(log n)
        Avarage: Theta(log n)
        Worst case: O(log n)
*/

int main(){
    int n;
    cin >> n;
    int count_even = 0, count_odd = 0;
    num_even_odd(n, count_even, count_odd);
    cout << "Number of odd digits is " << count_odd << endl;
    cout << "Number of even digits is " << count_even;
}