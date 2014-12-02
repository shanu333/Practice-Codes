#include <iostream>
#include <cstdio>

using namespace std;
struct node
{
    int data;
    int ht;
    struct node *left;
    struct node *right;
};
int abss(int a)
{
    return (a < 0)? -a: a;
}
struct node *new_node(int data)
{
    struct node *nn = new node();
    nn -> data = data;
    nn -> right = nn -> left = NULL;
    nn -> ht = 1;
    return nn;
}

int height(struct node *n)
{
    if (n == NULL) return 0;
    else if (n -> left == NULL && n -> right == NULL) return 1;
    else if (n -> left != NULL && n -> right == NULL) return 1 + n -> left -> ht;
    else if (n -> left == NULL && n -> right != NULL) return 1 + n -> right -> ht;
    else return 1 + max(n -> left -> ht, n -> right -> ht);
}
struct node *RightRotate(struct node *z)
{
    node *y = z -> left;
    node *t3 = y -> right;
    y -> right = z;
    z -> left = t3;

    z -> ht = max(height(z -> left), height(z -> right)) + 1;
    y -> ht = max(height(y -> left), height(y -> right)) + 1;
    return y;
};
struct node *LeftRotate(struct node *z)
{
    node *y = z -> right;
    node *t3 = y -> left;

    y -> left = z;
    z -> right = t3;

    z -> ht = max(height(z -> left), height(z -> right)) + 1;
    y -> ht = max(height(y -> left), height(y -> right)) + 1;
    return y;

};
struct node *insert(struct node *root, int data)
{
    if (root == NULL) {
        root = new_node(data);
    } else {
        if (root -> data > data) {
            root -> left = insert(root -> left, data);
        } else {
            root -> right = insert(root -> right, data);
        }
        root -> ht = height(root);
        if (abss(height(root -> left) - height(root -> right)) > 1) {
            // unbalanced case
            if (height(root -> left) - height(root -> right) > 1) {
                // left cases
                node *y = root -> left;
                if (height(y -> left) - height(y -> right) == 1) {
                    // left left case
                    root = RightRotate(root);
                } else {
                    // left right case
                    root -> left  = LeftRotate(root -> left);
                    root = RightRotate(root);
                }
            } else {
                // right cases
                node *y = root -> right;
                if (height(y -> left) - height(y -> right)== 1) {
                    // right left case
                    root -> right = RightRotate(root -> right);
                    root = LeftRotate(root);
                } else {
                    // right right case
                    root = LeftRotate(root);
                }
            }
        }
    }
    return root;
};

void inorder(struct node *p)
{
    if (p == NULL) {
        return;
    } else {
        inorder( p -> left);
        cout << p -> data << " " << p -> ht << endl;
        inorder(p -> right);
    }
}

int main()
{
    node *root = NULL;
    root = insert(root, 3);

    root = insert(root, 2);
    //cout << root -> data << endl;
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 5);
    inorder(root);

    return 0;
}
