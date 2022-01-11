//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int minR = 0, minC = 0, maxR = n - 1, maxC = n - 1;
    while(minR < maxR) {
        for(int i = 0; i < maxR - minR; i++) {
            int temp = matrix[minR][minC + i];
            matrix[minR][minC + i] = matrix[minR + i][maxC];
            matrix[minR + i][maxC] = matrix[maxR][maxC - i];
            matrix[maxR][maxC - i] = matrix[maxR - i][minC];
            matrix[maxR - i][minC] = temp;
        }
        minR++, minC++;
        maxR--, maxC--;
    }
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
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
