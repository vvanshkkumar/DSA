class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        int leftMax = 0;
        int rightMax = height.size()-1;
        int leftArea = 0;
        int rightArea = 0;
        int Area = 0;

        while(left < right) {

            if(height[left] <= height[right]){
                
                left++;
                if(height[left] < height[leftMax])
                leftArea += height[left];

                else if(height[left] >= height[leftMax]){
                  
                  Area += height[leftMax]*(left-leftMax-1) - leftArea;
                  leftArea = 0;
                  leftMax = left;
            }
            }
             else {
                
                right--;

                if(height[right] < height[rightMax])
                rightArea += height[right];

                else if(height[right] >= height[rightMax]){
                  
                  Area += height[rightMax]*(rightMax-right-1) - rightArea;
                  rightArea = 0;
                  rightMax = right;
            }
            }
        }

        return Area;


        
    }
};