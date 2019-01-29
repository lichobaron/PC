#include <iostream>
#include <assert.h>
using namespace std;

typedef int Tdata;
typedef struct TLNode
{
    Tdata info;
    TLNode *next, *prev;
}* LNode;

typedef struct TList
{
    LNode first, last, window;
}* List;
List create_list();
void push_front(List, Tdata);
void push_back(List, Tdata);
bool isEmpty(List);
void gofirst(List l);
void golast(List l);
void gonext(List l);
void insert(List l,const Tdata &info);
void annex(List l,const Tdata &info);
int main()
{
    List l;
    int casos,datos;
    char* accion=new char;
    Tdata info;
    cin>>casos;
    for(int i=0; i<casos; i++)
    {
        l=create_list();
        cin>>datos;
        for(int j=0; j<datos; j++)
        {
            cin>>info;
            cin>>accion;
            if(*accion=='i'||*accion=='I')
            {
                insert(l,info);
            }
            if(*accion=='a'||*accion=='A')
            {
                annex(l,info);
            }
        }
        gofirst(l);
        while(l->window!=l->last)
        {
            cout<<l->window->info<<" ";
            gonext(l);
        }
        cout<<l->window->info<<endl;
    }
    return 0;
}
bool isEmpty(List l)
{
    return l->first==NULL;
}
List create_list()
{
    List l= new TList;
    l->first=l->last=l->window=NULL;
    return l;
}
void push_front(List l,Tdata info)
{
    LNode box= new TLNode;
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
void push_back(List l,Tdata info)
{
    LNode box= new TLNode;
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
void gofirst (List l)
{
    l->window=l->first;
}
void golast (List l)
{
    l->window=l->last;
}
void gonext (List l)
{
    if(l->window->next!=NULL)
    {
        l->window=l->window->next;
    }
}
void insert(List l,const Tdata &info)
{
    LNode box=new TLNode;
    box->info=info;
    if(isEmpty(l))
    {
        push_front(l,info);
    }
    else
    {
        box->prev=l->window->prev;
        box->next=l->window;
        if(l->window->prev!=NULL)
        {
            box->prev->next=box;
        }
        if(l->window->next!=NULL)
        {
            box->next->prev=box;
        }
        l->window=box;
        if(box->prev==NULL)
        {
            l->first=l->window;
        }
    }
}
void annex(List l,const Tdata &info)
{
    LNode box= new TLNode;
    box->info=info;
    if(isEmpty(l))
    {
        push_back(l,info);
    }
    else
    {
        box->prev=l->window;
        box->next=l->window->next;
        l->window=box;
        if(l->window->prev!=NULL)
        {
            box->prev->next=box;
        }
        if(l->window->next!=NULL)
        {
            box->next->prev=box;
        }
        l->window=box;
        if(box->next==NULL)
        {
            l->last=l->window;
        }
    }
}
