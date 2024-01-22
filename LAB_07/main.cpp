#include <iostream>
#include <cstdlib>
#include <BST.h>

using namespace std;

int main()
{
    BST<int> tree;
    int i, num;
    int elements[100];      //for searching random elements
    for(i=0;i<100;i++)
    {
        elements[i]=rand()%100;
        tree.insert_node(elements[i]);
    }
    tree.search_node(elements[5]);
    tree.search_node(elements[40]);
    tree.search_node(elements[25]);
    tree.search_node(elements[80]);
    tree.search_node(300);              //not in tree
    tree.insert_node(400);
    tree.insert_node(500);
    tree.insert_node(323);
    tree.insert_node(300);              // added in tree
    tree.search_node(400);
    tree.search_node(500);
    tree.search_node(323);
    tree.search_node(300);
    tree.search_node(600);              //not in tree
    return 0;
}
