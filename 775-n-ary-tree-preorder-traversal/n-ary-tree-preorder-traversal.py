class Solution(object):
    def preorder(self, root):
        ans = []
        self.traverse(root, ans)
        return ans

    def traverse(self, root, ans):
        if root is None: 
            return
        ans.append(root.val)
        for child in root.children:
            self.traverse(child, ans)