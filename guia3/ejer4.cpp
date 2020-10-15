#include<iostream>
#include <string>
using namespace std;

struct node{
    int data;
    node* left,* right ;

    node() : left(NULL), right(NULL) {}
    node(int _data) : data(_data), left(NULL), right(NULL) {}
};

void inOrder(node*);
void preOrder(node*);
void postOrder(node*);
void insertTree(int, node**);
void traverseTree( node* );
int recursiveSize(node*);
void traverseInOrderIf(node*, int,int);


int main(void){

    node* tree = NULL;


    insertTree(30,&tree);
    insertTree(6,&tree);
    insertTree(8,&tree);
    insertTree(34,&tree);
    insertTree(1,&tree);
    insertTree(20,&tree);
    insertTree(35,&tree);
         

    cout << "El arbol es : " ;
    traverseTree(tree);
    cout << endl;
    cout << "El arbol tal que k1<= k <= k2  siendo k1 =15 y k2=33: " <<endl ; 
    traverseInOrderIf(tree, 15,33);
    cout << endl;

    cout << "******************** InOrder traversal ********************" << endl;
    inOrder(tree);
    cout << endl << endl;

    cout << "******************** PreOrder traversal ********************" << endl;
    preOrder(tree);
    cout << endl << endl;

    cout << "******************** PostOrder traversal ********************" << endl;
    postOrder(tree);
    cout << endl << endl;

    return 0;
}

void insertTree(int data, node** tree){
    if(!*tree){
        *tree = new node(data);
    }else{
        if(data < (*tree)->data){
            insertTree(data,&(*tree)->left);
        }else{
            insertTree(data,&(*tree)->right);
        }
    }
}

void traverseTree( node* tree){
    if(tree ==NULL){
        return;
    }else{    
        traverseTree(tree->right);
        cout << tree->data << " ";
        traverseTree( tree->left);
    }

}

void traverseInOrderIf(node* tree, int k1, int k2){
    if(tree){
        traverseInOrderIf(tree->left,k1,k2);
        if(tree->data <= k2 && tree->data >= k1){
            cout << tree->data << " " ;
        }
        traverseInOrderIf(tree->right,k1,k2);
    }
}

int recursiveSize(node* tree){

    if(tree != NULL){
    int left1 = recursiveSize(tree->left);
    int right1 = recursiveSize(tree->right);
    int medio = 1; // es la raiz

        return left1 + right1 + medio;
    }

    return 0;

}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->data << endl;
        inOrder(tree->right);
    }
}

void postOrder(node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data << endl;
    }
}

void preOrder(node* tree) {
    if(tree) {
        cout << tree->data << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
