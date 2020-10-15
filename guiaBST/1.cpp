#include <iostream>
#include <string>
using namespace std;

struct nodeData {
  
    int data;

    nodeData() {}
    
    nodeData(int _data) : data(_data) {}

    bool operator<(const nodeData& r) {
        return this->data < r.data;
    }

    bool operator>(const nodeData& r) {
        return this->data > r.data;
    }

    bool operator==(const nodeData& r) {
        return this->data == r.data;
    }


    friend ostream& operator<<(ostream& os, const nodeData& p) {
        os << (p.data);
        return os;
    }

};
typedef nodeData T;

struct node {
    T info;
    node* left,* right;

    node() : left(NULL), right(NULL) {}
    node(T _info) : info(_info), left(NULL), right(NULL) {}

};

void inOrder(node* tree);
void preOrder(node* tree);
void postOrder(node* tree);
void insertInTree(T info, node** tree);
T inOrderSuccesor(node* rightTree);
void removeData(T e, node** tree) ;


int main(void) {
    node* tree = NULL;
    int n;


    insertInTree(T(22), &tree);
    insertInTree(T(23), &tree);
    insertInTree(T(256), &tree);
    insertInTree(T(12), &tree);
    insertInTree(T(7), &tree);
    insertInTree(T(22), &tree);
    insertInTree(T(3), &tree);
    insertInTree(T(44), &tree);


    cout << "******************** InOrder traversal ********************" << endl;
    inOrder(tree);
    cout << "\t" << endl;

    cout << "Inserte el nodo a eliminar " ;
    cin>> n;


    removeData(T(n), &tree);


    inOrder(tree);

    return 0;
}

/*
    Works for insertion in BST
    Receives T info to insert and double pointer node of root
    When tree is empty a node is created, otherwise searchs for 
    a correct insertion place depending of alphabetical order
*/
void insertInTree(T info, node** tree) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insertInTree(info, &(*tree)->left);
        else
            insertInTree(info, &(*tree)->right);
    }
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info << endl;
        inOrder(tree->right);
    }
}

void postOrder(node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->info << endl;
    }
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->info.data << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

/*
    InOrder succesor is the element most at to the left of right
    subtree, if left subtree of right subtree is empty then
    succesor is rightsubtree.info
*/
T inOrderSuccesor(node* rightTree) {
    node* aux = rightTree;

    while(aux->left != NULL) {
        aux = aux->left;
    }

    return aux->info;
}

void removeData(T e, node** tree) {
    if(*tree) {
        if(e < (*tree)->info) {
            removeData(e, &(*tree)->left);
        }
        else if (e> (*tree)->info) {
            removeData(e, &(*tree)->right);
        }
        else {
            // If node to be deleted is leaf
            if(!(*tree)->left && !(*tree)->right) {
                node* auxDelete = *tree;
                *tree = NULL;
                delete auxDelete;
            }
            // If tree only has right side
            else if(!(*tree)->left && (*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->right;
                delete root;
            }
            // If tree only has left side
            else if((*tree)->left && !(*tree)->right) {
                node* root = *tree;
                *tree = (*tree)->left;
                delete root;
            }
            // If tree is root
            else {
                // Find inorder succesor
                (*tree)->info = inOrderSuccesor((*tree)->right);
                // Delete inorder succesor
                removeData((*tree)->info, &(*tree)->right);
            }
            
        }
    }
}