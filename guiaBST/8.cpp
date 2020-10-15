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
    
    bool operator+(const nodeData& r) {
        return this->data + r.data;
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

void travelInOrder(node* tree);
void travelPreOrder(node* tree);
void travelPostOrder(node* tree);
void insertInTree(T info, node** tree);
T travelInOrderSuccesor(node* rightTree);
void findtravelInOrderSuccesor(T e, node* tree);



int main(void) {
    node* tree = NULL;
    node* suc;
 
    int n;


    insertInTree(T(22), &tree);
    insertInTree(T(23), &tree);
    insertInTree(T(256), &tree);
    insertInTree(T(12), &tree);
    insertInTree(T(7), &tree);
    insertInTree(T(77), &tree);
    insertInTree(T(3), &tree);
    insertInTree(T(15), &tree);
    insertInTree(T(9), &tree);
    insertInTree(T(8), &tree);


    cout << "******************** travelInOrder traversal ********************" << endl;
    travelInOrder(tree);

    cout << "Numero al cual desea encontrar el sucesor? " ;
    cin>> n;

    findtravelInOrderSuccesor(T(n),tree);

    cout << "******************** travelInOrder traversal ********************" << endl;
    travelInOrder(tree);

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

void travelInOrder(node* tree) {
    if(tree) {
        travelInOrder(tree->left);
        cout << tree->info << endl;
        travelInOrder(tree->right);
    }
}

void travelPostOrder(node* tree) {
    if(tree) {
        travelPostOrder(tree->left);
        travelPostOrder(tree->right);
        cout << tree->info << endl;
    }
}

void travelPreOrder(node* tree) {
    if(tree) {
        cout << tree->info << endl;
        travelPreOrder(tree->left);
        travelPreOrder(tree->right);
    }
}

/*
    travelInOrder succesor is the element most at to the left of right
    subtree, if left subtree of right subtree is empty then
    succesor is rightsubtree.info
*/
T travelInOrderSuccesor(node* rightTree) {
    node* aux = rightTree;

    while(aux->left != NULL) {
        aux = aux->left;
    }
    return aux->info;
}

void findtravelInOrderSuccesor(T e, node* tree) {
    if(tree) {
        if(e < (tree)->info) {
            findtravelInOrderSuccesor(e, tree->left);
        }
        else if (e > (tree)->info) {
            findtravelInOrderSuccesor(e, tree->right);
        }
             // If tree is root
        else {
                 if(!tree->left && tree->right) {
                cout << "El inorden sucesor de " << e << " es " << (tree)->info + 1 ; 
            }else{
                tree->info = travelInOrderSuccesor(tree->right);
                cout << "El inorden sucesor de " << e << " es " << (tree)->info;
            }
        }
    }
}