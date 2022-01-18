//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int calculate(vector<vector<int>> &A, int i, int j)
    {
        if(i<=j)
            return A[i][j];
        return 0;
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n, vector<int>(n, 0));
	    
	    for(int i=0; i<n; i++)
	    {
	        for(int j=i, k=0; j<n; j++, k++)
	        {
	           // choosing from start i.e from kth position
	           //opponent can choose from k+1 or from j
	           //if from k+1 remaining choice = k+2 to j
	           //else k+1 to j-1
	           int ch1 = A[k] + min(calculate(dp, k+2, j), calculate(dp, k+1, j-1));
	           // choosing from end i.e jth position
	           //opponent can choose from k or j-1
	           //if from k remaining choice  = k+1 to j-1
	           //else k to j-2
	           int ch2 = A[j] + min(calculate(dp, k, j-2), calculate(dp, k+1, j-1));
	           
	           dp[k][j] = max(ch1, ch2);
	        }
	    }
	    
	    
	    
	    
	    return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
