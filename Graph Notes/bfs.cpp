//****************************BFS Treversal**************************************//

void bfs(int src,vector<int> &vis,vector<int> adjList[],,vector<int> &ans){
    
    queue<int> q;
    q.push(src);
    vis[src]=true;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto it: adjList[node]){
            if(!vis[i]){
                q.push(i);
                visited[i]=true;
            }
        }

    }
}

vector<int> bfsOfGraph(int V, vector<int> adjList[]) {

    vector<int> vis(V,0);
    vector<int> ans;
    for(int i=0;i<V;i++){       //For the graph disconnected component
        if(!vis[i]){
            bfs(i,vis,adjList,ans);
        }
    }
    return ans;
    	
}