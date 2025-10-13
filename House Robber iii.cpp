#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int,int> robTree(TreeNode* root) {
    if (!root) return {0, 0};
    auto left = robTree(root->left);
    auto right = robTree(root->right);
    int rob = root->val + left.second + right.second;
    int notRob = max(left.first, left.second) + max(right.first, right.second);
    return {rob, notRob};
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    auto ans = robTree(root);
    cout << max(ans.first, ans.second) << endl;

    return 0;
}
