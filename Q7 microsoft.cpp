#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    vector<int> cnt(26, 0);
		    queue<char> q;
		    string ans = "";
		    for(char& c : s){
		        cnt[c - 'a']++;
		        if(cnt[c - 'a'] == 1){
		            q.push(c);
		        } 
		        while(!q.empty() && cnt[q.front()-'a'] > 1){
		            q.pop();
		        } 
		        if(q.empty()) ans.push_back('#');
		        else ans.push_back(q.front());
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
