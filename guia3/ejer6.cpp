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
bool sameTree(node*,node*);

int main(void){

    node* tree1 = NULL;
    node* tree2 = NULL;
    int contador = 0;

    
    insertTree(30,&tree1);
    insertTree(6,&tree1);
    insertTree(8,&tree1);
    insertTree(34,&tree1);
    insertTree(1,&tree1);
    insertTree(3,&tree1);

    
    insertTree(30,&tree2);
    insertTree(6,&tree2);
    insertTree(8,&tree2);
    insertTree(34,&tree2);
    insertTree(1,&tree2);
    insertTree(2,&tree2);

    cout << "El arbol1 es : " <<endl ; 
    traverseTree(tree1, contador);
    cout << "-----------------------------" <<endl;
    cout << "El arbol2 es : " <<endl ; 
    traverseTree(tree2, contador);

    cout << "Son iguales? : " << (sameTree(tree1,tree2) ? "true" : "false") << endl << endl;
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
}

//funcion que compara los arboles
bool sameTree(node* root1, node* root2){

    if(!root1 && !root2 ){
        return 1;
    }
    else if(root1 && root2){
        if(root1->data == root2->data && 
            sameTree(root1->left,root2->left) &&
            sameTree(root1->right,root2->right)){
                return 1;
        }
    }
    return 0;
}