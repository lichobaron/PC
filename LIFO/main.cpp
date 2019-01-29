#include <iostream>
using namespace std;
template <typename Tdata>
struct TNode
{
    Tdata info;
    TNode<Tdata> *next;
};
template <typename Tdata>
struct Tstack
{
    TNode<Tdata> *top;
};
template <typename Tdata>
Tstack<Tdata> *create()
{
    Tstack <Tdata> *stack=new Tstack<Tdata>;
    stack->top=NULL;
    return stack;
}
template <typename Tdata>
void push(Tstack<Tdata> *stack, Tdata info)
{
    TNode <Tdata> *box= new TNode <Tdata>;
    box->info=info;
    box->next=stack->top;
    stack->top=box;

}
template <typename Tdata>
void pop (Tstack <Tdata> *stack)
{
    if(stack->top!=NULL)
    {
        TNode <Tdata> *aux;
        aux=stack->top->next;
        delete stack->top;
        stack->top=aux;
    }
}
template <typename Tdata>
Tdata top(Tstack <Tdata> *stack)
{
    if(stack->top!=NULL)
    {
        return stack->top->info;
    }

}
template <typename Tdata>
void imprimir(Tstack<Tdata> *stack)
{
    if(stack->top!=NULL)
    {
        TNode<Tdata> *aux=stack->top;
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
        if(b=="top")
        {
            if(enteros->top!=NULL)
            {
                cout<<top(enteros)<<endl;
            }
            else
            {
                cout<<"La estructura esta vacia"<<endl;
            }
        }
    }
    return 0;
}
