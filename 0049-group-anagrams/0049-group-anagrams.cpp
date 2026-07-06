class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
         unordered_map<string,int> map; // sorted word, index

         vector<vector<string>> result;

         for(int i=0;i<strs.size();i++){

            string word = strs[i];
            sort(word.begin(),word.end());

            if(map.count(word)){
                int index = map[word];
                result[index].push_back(strs[i]);
            }
            else {
                result.push_back({strs[i]});
                map[word] = result.size()-1;
            }
         }

         return result;
    }
};