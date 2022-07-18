//Shotest Distance in a Weighted DAG:----->


//return distance from source to all nodes
void findTopoSort(int node, vector<int> &vis, stack<int> &st,vector<pair<int,int>> adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        (!vis[it.first]){
            findTopoSort(it.first,vis,ad,adj);
        }
    }
    st.push(node);
}


vetor<int> shortestPath(int src,int n,vector<pair<int,int>> adj[]){
    
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0; i<n;i++){
        (!vis[i]){
            findTopoSort(i,vis,st,adj);
        }
    }

    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    
    while (!st.empty()){
        
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX){
            for(auto it: adj[node]){
                if(dist[node]+it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }

    }
    
    return dist;
}
