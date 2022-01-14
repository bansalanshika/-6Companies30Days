#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        set <vector<int>> set;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int s=j+1,e=n-1;
                
                while(s<e){
                    int sum =arr[i]+arr[j]+arr[s]+arr[e];
                    
                    if(sum==k){
                        vector<int>a{arr[i],arr[j],arr[s],arr[e]};
                        sort(a.begin(),a.end());
                        set.insert(a);
                        s++;e--;
                    }
                    else if(sum>k)e--;
                    else s++;
                }
            }
        }
        for(auto &x:set){
            ans.push_back(x);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
