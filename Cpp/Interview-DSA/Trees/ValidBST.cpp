/*
 * Problem: Validate Binary Search Tree
 * 
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * A valid BST is defined as follows:
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(h) where h is height of tree
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Approach 1: Using bounds
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    
    // Approach 2: Using inorder traversal
    bool isValidBSTInorder(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i-1]) {
                return false;
            }
        }
        return true;
    }
    
    // Approach 3: Using inorder with single pass
    bool isValidBSTSinglePass(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorderValidate(root, prev);
    }
    
private:
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true;
        
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
    
    bool inorderValidate(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr) return true;
        
        if (!inorderValidate(node->left, prev)) return false;
        
        if (prev != nullptr && prev->val >= node->val) {
            return false;
        }
        prev = node;
        
        return inorderValidate(node->right, prev);
    }
    
public:
    TreeNode* createTree(vector<int>& values, int index = 0) {
        if (index >= values.size() || values[index] == -1) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(values[index]);
        root->left = createTree(values, 2 * index + 1);
        root->right = createTree(values, 2 * index + 2);
        return root;
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
    
    // Valid BST: [2,1,3]
    vector<int> values1 = {2, 1, 3};
    TreeNode* root1 = solution.createTree(values1);
    cout << "Test 1 - Valid BST [2,1,3]: " << (solution.isValidBST(root1) ? "true" : "false") << endl;
    
    // Invalid BST: [5,1,4,null,null,3,6]
    vector<int> values2 = {5, 1, 4, -1, -1, 3, 6};
    TreeNode* root2 = solution.createTree(values2);
    cout << "Test 2 - Invalid BST [5,1,4,null,null,3,6]: " << (solution.isValidBST(root2) ? "true" : "false") << endl;
    
    solution.deleteTree(root1);
    solution.deleteTree(root2);
    return 0;
}