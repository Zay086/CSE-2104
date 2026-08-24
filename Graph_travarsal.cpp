#include<bits/stdc++.h>
using namespace std;

vector<int>V[11];

int main(){

    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){

        int nodeA,nodeB;
        cin>>nodeA>>nodeB;
        V[nodeA].push_back(nodeB);
        V[nodeB].push_back(nodeA);
    }

    for(int i=1;i<=n;i++){

        cout<<i<<" -> ";
        for(int j=0;j<V[i].size();j++){

            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}

/*
10 13
1 2
1 3
1 4
4 7
7 3
3 8
7 9
7 8
8 5
9 10
5 10
10 6
2 6
*/