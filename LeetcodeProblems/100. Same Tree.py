from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right

def isSameTree(p: Optional[TreeNode], q: Optional[TreeNode]):
    if not p and not q:
        return True
    if not p or not q:
        return False
    if p.val != q.val:
        return False

    return (isSameTree(p.left, q.left) and isSameTree(p.right, q.right))

Tree1 = TreeNode(1)
Tree1.left = TreeNode(2)
Tree1.right = TreeNode(3)

Tree2 = TreeNode(1)
Tree2.left = TreeNode(2)
Tree2.right = TreeNode(3)

print(isSameTree(Tree1, Tree2))
