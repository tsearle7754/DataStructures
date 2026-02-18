#include <iostream>

// recursive function that calculates n^n, given an n in between 1 and 9
// int crazySum(int n) {
//    if (n==1) {
//        return;
//    }
//    return pow(n, n) + crazy_sum(n-1);
//}


class Node {
public:
    int data;
    Node* next;
    Node(int d = 0, Node* n = nullptr) : data(d), next(n) {

    }
};

void print_list(Node* head);
void print_list_backwards(Node* head);

Node* reverse_list(Node* head);

Node* swap_pairs(Node* head);       // TODO

int main(void) {
    // Create a linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    print_list(head);
    print_list_backwards(head);
    std::cout << '\n';

    head = reverse_list(head);
    print_list(head);

    return 0;
}

void print_list(Node* head) {
    if (!head) {
        std::cout << '\n';
        return;
    }
    else {
        std::cout << head->data << " ";
        print_list(head->next);         // recursive line
    }
}

void print_list_backwards(Node* head) {
    if (!head) {
        return;
    }
    else {
        print_list_backwards(head->next);         // recursive line
        std::cout << head->data << " ";
    }
}

Node* reverse_list(Node* head) {
    if (! head || !head->next) {
        return head;
    }
    else {
        Node* p = reverse_list(head->next);
        head->next->next = head;
        head->next = nullptr;

        return p;
    }
}

Node* swap_pairs(Node* head) {
    // base case: if list is empty or has only one node
    if (!head || !head->next) {
        return head;
    }
    // nodes to be swapped
    Node* first = head;
    Node* second = head->next;

    // recursively swap nodes starting from third node - third node becomes first->next
    first->next = swap_pairs(second->next);

    // swap nodes
    second->next = first;

    return second;
}