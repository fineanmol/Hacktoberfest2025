/*
 * Problem: Binary Tree Inorder Traversal
 * 
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 * Inorder traversal: Left -> Root -> Right
 * 
 * Example:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(h) where h is height of tree (O(n) worst case, O(log n) average case)
 */

#include <iostream>
#include <vector>
#include <stack>
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
    // Recursive approach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    // Iterative approach using stack
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        
        while (current != nullptr || !stk.empty()) {
            // Go to the leftmost node
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }
            
            // Current is null, so we backtrack from stack
            current = stk.top();
            stk.pop();
            result.push_back(current->val);
            
            // Visit right subtree
            current = current->right;
        }
        
        return result;
    }
    
    // Morris Traversal (O(1) space complexity)
    vector<int> inorderTraversalMorris(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (current->left == nullptr) {
                // No left child, add current to result and go right
                result.push_back(current->val);
                current = current->right;
            } else {
                // Find the rightmost node in left subtree (predecessor)
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                
                if (predecessor->right == nullptr) {
                    // Make current the right child of predecessor
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // Revert the changes (restore tree)
                    predecessor->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        
        return result;
    }
    
    // Preorder Traversal (Root -> Left -> Right)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
    
    // Postorder Traversal (Left -> Right -> Root)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
private:
    void inorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        inorderHelper(root->left, result);   // Left
        result.push_back(root->val);         // Root
        inorderHelper(root->right, result);  // Right
    }
    
    void preorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        result.push_back(root->val);         // Root
        preorderHelper(root->left, result);  // Left
        preorderHelper(root->right, result); // Right
    }
    
    void postorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        postorderHelper(root->left, result);  // Left
        postorderHelper(root->right, result); // Right
        result.push_back(root->val);          // Root
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
    
    // Helper function to print vector
    void printVector(const vector<int>& vec, const string& label) {
        cout << label << ": [";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
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
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    vector<int> values1 = {1, 2, 3, 4, 5, -1, -1};
    TreeNode* root1 = solution.createTree(values1);
    
    cout << "Test Case 1: Binary Tree" << endl;
    vector<int> inorder1 = solution.inorderTraversal(root1);
    vector<int> inorderIter1 = solution.inorderTraversalIterative(root1);
    vector<int> inorderMorris1 = solution.inorderTraversalMorris(root1);
    vector<int> preorder1 = solution.preorderTraversal(root1);
    vector<int> postorder1 = solution.postorderTraversal(root1);
    
    solution.printVector(inorder1, "Inorder (Recursive)");
    solution.printVector(inorderIter1, "Inorder (Iterative)");
    solution.printVector(inorderMorris1, "Inorder (Morris)");
    solution.printVector(preorder1, "Preorder");
    solution.printVector(postorder1, "Postorder");
    cout << endl;
    
    // Test case 2: Right skewed tree
    //   1
    //    \
    //     2
    //    /
    //   3
    vector<int> values2 = {1, -1, 2, 3, -1};
    TreeNode* root2 = solution.createTree(values2);
    
    cout << "Test Case 2: Right Skewed Tree" << endl;
    vector<int> inorder2 = solution.inorderTraversal(root2);
    solution.printVector(inorder2, "Inorder");
    cout << endl;
    
    // Test case 3: Single node
    vector<int> values3 = {1};
    TreeNode* root3 = solution.createTree(values3);
    
    cout << "Test Case 3: Single Node" << endl;
    vector<int> inorder3 = solution.inorderTraversal(root3);
    solution.printVector(inorder3, "Inorder");
    cout << endl;
    
    // Test case 4: Empty tree
    TreeNode* root4 = nullptr;
    cout << "Test Case 4: Empty Tree" << endl;
    vector<int> inorder4 = solution.inorderTraversal(root4);
    solution.printVector(inorder4, "Inorder");
    
    // Clean up memory
    solution.deleteTree(root1);
    solution.deleteTree(root2);
    solution.deleteTree(root3);
    
    return 0;
}