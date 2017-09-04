/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* dfs(vector<int>&nums, int l, int r){
        if (l > r) return NULL;
        int mid = (l + r + 1) / 2;
        TreeNode* ret = new TreeNode(nums[mid]);
        ret->left = dfs(nums, l, mid - 1);
        ret->right = dfs(nums, mid + 1, r);
        return ret;
    }
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};