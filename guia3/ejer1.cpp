#include <iostream>

using namespace std;

typedef struct  node
{
    char data;
    node* left, *right;

    node(){
        left = right = NULL;
    }
    node(char _data): data(_data) {
        left = right = NULL;
    }

}T;

int charToInt(char);
char intToChar(int);
void insert(char, T**);
void inOrder(T*);
float resolveOperation(T*);
void search(T, T*);
void preOrder(T*);

int main(void)
{
    T *tree = NULL;

    insert('*',&tree);
    insert('+',&tree);
    insert('/',&tree);
    insert('c',&tree);
    insert('a',&tree);
    insert('b',&tree);
    insert('-',&tree);
    insert('d',&tree);
    insert('e',&tree);

    inOrder(tree);

    cout<<endl<<endl;

    search(T('/'), tree); cout<<endl;
    search(T('-'), tree); cout<<endl;
    search(T('+'), tree); cout<<endl;
    search(T('*'), tree); cout<<endl;

    cout<<endl;

    return 0;
}

int charToInt(char c){
    switch(c) {
            case 'a':
                return 1;
            case '/':
                return 2;
            case 'b':
                return 3;
            case '+':
                return 4;
            case 'c':
                return 5;
            case '*':
                return 6;
            case 'd':
                return 7;
            case '-':
                return 8;
            case 'e':
                return 9;
        default:
            return 0;
    }
}

char IntToChar(int n) {
    switch(n) {
        case 1:
            return 'a';
        case 2:
            return '/';
        case 3:
            return 'b';
        case 4:
            return '+';
        case 5:
            return 'c';
        case 6:
            return '*';
        case 7:
            return 'd';
        case 8:
            return '-';
        case 9:
            return 'e';
        default:
            return '0';
    }
}

void insert(char info, T** tree){
    if(!*tree){
        *tree = new T(info);
    }else{
        if (charToInt(info) < charToInt((*tree)->data))
            insert(info, &(*tree)->left);
        else
            insert(info, &(*tree)->right);
    }
}

void inOrder(T* tree){
    if(tree){
        inOrder(tree->left);
        cout << tree->data << "  ";
        inOrder(tree->right);
    }
}

void search(T nod, T* tree){

    if(tree){
        if(charToInt(nod.data) < charToInt(tree->data)){
            search(nod, tree->left);
        }else{
            if(charToInt(nod.data) > charToInt(tree->data)){
                search(nod, tree->right);
            }else{
                //He encontrado el arbol
                cout << resolveOperation(tree);
            }
        }
    }
}

float resolveOperation(T* subTree){

    if(subTree->left){

        switch(subTree->data){

        case '/':
            return 1.0 * resolveOperation(subTree->left) / resolveOperation(subTree->right);
        case '+':
            return 1.0 * resolveOperation(subTree->left) + resolveOperation(subTree->right);
        case '-':
            return 1.0 * resolveOperation(subTree->left) - resolveOperation(subTree->right);
        case '*':
            return 1.0 * resolveOperation(subTree->left) * resolveOperation(subTree->right);
        
        default: 
            return 0.0;
        }

    }else{
        return charToInt(subTree->data);
    }
}

void preOrder(T* tree){
    if(tree){
        cout << tree->data << "  ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}