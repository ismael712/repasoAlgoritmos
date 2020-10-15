#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct nodeData{
    char c;
    int value;
    nodeData(){};
    nodeData(char _data, int _value): c(_data), value(_value) {}
    nodeData (const nodeData& n) : c(n.c), value(n.value) {}
} I;

typedef struct  node
{
    I data;
    node* left, *right;

    node(){
        left = right = NULL;
    }
    node(I _data): data(_data) {
        left = right = NULL;
    }

}T;

void insert(char, T**);
void inOrder(T*);
void preOrder(T*);
void postOrder(T*);
void getTree(string, string);
void insertInTree(I, T**);


int main(void)
{

    string pre, in;
    
    cin >> pre >> in;

    getTree(pre, in);

    return 0;
}


void getTree(string pre, string in){

    T* tree = NULL;

    vector<nodeData> vct;
    vector<nodeData>::iterator it;

    int n = pre.length();

    for(int i = 0; i < n ; i++)
        vct.push_back(I(pre[i], in.find(pre[i])));
    

    for(it = vct.begin(); it != vct.end(); it++)
        insertInTree((*it), &tree);
    
    inOrder(tree); cout<<endl;
    preOrder(tree); cout<<endl;
    postOrder(tree); cout<<endl;
}

void insertInTree(I data, T** tree) {
    if(!*tree)
        *tree = new T(data);
    else {
        if(data.value < (*tree)->data.value)
            insertInTree(data, &(*tree)->left);
        else
            insertInTree(data, &(*tree)->right);
    }
}

void preOrder(T* tree){
    if(tree){
        cout << tree->data.c << "  ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}


void inOrder(T* tree){
    if(tree){
        inOrder(tree->left);
        cout << tree->data.c << "  ";
        inOrder(tree->right);
    }
}

void postOrder(T* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data.c << "  ";
    }
}