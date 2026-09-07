#include<bits/stdc++.h>
using namespace std;

vector<int>arr;
int counting=0;

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
            counting++;
            swap(arr[i],arr[j]);
        }
    }
    if(low!=j){
    swap(arr[j],arr[low]);
    counting++;
    }

    return j;
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
    cout<<"Number of swaps required: "<<counting<<endl;
    
    return 0;
}