#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> v(26,0);
		    queue<char> q;
		    string ans = "";
		    
		    for(int i=0;i<A.size();i++){
		        int index = A[i] - 'a';
		        
		        if(v[index] == 0){
		            q.push(A[i]);
		        }
		        
		        v[index]++;
		        
		        while(!q.empty()){
		            int ind = q.front() - 'a';
		            
		            if(v[ind] > 1){
		                q.pop();
		            }
		            else{
		                ans+=q.front();  
		                break;
		            }
		        }
		        
		        if(q.empty()){
		            ans+='#';
		        }
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
