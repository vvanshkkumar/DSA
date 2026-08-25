/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int find(TreeNode* node, unordered_map<TreeNode*, unordered_map<int,int>>& dp, int cond){ // cond = 0->not_take, 1->take

         if(node==NULL) return 0;

         if(cond!=-1 && dp[node].count(cond)) return dp[node][cond];
         
         int take = 0;
         int notTake = 0;

         if(cond==0 || cond==-1){
            notTake = max(find(node->left, dp, 0), find(node->left, dp, 1)) + max(find(node->right, dp, 0), find(node->right, dp, 1));
         }
         if(cond==1 || cond==-1){
            take = node->val + find(node->left, dp,0) + find(node->right, dp, 0);
         }

         dp[node][cond] = max(take, notTake);

         return dp[node][cond];
        
    }


    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*, unordered_map<int,int>> dp;

        return find(root, dp, -1);
        
    }
};