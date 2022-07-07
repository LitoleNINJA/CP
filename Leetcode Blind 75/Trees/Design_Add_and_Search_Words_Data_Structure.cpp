struct node {
    struct node *child[26];
    bool isEnd;
} *root;
class WordDictionary {
public:
    WordDictionary() {
        node *newNode = new node();
        root = newNode;
    }
    void addWord(string word) {
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
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                    if (temp->child[j] != NULL)
                        return search(word.substr(j + 1));
                return false;
            }
            else if (temp->child[word[i] - 'a'] == NULL)
                return false;
            temp = temp->child[word[i] - 'a'];
        }
        if (temp->isEnd)
            return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */