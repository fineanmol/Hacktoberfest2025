
#include <bits/stdc++.h>
using namespace std;
int partition_index(vector<int>& arr, int low, int high) {
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(i<j){
            while(arr[i] <= pivot && i<high){
                i++;
            }
            while(arr[j]>pivot && j> low){
                j--;
            }
            if(i<j)
                swap(arr[i],arr[j]);
        }
        swap(arr[j],arr[low]);
        return j;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if(low>=high)
        return;
        int pIndex= partition_index(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex +1, high);
        
    }
    
int main(){
    
    int n;
    cout<<"Length ";
    cin>>n;
    vector<int> arr(n,0);
    cout<<"Array ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<"Sorted Array :";
        for(auto it:arr){
            cout<<it<<" ";
        }
        cout<<endl; 
        return 0;
    }