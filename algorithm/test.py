class SegTreeNode:

    def __init__(self, l: int = 0, r: int = 0):
        self.lazy = 0
        self.val = 0
        self.l = l
        self.r = r
        self.left = None
        self.right = None

MAX = int(1e9+1)

class SegTree:

    def __init__(self) -> None:
        self.root = SegTreeNode(0, MAX)


    def _push_down(self, root: SegTreeNode):
        l, r = root.l, root.r
        mid = (l + r) >> 1
        if not root.left:
            root.left = SegTreeNode(l, mid)
        if not root.right:
            root.right = SegTreeNode(mid + 1, r)
        if root.lazy:
            ln, rn = mid - l + 1, r - mid
            root.left.lazy += root.lazy
            root.right.lazy += root.lazy
            root.left.val += root.lazy * ln
            root.right.val += root.lazy * rn
            root.lazy = 0


    def _push_up(self, root: SegTreeNode):
        root.val = root.left.val + root.right.val


    def _update(self, L: int, R: int, val: int, root: SegTreeNode):
        start, end = root.l, root.r
        if L <= start and end <= R:
            root.val += val * (end - start + 1)
            root.lazy += val
            return

        self._push_down(root)
        mid = (start + end) >> 1
        if L <= mid:
            self._update(L, R, val, root.left)
        if mid < R:
            self._update(L, R, val, root.right)
        self._push_up(root)


    def _query(self, L: int, R: int, root: SegTreeNode) -> int:
        start, end = root.l, root.r
        if L > end or R < start:
            return 0
        elif L <= start and end <= R:
            return root.val

        self._push_down(root)
        return self._query(L, R, root.left) + self._query(L, R, root.right)


    def update(self, L: int, R: int, val: int):
        self._update(L, R, val, self.root)


    def query(self, L: int, R: int) -> int:
        return self._query(L, R, self.root)