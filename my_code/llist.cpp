#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    os << "data: " << nd->data;
    if (!nd) {
        os << " next: " << nd->next;
    }
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!(head->next)) {
        head->next = new Node(d, nullptr);
    }
    else add_at_end(head->next, d);
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    if (curr){
        os << curr << " ";
        print_list(os, curr->next);
    }
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    Node* new_head = new Node(d, head);
    head = new_head;
}

/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if (!head) return nullptr;
    else if (!(head->next)) return head;
    else {
        return last(head->next);
    }
}

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head){
    if (!head) return false;
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& head){
    if (!head) return false; //checks for empty llist
    else if (head->next == nullptr) { //checks for list of size one
        Node* temp = head;
        head = nullptr;
        delete temp;
        return true;
    }
    else if (head->next->next == nullptr) { //next = last
        delete head->next;
        head->next = nullptr;
        return true;
    }
    else return del_tail(head->next);
}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head){
    if (!head) return head;
    else {
        Node* new_head = new Node(head->data, duplicate(head->next));
        return new_head;
    }
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next){
    if (!curr->next) {
        Node* new_curr = new Node(curr->data, curr->next);
        new_curr->next = new_next;
        return new_curr;
    }
    else {
        Node* new_curr = new Node(curr->data, curr->next);
        Node* temp = new_curr->next;
        new_curr->next = new_next;
        new_next = new_curr;
        new_curr = temp;
        return reverse(new_curr, new_next);
    }
}
/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2){
    last(list1)->next = list2;
    return list1;
}