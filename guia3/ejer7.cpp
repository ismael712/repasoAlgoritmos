#include<iostream>
#include <string>
using namespace std;

struct node{
    char data;
    node* left,* right ;

    node() : left(NULL), right(NULL) {}
    node(char _data) : data(_data), left(NULL), right(NULL) {}
};

void insertTree(char, node**);
void traverseTree( node* );
void copyTree(node*, node**);

int main(void){

    node* treeA = NULL;
    node* treeB = NULL;


    insertTree('f',&treeA);
    insertTree('d',&treeA);
    insertTree('e',&treeA);
    insertTree('k',&treeA);
    insertTree('m',&treeA);
    insertTree('j',&treeA);
    insertTree('b',&treeA);
         

    cout << "El arbol A es : " ;
    traverseTree(treeA);
    cout << endl;
    copyTree(treeA,&treeB);


    cout << "La copia del arbol es : " ; 
    traverseTree(treeB);
    cout << endl;

    return 0;
}

void insertTree(char data, node** tree){
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

void copyTree(node* rootA, node** rootB){
    if(rootA){
        if(!*rootB){
            *rootB = new node(rootA->data);
            copyTree(rootA->left, &(*rootB)->left);
            copyTree(rootA->right, &(*rootB)->right);
        }else{
            if(rootA->data < (*rootB)->data){
                copyTree(rootA, &(*rootB)->left);
            }else{
                copyTree(rootA, &(*rootB)->right);
            }
        }
    }
}

