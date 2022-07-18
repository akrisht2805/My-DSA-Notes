//We can use this algorithm on unit waeighted graph or same weighted graph to find the distance 
// It is single source shortest path
 


//return distance from given source to other nodes
 vetor<int> bfs(int n,int src,vector<int> adj[]){
   
   vector<int> dist(n,INT_MAX);
    queue<int> q;

    dist[src]=0;
    q.push(src);
    while(q.empty()==false){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node]+1 < dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }

    }

    return dist;
}





//Find Path from source to dest :----->
                                        // By tracking parent 
vetor<int> bfs(int n,int src,int dest,vector<int> adj[]){
    
    vector<int> parent(n,-1);
    vector<int> vis(n,0);
    queue<int> q;

    q.push(src);
    vis[src]=true;
    parent[src]=-1;

    while(q.empty()==false){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=true;
                parent[it]=node;
                q.push(it);
            }
        }

    }

    //prepare shortest path
    vector<int> ans;
    int currNode = dest;
    ans.push_back(dest)
    while(currNode != src ){
        currNode  = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(),ans.end());
    
    return ans;
}
