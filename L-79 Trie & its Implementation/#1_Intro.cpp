#include <bits/stdc++.h>

using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // word will be [A - Z]
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // RECURSION
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool removeUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            delete root;
            // root->isTerminal = false;
            return true;
        }
        // word will be [A - Z]
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        // RECURSION
        return removeUtil(child, word.substr(1));
    }

    bool removeWord(string word)
    {
        return removeUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        // word will be [A - Z]
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        // RECURSION
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }
};
int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    cout << "abcd is " << (t->search("ABCD") ? "exist" : "doesn't exist") << endl;
    cout << "DCBA is " << (t->search("DCBA") ? "exist" : "doesn't exist") << endl;

    cout << "abcd is removed" << (t->removeWord("ABCD") ? " yes it removed" : " no it's not found") << endl;
    cout << "abcd is " << (t->search("ABCD") ? "exist" : "doesn't exist") << endl;

    return 0;
}