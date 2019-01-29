#include <iostream>
using namespace std;

template <typename Tdata>
struct TLNode
{
    Tdata info;
    TLNode<Tdata> *next, *prev;
};
template <typename Tdata>
struct TList
{
    TLNode<Tdata> *first, *last,*window;
};
template <typename Tdata>
TList<Tdata> * create_list();
template <typename Tdata>
TList<Tdata> * create_list();
template <typename Tdata>
void push_front(TList<Tdata> *l, Tdata);
template <typename Tdata>
void push_back(TList<Tdata> *l, Tdata);
template <typename Tdata>
bool isEmpty(TList<Tdata> *l);
template <typename Tdata>
bool isEnd(TList<Tdata> *l);
template <typename Tdata>
void gofirst(TList<Tdata> *l);
template <typename Tdata>
void golast(TList<Tdata> *l);
template <typename Tdata>
void gonext(TList<Tdata> *l);
template <typename Tdata>
void goprev(TList<Tdata> *l);
template <typename Tdata>
void insert(TList<Tdata> *l, Tdata info);
template <typename Tdata>
void annex(TList<Tdata> *l, Tdata info);
template <typename Tdata>
void erase(TList<Tdata> *l);

template <typename Tdata>
TList<Tdata> * create_list()
{
    TList<Tdata> * l= new TList<Tdata>;
    l->first=l->last=l->window=NULL;
    return l;
}
template <typename Tdata>
bool isEmpty(TList<Tdata> *l)
{
    return l->first==NULL;
}
template <typename Tdata>
bool isEnd(TList<Tdata> *l)
{
    return l->window==NULL;
}
template <typename Tdata>
void print(TList<Tdata> *l)
{
    TLNode<Tdata>*aux=l->window;
    gofirst(l);
    if(!isEmpty(l))
    {
        while(!isEnd(l))
        {
            cout<<"- "<<l->window->info<<endl;
            gonext(l);
        }
    }
    l->window=aux;
}
template <typename Tdata>
void gofirst (TList<Tdata> *l)
{
    l->window=l->first;
}
template <typename Tdata>
void golast (TList<Tdata> *l)
{
    l->window=l->last;
}
template <typename Tdata>
void gonext (TList<Tdata> *l)
{
    if(!isEmpty(l)&&l->window!=NULL)
    {
        if(l->window->next!=NULL)
        {
            l->window=l->window->next;
        }
        else
        {
            l->window=NULL;
        }
    }
}
template <typename Tdata>
void goprev (TList<Tdata> *l)
{
    if(!isEmpty(l)&&l->window!=NULL)
    {
        if(l->window->prev!=NULL)
        {
            l->window=l->window->prev;
        }
        else
        {
            l->window=NULL;
        }
    }
}
template <typename Tdata>
void push_front(TList<Tdata> *l,Tdata info)
{
    TLNode<Tdata> *box= new TLNode<Tdata>;
    box->info=info;
    if(isEmpty(l))
    {
        l->first=l->last=l->window=box;
        box->prev=box->next=NULL;
    }
    else
    {
        l->first->prev=box;
        box->next=l->first;
        box->prev=NULL;
        l->first=box;
        l->window=box;
    }
}
template <typename Tdata>
void push_back(TList<Tdata> *l,Tdata info)
{
    TLNode<Tdata> *box= new TLNode<Tdata>;
    box->info=info;
    if(isEmpty(l))
    {
        l->first=l->last=l->window=box;
        box->prev=box->next=NULL;
    }
    else
    {
        l->last->next=box;
        box->prev=l->last;
        box->next=NULL;
        l->last=box;
        l->window=box;

    }
}
template <typename Tdata>
void annex(TList<Tdata> *l, Tdata info)
{
    TLNode<Tdata> *box= new TLNode<Tdata>;
    box->info=info;
    TLNode<Tdata> *aux;
    if(isEmpty(l))
    {
        push_back(l,info);
    }
    else
    {
        if(!isEnd(l))
        {
            if(l->window->next==NULL)
            {
                box->prev=l->window;
                box->next=NULL;
                l->window->next=box;
                l->window=box;
                l->last=box;
            }
            else
            {
                aux=l->window->next;
                box->prev=l->window;
                box->next=l->window->next;
                l->window->next=box;
                aux->prev=box;
                l->window=box;
            }
        }
    }
}
template <typename Tdata>
void insert(TList<Tdata> *l, Tdata info)
{
    TLNode<Tdata> *box= new TLNode<Tdata>;
    box->info=info;
    TLNode<Tdata> *aux;
    if(isEmpty(l))
    {
        push_front(l,info);
    }
    else
    {
        if(!isEnd(l))
        {
            if(l->window->prev==NULL)
            {
                box->next=l->window;
                box->prev=NULL;
                l->window->prev=box;
                l->window=box;
                l->first=box;
            }
            else
            {
                aux=l->window->prev;
                box->next=l->window;
                box->prev=l->window->prev;
                l->window->prev=box;
                aux->next=box;
                l->window=box;
            }
        }
    }
}
template <typename Tdata>
void erase(TList<Tdata> *l)
{
    if(l->window!=NULL)
    {
        TLNode<Tdata> *aux;
        if(l->window->next==NULL&&l->window->prev==NULL)
        {
            delete l->window;
            l->first=l->last=l->window=NULL;
        }
        else
        {
            if(l->window->prev==NULL)
            {
                l->first=l->window->next;
                l->window->next->prev=NULL;
                delete l->window;
                l->window=l->first;
            }
            else if(l->window->next==NULL)
            {
                l->last=l->window->prev;
                l->window->prev->next=NULL;
                delete l->window;
                l->window=NULL;
            }
            else
            {
                aux=l->window->next;
                l->window->next->prev=l->window->prev;
                l->window->prev->next=l->window->next;
                delete l->window;
                l->window=aux;
            }
        }
    }
}
