//TOPOLOGICAL SORT: It is ordering of vertex where if U->V is an edge so U occur before then V;
	
//USING DFS:
	void findTopo(int node,vector<int> &vis, stack<int> &st,vector<int> adj[]){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            findTopo(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            findTopo(i,vis,st,adj);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}



//USING BFS:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
  
  
