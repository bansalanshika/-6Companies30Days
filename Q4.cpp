#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{
  int count=1;
  for(int i=0;i<s.length();i++)
  {
      if(s[i]==s[i+1])
        count++;
      else{
        cout<<s[i]<<count;
        count=1;
      }
  }
}     
 

