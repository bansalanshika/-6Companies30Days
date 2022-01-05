// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string solve(string s, int& i){
        string res = "";
        int num = 0;
        for(; i<s.size(); i++){
            //int num = 0;
            char c = s[i];
            if(isalpha(c)) res += c;
            else if(isdigit(c)) num = num*10+c-'0';
            else if(c == ']') return res;
            else {
                string temp = solve(s, ++i);
                while(num--) res += temp;
                num = 0;
            }
        }
        return res;
    }
    
    
    string decodedString(string s){
        // code here
        int k = 0;
        return solve(s, k);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
