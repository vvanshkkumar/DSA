class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m;
        int n;

        if(nums1.size() <= nums2.size()){
            m = nums1.size();
            n = nums2.size();
        }
        else {
            m = nums2.size();
            n = nums1.size();
            swap(nums1, nums2);
        }
        
         int low = 0;
         int high = min(m,n);

         int mid1;
         int mid2;
         int left1, left2, right1, right2;

         while(low<=high){

            int i = (low + high)/2;

            int j = (m+n+1)/2 - i;

            left1 = (i-1)>=0?nums1[i-1]:INT_MIN;
            left2 = (j-1)>=0?nums2[j-1]:INT_MIN;

            right1 = i<m?nums1[i]:INT_MAX;
            right2 = j<n?nums2[j]:INT_MAX;

            if(left1 <= right2 && left2<=right1){
                
                mid1 = max(left1, left2);
                mid2 = min(right1, right2);
                break;
            }
            else if(left1 > right2)  high = i-1;
            else if(left2 > right1) low = i+1 ;
         }

         if((m+n)%2) return mid1;
         
         return (mid1+mid2)/2.0;
    }
};