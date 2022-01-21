#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        string ans="", temp="";
        for(int i=0;s[i];i++) {
            if(s[i]>='A'&&s[i]<='Z') {
                ans+=temp;
                if(i!=0) {
                    ans+=" ";
                }
                temp="";
                temp+=tolower(s[i]);
            }
            else
            temp+=s[i];
        }
        ans+=temp;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
