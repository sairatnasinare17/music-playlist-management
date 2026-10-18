
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

struct Node
{
    string word;
    int frequency;
    Node *left;
    Node *right;
};

class BST
{
    Node *root;

    Node* insert(Node *node, string word)
    {
        if (node == NULL)
        {
            Node *newNode = new Node;
            newNode->word = word;
            newNode->frequency = 1;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        if (word == node->word)
        {
            node->frequency++;
        }
        else if (word < node->word)
        {
            node->left = insert(node->left, word);
        }
        else
        {
            node->right = insert(node->right, word);
        }

        return node;
    }

    void display(Node *node)
    {
        if (node == NULL)
            return;

        display(node->left);

        cout << node->word << " : "
             << node->frequency << endl;

        display(node->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insertWord(string word)
    {
        root = insert(root, word);
    }

    void displayFrequencies()
    {
        cout << "\nWord Frequencies:\n";
        cout << "-----------------\n";
        display(root);
    }
};

int main()
{
    BST tree;
    string paragraph, word;

    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    stringstream ss(paragraph);

    while (ss >> word)
    {
        string cleanedWord = "";

        for (char ch : word)
        {
            if (isalnum(static_cast<unsigned char>(ch)))
            {
                cleanedWord += static_cast<char>(
                    tolower(static_cast<unsigned char>(ch))
                );
            }
        }

        if (!cleanedWord.empty())
        {
            tree.insertWord(cleanedWord);
        }
    }

    tree.displayFrequencies();

    return 0;
}
