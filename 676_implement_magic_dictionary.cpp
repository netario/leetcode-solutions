class MagicDictionary {
private:
    struct DicNode {
        bool isValid;
        DicNode* children[26];
    };
        DicNode* root;
        bool dfs(DicNode* root, string& s, int idx, int m) {
        if (idx == s.size()) return m == 0 && root->isValid;
        if (root->children[s[idx] - 'a'] && dfs(root->children[s[idx] - 'a'], s, idx + 1, m)) return true;
        if (m > 0) {
            for (int i = 0; i < 26; ++ i)
                if (i != s[idx] - 'a' && root->children[i] && dfs(root->children[i], s, idx + 1, 0)) return true;
        }
        return false;
    }
    public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new DicNode();
    }
        /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto& word : dict) {
            DicNode* u = root;
            for (auto& c : word) {
                u = !u->children[c - 'a'] ? u->children[c - 'a'] = new DicNode() : u->children[c - 'a'];
            }
            u->isValid = true;
        }
    }
        /** Returns if there is any word in the trie that equals to the given word after modifying exactly one 
        character */
    bool search(string word) {
        return dfs(root, word, 0, 1);
    }
};
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */