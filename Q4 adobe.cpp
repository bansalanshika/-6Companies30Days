// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int n, int sum){
        
        bool dp[n+1][sum+1];
        
        int i,j;
        
        for(i=0; i<1; i++)
            for(j = 0; j<=sum; j++){
                dp[i][j] =  false;
            }
        
        for(j=0; j<1; j++)
            for(i = 0; i<=n; i++){
                dp[i][j] =  true;
            }    
        
        for(i=1; i<=n; i++){
            for(j=1; j<=sum; j++){
                
                if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                
                else
                dp[i][j] = dp[i-1][j];
                
                
                
            }
        }
    
        return dp[n][sum];
        
    }
    
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        
        if(sum%2 !=0) return 0;
        
        return isSubsetSum(arr, n, sum/2);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
