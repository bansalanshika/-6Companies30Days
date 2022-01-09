#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        int temp;
        while(n>0){
            temp = n % 26;
            if(temp == 0){
                ans = 'Z' + ans;
                n -= 26;
            }
            else{
                n -= temp;
                temp--;
                char t = 'A' + temp;
                ans = t + ans;
            }
                n = n / 26;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
