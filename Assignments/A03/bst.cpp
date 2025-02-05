#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Bst
{
    Node *root;

    void _print(Node *subroot)
    {
        if (!subroot)
            return;
        _print(subroot->left);
        cout << subroot->data << " ";
        _print(subroot->right);
    }

    // This will avoid inserting the duplicate values.
    bool _search(Node *subroot, int key)
    {
        if (!subroot)
            return false;
        if (subroot->data == key)
            return true;
        if (key < subroot->data)
            return _search(subroot->left, key);
        return _search(subroot->right, key);
    }

    void _insert(Node *&subroot, int x)
    {
        if (!subroot)
        {
            subroot = new Node(x);
        }
        else if (x < subroot->data)
        {
            _insert(subroot->left, x);
        }
        else
        {
            _insert(subroot->right, x);
        }
    }

    // This will help in finding the inorder successor.
    Node *findMin(Node *subroot)
    { // Helper function to find the inorder successor
        while (subroot && subroot->left)
            subroot = subroot->left;
        return subroot;
    }

    Node *_delete(Node *subroot, int key)
    {
        if (!subroot)
            return nullptr;

        if (key < subroot->data)
        {
            subroot->left = _delete(subroot->left, key);
        }
        else if (key > subroot->data)
        {
            subroot->right = _delete(subroot->right, key);
        }
        else
        {
            // Case 1: No child
            if (!subroot->left && !subroot->right)
            {
                delete subroot;
                return nullptr;
            }
            // Case 2: One child
            if (!subroot->left)
            {
                Node *temp = subroot->right;
                delete subroot;
                return temp;
            }
            else if (!subroot->right)
            {
                Node *temp = subroot->left;
                delete subroot;
                return temp;
            }
            // Case 3: Two children
            Node *successor = findMin(subroot->right);
            subroot->data = successor->data;
            subroot->right = _delete(subroot->right, successor->data);
        }
        return subroot;
    }

    void _generateDot(Node *subroot, ofstream &dotFile)
    {
        if (!subroot)
            return;

        if (subroot->left)
        {
            dotFile << "    " << subroot->data << " -> " << subroot->left->data << ";\n";
            _generateDot(subroot->left, dotFile);
        }
        if (subroot->right)
        {
            dotFile << "    " << subroot->data << " -> " << subroot->right->data << ";\n";
            _generateDot(subroot->right, dotFile);
        }
    }

public:
    Bst() { root = nullptr; }

    void insert(int x)
    {
        if (!_search(root, x))
        { // Prevent duplicate values
            _insert(root, x);
        }
        else
        {
            cout << "Value " << x << " already exists in the BST!\n";
        }
    }

    void deleteNode(int key)
    {
        root = _delete(root, key);
    }
    bool search(int key) { return _search(root, key); }

    void print() { _print(root); }

    void saveDotFile(const string &filename)
    {
        ofstream dotFile(filename);
        if (!dotFile)
        {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        dotFile << "digraph BST {\n";
        dotFile << "    node [shape=circle];\n";

        if (root)
            _generateDot(root, dotFile);

        dotFile << "}\n";
        dotFile.close();

        cout << "DOT file saved as " << filename << endl;
        cout << "Use Graphviz to visualize: dot -Tpng " << filename << " -o output.png\n";
    }
};

int main()
{
    Bst tree;
    tree.insert(11);
    tree.insert(13);
    tree.insert(5);
    tree.insert(7);
    tree.insert(17);
    tree.insert(3);
    tree.insert(12);

    cout << "Inorder Traversal: ";
    tree.print();

    cout << "Trying to insert duplicate value \n";
    tree.insert(7);

    cout << "Deleting a leaf node \n";
    tree.deleteNode(7);
    tree.print();

    cout << "Deleting a node with one child \n";
    tree.deleteNode(5);
    tree.print();

    cout << "Deleting a node with two children \n";
    tree.deleteNode(11);
    tree.print();
    cout << endl;

    tree.saveDotFile("bst.dot"); // Generates bst.dot for Graphviz visualization
}
