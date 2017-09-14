class Solution
{
  public:
    static int maxSum(TreeNode* root)
    {
        if (root == nullptr)
        {
          return 0;
        }
        auto r = maxSum(root->right) + root->value;
        auto l = maxSum(root->left) + root->value;
        return std::max(r, l);
    }
};