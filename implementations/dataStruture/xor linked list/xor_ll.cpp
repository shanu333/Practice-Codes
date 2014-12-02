#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int data;
    struct node *npx; // xor of next and previous node
};

struct node* XOR(struct node *a, struct node *b)
{
    return (struct node *)((unsigned int) (a) ^ (unsigned int) (b));
};

void insert_at_begining(struct node **head, int data, struct node **tail)
{
    // create new node to insert
    struct node *new_node = new node();
    new_node -> data = data;

    new_node -> npx = XOR(NULL, *head);

    //update the previous head pointer
    if ((*head) != NULL) {
        struct  node * next = XOR((*head) -> npx, NULL);
        (*head) -> npx = XOR(new_node, next);
    } else {
        *tail = *head;
    };
    *head = new_node;

}


void insert_at_ending(struct node **head, int data, struct node **tail)
{
    // create new node to insert
    struct node *new_node = new node();
    new_node -> data = data;

    if (*head == NULL) {
        insert_at_begining(&(*head), data, &(*tail));
        return;
    }
    node *current = *head;
    node *prev = NULL;
    node *next = NULL;
    while (XOR(prev, current -> npx) != NULL) {
        next = XOR(prev, current -> npx);
        prev = current;
        current = next;


    }
    current -> npx = XOR(prev, new_node);
    new_node -> npx = XOR(current, NULL);
    *tail = new_node;
}
void insert_at_n(struct node **head, int data, struct node **tail, int n)
{
    // create new node to insert
    struct node *new_node = new node();
    new_node -> data = data;

    node *current = *head;
    node *prev = NULL;
    node *prev_prev = NULL;
    node *next_next = NULL;
    node *next = NULL;
    int i = 0;
    if (n == 0) {
        insert_at_begining(&(*head), data, &(*tail));
        return;
    }
    while ( i < n ) {
        next = XOR(prev, current -> npx);
        prev = current;
        current = next;
        i++;
    }

    if (next == NULL ) {
        cout <<" i = " <<  i <<endl;
        insert_at_ending(&(*head), data, &(*tail));
        return;
    }
    // obtain address
    next_next = XOR(prev, next -> npx);
    prev_prev = XOR(next, prev -> npx);
    //preforms insertion
    prev -> npx = XOR(prev_prev, new_node);
    new_node -> npx = XOR(prev, next);
    next -> npx = XOR(next_next, new_node);


    //*tail = new_node;
}

void print(struct node *head)
{
    node *current = head;
    node *prev = NULL;
    node *next;
    cout << "list contains : \n";
    while(current != NULL) {
        cout << current -> data << " ";
        next = XOR(prev, current -> npx);
        prev = current;
        current = next;
    }
    cout << endl;

}
void print_reverse(struct node *tail)
{
    node *current = tail;
    node *prev = NULL;
    node *next;
    cout << "list contains : \n";
    while(current != NULL) {
        cout << current -> data << " ";
        next = XOR(prev, current -> npx);
        prev = current;
        current = next;
    }
    cout << endl;

}


void delete_at_begining(struct node **head, struct node **tail)
{
   if ((*head) == NULL) {
        cout << "list is empty";
        return;
   } else if (XOR(NULL, (*head) -> npx) == NULL) {
        (*head) = NULL;
        (*tail) = NULL;
        return;
   } else {
        //cout << "head = " << (*head) -> data << endl;
        node *next = XOR(NULL, (*head) -> npx);
        //cout << "next = " << (next) -> data << endl;
        node *next_next = XOR((*head), (next) -> npx);
        //cout << "next_next = " << (next_next) -> data << endl;
        next-> npx = XOR(NULL, next_next);
        *head = next;
        if (XOR(*head, (*head) -> npx) == NULL) {
            *tail = (*head);
        }


   }

}


int main()
{
    struct node  *head = NULL;
    struct node *tail = NULL;
    insert_at_ending(&head, 0, &tail);
    insert_at_ending(&head, 10, &tail);
    insert_at_ending(&head, 2, &tail);
    insert_at_ending(&head, 30, &tail);
    print(head);
    insert_at_n(&head, 40, &tail, 0);
    print(head);
    print_reverse(tail);
    delete_at_begining(&head, &tail);
    print(head);
    print_reverse(tail);
    delete_at_begining(&head, &tail);
    print(head);
    print_reverse(tail);
    delete_at_begining(&head, &tail);
    print(head);
    print_reverse(tail);delete_at_begining(&head, &tail);
    print(head);
    print_reverse(tail);
    delete_at_begining(&head, &tail);
    print(head);
    print_reverse(tail);
   // print_reverse(tail);

    return 0;
}
