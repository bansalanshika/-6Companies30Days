#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    ull two = 0;
	    ull three = 0;
	    ull five = 0;
	    
	    vector<ull> res(n, 1);
	    ull curr = 1;
	    
	    while(curr<n){
	        ull least = min(2*res[two], min(3*res[three], 5*res[five]));
	        if(least == 2*res[two]) two++;
	        if(least == 3*res[three]) three++;
	        if(least == 5*res[five]) five++;
	        
	        res[curr]=least;
	        curr++;
	    }
	    
	    return res[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
