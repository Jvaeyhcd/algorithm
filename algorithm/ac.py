class ACNode:
    def __init__(self):
        self.fail = None
        self.outputs = []
        self.children = {}

class ACAutomaton:
    def __init__(self, keywords):
        self.root = ACNode()
        self._build_trie(keywords)
        self._build_fail_links()

    def _build_trie(self, keywords):
        for keyword in keywords:
            node = self.root
            for char in keyword:
                node = node.children.setdefault(char, ACNode())
            node.outputs.append(keyword)

    def _build_fail_links(self):
        queue = []
        for node in self.root.children.values():
            node.fail = self.root
            queue.append(node)

        while queue:
            node = queue.pop(0)
            for char, child in node.children.items():
                queue.append(child)
                fail_node = node.fail
                while fail_node and char not in fail_node.children:
                    fail_node = fail_node.fail
                child.fail = fail_node.children[char] if fail_node else self.root
                child.outputs += child.fail.outputs

    def search(self, text):
        results = []
        node = self.root
        for i, char in enumerate(text):
            while node and char not in node.children:
                node = node.fail
            if not node:
                node = self.root
                continue
            node = node.children[char]
            for keyword in node.outputs:
                results.append((i - len(keyword) + 1, keyword))
        return results

keywords = ['he', 'she', 'his', 'hers']
text = 'ushers'
ac = ACAutomaton(keywords)
results = ac.search(text)
print(results)  # [(1, 'she'), (2, 'he'), (2, 'hers')]
