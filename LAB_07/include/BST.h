#ifndef BST_H
#define BST_H

template <class T>
class BST
{
    public:
        BST();
        virtual ~BST();
        void search_node(T x);
        void insert_node(T x);
        void remove_node(T x);

    private:
        struct node
        {
            T data;
            node* left;
            node* right;
        };
        node*root;
        void  remove_node(T x,node*& root);
        node* findMin(node* root);              //for two child case
        node* search_node(T x,node*& root);
        void insert_node(T x,node*& root);
        void delete_nodes(node*& root);         // to free up space
};

#endif // BST_H
