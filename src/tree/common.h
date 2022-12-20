#include <iostream>
#include <vector>

namespace algo {
namespace tree {
template <typename T>
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

static size_t i = 0;

template <typename T>
TreeNode<T>* toBinaryTree(TreeNode<T>* root, const std::vector<T>& nums) {
  if (nums[i] == -1 || i > nums.size()) {
    return root;
  }

  root = new TreeNode<T>();
  root->val = nums[i];
  i++;
  root->left = toBinaryTree(root->left, nums);
  i++;
  root->right = toBinaryTree(root->right, nums);

  return root;
}

template <typename T>
TreeNode<T>* ToBinaryTree(const std::vector<T>& nums) {
  TreeNode<T>* root = nullptr;
  if (nums.size() < 1) {
    return root;
  }
  root = toBinaryTree(root, nums);
  return root;
}

template <typename T>
void FreeBinaryTree(TreeNode<T>* root) {
  if (root == nullptr) {
    return;
  }

  FreeBinaryTree(root->left);
  FreeBinaryTree(root->right);

  delete root;
  i = 0;
}
}  // namespace tree
}  // namespace algo