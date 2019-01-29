#include <iostream>
using namespace std;
template <typename Tdata>
struct TNodestack
{
    Tdata info;
    TNodestack<Tdata> *next;
};
template <typename Tdata>
struct Tstack
{
    TNodestack<Tdata> *top;
};
template <typename Tdata>
Tstack<Tdata> *createstack()
{
    Tstack <Tdata> *stack=new Tstack<Tdata>;
    stack->top=NULL;
    return stack;
}
template <typename Tdata>
void pushstack(Tstack<Tdata> *stack, Tdata info)
{
    TNodestack <Tdata> *box= new TNodestack <Tdata>;
    box->info=info;
    box->next=stack->top;
    stack->top=box;

}
template <typename Tdata>
void popstack(Tstack <Tdata> *stack)
{
    if(stack->top!=NULL)
    {
        TNodestack <Tdata> *aux;
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
template<typename Tdata>
struct TNodequeue
{
    Tdata info;
    TNodequeue<Tdata> *next,*prev;
};
template <typename Tdata>
struct Tqueue
{
    TNodequeue<Tdata> *first,*last;
};
template <typename Tdata>
Tqueue<Tdata> *createqueue()
{
    Tqueue <Tdata> *queue=new Tqueue<Tdata>;
    queue->first=NULL;
    queue->last=NULL;
    return queue;
}
template <typename Tdata>
void pushqueue(Tqueue<Tdata> *queue,Tdata info)
{
    TNodequeue<Tdata> *box= new TNodequeue<Tdata>;
    box->info=info;
    if(queue->first==NULL)
    {
        queue->first=queue->last=box;
        box->prev=box->next=NULL;
    }
    else
    {
        queue->last->next=box;
        box->prev=queue->last;
        box->next=NULL;
        queue->last=box;
    }
}
template <typename Tdata>
void popqueue(Tqueue <Tdata> *queue)
{
    if(queue->first!=NULL)
    {
        if(queue->first->next==NULL&&queue->first->prev==NULL)
        {
            delete queue->first;
            queue->first=queue->last=NULL;
        }
        else
        {
            TNodequeue <Tdata> *aux;
            aux=queue->first->next;
            aux->next=queue->first->next->next;
            aux->prev=NULL;
            delete queue->first;
            queue->first=aux;
        }
    }

}
template <typename Tdata>
Tdata front(Tqueue <Tdata> *queue)
{
    if(queue->first!=NULL)
    {
        return queue->first->info;
    }
}
template <typename Tdata>
void imprimir(Tqueue<Tdata> *queue)
{
    if(queue->first!=NULL)
    {
        TNodequeue<Tdata> *aux=queue->first;
        while(aux!=NULL)
        {
            if(aux->next==NULL)
            {
                cout<<aux->info;
            }
            else
            {
                cout<<aux->info;
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
    Tqueue<char> *salida=createqueue<char>();
    Tstack<char> *operadores=createstack<char>();
    char cadena[50];
    cin>>cadena;
    char* aux=&cadena[0];
    while(*aux!='\0')
    {
        if(*aux>=48&&*aux<=57)
        {
            pushqueue(salida,*aux);
        }
        else
        {
            if(*aux=='(')
            {
                pushstack(operadores,*aux);
            }
            if(*aux==')')
            {
                while(top(operadores)!='(')
                {
                    pushqueue(salida,top(operadores));
                    popstack(operadores);
                }
                popstack(operadores);
            }
            if(*aux=='+'||*aux=='-')
            {
                if(top(operadores)=='+'||top(operadores)=='-'||top(operadores)=='*'||top(operadores)=='/')
                 {
                     pushqueue(salida,top(operadores));
                     popstack(operadores);
                     pushstack(operadores,*aux);
                 }
                 else
                 {
                     pushstack(operadores,*aux);
                 }
            }
            if(*aux=='*'||*aux=='/')
            {
                if(top(operadores)=='*'||top(operadores)=='/')
                {
                    pushqueue(salida,top(operadores));
                    popstack(operadores);
                    pushstack(operadores,*aux);

                }
                else
                {
                    pushstack(operadores,*aux);
                }
            }
        }
        if(*(aux+1)=='\0')
        {
            while(operadores->top!=NULL)
            {
                pushqueue(salida,top(operadores));
                popstack(operadores);

            }

        }
        aux++;
    }

    imprimir(salida);
    return 0;
}
