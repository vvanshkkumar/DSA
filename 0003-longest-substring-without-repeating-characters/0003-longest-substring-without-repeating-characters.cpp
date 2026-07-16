class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.size()==0) return 0;
        
        vector<int> check(129,-1);

        int i = 0;
        int j = 0;

        int maxLen = 0;

        while(j<s.size()){

            int index = s[j];

            if(check[index]==-1){
                check[index] = j;
                j++;
            }
            else if(check[index]!=-1){
                i = max(i,check[index] + 1);
                check[index] = j;
                j++;
            }
            maxLen = max(maxLen, j-i);
        }

        return maxLen;
    }
};