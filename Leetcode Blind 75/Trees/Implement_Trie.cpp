struct node {
    struct node *child[26];
    bool isEnd;
} *root;
class Trie {
public:
    Trie() {
        node *newNode = new node();
        root = newNode;
    }
    void insert(string word) {
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->child[word[i] - 'a'] == NULL)
                temp->child[word[i] - 'a'] = new node();
            temp = temp->child[word[i] - 'a'];
        }
        temp->isEnd = true;
    }
    bool search(string word) {
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->child[word[i] - 'a'] == NULL)
                return false;
            temp = temp->child[word[i] - 'a'];
        }
        if (temp->isEnd)
            return true;
        return false;
    }
    bool startsWith(string prefix) {
        node *temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (temp->child[prefix[i] - 'a'] == NULL)
                return false;
            temp = temp->child[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */