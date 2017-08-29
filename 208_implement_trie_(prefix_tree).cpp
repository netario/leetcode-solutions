class Trie {
private:
    struct TrieNode {
        bool isValid;
        TrieNode* children[26];
    };
        TrieNode* root;
        int dfs(TrieNode* u, string& str, int idx) {
        if (idx == str.size()) return u->isValid ? 1 : 2;
        if (!u->children[str[idx] - 'a']) return 0;
        return dfs(u->children[str[idx] - 'a'], str, idx + 1);
    }
    public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
        /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* u = root;
        for (auto& c : word) {
            if (!u->children[c - 'a']) u->children[c - 'a'] = new TrieNode();
            u = u->children[c - 'a'];
        }
        u->isValid = true;
    }
        /** Returns if the word is in the trie. */
    bool search(string word) {
        return dfs(root, word, 0) == 1;
    }
        /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return dfs(root, prefix, 0) > 0;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */