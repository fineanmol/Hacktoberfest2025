#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool canWePlace(int dist, int cows, int n, int arr[]){
    int cntCow = 1, lastCow = arr[0];
    for(int i=0 ;i<n;i++){
        if(arr[i] - lastCow >= dist){
            cntCow++;
            lastCow = arr[i];
        }
        if(cntCow >= cows) return true;
    }
    return false;
}

int aggresiveCow(int arr[], int k, int n){
    sort(arr, arr + n); 
    int low = 1;
    int high = arr[n-1] - arr[0];;
    while(low < high){
        int mid = low + (high - low)/2;
        if(canWePlace(mid, k, n, arr)){
            low = mid+1;
        }      
        else high = mid -1;

    }
    return high;
}
 
int main(){
    int n = 5,k;
    cout << " enter the no of size";
    cin >> n;
    int arr[n];
    cout << "enter the no of cows";
    cin >> k;
    cout<< "\n";
    cout << "enter the no of element ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    
cout << " answwer = "<< aggresiveCow(arr, k, n);

return 0;
}