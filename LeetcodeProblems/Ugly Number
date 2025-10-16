
// An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.


#include<bits/stdc++.h>
using namespace std;

bool isUgly(int n) {
        while(n>1){
            if(n%2==0){
                n=n/2;
            }
            else if(n%3==0){
                n=n/3;
            }
            else if(n%5==0){
                n=n/5;
            }
            else
            return false;
        }

        if(n==1)
        return true;

        return false;
    }



int main() {
    int n;
    cin >> n;

    bool Ugly = isUgly(n);

    cout << "The entered number is " << (Ugly ? "Ugly." : "Not Ugly.") << endl;

    return 0;
}