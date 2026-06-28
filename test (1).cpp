#include <bits/stdc++.h>
using namespace std;

int BianrySearch(vector<int>&book_ids, int x){
    
    int low=0;
    int high=book_ids.size();
    
    int mid;
    
    while(low<high){
        mid=(low-high)/2;
        
        if(book_ids[mid]==x){
            return 1;
        }
        else if(book_ids[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    
}
int UpperBoundSearch(vector<int>&book_ids, int x){
    
    int low=0;
    int high=book_ids.size();
    
    int mid;
    
    while(low<high){
        mid=(low-high)/2;
        
        if(low==high){
            return low;
        }
        else if(book_ids[mid]<=x){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    
    
int LowerBoundSearch(vector<int>&book_ids, int x){
    
    int low=0;
    int high=book_ids.size();
    
    int mid;
    
    while(low<high){
        mid=(low-high)/2;
        
        if(low==high){
            return low;
        }
        else if(book_ids[mid]>=x){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }   


int main() {
	
	int n,x,flag=0;
	vector<int>book_ids;
	
	cin>>n;
	for(int i=0;i<n;i++){
	    
	    cin>>n;
	    book_ids.push_back(x);
	}
	
	cin>>x;
	
	if(BianrySearch(&book_ids,x)){
	    cout<<"Book found"<<endl;
	    
	    cout<<"Lower Bound index:"<<LowerBoundSearchSearch(&book_ids,x))<<endl;
	    
	    cout<<"Upper Bound index:"<<UpperBoundSearchSearch(&book_ids,x))<<endl;
	    
	}else{
	   cout<<"Book not found"<<endl;
	}
	
	
	
	

}
