class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string>> WordToPattern;
        unordered_map<string, vector<string>> PatternToWord;

        bool flag = false;
        bool endFlag = false;

        for(string word : wordList) {
            if(beginWord == word) flag = true;
            if(word == endWord) endFlag = true;
        }

        if(endFlag==false) return 0;

        if(!flag){
            
            for(int i=0;i<beginWord.size();i++){
                string word = beginWord;
                word[i] = '*';
                
                WordToPattern[beginWord].push_back(word);
                PatternToWord[word].push_back(beginWord);
            }
        }

        for(string Word : wordList){
           
            for(int i=0;i<Word.size();i++){
                string word = Word;
                word[i] = '*';
                
                WordToPattern[Word].push_back(word);
                PatternToWord[word].push_back(Word);
            }
        }
        
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        int count = 0;

        while(!q.empty()){

            int size = q.size();
            count++;
                      

            while(size--){

            string word = q.front();
            q.pop();

            for(string pattern : WordToPattern[word]){

                if(!visited.count(pattern)){
                    visited[pattern] = true;    
                
                for(string realWord : PatternToWord[pattern]){
                    
                    if(!visited.count(realWord)){
                    visited[realWord] = true;    
                    q.push(realWord);

                    if(realWord==endWord) return count+1;
                         
                    }
                }
                }
            }
          
        }
          
           

        }
         
         return 0;
    }
};