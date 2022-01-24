#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    private:
        void solve(string &str,int front,int k,string &maxs){
            if(k==0)
                return;
            char maxi=str[front];
            for(int i=front+1;i<str.length();i++){
                if(str[i]>maxi){
                    maxi=str[i];
                }
            }
            if(maxi != str[front])
                --k;
            for(int j=str.length()-1;j>=front;j--){
                 if(str[j]==maxi){
                    swap(str[j],str[front]);
                    if(str.compare(maxs)>0)
                        maxs=str;
                    solve(str,front+1,k,maxs);
                    swap(str[front],str[j]);
                 }
            }
        }       
            //if (str.compare(maxs) > 0)
            //    maxs = str;
            //(str[front],swap[pos]);
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       int front=0;
       string maxs=str;
       solve(str,front,k,maxs);
       return maxs;
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
