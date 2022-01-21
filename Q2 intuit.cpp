#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>& board,string w,int i,int j,int ind)
    {
        if(ind==w.length())
            return true;
        if(i<0||i>=board.size()||j<0||j>=board[ind].size()||board[i][j]!=w[ind])
            return false;
        
        board[i][j]='0';
        bool stat=dfs(board,w,i+1,j,ind+1)||
            dfs(board,w,i-1,j,ind+1)||
            dfs(board,w,i,j+1,ind+1)||
            dfs(board,w,i,j-1,ind+1);
        board[i][j]=w[ind];
        return stat;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0]&&dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
