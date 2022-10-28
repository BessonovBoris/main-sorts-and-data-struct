#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *previous;
};


class List{
private:
    Node *last;

public:
    List(){
        last = nullptr;
    }

    void add_node(int d){
        Node *new_node = new Node;

        new_node->value = d;
        new_node->previous = last;

        last = new_node;
    }

    void del_node(){
        if(last != nullptr){

            cout << last->value << '\n';
            last = last->previous;

        }
    }

    void print_elements(){
        Node *current = last;

        while(current != nullptr){
            cout << current->value << "\n";
            current = current->previous;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    List stack;

    int n;
    char oper;
    int value;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> oper;

        if(oper == '+'){
            cin >> value;
            stack.add_node(value);
        } else if (oper == '-'){
            stack.del_node();
        }
    }

    return 0;
}
