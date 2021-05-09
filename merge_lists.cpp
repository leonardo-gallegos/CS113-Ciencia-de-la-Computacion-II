#include <iostream>

// Renzo Leonardo Gallegos Vilca

using namespace std;

template <typename T>
struct nodo
{
   T valor;
   nodo *next; 
   nodo(T v, nodo *n=nullptr)
   { 
      valor = v;
      next = n;
    }
};

// Agregué el tipo <int> al nodo que no estaba agregado
void arraytolist(int *a, nodo<int>*& head)
{
   head = new nodo<int>(a[0]);
   nodo<int>* t= head;
   for(int i=1;i<10;i++)
     {
       t->next = new nodo<int>(a[i]);
       t = t->next;
     }
}

void printlista(nodo<int> *p)
{
  cout<<"Head -> ";
  for(;p;p=p->next)
    cout<<p->valor<<" -> ";
  cout<<"NULL"<<endl;
}

void mezcla(nodo<int>*& l1,nodo<int>*& l2,nodo<int>*& l3)
{
    nodo<int>*p = l1;
    nodo<int>*q = l2;
    nodo<int>*r = l3;
    
    // Primera instancia, cuando l3 apunta a nulo
    if(r ==  nullptr) {        
        // Si p < q, entonces l3 apunta a p
        if(p -> valor < q -> valor) {
            l3 = p;
            p = p -> next;
        }
        // Si no apunta a q 
        else {
            l3 = q;
            q = q -> next;
        }
    }
    r = l3;
    
    // Mientras que p y q no apunten a nulo, es decir
    // mientras no se haya recorrido las listas
    while((p != nullptr) && (q != nullptr)) {
  	 
        // Si p es menor que q
        if(p -> valor < q -> valor) {
            r -> next = p;
            r = r -> next;
            p = p -> next;
        } 
        else {
            r -> next = q;
            r = r -> next;
            q = q -> next;
        }

        //Fin de recorrido de p o q
        // Cuando p se haga nulo r apunta a q
        if(p == nullptr) {
            r -> next = q;
            r = r -> next;
            q = q -> next;
        }
        // Cuando q se haga nulo r apunta a p
        else if(q ==  nullptr) {
            r -> next = p;
            r = r->next;
            p = p->next;
        }
    }

    l1 = nullptr;
    l2 = nullptr;
}

int main() {
    int a[10] = {4,7,11,14,17,20,31,32,33,40};
    int b[10] = {4,7,9,11,14,17,20,23,25,30};
    nodo<int> *lista1=0, *lista2=0, *lista3=0;

    arraytolist(a,lista1);
    cout<<"Lista 1"<<endl;
    printlista(lista1);

    arraytolist(b,lista2);
    cout<<"Lista 2"<<endl;
    printlista(lista2);

    mezcla(lista1,lista2,lista3);
    cout<<"-----------------------------------"
    "----------------------------------"<<endl;
    cout<<"Lista 1"<<endl;
    printlista(lista1);
    cout<<"Lista 2"<<endl;
    printlista(lista2);
    cout<<"Lista 3"<<endl;
    printlista(lista3);
    
}