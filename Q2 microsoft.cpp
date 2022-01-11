#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool checkCycle(int n, vector<int>adj[], int status[])
    {
        status[n] = 1;
        for(auto i:adj[n])
        {
            // cout<<i<<' '<<n<<' '<<status[i]<<endl;
            if(status[i] == 1)
                return true;
            if(status[i] == 0 && checkCycle(i, adj, status))
                return true;
        }
        status[n] = 2;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N];
	    for(auto p:prerequisites)
	    {
	        adj[p.second].push_back(p.first);
	    }
	   // for(int i=0; i<N; ++i)
	   // {
	   //     cout<<i<<':';
	   //     for(auto j:adj[i])
	   //         cout<<j<<' ';
	   //     cout<<endl;
	   // }
	    int status[N];
	    for(int i=0; i<N; ++i)
	        status[i] = 0;
	    for(int i=0; i<N; ++i)
	    {
	        if(status[i] == 0 && checkCycle(i, adj, status))
	            return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
