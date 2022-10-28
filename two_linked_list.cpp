#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next = nullptr;
    Node *previous;
};


class List{
private:
    Node *head;
    Node *last;

public:
    List(){
        head = nullptr;
        last = nullptr;
    }

    void add_node(int d){
        Node *new_node = new Node;

        new_node->value = d;

        if(last == nullptr){
            head = new_node;
            last = new_node;
            new_node->previous = nullptr;
        } else {
            new_node->previous = last;
            last->next = new_node;
            last = new_node;
        }
    }

    void del_node(){
        if(last != nullptr) {
            last = last->previous;
            delete last->next;
            last->next = nullptr;
        }
    }

    void print_elements(){
        Node *current = head;

        while(current != nullptr){
            cout << current->value << "\n";
            current = current->next;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    List list;

    list.add_node(1);
    list.add_node(2);
    list.add_node(3);
    list.add_node(4);

    list.del_node();

    list.print_elements();

    return 0;
}
