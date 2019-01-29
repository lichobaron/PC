#include <iostream>
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
bool isEnd(List l);
void gofirst(List l);
void golast(List l);
void gonext(List l);
void goprev(List l);
void insert(List l, Tdata info);
void annex(List l, Tdata info);
void erase(List l);
void imprimir (List l);
int main()
{
    List l;
    int casos,datos;
    string accion;
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
            if(accion=="insert")
            {
                if(isEnd(l)&&!isEmpty(l))
                {
                    cout<<"Imposible insertar el elemento"<<endl;
                }
                else
                {
                    insert(l,info);
                    imprimir(l);
                }
            }
            if(accion=="annex")
            {
                if(isEnd(l)&&!isEmpty(l))
                {
                    cout<<"Imposible anexar el elemento"<<endl;
                }
                else
                {
                    annex(l,info);
                    imprimir(l);
                }
            }
            if(accion=="push_front")
            {
                push_front(l,info);
                imprimir(l);
            }
            if(accion=="push_back")
            {
                push_back(l,info);
                imprimir(l);
            }
            if(accion=="goFirst")
            {
                gofirst(l);
                imprimir(l);
            }
            if(accion=="goLast")
            {
                golast(l);
                imprimir(l);
            }
            if(accion=="goNext")
            {
                gonext(l);
                imprimir(l);
            }
            if(accion=="goPrev")
            {
                goprev(l);
                imprimir(l);
            }
            if(accion=="erase")
            {
                if(isEnd(l))
                {
                    cout<<"No hay un elemento seleccioando para eliminar"<<endl;
                }
                else
                {
                    erase(l);
                    imprimir(l);
                }
            }
            if(accion=="isEmpty")
            {
                if(isEmpty(l))
                {
                    cout<<"La lista esta vacia"<<endl;
                }
                else
                {
                    cout<<"La lista no esta vacia"<<endl;
                }
            }
            if(accion=="isEnd")
            {
                if(isEnd(l))
                {
                    cout<<"La ventana esta indefinida"<<endl;
                }
                else
                {
                    cout<<"La ventana apunta a"<<" "<<l->window->info<<endl;
                }
            }
        }

    }
    return 0;
}
bool isEmpty(List l)
{
    return l->first==NULL;
}
bool isEnd(List l)
{
    return l->window==NULL;
}
List create_list()
{
    List l= new TList;
    l->first=l->last=l->window=NULL;
    return l;
}
void imprimir (List l)
{
    LNode aux=l->window;
    bool x=false;
    gofirst(l);
    cout<<'[';
    if(!isEmpty(l))
    {
        while(!isEnd(l))
        {
            if(l->window==aux)
            {
                cout<<'*'<<l->window->info<<'*'<<" ";
                x=true;
            }
            else
            {
                cout<<l->window->info<<" ";
            }
            gonext(l);
        }
    }
    if(x==false)
    {
        cout<<"**";
    }
    cout<<']'<<endl;
    l->window=aux;
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
void goprev (List l)
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
void annex(List l, Tdata info)
{
    LNode box= new TLNode;
    box->info=info;
    LNode aux;
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
void insert(List l, Tdata info)
{
    LNode box= new TLNode;
    box->info=info;
    LNode aux;
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
void erase(List l)
{
    if(l->window!=NULL)
    {
        LNode aux;
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
