class WordDictionary {
private:
    struct Node {
        bool isValid;
        Node* children[26];
                Node() {
            isValid = false;
            memset(children, NULL, sizeof(children));
        }
    };
        Node* trie;
        bool dfs(Node* root, string& word, int u) {
        if (u == word.size()) return root->isValid;
        if (word[u] != '.') 
            return !root->children[word[u] - 'a'] ? false : dfs(root->children[word[u] - 'a'], word, u + 1);
        else
            for (int i = 0; i < 26; ++ i)
                if (root->children[i] && dfs(root->children[i], word, u + 1)) return true;
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Node();
    }
        /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* tmp = trie;
        for (auto& c : word) {
            tmp = tmp->children[c - 'a'] ? tmp->children[c - 'a'] : tmp->children[c - 'a'] = new Node();
        }
        tmp->isValid = true;
    }
        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any 
        one letter. */
    bool search(string word) {
        return dfs(trie, word, 0);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */