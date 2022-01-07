// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<string,pair<int,string>> dp;
    pair<int,string> helper(int A[], int left, int right){
        if(left+1==right){
            return {0,""+string(1,left+'A')};
        }
        string key=to_string(left)+"-"+to_string(right);
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        int currMin=INT_MAX;
        string minString="";
        for(int par=left+1;par<right;par++){
            auto p1=helper(A,left,par);
            auto p2=helper(A,par,right);
            if(p1.first+p2.first+A[left]*A[par]*A[right]<currMin){
                currMin=p1.first+p2.first+A[left]*A[par]*A[right];
                minString="(" +p1.second  +p2.second+ ")";
            }
        }
        return dp[key]={currMin,minString};
    }
    string matrixChainOrder(int A[], int n){
        dp.clear();
        return helper(A,0,n-1).second;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
