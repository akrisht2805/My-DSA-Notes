// Cycle Detection in UnDirected Graph:

// USING DFS: Doing dfs if there is a node which will trevese privisely so that it will have have cycle . done using parent if node;
	
    bool isDfsCycle(int src,int parent,vector<int> &vis,vector<int> adj[]){
        vis[src]=1;
        for(auto it: adj[src]){
            if(!vis[it]){
                if(isDfsCycle(it,src,vis,adj)==true){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    	}
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isDfsCycle(i,-1,vis,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }	


// USING BFS:
	bool isBfsCycle(int node,vector<int> &vis,vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({node,-1});
        
        while(!q.empty()){
            pair<int,int> f=q.front();
            q.pop();
            vis[f.first]=1;
            for(auto it: adj[f.first]){
                if(!vis[it]){
                    q.push({it,f.first});
                    vis[it]=1;
                }
                else if(it!=f.second){
                    return true;
                }
            }
        }
        return false;    
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isBfsCycle(i,vis,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }
