class Solution {
public:
    bool checkValidString(string s) {
        
        int low = 0;
        int high = 0;

        for(int i=0;i<s.size();i++){

            if(s[i]=='(') {
                low++;
                high++;
            }
            else if(s[i]==')'){
                low--;
                high--;
            }
            else if(s[i]=='*'){
                low--;
                high++;
            }

             if(high<0) return false;
            if(low<0) low = max(low,0);
        }

        if(low==0) return true;

        return false;
    }
};