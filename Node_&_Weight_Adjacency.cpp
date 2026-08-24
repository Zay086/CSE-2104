#include<bits/stdc++.h>
using namespace std;

vector<int>V[11];
vector<int>W[11];

int main(){

    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){

        int nodeA,nodeB,cost;
        cin>>nodeA>>nodeB>>cost;
        V[nodeA].push_back(nodeB);//Node Adjacency Input
        V[nodeB].push_back(nodeA);
        W[nodeA].push_back(cost);//Weight Adjacency input
        W[nodeB].push_back(cost);
    }

    cout<<"Node Adjacency List"<<endl;

    for(int i=1;i<=n;i++){

        cout<<i<<" -> ";
        for(int j=0;j<V[i].size();j++){

            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"Weight Adjacency List"<<endl;

    for(int i=1;i<=n;i++){

        cout<<i<<" -> ";
        for(int j=0;j<W[i].size();j++){

            cout<<W[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"Node Adjacency List with Weight"<<endl;

    for(int i=1;i<=n;i++){

        cout<<i<<" -> ";
        for(int j=0;j<V[i].size();j++){

            cout<<V[i][j]<<" ("<<W[i][j]<<") ";
        }
        cout<<endl;
    }

    return 0;

}

/* Input 
10 13
1 2 20
1 3 67
1 4 23
4 7 12
7 3 10
3 8 1
7 9 8
7 8 5
8 5 22
9 10 911
5 10 18
10 6 18
2 6 86
*/

/*
Node Adjacency List
1 -> 2 3 4 
2 -> 1 6 
3 -> 1 7 8 
4 -> 1 7 
5 -> 8 10 
6 -> 10 2 
7 -> 4 3 9 8 
8 -> 3 7 5 
9 -> 7 10 
10 -> 9 5 6 

Weight Adjacency List
1 -> 20 67 23 
2 -> 20 86 
3 -> 67 10 1 
4 -> 23 12 
5 -> 22 18 
6 -> 18 86 
7 -> 12 10 8 5 
8 -> 1 5 22 
9 -> 8 911 
10 -> 911 18 18 

Node Adjacency List with Weight
1 -> 2 (20) 3 (67) 4 (23) 
2 -> 1 (20) 6 (86) 
3 -> 1 (67) 7 (10) 8 (1) 
4 -> 1 (23) 7 (12) 
5 -> 8 (22) 10 (18) 
6 -> 10 (18) 2 (86) 
7 -> 4 (12) 3 (10) 9 (8) 8 (5) 
8 -> 3 (1) 7 (5) 5 (22) 
9 -> 7 (8) 10 (911) 
10 -> 9 (911) 5 (18) 6 (18) 
*/
