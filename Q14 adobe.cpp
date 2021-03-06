#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    struct Node{
      int data, idx, arrIdx;
        Node(int val, int index, int arrayindex){
            data=val;
            idx=index;
            arrIdx=arrayindex;
        }
    };
    
    struct cmp{
      bool operator()(Node* &x, Node* &y){
          return x->data > y->data;
      }  
    };
    pair<int,int> findSmallestRange(int nums[][N], int n, int k)
    {
        pair<int,int>res = {-1000000, 1000000};
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        int curMax=INT_MIN;
        for(int i=0; i<k; ++i){
            Node *e = new Node(nums[i][0],0,i);
            pq.push(e);
            curMax = max(curMax, nums[i][0]);
        }
        
        int curdif = INT_MAX;
        while(1){
            Node *cur = pq.top();
            pq.pop();
            int data = cur->data;// 0
            int idx = cur->idx; // 0
            int arrIdx = cur->arrIdx;//0
            if(curMax-data < curdif){
                res={data,curMax};
