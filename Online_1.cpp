#include<bits/stdc++.h>
using namespace std;

vector<int>book;

int UpperBoundSearch(int n){

    int low=0;
    int high=book.size()-1;
    int mid,ans;
    while(low<=high){

        mid=(low+high)/2;

        if(book[mid]>n){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;


}

int main(){

    int year,t,x;
    cin>>year>>t;
    for(int i=0;i<year;i++){
        cin>>x;
        book.push_back(x);

    }

    vector <int> Search;
    for(int i=0;i<t;i++){
        cin>>x;
        Search.push_back(x);
    }

    for(int i=0;i<t;i++){
        int flag=UpperBoundSearch(Search[i]);

        if(flag>=year){
            cout<<"-1"<<endl;
        }
        else{
            cout<<flag<<endl;
        }

    }






}
