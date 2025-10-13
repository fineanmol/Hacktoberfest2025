/*
 * Problem: Maximum Depth of Binary Tree
 * 
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.
 * 
 * Example:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(h) where h is height of tree (O(n) worst case, O(log n) average case)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
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
    // Recursive approach (DFS)
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth);
    }
    
    // Iterative approach using BFS (Level Order Traversal)
    int maxDepthIterative(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            depth++;
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return depth;
    }
    
    // Find minimum depth of binary tree
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        int minLeft = INT_MAX, minRight = INT_MAX;
        
        if (root->left) {
            minLeft = minDepth(root->left);
        }
        if (root->right) {
            minRight = minDepth(root->right);
        }
        
        return 1 + min(minLeft, minRight);
    }
    
    // Check if tree is balanced (height difference <= 1)
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
    // Get all paths from root to leaves with their depths
    vector<pair<vector<int>, int>> getAllPaths(TreeNode* root) {
        vector<pair<vector<int>, int>> allPaths;
        vector<int> currentPath;
        getAllPathsHelper(root, currentPath, allPaths);
        return allPaths;
    }
    
private:
    // Helper function for balanced tree check
    int checkHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced
        
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced
        
        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Not balanced
        }
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    // Helper function to get all paths
    void getAllPathsHelper(TreeNode* root, vector<int>& currentPath, 
                          vector<pair<vector<int>, int>>& allPaths) {
        if (root == nullptr) {
            return;
        }
        
        currentPath.push_back(root->val);
        
        // If it's a leaf node, add the path
        if (root->left == nullptr && root->right == nullptr) {
            allPaths.push_back({currentPath, currentPath.size()});
        } else {
            getAllPathsHelper(root->left, currentPath, allPaths);
            getAllPathsHelper(root->right, currentPath, allPaths);
        }
        
        currentPath.pop_back(); // Backtrack
    }
    
public:
    // Helper function to create tree from array (level order)
    TreeNode* createTree(vector<int>& values, int index = 0) {
        if (index >= values.size() || values[index] == -1) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(values[index]);
        root->left = createTree(values, 2 * index + 1);
        root->right = createTree(values, 2 * index + 2);
        
        return root;
    }
    
    // Helper function to print tree structure
    void printTree(TreeNode* root, int space = 0, int height = 10) {
        if (root == nullptr) return;
        
        space += height;
        printTree(root->right, space);
        
        cout << endl;
        for (int i = height; i < space; i++) {
            cout << " ";
        }
        cout << root->val << endl;
        
        printTree(root->left, space);
    }
    
    // Helper function to delete tree
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Regular binary tree
    //       3
    //      / \
    //     9   20
    //        / \
    //       15  7
    vector<int> values1 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* root1 = solution.createTree(values1);
    
    cout << "Test Case 1: Regular Binary Tree" << endl;
    cout << "Tree structure:" << endl;
    solution.printTree(root1);
    cout << "\nMax Depth (Recursive): " << solution.maxDepth(root1) << endl;
    cout << "Max Depth (Iterative): " << solution.maxDepthIterative(root1) << endl;
    cout << "Min Depth: " << solution.minDepth(root1) << endl;
    cout << "Is Balanced: " << (solution.isBalanced(root1) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 2: Skewed tree (unbalanced)
    //   1
    //    \
    //     2
    //      \
    //       3
    //        \
    //         4
    vector<int> values2 = {1, -1, 2, -1, 3, -1, 4};
    TreeNode* root2 = solution.createTree(values2);
    
    cout << "Test Case 2: Right Skewed Tree" << endl;
    cout << "Max Depth (Recursive): " << solution.maxDepth(root2) << endl;
    cout << "Max Depth (Iterative): " << solution.maxDepthIterative(root2) << endl;
    cout << "Min Depth: " << solution.minDepth(root2) << endl;
    cout << "Is Balanced: " << (solution.isBalanced(root2) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 3: Single node
    vector<int> values3 = {1};
    TreeNode* root3 = solution.createTree(values3);
    
    cout << "Test Case 3: Single Node" << endl;
    cout << "Max Depth: " << solution.maxDepth(root3) << endl;
    cout << "Min Depth: " << solution.minDepth(root3) << endl;
    cout << "Is Balanced: " << (solution.isBalanced(root3) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 4: Empty tree
    TreeNode* root4 = nullptr;
    cout << "Test Case 4: Empty Tree" << endl;
    cout << "Max Depth: " << solution.maxDepth(root4) << endl;
    cout << "Min Depth: " << solution.minDepth(root4) << endl;
    cout << "Is Balanced: " << (solution.isBalanced(root4) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 5: Get all paths from root to leaves
    cout << "Test Case 5: All Paths from Root to Leaves (Tree 1)" << endl;
    auto paths = solution.getAllPaths(root1);
    for (int i = 0; i < paths.size(); i++) {
        cout << "Path " << i + 1 << " (Depth " << paths[i].second << "): [";
        for (int j = 0; j < paths[i].first.size(); j++) {
            cout << paths[i].first[j];
            if (j < paths[i].first.size() - 1) cout << " -> ";
        }
        cout << "]" << endl;
    }
    
    // Clean up memory
    solution.deleteTree(root1);
    solution.deleteTree(root2);
    solution.deleteTree(root3);
    
    return 0;
}