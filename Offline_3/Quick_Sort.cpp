#include<bits/stdc++.h>
using namespace std;

vector<int>arr;
//Pivot is the first element of the array
int partition(int low, int high){

    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){

        while(arr[i]<=pivot &&i<=high-1){
            i++;
        }

        while(arr[j]>pivot && j>=low+1){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}
//Pivot is the last element of the array

int partition2(int low, int high){

    int pivot=arr[high];
    int idx=low-1;

    for(int i=low;i<high;i++){
        if(arr[i]<pivot){
            idx++;
            swap(arr[idx],arr[i]);
        }
    }
    swap(arr[idx+1],arr[high]);
    return idx+1;
}

void quickSort(int low, int high){

    if(low<high){
        int pivot=partition2(low,high);
        quickSort(low,pivot-1);
        quickSort(pivot+1,high);
    }
}

int main(){

    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++) {
 
        int x;
        cin >> x;
        arr.push_back(x);
 
    }
 
    quickSort(0, n - 1);
 
    cout << "Sorted Array: ";
    for(int x : arr) {
    cout << x << " ";
    }
    
    return 0;
}