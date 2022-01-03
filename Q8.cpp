#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int md = 1e9 + 7;
	public:
	
		int CountWays(string s){
		    int n =s.size();
            vector<int> dp(n+1,0);
            dp[0]=1;
            if(s[0] != '0')
                dp[1]=1;
            for(int i=2;i<=n;i++)
            {
                int x1 = s[i-1] - '0';
                int x2 = (s[i-2] - '0')*10 + x1;
                if(x1 >= 1)
                    dp[i]=(dp[i]+dp[i-1])%md;
                if(x2 >=10 && x2 <= 26)
                    dp[i]=(dp[i]+dp[i-2])%md;
            }
            return dp[n]%md;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
