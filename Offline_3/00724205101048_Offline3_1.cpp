#include<bits/stdc++.h>
using namespace std;

vector<int>arr;
int counting=0;

int partition(int low, int high){

    int pivot=arr[high];
    int idx=low-1;

    for(int i=low;i<high;i++){
        counting++;
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
 
    cout << "Sorted Array: ";
    for(int x : arr) {
    cout << x << " ";
    }
    cout<<endl;
    cout<<"Number of comparisons: "<<counting<<endl;
    
    return 0;
}