#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

struct node
{
    string element;
    node *left;
    node *right;
};

stack<node *> s;

void postfix2exptree(string postfix)
{

	struct node *newnode = NULL;
	struct node *op1 = NULL;
	struct node *op2 = NULL;

	for (int i = 0; i < postfix.size(); i++) {
		if(isalpha(postfix[i]) || isdigit(postfix[i])) {
			// operand case
			newnode = new node();
			newnode->element = postfix[i];
			newnode->left = NULL;
			newnode->right = NULL;
			s.push(newnode);
		} else {
		    // operator case
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			newnode = new node();
			newnode->element = postfix[i];
			newnode->left = op2;
			newnode->right = op1;
			s.push(newnode);
		}
	}
}

void inorder(struct node *x)
{
	if(x != NULL)
	{
		inorder(x->left);
		cout << x->element << " ";
		inorder(x->right);
	}
}

void preorder(struct node *x)
{
	if(x != NULL)
	{
		cout << x->element << " ";
		preorder(x->left);
		preorder(x->right);
	}
}

void postorder(struct node *x)
{
	if(x != NULL)
	{
		postorder(x->left);
		postorder(x->right);
		cout << x->element << " ";
	}
}

int main()
{
    string s1 = "ABC*+";
    postfix2exptree(s1);
    node* root = s.top();
    cout << "inorder " << endl;
    inorder(root);
    cout << "\npre order " << endl;
    preorder(root);
    cout << "\npost order " << endl;
    postorder(root);
    return 0;
}
