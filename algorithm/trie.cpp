#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26
#define MIN_ALPHABET 'a'
class TrieNode
{
public:
    bool isEnd;
    char ch;
    int count;
    TrieNode* children[ALPHABET_SIZE];

    TrieNode(char ch = 0) {
        this->ch = ch;
        isEnd = false;
        count = 1;
        memset(children, 0, sizeof(children));
    }
};

class Trie
{
private:
    TrieNode* pRoot;
public:
    Trie() {
        pRoot = new TrieNode();
    }
    ~Trie() {
        destory(pRoot);
    }

    void insert(string str) {
        TrieNode* curNode = pRoot;
        for (char ch: str) {
            ch -= MIN_ALPHABET;
            if (curNode->children[ch] != nullptr) {
                curNode = curNode->children[ch];
                curNode->count++;
            } else {
                TrieNode *newNode = new TrieNode(ch);
                curNode->children[ch] = newNode;
                curNode = curNode->children[ch];
            }
        }
        curNode->isEnd = true;
    }

    bool search(string str) {
        if (str.length() == 0) {
            return false;
        }
        TrieNode* curNode = pRoot;
        for (char ch: str) {
            ch -= MIN_ALPHABET;
            if (curNode != nullptr) {
                curNode = curNode->children[ch];
            }
        }
        return (curNode != nullptr && curNode->isEnd);
    }

    bool startWidth(string str) {
        if (str.length() == 0) {
            return false;
        }
        TrieNode* curNode = pRoot;
        for (char ch: str) {
            ch -= MIN_ALPHABET;
            if (curNode != nullptr) {
                curNode = curNode->children[ch];
            }
        }
        return curNode != nullptr;
    }

    int getPrefixNum(string str) {
        if (str.length() == 0 || !startWidth(str)) {
            return 0;
        }
        TrieNode* curNode = pRoot;
        for (char ch: str) {
            ch -= MIN_ALPHABET;
            if (curNode != nullptr) {
                curNode = curNode->children[ch];
            }
        }
        if (curNode != nullptr) {
            return curNode->count;
        }
        return 0;
    }

    TrieNode* getKNode(string str, int k) {
        TrieNode* curNode = pRoot;
        for (char ch: str) {
            ch -= MIN_ALPHABET;
            if (k-- == 0) {
                break;
            }
            if (curNode != nullptr) {
                curNode = curNode->children[ch];
            }
        }
        return curNode;
    }

    bool remove(string str) {
        if (str.length() == 0 || !search(str)) {
            return false;
        }

        // only need update node's count
        if (getPrefixNum(str) > 1) {
            int k = str.size();
            TrieNode* lastNode = getKNode(str, k);
            lastNode->isEnd = false;
            while (lastNode != pRoot) {
                lastNode->count--;
                lastNode = getKNode(str, --k);
            }
            return true;
        }

        bool updateRoot = getPrefixNum(str.substr(0, 1)) == 1;
        TrieNode* curNode = pRoot;
        int k = str.size();
        auto it = str.rbegin();
        while (it != str.rend())
        {
            char ch = *it - MIN_ALPHABET;
            TrieNode* delNode = getKNode(str, k--);
            if (delNode->count == 1 && delNode != pRoot) {
                if (updateRoot) {
                    free(delNode);
                }
                delNode = nullptr;
            } else {
                delNode->count -= 1;
            }
            ++it;
        }
        if (updateRoot) {
            pRoot->children[str[0] - MIN_ALPHABET] = nullptr;
        }
        return true;
    }

    void destory(TrieNode* pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (pRoot->children[i] != nullptr) {
                destory(pRoot->children[i]);
            }
        }
        delete pRoot;
        pRoot = nullptr;
    }
};

int main()
{
    Trie trie = Trie();
    trie.insert("huang");
    trie.insert("huang");
    trie.insert("huan");
    trie.remove("huan");
    trie.insert("zhouji");
    cout << trie.getPrefixNum("ji") << endl;
    return 0;
}
