//Check Bipartite Graph: That can be colored using two colors such that no adjacent nodes have same color.
	
//USING DFS:
	bool checkBipartiteUsingDFS(int node,vector<int> &color,vector<int> adj[]){
        if(color[node]==-1)   color[node]=1;
        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(checkBipartiteUsingDFS(it,color,adj)==false){
                    return false;
                }
            }else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    	}

	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(checkBipartiteUsingDFS(i,color,adj)==false){
	                return false;
	            }
	        }
	    }
	    
	    return true;    
	}


//USING BFS:
	bool checkBipartiteUsingBFS(int src,vector<int> &color,vector<int> adj[]){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    	}

	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(checkBipartiteUsingBFS(i,color,adj)==false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	    
	}
