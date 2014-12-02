#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
void print(int a[], int size);
void insert_heapify(int a[], int pos)
{
  //  cout << " pos = " << pos << << endl;
    int parent =  (pos - 1) / 2;
    if (pos == 0) return;
    if (a[parent] < a[pos]) {
        int temp = a[parent];
        a[parent] = a[pos];
        a[pos] = temp;
        insert_heapify(a, parent);
        return;
    }
}

void heapify(int a[], int size, int pos)
{
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;
    int max_elem = pos;
    if (lchild < size && a[max_elem] < a[lchild]) {
        max_elem = lchild;
    }
    if (rchild < size && a[max_elem] < a[rchild]) {
        max_elem = rchild;
    }
    if (max_elem != pos) {
        int temp = a[pos];
        a[pos] = a[max_elem];
        a[max_elem] = temp;
        heapify(a, size, max_elem);
        return;
    }

}

void insert(int a[], int &size, int elem)
{
    a[size] = elem;
    size++;
    print(a, size);
    insert_heapify(a, size - 1);
    print(a, size);
}

void delet(int a[], int &size)
{
    if (size == 0) return;
    int temp = a[0];
    a[0] = a[size - 1];
    a[size - 1] = temp;
    cout << a[size - 1] << "\n";
    heapify(a, size - 1, 0);
    size--;
}

void print(int a[], int size)
{
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[10] ;
    int size = 0;
    insert(a, size, 3);
    insert(a, size, 2);
    insert(a, size, 4);
    insert(a, size, 5);
   // insert(a, size, 1);
   // insert(a, size, 7);

   // print(a, size);
    delet(a, size);
    delet(a, size);
    delet(a, size);
    delet(a, size);
    delet(a, size);
    delet(a, size);



    return 0;
}
