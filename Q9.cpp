#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S) {
        int n = S.size() + 1;
        string ans;
        
        for(int i=1; i<=n; i++) 
            ans += (i + '0');
        
        int st;
        
        for(int i=0; S[i]; i++) {
            if(S[i] == 'I' && (i != 0 && S[i-1] == 'D')) {
                reverse(ans.begin()+st, ans.begin()+(i+1));
            }
                
            else if(S[i] == 'D' && (i==0 || S[i-1] == 'I'))
                st = i;
        }
        
        if(S[n-2] == 'D')
            reverse(ans.begin()+st, ans.end());
            
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
