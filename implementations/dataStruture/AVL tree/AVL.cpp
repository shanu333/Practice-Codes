#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int i;
    int height;
    struct node * left;
    struct node *right;
};

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int height(node *a)
{
    if (a == NULL) {
        return 0;
    }
    return a -> height;
}
int getBalance(node *a)
{
    if (a == NULL) {
        return 0;
    } else {
        return height(a -> left) - height(a -> right);
    }
}

struct node *RightRotate(node *z)
{
    node *y = z -> left;
    node *t2 = y -> right;

    y -> right = z;
    z -> left = t2;

    /** !!!! CAUTION !!!!!!!!! **/
    /** !!! Don't update the height of node y first !!!! **/
    z -> height = max(height(z -> left), height(z -> right)) + 1;
    y -> height = max(height(y -> left), height(y -> right)) + 1;
    return y;
}

struct node *LeftRotate(node *z)
{
    node *y = z -> right;
    node *t2 = y -> left;

    y -> left = z;
    z -> right = t2;
    z -> height = max(height(z -> left), height(z -> right)) + 1;
    y -> height = max(height(y -> left), height(y -> right)) + 1;
    return y;
};

class AVL
{
public :
        node *root;
        AVL(){
            (root) = NULL;
        }

        void insert(int key, struct node **root) {
            if (*root == NULL) {
                (*root) = new node();
                (*root) -> i = key;
                (*root) -> left = NULL;
                (*root) -> right = NULL;
                (*root) -> height = 1;
            } else if ((*root) -> i < key) {
                insert(key, &((*root) -> right));
            } else {
                insert(key, &((*root) -> left));
            }
            /** update the height **/
            (*root)-> height = max(height((*root)-> left), height((*root)-> right)) + 1;
            /** .....check for balance ...**/
            int balance = getBalance((*root));

            if (balance > 1) {
                cout << "balance " << balance << endl;
                // left part is more than right one
                if (key < (*root)-> left -> i) {
                    cout << "left left" << endl;
                    // left left case
                    /** perform a right rotation **/
                   (*root) =  RightRotate((*root));

                } else {
                    cout << "left right" << endl;
                    // left right case
                    /** perform a left rotate on left child **/
                    (*root) -> left = LeftRotate((*root) -> left);
                    /** perform a left rotate on left child **/
                    (*root) = RightRotate((*root));

                }
            } else if (balance < -1) {
                cout << "balance " << balance << endl;
                // right part is more than left one
                if (key < (*root) -> right -> i) {
                    cout << "right left" << endl;
                    // right left case
                    (*root) -> right = RightRotate((*root) -> right);
                    (*root) = LeftRotate((*root));
                } else {
                    cout << "right right" << endl;
                    //int old = (*root) -> i, h1 = (*root) -> height;
                    // right right case
                    /** perform a left rotation **/
                   (*root) = LeftRotate((*root));
//                    cout << endl;print(*root);cout << endl;;
//                    cout << "After roatation data of this node change from " <<  old << " to " << (*root) -> i;
//                    cout << " and height  change from " <<  h1 << " to " << (*root) -> height << endl;
                }
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
                //print(head -> left);
                cout << (head) -> i <<  " ";
                print(head -> left);
                print(head -> right);
            }
        }
        void delete_it(int key, struct node **root)
        {
            if ((*root) == NULL) {
                return ;
            } else if ((*root) -> i == key) {
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

            } else if ((*root) -> i < key){
                return delete_it(key, &((*root) -> right));
            } else {
                return delete_it(key, &((*root) -> left));
           }
            if((*root) == NULL) {
                return;
            }
            /** update the height **/
            (*root)-> height = max(height((*root)-> left), height((*root)-> right)) + 1;
            /** .....check for balance ...**/
            int balance = getBalance((*root));

            if (balance > 1) {
                cout << "balance " << balance << endl;
                // left part is more than right one
                if (key < (*root)-> left -> i) {
                    cout << "left left" << endl;
                    // left left case
                    /** perform a right rotation **/
                   (*root) =  RightRotate((*root));

                } else {
                    cout << "left right" << endl;
                    // left right case
                    /** perform a left rotate on left child **/
                    (*root) -> left = LeftRotate((*root) -> left);
                    /** perform a left rotate on left child **/
                    (*root) = RightRotate((*root));

                }
            } else if (balance < -1) {
                cout << "balance " << balance << endl;
                // right part is more than left one
                if (key < (*root) -> right -> i) {
                    cout << "right left" << endl;
                    // right left case
                    (*root) -> right = RightRotate((*root) -> right);
                    (*root) = LeftRotate((*root));
                } else {
                    cout << "right right" << endl;
                    //int old = (*root) -> i, h1 = (*root) -> height;
                    // right right case
                    /** perform a left rotation **/
                   (*root) = LeftRotate((*root));
//                    cout << endl;print(*root);cout << endl;;
//                    cout << "After roatation data of this node change from " <<  old << " to " << (*root) -> i;
//                    cout << " and height  change from " <<  h1 << " to " << (*root) -> height << endl;
                }
            }
        }

};

int main()
{
    AVL b;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
       cin >> k;
       b.insert(k, &b.root);
    }
    b.print(b.root);
   // cout << endl << b.search(2, b.root) << endl;
    cout << "enter number of queries for del" << endl;
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
