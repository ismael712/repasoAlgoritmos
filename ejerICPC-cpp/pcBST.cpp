#include <iostream>
#include <cmath>

using namespace std;

typedef struct component
{
    string name;
    int len;

    component() {}
    component(string _name, int _len) : name(_name), len(_len) {}

    bool operator<=(const component &r)
    {
        return this->len <= r.len;
    }

    bool operator>=(const component &r)
    {
        return this->len >= r.len;
    }

    bool operator<(const component &r)
    {
        return this->len < r.len;
    }

    bool operator>(const component &r)
    {
        return this->len > r.len;
    }

    string toString()
    {
        return this->name + ", " + to_string(this->len) + "\n";
    }
} T;

struct node {
    T info;
    node* left,* right;

    node() : left(NULL), right(NULL) {}
    node(T _info) : info(_info), left(NULL), right(NULL) {}
};


bool isPrime(int n);
void insertInTree(node** tree, T info);
void inOrder(node* tree);
void inOrderReverse(node* tree);

int main(void)
{
    node *odd = NULL, *even = NULL, *prime = NULL;
    string auxCom = "";
    int n, auxLen; 

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> auxCom >> auxLen;

        if (auxLen == 0)
            insertInTree(&even, T(auxCom, auxLen));
        else if (auxLen == 2)
            insertInTree(&prime, T(auxCom, auxLen));
        else if(auxLen%2 == 0)
            insertInTree(&even, T(auxCom, auxLen));
        else
            (isPrime(auxLen)) ?  insertInTree(&prime, T(auxCom, auxLen)) : insertInTree(&odd, T(auxCom, auxLen));
    }

    cout<<endl;
    cout<<"ODD"<<endl; inOrder(odd); cout<<endl;
    cout<<"EVEN"<<endl; inOrderReverse(even); cout<<endl;
    cout<<"PRIME"<<endl; inOrder(prime); cout<<endl;


}

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}


void insertInTree(node** tree, T info ) {
    if(!*tree)
        *tree = new node(info);
    else {
        if(info < (*tree)->info)
            insertInTree(&(*tree)->left, info);
        else
            insertInTree(&(*tree)->right, info);
    }
}

void inOrder(node* tree) {
    if(tree) {
        inOrder(tree->left);
        cout << tree->info.toString();
        inOrder(tree->right);
    }
}

void inOrderReverse(node* tree) {
    if(tree) {
        inOrderReverse(tree->right);
        cout << tree->info.toString();
        inOrderReverse(tree->left);
    }
}