class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack<pair<int,int>> st;
        vector<int> answer(temp.size(),0);

        for(int i=0; i<temp.size();i++){

            if(st.empty()) {
                st.push({temp[i],i});
            }
           else {
            while(!st.empty() && (temp[i] > (st.top()).first)){
                    answer[(st.top()).second] = i - (st.top()).second;
                    st.pop();
                }
             st.push({temp[i],i});
            }
        }
            return answer; 
        }   
};