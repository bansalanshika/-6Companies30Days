class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int sum=0,count=0;
        while(sum<=dividend){
            sum=sum+divisor;
            count++;
        }
        int ans=count-1;
        
        if(ans>=INT_MAX){
            return INT_MAX;
        }
        else if(ans<=INT_MIN){
            return INT_MIN;
        }
      return ans;  
    }
};
