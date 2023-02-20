#include <bits/stdc++.h>
using namespace std;
// https://codeantenna.com/a/yQhg8UKR22
const int MaxBranchNum = 123;

class TreeNode
{
private:
    bool isEnd;
    char ch;
    int count;
    TreeNode* children[MaxBranchNum];
public:
    TreeNode(char ch = 0) {
        this->ch = ch;
        isEnd = false;
        count = 1;
        memset(children, 0, sizeof(children));
    }
};



int main()
{
    int n; cin >> n;
    // Trie trie = Trie();
    // insert("huang");
    // trie.insert("huan");
    // trie.insert("Jack");
    // cout << trie.search("huang") << endl;
    return 0;
}
