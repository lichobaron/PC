#include <iostream>
#include <fstream>
using namespace std;
template <typename Tdata>
struct TNode
{
    Tdata info;
    TNode<Tdata> *next,*prev;
};
template <typename Tdata>
struct Tstack
{
    TNode<Tdata> *first,*last;
};
template <typename Tdata>
Tstack<Tdata> *create()
{
    Tstack <Tdata> *stack=new Tstack<Tdata>;
    stack->first=NULL;
    stack->last=NULL;
    return stack;
}
template <typename Tdata>
void push(Tstack<Tdata> *stack,Tdata info)
{
    TNode<Tdata> *box= new TNode<Tdata>;
    box->info=info;
    if(stack->first==NULL)
    {
        stack->first=stack->last=box;
        box->prev=box->next=NULL;
    }
    else
    {
        stack->last->next=box;
        box->prev=stack->last;
        box->next=NULL;
        stack->last=box;
    }
}
template <typename Tdata>
void pop (Tstack <Tdata> *stack)
{
    if(stack->first!=NULL)
    {
        if(stack->first->next==NULL&&stack->first->prev==NULL)
        {
            delete stack->first;
            stack->first=stack->last=NULL;
        }
        else
        {
            TNode <Tdata> *aux;
            aux=stack->first->next;
            aux->next=stack->first->next->next;
            aux->prev=NULL;
            delete stack->first;
            stack->first=aux;
        }
    }

}
template <typename Tdata>
Tdata front(Tstack <Tdata> *stack)
{
    if(stack->first!=NULL)
    {
        return stack->first->info;
    }
}
template <typename Tdata>
void imprimir(Tstack<Tdata> *stack, ofstream &salida)
{
    if(stack->first!=NULL)
    {
        TNode<Tdata> *aux=stack->first;
        salida<<"Cartas desechadas: ";
        while(aux!=NULL)
        {
            if(aux->next==NULL)
            {
                salida<<aux->info;
            }
            else
            {
                salida<<aux->info<<","<<" ";
            }

            aux=aux->next;
        }
        salida<<endl;
    }
}
int main(int argc, char *argv[])
{
    int n;
    ofstream salida;
    salida.open(argv[1]);
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        Tstack<int> *enteros=create<int>();
        Tstack<int> *desechados=create<int>();

        int x=1;
        while(x<=n)
        {
            push(enteros,x);
            x++;
        }
        TNode<int> *aux=enteros->first;
        if(n==1)
        {
            salida<<"Cartas desechadas: "<<endl<<"Carta final: "<<enteros->last->info<<endl;
        }
        else
        {
            while(aux->next->next!=NULL)
            {
                push(desechados,enteros->first->info);
                pop(enteros);
                push(enteros,enteros->first->info);
                pop(enteros);
                aux=enteros->first;
            }
            push(desechados,enteros->first->info);
            imprimir(desechados,salida);
            if(aux->next!=NULL)
            {
                salida<<"Carta final: "<<enteros->last->info<<endl;
            }
            else
            {
                salida<<"Carta final: "<<enteros->last->info;
            }
        }
    }
    salida.close();
    return 0;
}
