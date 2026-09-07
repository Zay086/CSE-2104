#include<bits/stdc++.h>
using namespace std;

vector<int>arr;

void Merge(int low,int mid, int high){

    vector<int>temp;
    int i=low;
    int j=mid+1;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=low;k<=high;k++){
        arr[k]=temp[k-low];

    }

}

void MergeSort(int low, int high){

    if(low<high){
        int mid=low+(high-low)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }
}

int main(){

    int n,m;
    cin >> n;
 
    for(int i = 0; i < n; i++) {
 
        int x;
        cin >> x;
        arr.push_back(x);
 
    }
    cin>>m;

    for(int j=0;j<m;j++){
        int y;
        cin>>y;
        arr.push_back(y);
    }
    MergeSort(0, n + m - 1);

    cout << "Sorted Array: ";
    for(int x : arr) {
    cout << x << " ";
    }
    cout<<endl;
    cout<<"Median: "<<arr[(n + m - 1)/2]<<endl;
    
    return 0;
}