#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int func(int arr[], int i, int n, vector<int>& v)
    {
        if(i>=n) return 0;
        if(v[i]!=-1) return v[i];
        v[i] = max(arr[i]+func(arr,i+2,n,v), func(arr,i+1,n,v));
        return v[i];
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> v(n+1,-1);
        return func(arr,0,n,v);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
