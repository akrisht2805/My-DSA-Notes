//****************************DFS Treversal**************************************//

void dfs(int src,vector<int> &vis,vector<int> adjList[],vector<int> &ans){
    ans.push_back(src);
    vis[src]=true;
    for(auto it: adjList[src]){
        if(!vis[it]){
            dfs(it,vis,adjList,ans);
        }
    }
}

vector<int> bfsOfGraph(int V, vector<int> adjList[]) {

    vector<int> vis(V,0);
    vector<int> ans;
    for(int i=0;i<V;i++){       //For the graph disconnected component
        if(!vis[i]){
            dfs(i,vis,adjList,ans);
        }
    }
    return ans;
    	
}