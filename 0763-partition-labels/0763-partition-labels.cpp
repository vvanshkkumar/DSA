class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int> map;

        for(int i=0;i<s.size();i++) map[s[i]] = i;

        int end = 0;
        vector<int> result;
        int prev = 0;

        for(int i=0;i<s.size();i++){

            end = max(map[s[i]],end);
            
            if(i == end){
                int validPart = end - prev + 1;
                result.push_back(validPart);
                prev = end+1;
                end = 0;
            }
           
        }

        return result;
    }
};