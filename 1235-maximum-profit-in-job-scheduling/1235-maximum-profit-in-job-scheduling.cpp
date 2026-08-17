class Solution {
public:  
   int find(vector<tuple<int,int,int>>& jobs, vector<int>& dp, int index){

      if(index==jobs.size()) return 0;

      if(dp[index]!=-1) return dp[index]; 

      int skip = find(jobs, dp, index+1);
      int take = 0;
      int end = 0;
         
         auto bound = lower_bound(jobs.begin()+index+1, jobs.end(), get<1>(jobs[index]),
         [](const auto& job, const auto& time){
            return get<0>(job) < time;
         });   
         
         if(bound==jobs.end()){
           end = get<2>(jobs[index]);
         }
         else {

         int bound_index = bound - jobs.begin();

         take = get<2>(jobs[index]) + find(jobs, dp, bound_index);
         }

      dp[index] = max({take, skip, end});

      return dp[index];
   }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<int> dp(startTime.size(), -1);

        vector<tuple<int,int,int>> jobs;

        for(int i=0;i<startTime.size();i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(jobs.begin(), jobs.end(), 
            [](const auto& a, const auto& b){
                return get<0>(a) < get<0>(b);
            }
        );

        return find(jobs, dp, 0);

    }
};