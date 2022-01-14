#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
string binary (int n)
{
    string str="";
    
    while(n!=0)
    {
        int rem = n%2;
        str = (rem? '1': '0') + str;
        n = n/2;
    }
    return str;
}
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1; i<=N; i++)
	{
	    ans.push_back(binary(i));
	}
	return ans;
	
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
