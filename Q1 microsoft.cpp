#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum += arr[i];
	    }
	    vector<bool> dp(sum+1,false);
	    dp[0]=true;
	    for(int x=0;x<n;x++)
	    {
	        for(int i=sum;i>=arr[x];i--)
	        {
	            dp[i] = dp[i]||dp[i-arr[x]];
	        }
	    }
	    int ans=INT_MAX;
	    for(int i=0;i<=sum/2;i++)
	    {
	        if(dp[i] == true)
	        {
	            ans = min(ans,abs(sum-2*i));
	        }
	    }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
