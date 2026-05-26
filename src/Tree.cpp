#include "header.h"
template <typename T>
class Tree
{

private:

    struct Node
    {
        T data;
        Node *left;
        Node *right;

        Node(T value) : data(value) , left(nullptr) , right(nullptr) {}
    };
    
    Node *root;
    
public:
    
    Tree() : root(nullptr) {}


    void Insert(T value)
    {
        root = Insert(root,value); 
    }

    Node* Insert(Node *node,T value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }
        
        if (value < node->data)
        {
            node->left = Insert(node->left,value);
        }
        else if(value > node->data) 
        {
            node->right = Insert(node->right,value);
        }
        
        return node;
    }

    void inorder()
    {
        inorder(root);
    }
    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);

        cout << node->data << " ";

        inorder(node->right);
        
    }
    bool search(T value)
    {
        return search(root,value);
    }
    bool search(Node *node,T value)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }
        else if (node->data < value)
        {
           return search(node->right,value); 
        }
        else
        {
            return search(node->left,value);
        }
    }

};



int main(int argc, char* argv)
{
    Tree<int> tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    cout << tree.search(30) << endl;
    cout << tree.search(0) << endl;


    tree.inorder();

    return 0;
}
