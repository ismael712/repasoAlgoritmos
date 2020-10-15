#include <cmath>
#include <iostream>
using namespace std;

typedef struct component {
    string name;
    int len;

    component() {}
    component(string _name, int _len) : name(_name), len(_len) {}

    bool operator>=(const component& r){
        return this->len > r.len;
    }
     bool operator<=(const component& r){
        return this->len < r.len;
    }

        friend ostream& operator<<(ostream& os, const component& p) {
        os << (p.name );
        return os;
    }

}T;

struct node {
    T info;
    node* next,* prev;

    node() { next = prev = NULL; }
    node(T _info) : info(_info) { next = prev = NULL; }
};

bool isPrime(int n);

void swap(T* a, T* b);

void pushBack(node** dl, T info);
void _quickSort(node* low, node* high);
node* lastNode(node* head);
node* partition(node* low, node* high);
void quickSort(node* head); 
void travelListOdd(node* list);
void travelListEven(node* list);


int main(void) {
     node* odd,* even,* prime = NULL;
    int n = 0, auxLen = 0;
    string auxCom = "";

    cin>> n;

    for(int i = 0 ; i < n ; i++){
        cin >> auxCom >> auxLen ;
      
        if(auxLen == 0){
              pushBack(&even,T(auxCom,auxLen));
        }else if(isPrime(auxLen)){
            pushBack(&prime,T(auxCom,auxLen));
        }else{
            (auxLen % 2 == 0) ? pushBack(&even,T(auxCom,auxLen)) : pushBack(&odd,T(auxCom,auxLen));
        }
    }

    quickSort(even); // DESC
    quickSort(odd); // DESC     // ASC
    quickSort(prime); // ASC - DESC - No sorted


    travelListEven(even);
    travelListOdd(odd);
    travelListOdd(prime);

    return 0;
}

bool isPrime(int n) {
    for(int i = 2; i < sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}


void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}


void pushBack(node** dl, T info) {
    node* n = new node(info);
    
    if(!*dl)
        *dl = n;
    else {
        node* aux = *dl;

        while(aux->next)
            aux = aux->next;

        n->prev = aux;
        aux->next = n;
    }
}

void _quickSort(node* low, node* high) {
    if(high && low != high && low != high->next) {
        node* pivot = partition(low, high);

        _quickSort(low, pivot->prev);
        _quickSort(pivot->next, high);
    }
}

void quickSort(node* head) {
    node* last = lastNode(head);

    _quickSort(head, last);
}



node* lastNode(node* head) {
    while(head && head->next)
        head = head->next;

    return head;
}

// NULL 8 9 5 7 12 Null

node* partition(node* low, node* high) {
    T pivot = high->info;
    node* i = low->prev;

    for(node* j = low; j != high; j = j->next) {
        if(j->info<= pivot) {
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

void travelListOdd(node* list) {
    if(list){
        cout << list->info.name << "" << "\t" ;
        travelListOdd(list->next);
    }
    else{
        cout << endl << endl;
    }
}

void travelListEven(node* list) {
    if(list){
        cout << list->info.name << "" << "\t" ;
        travelListEven(list->prev);
    }
    else{
        cout << endl << endl;
    }
}