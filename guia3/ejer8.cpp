#include <iostream>
using namespace std;

struct node{
    int data;
    node* left,* right;

    node(): left(NULL), right(NULL){};
    node(int _data) : data(_data), left(NULL), right(NULL){}
};

void insertTree(int, node**);
void traverseTree(node*, int);
void treeForOneLevel(node*, int);

int main(void){

    node* tree = NULL;

    
    insertTree(30,&tree);
    insertTree(6,&tree);
    insertTree(8,&tree);
    insertTree(34,&tree);
    insertTree(1,&tree);
    insertTree(3,&tree);
    insertTree(35,&tree);



    cout << "Imprimiendo un nivel : " ;
    treeForOneLevel(tree,3);
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
}

void treeForOneLevel(node* tree, int nivel){
    if(tree){
        if(nivel == 0){
            cout << tree->data << "  " ;
        }
        treeForOneLevel(tree->left, nivel - 1);
        treeForOneLevel(tree->right, nivel - 1);
    }
}

