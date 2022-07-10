//Cycle Detection in Directed Graph:

//USING DFS: Using visited nodes and visited DFS concept.
	
  bool isDetectCycle(int src,vector<int> &vis,vector<int> &dfsVis,vector<int> adj[]){
        vis[src]=1;
        dfsVis[src]=1;
        for(auto it: adj[src]){
            if(vis[it]==0){
                if(isDetectCycle(it,vis,dfsVis,adj)==true){
                    return true;
                }
            }
            else if(dfsVis[it]==1){
                return true;
            }
        }
        dfsVis[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        
        for(int i=0; i<V; i++){
            if( !vis[i] ){
                if( isDetectCycle(i,vis,dfsVis,adj)==true ){
                    return true;
                }
            }
        }
        return false;
    }
	



//USING BFS: Kahn's Algorithm (if toposort of Directed graph is possible then it is Dirceted Acyclic Graph Other wise it is Directed Cylcic Graph)

    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        int count=0;
        while(!q.empty()){
            int src=q.front();
            q.pop();
            count++;
            for(auto it: adj[src]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(count==V)    return false;
        else return true;
        
    }
