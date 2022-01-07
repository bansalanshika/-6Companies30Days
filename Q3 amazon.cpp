#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> a, int n, int k) {
        vector<int> res;
        deque<int> q;
        for(int i=0; i<k; i++){
            while(q.size() && a[q.back()]<=a[i])
                q.pop_back();
            q.push_back(i);   
        }
        for(int i=k; i<n; i++){
            res.push_back(a[q.front()]);
            while(q.size() && i-q.front()>=k)
                q.pop_front();
            while(q.size() && a[q.back()] <= a[i])
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(a[q.front()]);
        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
