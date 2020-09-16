#include<bits/stdc++.h>
#include<iterator>

using namespace std;
//depth first search of a given undirected graph
//the below dfs implementation will work fine only with graph (having n nodes) which have indices of nodes as 0,1...n-1
void dfstill(int u, vector<bool>& visited,vector<vector<int> >& adj, stack<int>& st, vector<int>& out){
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!visited[v]){
            //cout<<v<<endl;
            visited[v]=true;
            st.push(v);
            out.push_back(v);
            dfstill(v,visited,adj,st,out);
        }
    }
}
vector<int> dfs(vector<vector<int> >& adj,int n, int s){
//s is the index of starting vertex, n is number of nodes
    vector<int> out;
    stack<int> st;
    vector<bool> visited(n, false);
    st.push(s);
    visited[s]= true;
    out.push_back(s);
    while(!st.empty()){
        int u = st.top();
        //cout<<u<<endl;
        dfstill(u,visited,adj,st,out);
        st.pop();
    }
    return out;
}

int main(){
    int t;
    cout<<"enter the number of test cases"<<endl;
    cin>>t;
    while(t--){
        int n,m;
        //n=nodes, m=edges
        cout<<"enter the number of nodes"<<endl;
        cin>>n;
        cout<<"enter the number of edges"<<endl;
        cin>>m;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int x,y;
            cout<<"enter the indices of starting and ending node of an edge"<<endl;
            cin>>x>>y; 
            adj[x].push_back(y);
            //if you want to work with directed graph then comment the below line
            adj[y].push_back(x);
        }
        //-----to print the adjacency list-----------
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<"enter the index of the node from where you want to run dfs"<<endl;
        vector<int> out;
        int s;
        cin>>s;
        out = dfs(adj,n,s);
        cout<<"dfs with starting index "<<s<<"is"<<endl;
        for(int i=0;i<out.size();i++){
            cout<<out[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}