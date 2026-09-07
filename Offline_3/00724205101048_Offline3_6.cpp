#include<bits/stdc++.h>
using namespace std;

vector<int>arr;

int partition(int low, int high){
    int counting=0;
    int pivot=arr[high];
    int idx=low-1;

    for(int i=low;i<high;i++){
        if(arr[i]<pivot){   
            idx++;
            swap(arr[idx],arr[i]);
            counting++;
            
        }
    }
    swap(arr[idx+1],arr[high]);
    cout<<"Number of elements less than pivot: "<<counting<<endl;
    return idx+1;
}

void quickSort(int low, int high){

    if(low<high){
        int pivot=partition(low,high);
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
 

    
    return 0;
}