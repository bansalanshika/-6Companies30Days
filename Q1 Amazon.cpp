// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   
   //https://youtu.be/3YILP-PdEJA
  
    int maxProfit(int K, int N, int A[]) {
        // code here
        int t[K+1][N];
       // memset(t,0,sizeof t);
        for(int i=0;i<K+1;i++){
            for(int j=0;j<N;j++){
                if(j==0 or i==0) t[i][j]=0;
            }
        }
        for(int i=1;i<K+1;i++){
            int mx=t[i-1][0]-A[0];
            for(int j=1;j<N;j++){
                mx=max(mx,t[i-1][j-1]-A[j-1]);
                t[i][j]=max(t[i][j-1],mx+A[j]);
            }
        }
        return t[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
