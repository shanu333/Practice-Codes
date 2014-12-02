#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int i;
    struct node * left;
    struct node *right;
};

class BST
{
public :
        node *root;
        BST(){
            (root) = NULL;
        }
        void insert(int data, struct node **root) {
            if (*root == NULL) {
                (*root) = new node();
                (*root) -> i = data;
                (*root) -> left = NULL;
                (*root) -> right = NULL;
            } else if ((*root) -> i < data) {
                insert(data, &((*root) -> right));
            } else {
                insert(data, &((*root) -> left));
            }
        }
        bool search(int data, struct node *root)
        {
            if (root == NULL) {
                return false;
            } else if (root -> i == data) {
                return true;
            } else if (root -> i < data){
                return search(data, root -> right);
            } else {
                return search(data, root -> left);
           }

        }
        void print(struct node *head) {
            if ((head) != NULL) {
                print(head -> left);
                cout << (head) -> i <<  " ";
                //print(head -> left);
                print(head -> right);
            }
        }
        void delete_it(int data, struct node **root)
        {
            if ((*root) == NULL) {
                return ;
            } else if ((*root) -> i == data) {
                // delete this node
                if ((*root) -> left == NULL && (*root) -> right == NULL) {
                    (*root) = NULL;
                } else if ((*root) -> left != NULL && (*root) -> right == NULL) {
                    // only left child
                    (*root) = (*root) -> left;
                } else if ((*root) -> left == NULL && (*root) -> right != NULL) {
                    // only right child
                    (*root) = (*root) -> right;
                } else {
                    cout << "asdf";
                    // both child
                    node *rt = (*root) -> right;
                    if (rt -> left == NULL ){
                        (*root) -> i = rt -> i;
                        (*root) -> right = (*root) -> right -> right;
                        return;
                    } else {
                        while (rt -> left -> left != NULL) {
                            rt = rt -> left;
                        }
                        (*root) -> i = rt -> left -> i;
                        rt -> left = rt -> left -> right;
                    }

                }

            } else if ((*root) -> i < data){
                return delete_it(data, &((*root) -> right));
            } else {
                return delete_it(data, &((*root) -> left));
           }

        }

};

int main()
{
    BST b;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
       cin >> k;
       b.insert(k, &b.root);
    }
    b.print(b.root);
    cout << endl << b.search(2, b.root) << endl;
    cout << "enter number of queries" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "enter what to del\n";
        cin >> k;
        b.delete_it(k, &b.root);
        cout << endl;
        b.print(b.root);
    }

    return 0;
}
