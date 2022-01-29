#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void find(int idx,string str,int k,string &mx){
        if(k==0){
            return;
        }
        
        if(idx>str.length())return;
        
        char temp=str[idx];
        for(int i=idx+1;i<str.length();i++){
            if(temp<str[i])temp=str[i];
        }
        
       if(temp!=str[idx])k--;
       
       for(int i=str.length()-1;i>=idx;i--){
           if(str[i]==temp){
               swap(str[i],str[idx]);
               if(str.compare(mx)>0)mx=str;
               find(idx+1,str,k,mx);
               swap(str[i],str[idx]);
           }
       }
    }
    
    string findMaximumNum(string str, int k)
    {
       string mx=str;
       find(0,str,k,mx);
       
       return mx;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
