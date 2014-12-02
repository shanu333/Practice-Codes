#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
struct node
{
    char data;
    int is_end_of_string;
    struct node *a[26];
};
struct node *new_node(char c)
{
    node *p = new node();
    p -> data = c;
    p -> is_end_of_string = 0;
    for (int i = 0; i < 26; i++) {
        p -> a[i] = NULL;
    }
    return p;
};
struct node *insert(node *root, string s)
{
    int i = 0;
    node *p = root;

    if (root == NULL){
        root = new_node('A');
        root -> a[s[0] - 'a'] = new_node(s[0]);
    } else {
        if (root -> a[s[0] - 'a'] == NULL) {
            root -> a[s[0] - 'a'] = new_node(s[0]);
        }
    }

    p = root -> a[s[0] - 'a'];
    for (i = 1; i < (int)s.size() - 1; i++) {

        if (p -> a[s[i] - 'a'] == NULL) {
            p -> a[s[i] - 'a'] = new_node(s[i]);
        }
        p =  p -> a[s[i] - 'a'];

    }
   // cout << p -> data << endl;
    if (s.size() > 1) {
        if ( p -> a[s[i] - 'a'] == NULL) {
            p -> a[s[i] - 'a'] = new_node(s[i]);
        }
        p =  p -> a[s[i] - 'a'];
    }

    p -> is_end_of_string = 1;

    return root;
}

bool search(node *root, string s)
{
    int i;
    if (root == NULL) {
        return false;
    }
    node *p = root;
    for (i = 0; i < s.size(); i++) {
        if (p -> a[s[i] - 'a'] == NULL) {
            return false;
        }
        p = p -> a[s[i] - 'a'];
    }
    if (p -> is_end_of_string == 1) {
        return true;
    } else
        return false;
}

struct node *haha(node *root, string s)
{
    node *p = insert(root, s);
    root = p;
    if (search(root, s)) {
        cout << "Yes\n";
    } else{
        cout << "No\n";
    }
    return p;
}

int main()
{
    node *root = NULL;
    root = haha(root, "abc");
    root = haha(root, "ac");
    root = haha(root, "ab");
    root = haha(root, "cb");
    root = haha(root, "c");


    return 0;
}
