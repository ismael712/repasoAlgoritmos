#include <vector>
#include <iostream>
using namespace std;

 struct laptop{
    int p,q;

    laptop(){}
    laptop(int _p, int _q): p(_p), q(_q) {}

    bool operator>(const laptop& r){
        return this->p > r.p;
    }
} ;

void swap(laptop* lap1, laptop* lap2);
void heapify(vector<laptop>* vct, int n, int i);
void heapSort(vector<laptop>* vct, int n);


int main(void){

    vector<laptop> vct;
    int n = 0,aux1 = 0,aux2 = 0;

    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>> aux1 >> aux2 ;
        vct.push_back(laptop(aux1,aux2));
    }

    heapSort(&vct,vct.size());

    for(auto it = vct.begin(); it != vct.end() - 1 ; it++){
        if(it->q > (it + 1)->q){
            cout << "Happy Alex" << endl;
            return 0;
        }
    }

    cout << "Poor Alex " << endl;

    return 0;
}

void swap(laptop* lap1, laptop* lap2) {
    laptop temp = *lap1;
    *lap1 = *lap2;
    *lap2 = temp;
}


void heapify(vector<laptop>* vct, int n, int i) {
    // First we assume that largest element is at root pos
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If either left or right is larger than largest, switch largest with LR pos
    if(left < n && vct->at(left) > vct->at(largest))
        largest = left;

    if(right < n && vct->at(right) > vct->at(largest))
        largest = right;

    // If largest is not root, swap root with largest and recurse
    if(largest != i) {
        swap(vct->at(i), vct->at(largest));
        heapify(vct, n, largest);
    }
}


void heapSort(vector<laptop>* vct, int n) {
    // First a maxheap must be made in order to sort elements
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(vct, n, i);

    for(int i = n - 1; i > 0; i--) {
        // root position must be swapped with last - 1 pos
        swap(vct->at(0), vct->at(i));

        // After swapping maxheap must be remade
        heapify(vct, i, 0);
    }
}