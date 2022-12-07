#include <iostream>

using namespace std;

struct Node {
    int value;
    int balance = 0;
    Node *parent = nullptr;
    Node *left_son = nullptr;
    Node *right_son = nullptr;
};

class Tree {
private:
    Node *root;

public:
    Tree() {
        root = nullptr;
    }

    void balance(Node *current) {
        if(current->parent == nullptr)
            return;

        if(current->parent->right_son == current) {
            current->parent->balance++;
            if(current->parent->balance <= 0)
                return;
        } else if(current->parent->left_son == current) {
            current->parent->balance--;
            if(current->parent->balance >= 0)
                return;
        }

        balance(current->parent);
    }

    void add_node(int val) {
        Node *new_node = new Node;

        new_node->value = val;

        if(root == nullptr) {
            root = new_node;
        } else {
            Node *current = root;
            while(current != nullptr) {
                if(val >= current->value) {
                    if(current->right_son == nullptr) {
                        break;
                    }
                    current = current->right_son;
                } else {
                    if(current->left_son == nullptr) {
                        break;
                    }
                    current = current->left_son;
                }
            }

            new_node->parent = current;
            if(val >= current->value) {
                current->right_son = new_node;
            } else {
                current->left_son = new_node;
            }
        }

        balance(new_node);
    }

    Node* get_root() {
        return root;
    }

    void print_tree(Node *current) {
        if(current == nullptr)
            return;

        print_tree(current->left_son);
        cout << current->value << " " << current->balance << '\n';
        print_tree(current->right_son);
    }
};

int main() {
    Tree tree;

    int s;

    while(cin >> s) {
        if(s == -999)
            break;

        tree.add_node(s);
    }

    tree.print_tree(tree.get_root());

    return 0;
}
