#include <iostream>
#include <map>

using namespace std;

class Trie {
    bool isEnd;
    map<char, Trie *> child;
public:
    Trie() {
        this->isEnd = false;
    }

    void insert(string s) {
        Trie *trie = this;
        for (auto x:s) {
            if (!trie->child[x]) {
                trie->child[x] = new Trie;
                trie->child[x]->isEnd = false;
            } else
                trie->child[x]->isEnd = false;
            trie = trie->child[x];
        }
        trie->isEnd = true;
    }

    bool search(string s) {
        Trie *trie = this;
        for (auto x:s) {
            if (!trie->child[x]) {
                return false;
            } else
                trie = trie->child[x];
        }
        return true;
    }
};

int main() {
    Trie *s = new Trie;
    s->insert("Hello");
    cout << s->search("Hello");
    return 0;
}