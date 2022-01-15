#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int n,int par,int timer,int in[],int low[],int vis[],vector<int> adj[]){
        vis[n]=1;
        in[n]=low[n]=timer++;
        
        for(auto child:adj[n]){
            if(child==par) continue;
            if(vis[child]==1){
                low[n]=min(low[n],in[child]);
            }
            else{
                dfs(child,n,timer,in,low,vis,adj);
                low[n]=min(low[n],low[child]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int in[V],low[V],vis[V]={0};
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,-1,0,in,low,vis,adj);
            }
        }
        if(low[c]>in[d]) return 1;
        if(low[d]>in[c]) return 1;
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
