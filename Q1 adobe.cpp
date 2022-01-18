#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
       int l = 0;
       long long currSum = arr[0];
       vector<int> vec;
       for(int i = 1; i <= n; i++){
           while(currSum > s && l < n - 1){
               currSum -= arr[l];
               l++;
           }
           if(currSum == s){
               vec.push_back(++l);
               vec.push_back(i);
               return vec;
           }
           if(i < n){
               currSum += arr[i];
           }
       }
       if(n == 0){
            vec.push_back(0);
            vec.push_back(0);
            return vec;
        }
        if(n == 1){
            vec.push_back(1);
            vec.push_back(1);
            return vec;
        }
        vec.push_back(-1);
        return vec;
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
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
