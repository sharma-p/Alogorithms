#Q.Given a binary tree, find its minimum depth.
#The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#Note: A leaf is a node with no children.

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        self.p=float("inf")
        def find(root,x):
            if x>self.p:
                return
            if not root.left and not root.right:
                self.p=min(self.p,x)
            elif not root.right:
                find(root.left,x+1)
            elif not root.left:
                find(root.right,x+1)
            else:
                find(root.left,x+1)
                find(root.right,x+1)
        find(root,1)
        return(self.p)
