struct Trie{
    static const int K = 26;
    struct Vertex {
        int next[K];
        bool leaf = false;
        Vertex() {
            fill(begin(next), end(next), -1);
        }
    };
    vector<Vertex> trie;
    Trie(){
        trie.emplace_back();
    }
    void add_string(string const& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].leaf = true;
    }
};

