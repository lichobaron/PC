#include <iostream>
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
void imprimir(Tstack<Tdata> *stack)
{
    if(stack->first!=NULL)
    {
        TNode<Tdata> *aux=stack->first;
        while(aux!=NULL)
        {
            if(aux->next==NULL)
            {
                cout<<aux->info;
            }
            else
            {
                cout<<aux->info<<" ";
            }

            aux=aux->next;
        }
        cout<<endl;
    }
    else
    {
        cout<<"La estructura esta vacia"<<endl;
    }

}
int main()
{
    string b;
    int y;
    Tstack<long int> *enteros=create<long int>();
    cin>>y;
    for(int j=0; j<y; j++)
    {
        long int info;
        cin>>info;
        cin>>b;

        if(b=="push")
        {
            push(enteros,info);
            imprimir(enteros);
        }
        if(b=="pop")
        {
            pop(enteros);
            imprimir(enteros);
        }
        if(b=="front")
        {
            if(enteros->first!=NULL)
            {
                cout<<front(enteros)<<endl;
            }
            else
            {
                cout<<"La estructura esta vacia"<<endl;
            }
        }
    }
    return 0;
}
