/*
 * Problem: Lowest Common Ancestor of a Binary Tree
 * 
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * The LCA is defined as the lowest node that has both nodes as descendants.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(h) where h is height of tree
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left != nullptr && right != nullptr) {
            return root; // Both nodes found in different subtrees
        }
        
        return left != nullptr ? left : right; // Return non-null result
    }
    
    // For BST specifically (more efficient)
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        // If both nodes are smaller than root, LCA is in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestorBST(root->left, p, q);
        }
        // If both nodes are greater than root, LCA is in right subtree
        else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestorBST(root->right, p, q);
        }
        // If nodes are on different sides, root is LCA
        else {
            return root;
        }
    }
    
    TreeNode* createTree(vector<int>& values, int index = 0) {
        if (index >= values.size() || values[index] == -1) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(values[index]);
        root->left = createTree(values, 2 * index + 1);
        root->right = createTree(values, 2 * index + 2);
        return root;
    }
    
    TreeNode* findNode(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        TreeNode* left = findNode(root->left, val);
        if (left) return left;
        return findNode(root->right, val);
    }
    
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    Solution solution;
    
    // Test tree: [3,5,1,6,2,0,8,null,null,7,4]
    vector<int> values = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root = solution.createTree(values);
    
    TreeNode* p = solution.findNode(root, 5);
    TreeNode* q = solution.findNode(root, 1);
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    
    cout << "LCA of 5 and 1: " << (lca ? lca->val : -1) << endl;
    
    solution.deleteTree(root);
    return 0;
}