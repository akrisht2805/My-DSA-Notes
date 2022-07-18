/*
	TC O(V+E)*logV
	PC O(V)
	Implementations wise its like BFS ( instead of queue we use priority queue)
	0-Is there are negetive edges but not in a cycle then we an use this algo
	1-If there are negetive edges in a cycle we cant use this also for this we use bellman ford
	2-It there are negetive weight cycles then we cant use bellman ford too, we 
	can just detect negetive weight cycles using bellman ford
*/


vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  //min heap in pair
        vector<int> distTo(V,INT_MAX);
        
        distTo[S]=0;
        pq.push({0,S}); //{distance ,from}
        
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();
            int dist = top.first;
            int prev = top.second;
            
            for(auto &it: adj[node]){
                int next = it.first;
                int nextDist = it.second;
                if(distTo[next] > dist + nextDist){
                  distTo[next] = distTo[prev] + nextDist;
                  pq.push({distTo[next], next});
                }
            }
            
        }
        
        return distTo;
    }
