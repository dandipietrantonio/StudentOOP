#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    os << "data: " << nd.data << "next: " << nd.next;
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head) head->next = Node(d);
    else add_at_end(head->next);
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    if (!curr){
        cout << curr << " ";
        print_list(curr->next)
    }
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    new_front = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (!(head->next)) last(head->next);
    else return head;
}