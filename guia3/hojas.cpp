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
void traverseTree( node*);
void treeLeaves(node*);


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
         


    cout << "El arbol es : "  ; 
    traverseTree(tree);
    cout << endl;

    cout << "Las hojas son : " ;
    treeLeaves(tree);


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

void treeLeaves(node* tree)
{
 if(tree!=NULL){
    treeLeaves(tree->left);
    treeLeaves(tree->right);
    if(tree->right==NULL && tree->left==NULL){
        cout<<tree->data<<" ";
        }
   }
}