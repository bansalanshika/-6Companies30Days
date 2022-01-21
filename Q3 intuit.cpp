#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


int num(const string&s, int i, int l){
    if(i+l>s.length())
        return -1;
    int val = 0;
    for(int k=i;k<i+l;k++){
        if(s[k]<'0' || s[k]>'9')
            return -1;
        val = val*10 + (s[k]-'0');
    }
    return val;
}
int missingNumber(const string&s){
    for(int l=1;l<=6;l++){
        int n = num(s,0,l);
        if(n==-1) 
            return -1;
            
        int miss = -1;
        bool fail = false;
        for(int i=l;i<s.length();i+=1+log10(n)){
            if(miss==-1 && num(s,i,1+log10(n+2))==n+2){
                miss = n+1;
                n+=2;
            }else if(num(s,i,1+log10(n+1))==n+1)
                n++;
            else{
                fail=true;
                break;
            }
        }
        if(!fail)
            return miss;
    }
    return -1;
}
