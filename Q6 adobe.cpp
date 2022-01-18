//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void ans(int n, vector<string>&v, string s, int open, int close)
    {
        if(open>n || close>n || close>open)
        return;
        if(open==close && open==n)
        {
            v.push_back(s);
            return;
        }
        ans(n, v, s+'(', open+1, close);
        ans(n, v, s+')', open, close+1);
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>v;
        string s="";
        ans(n, v, s, 0, 0);
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
