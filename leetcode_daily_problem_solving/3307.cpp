class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        string w="a";
        long long c=0;
        int ind=-1;
        for(int i=0 ; i<operations.size() ;++i){
            if(k<=pow(2,i+1)){
                c=pow(2,i+1);
                ind=i;
                break;
            }
        }

        int shift=0;
        
        for(int i=ind ;i>=0 ;--i){
                c=c/2;

            
                if(c<k) {
                    k=k-c;
                    if(operations[i]==1)
                        shift++;
                } 
            
        }
        return (char)('a'+(shift%26));
    }
};