/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */
#include <stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    struct trie
    {
        struct trie *child[26];
        string word; //string at end of the path for a word;
        trie()
        {
            for (int i = 0; i < 26; i++)
            {
                child[i] = nullptr;
            }
            word = "";
        }
    };

    struct trie *root;

    void trie_insert(string s)
    {
        struct trie *curr = root;
        for (char c : s)
        {
            if (curr->child[c - 'a'] == nullptr)
                curr->child[c - 'a'] = new trie;
            curr = curr->child[c - 'a'];
        }

        curr->word = s;
    }

    string dfs(struct trie *root) //Other approach can be dirctly searching in trie keeping the condition in view
    {
        /* 
    Modified dfs follow depth only when
    count>=1 for nodes in middle (as our requirement is to construct 
    "words that can be built one character at a time by other words in words")
 */
        stack<struct trie *> st;
        string mx_len_string = "";
        struct trie *curr = root;
        st.push(curr);
        while (!st.empty())
        {
            curr = st.top();
            st.pop();
            for (auto c : curr->child)
                if (c&&c->word != "" && c->word.length() - curr->word.length() <= 1) //Condition to take care  "words that can be built one character at a time by other words in words")
                {
                    if ((c->word).length() > mx_len_string.length())
                        mx_len_string = c->word;
                    else if ((c->word).length() == mx_len_string.length() && mx_len_string > c->word)
                        mx_len_string = c->word;
                    st.push(c);
                }
        }
        return mx_len_string;
    }
    string longestWord(vector<string> &words)
    {
        root = new trie;
        for (string x : words)
            trie_insert(x);
        string res = dfs(root);
        return res;
    }
};
// @lc code=end
