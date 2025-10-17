//Accenture Question Asked in 2025 Exam
#include<iostream>
using namespace std;

int main(){
    int n = 3;
    int arr[n] = {2,3,1};
    int sum = 0;

    for(int i=0;i<n;i++){
        int m = max(0,i-arr[i]);
        for(int j= m;j<=i;j++){
            sum+=arr[j];
            cout<<sum<<endl;
        }
    }
    cout<<sum;
}
