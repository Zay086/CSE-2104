#include<bits/stdc++.h>
using namespace std;

void graph(vector<int> vertecies[],int node, int edges){

    for(int i=0;i<edges;i++){

        int nodeA,nodeB;
        cin>>nodeA>>nodeB;

        vertecies[nodeA].push_back(nodeB);
        vertecies[nodeB].push_back(nodeA);
    }
}

void GraphPrint(vector<int> vertecies[],int node){

    for(int i=0;i<node;i++){

        cout<<i<<"->";
        for(int j=0;j<vertecies[i].size();j++){

            cout<<vertecies[i][j]<<" ";
        }
        cout<<endl;
    }
}


void DFS(vector<int> vertecies[],int starting_node,int total_nodes){

    vector<int> visited;
    vector<bool> marked(total_nodes, false);

    stack<int> temp;
    temp.push(starting_node);

    while(!temp.empty()){
        
        int current=temp.top();
        temp.pop();
        visited.push_back(current);
        marked[current]=true;
        for(int i=0;i<vertecies[current].size();i++){

            int neighbour=vertecies[current][i];
            if(!marked[neighbour]){
                temp.push(neighbour);
                marked[neighbour]=true;
            }
        }

    }

    for(int i=0;i<visited.size();i++){
        cout<<visited[i]<<" ";
    }
}

int main(){

    int node,edges;
    cin>>node>>edges;

    vector<int> vertecies[node];
    graph(vertecies,node,edges);

    cout<<"Graph representation: "<<endl;
    GraphPrint(vertecies,node);
    cout<<endl;
    
    cout<<"DFS traversal: "<<endl;
    DFS(vertecies,0,node);

    return 0;


}