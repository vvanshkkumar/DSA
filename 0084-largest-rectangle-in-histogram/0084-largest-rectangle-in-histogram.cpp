class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int,int>> stack;
        // pair -> index, height;

        int i = 0;
        int MaxArea = 0;
        int n = heights.size();


        while(i<heights.size()){

            if(stack.empty()) stack.push({i, heights[i]});

            else if(heights[i]>=stack.top().second){

                stack.push({i,heights[i]});
            }
            else {
                int index = i;

                while(!stack.empty() && heights[i]<stack.top().second){

                auto [start, height] = stack.top();
                index = start;
                stack.pop();

                MaxArea = max(MaxArea, (i-start)*(height));
                }

                if(stack.empty()){
                     MaxArea = max(MaxArea, (i+1)*(heights[i]));
                }
                stack.push({index,heights[i]});
            }
            i++;
        }

         while(!stack.empty()){
            
             auto [start, height] = stack.top();
                stack.pop();

                MaxArea = max(MaxArea, (n-start)*height);
            
          }

          return MaxArea;      
    }
};