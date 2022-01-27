class Solution {
public:
bool winnerOfGame(string colors) {

    int alice = 0 , bob = 0;
    for(int i=1;i<colors.size()-1;i++){
        
        char prev = colors[i-1];
        char curr = colors[i];
        char next = colors[i+1];
        
        if(curr == 'A' && curr == prev && curr == next) alice+=1;
        if(curr == 'B' && curr == prev && curr == next) bob+=1;
    }
    
    return alice > bob;
    
}
};
