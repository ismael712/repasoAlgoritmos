#include<iostream>
#include <string>
using namespace std;

struct node{
    int data;
    node* left,* right ;

    node() : left(NULL), right(NULL) {}
    node(int _data) : data(_data), left(NULL), right(NULL) {}
};

void insertTree(int, node**);
void traverseTree( node*, int );
int recursiveSize(node*);

int main(void){

    node* tree = NULL;
    int contador = 0;

    insertTree(30,&tree);
    insertTree(6,&tree);
    insertTree(8,&tree);
    insertTree(34,&tree);
    insertTree(1,&tree);
    insertTree(3,&tree);
    insertTree(35,&tree);
         


    cout << "El arbol es : " <<endl ; 
    traverseTree(tree, contador);
    cout << "\n" ;

    cout << "Los nodos son : " ;
    cout << recursiveSize(tree) <<endl;


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

void traverseTree( node* tree,int num){
    if(tree ==NULL){
        return;
    }else{    
        traverseTree(tree->right,num + 1);
        for(int i = 0; i < num ; i++){
            cout <<"    ";
        }
        cout << tree->data <<endl;
        traverseTree( tree->left, num + 1);
    }
    cout << endl;

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

//calculando hojas
/*
int recursiveSizeH(node* tree){

    if(tree == NULL){
        return 0;
    }else{
        return recursiveSizeH(tree->left) + recursiveSizeH(tree->right);
    }
    */