#include <iostream>
#include <fstream>
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
void imprimir(Tstack<Tdata> *stack, ofstream &salida)
{
    if(stack->top!=NULL)
    {
        TNode<Tdata> *aux=stack->top;
        while(aux!=NULL)
        {
            if(aux->next==NULL)
            {
                salida<<aux->info;
            }
            else
            {
                salida<<aux->info<<" ";
            }

            aux=aux->next;
        }
        salida<<endl;
    }
    else
    {
        salida<<"La pila esta vacia"<<endl;
    }

}
int main()
{

    ifstream lectura;
    ofstream salida;
    lectura.open("entrada1.txt");
    salida.open("misalida.txt");
    string a, b;
    int x,y;
    lectura>>x;
    cout<<x<<endl;
    for(int i=0; i<x; i++)
    {
        Tstack<int> *enteros=create<int>();
        Tstack<double> *dobles=create<double>();
        Tstack<char> *caracteres=create<char>();
        Tstack<string> *cadenas=create<string>();

        lectura>>y;
        cout<<y<<endl;
        for(int j=0; j<y; j++)
        {

            lectura>>a;
            if(a=="I")
            {
                lectura>>b;
                int info;
                lectura>>info;

                if(b=="push")
                {
                    push(enteros,info);
                    imprimir(enteros,salida);
                }
                if(b=="pop")
                {
                    pop(enteros);
                    imprimir(enteros,salida);
                }
                if(b=="top")
                {
                    if(enteros->top!=NULL)
                    {
                        salida<<top(enteros)<<endl;
                    }
                    else
                    {
                        salida<<"La pila esta vacia"<<endl;
                    }
                }
            }
            if(a=="D")
            {
                lectura>>b;
                double info;
                lectura>>info;
                if(b=="push")
                {
                    push(dobles,info);
                    imprimir(dobles,salida);

                }
                if(b=="pop")
                {
                    pop(dobles);
                    imprimir(dobles,salida);
                }
                if(b=="top")
                {
                    if(dobles->top!=NULL)
                    {
                        salida<<top(dobles)<<endl;
                    }
                    else
                    {
                        salida<<"La pila esta vacia"<<endl;
                    }
                }
            }
            if(a=="C")
            {
                lectura>>b;
                char info;
                lectura>>info;
                if(b=="push")
                {
                    push(caracteres,info);
                    imprimir(caracteres,salida);
                }
                if(b=="pop")
                {
                    pop(caracteres);
                    imprimir(caracteres,salida);
                }
                if(b=="top")
                {
                    if(caracteres->top!=NULL)
                    {
                        salida<<top(caracteres)<<endl;
                    }
                    else
                    {
                        salida<<"La pila esta vacia"<<endl;
                    }
                }
            }
            if(a=="S")
            {
                lectura>>b;
                string info;
                lectura.ignore();
                getline(lectura,info,'\n');
                if(b=="push")
                {
                    push(cadenas,info);
                    imprimir(cadenas,salida);
                }
                if(b=="pop")
                {
                    pop(cadenas);
                    imprimir(cadenas,salida);
                }
                if(b=="top")
                {
                    if(cadenas->top!=NULL)
                    {
                        salida<<top(cadenas)<<endl;
                    }
                    else
                    {
                        salida<<"La pila esta vacia"<<endl;
                    }
                }
            }
        }
    }
    salida.close();
    return 0;
}