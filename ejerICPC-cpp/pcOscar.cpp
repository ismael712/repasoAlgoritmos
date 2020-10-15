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

    string toString()
    {
        return this->name + ", " + to_string(this->len) + "\n";
    }
} T;

struct node
{
    T info;
    node *next, *prev;

    node() { next = prev = NULL; }
    node(T _info) : info(_info) { next = prev = NULL; }
};


void swap(T *a, T *b);
void pushBack(node **dl, T info);
void _quickSort(node*low, node*high, char Order);
void quickSort(node *head, char Order); // A for Asc or  D for Desc
node* lastNode(node *head);
node* partition(node *low, node *high);
void traverseOdd(node *list);
void traverseEven(node *list);
bool isPrime(int n);

int main(void)
{
    node *odd = NULL, *even = NULL, *prime = NULL;
    string auxCom = "";
    int n, auxLen; 

    cout<<isPrime(4);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> auxCom >> auxLen;

        if (auxLen == 0)
            pushBack(&even, T(auxCom, auxLen));
        else if (auxLen == 2)
            pushBack(&prime, T(auxCom, auxLen));
        else if(auxLen%2 == 0)
            pushBack(&even, T(auxCom, auxLen));
        else
            (isPrime(auxLen)) ?  pushBack(&prime, T(auxCom, auxLen)) : pushBack(&odd, T(auxCom, auxLen));
    }

    cout<<endl;
    cout<<"even"<<endl;traverseEven(even);cout<<endl;
    cout<<"odd"<<endl;traverseOdd(odd);cout<<endl;
    cout<<"prime"<<endl;traverseOdd(prime);cout<<endl;

}

void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

void pushBack(node **dl, T info)
{
    node *n = new node(info);

    if (!*dl)
        *dl = n;
    else
    {
        node *aux = *dl;

        while (aux->next)
            aux = aux->next;

        n->prev = aux;
        aux->next = n;
    }
}

void _quickSort(node *low, node *high, char Order)
{
    if (high && low != high && low != high->next)
    {
        node *pivot;

        if (Order == 'A')
            pivot = partition(low, high);
        else
            pivot = partition(low, high);

        _quickSort(low, pivot->prev, Order);
        _quickSort(pivot->next, high, Order);
    }
}

void quickSort(node *head, char Order)
{
    node *last = lastNode(head);

    _quickSort(head, last, Order);
}

node *lastNode(node *head)
{
    while (head && head->next)
        head = head->next;

    return head;
}

node *partition(node *low, node *high)
{
    T pivot = high->info;
    node *i = low->prev;

    for (node *j = low; j != high; j = j->next)
    {
        if (j->info <= pivot)
        {
            // equivalent to i++
            i = (!i) ? low : i->next;

            swap(&(i->info), &(j->info));
        }
    }

    // swap arr i + 1, arr high
    // return i + 1
    i = (!i) ? low : i->next;
    swap(&(i->info), &(high->info));
    return i;
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

void traverseOdd(node* list) {
    if(list){
        cout << list->info.name << "" << "\t" ;
        traverseOdd(list->next);
    }
    else{
        cout << endl << endl;
    }
}

void traverseEven(node* list) {
    if(list){
        cout << list->info.name << "" << "\t" ;
        traverseEven(list->prev);
    }
    else{
        cout << endl << endl;
    }
}