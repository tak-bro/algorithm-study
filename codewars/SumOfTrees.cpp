// Return the sum of all values in the tree, including the root
int sumTheTreeValues(node* root) {
  // Put the magic here
  
  if (root == 0) {
    return 0;
  }
  
  return sumTheTreeValues(root->left) + sumTheTreeValues(root->right) + root->value;
}