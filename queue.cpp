#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
};


class List{
private:
    Node *head;

public:
    List(){
        head = nullptr;
    }

    void add_node(int d){
        Node *new_node = new Node;

        new_node->value = d;
        new_node->next = nullptr;

        if(head == nullptr){
            head = new_node;
        } else {
            Node *current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void del_node(){
        if(head != nullptr) {
            cout << head->value << "\n";
            head = head->next;
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

    List queue;

    int n;
    char oper;
    int value;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> oper;

        if(oper == '+'){
            cin >> value;
            queue.add_node(value);
        } else if (oper == '-'){
            queue.del_node();
        }
    }

    return 0;
}
