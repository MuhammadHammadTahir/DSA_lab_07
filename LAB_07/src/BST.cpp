#include "BST.h"
#include <iostream>

using namespace std;
template <class T>
BST<T>::BST()
{
    root=NULL;          //initillization
}

template <class T>
BST<T>::~BST()                  //free up space
{
    delete_nodes(root);
}

template <class T>
void BST<T>::search_node(T x)       //ADT function for search element
{
    typename BST<T>::node* value=search_node(x, root);
    if(value==NULL)
    {
        cout<<"\n ["<<x<<"] Required number is not found\n";
    }
    else
    {
        cout<<"\n ["<<x<<"] Required number is found\n";
    }
}

template <class T>
void BST<T>::insert_node(T x)       //ADT function for insert element
{
    insert_node(x, root);
}

template <class T>
typename BST<T>::node* BST<T>::search_node(T x,node*& root)         //implementation function for searching element
{
    if(root==NULL)
    {
        return NULL;
    }
    else
        {
            if(x<root->data)
            {
               search_node(x,root->left);
            }
            else
            {
                if(x>root->data)
                {
                    search_node(x,root->right);
                }
                else
                    return root;
            }
        }
}
template <class T>
void BST<T>::insert_node(T x,node*& root)               //implementation function for inserting element
{
    if(root==NULL)
    {
        root=new node;
        root->data=x;
        root->left=NULL;
        root->right=NULL;
    }
    else
        {
            if(x<root->data)
            {
                insert_node(x,root->left);
            }
            else
            {
                if(x>root->data)
                {
                    insert_node(x,root->right);
                }
            }

        }
}

template <class T>
void BST<T>:: remove_node(T x)      //ADT function for remove element
{
    remove_node(x,root);
}

template <class T>
typename BST<T>::node* BST<T>:: findMin(node* root)         //for finding minimum element for two child case
{
    if(root!=NULL)
    {
        findMin(root->left);
    }
    else
    {
        return root;
    }
}

template <class T>
void BST<T>:: remove_node(T x,node*& root)                  //implementation function for removing element
{
    if(root!=NULL)
    {
        if(x<root->data)
        {
            remove_node(x, root->left);
        }
        else
        {
            if(x>root->data)
            {
                remove_node(x, root->right);
            }
            else
            {
                if(root->left!=NULL && root->right!=NULL)
                {
                    root->data=findMin(root->right)->data;
                    remove_node(root->data,root->right);
                }
                else
                {
                    node* oldNode = root;
                    root = (root->left != NULL) ? root->left : root->right;
                    delete oldNode;
                }
            }
        }
    }
}

template <class T>
void BST<T>::delete_nodes(node*& root)              //implementation for free-up space
{
    if(root!=NULL)
    {
        delete_nodes(root->left);
        delete_nodes(root->right);
        delete_nodes(root);
    }
    else
    {
        delete root;
    }
}

