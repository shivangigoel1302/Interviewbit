bool iscycle(int i,vector<bool>&visited,vector<bool>&recstack,vector<int>adj[]){
	    visited[i] = true;
	    recstack[i] = true;
	    for(auto nbr: adj[i]){
	        if(recstack[nbr]){
	            return true;
	        }
	        if(!visited[nbr]){
	            if(iscycle(nbr,visited,recstack,adj)){
	                return true;
	            }
	        }
	    }
	    recstack[i] = false;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[])
	{
	   	// code here
	   	vector<bool>visited(V,false);
	   	vector<bool>recstack(V,false);
	   	for(int i = 0; i < V; i++){
	   	    if(!visited[i]){
	   	        if(iscycle(i,visited,recstack,adj)){
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
