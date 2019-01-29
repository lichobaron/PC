#include <iostream>
#include <fstream>
#include "TAD.h"
#include "cadenas.h"
#include "hoja.h"
#include "reporte.h"
using namespace std;

struct Tnombres
{
    string izquierda;
    string derecha;
    bool usado=false;
};
struct Truta
{
    string nombre;
    TList<Truta*> *contenido;
};
void leer_direccion(TList<string> *direccion);
void agregar(TList<Truta*> *lista,Truta *info)
{
    if(isEmpty(lista))
    {
        //cout<<"no hay nada"<<endl;
        annex(lista,info);
    }
    else
    {
        string a=convertir(info->nombre);
        string b=convertir(lista->first->info->nombre);
        if(a==b)
        {
            //cout<<"son iguales"<<endl;
            insert(lista,info);
        }
        if(a>b)
        {
            //cout<<"es mayor"<<endl;
            TLNode<Truta*> *aux=lista->window;
            gofirst(lista);
            while(!isEnd(lista))
            {
                if(lista->window->next==NULL)
                {
                    push_back(lista,info);
                    break;
                }
                string c=convertir(lista->window->info->nombre);
                if(a<c)
                {
                    annex(lista,info);
                    break;
                }
                gonext(lista);
            }
            lista->window=aux;
        }
        if(a<b)
        {
            //cout<<"es menor"<<endl;
            TLNode<Truta*> *aux=lista->window;
            golast(lista);
            while(!isEnd(lista))
            {
                if(lista->window->prev==NULL)
                {
                    push_front(lista,info);
                    break;
                }
                string c=convertir(lista->window->info->nombre);
                if(a>c)
                {
                    insert(lista,info);
                    break;
                }
                goprev(lista);
            }
            lista->window=aux;
        }
    }
}
void imprimir (TList<Truta*> *l, int espacios)
{
    espacios++;
    TLNode<Truta*>*aux=l->window;
    gofirst(l);
    if(!isEmpty(l))
    {

        while(!isEnd(l))
        {
            //cout<<"|";
            for(int i=0; i<espacios; i++)
            {
                cout<<" ";
            }
            cout<<"- "<<l->window->info->nombre<<endl;
            if(l->window->info->contenido!=NULL)
            {

                //cout<<"   ";
                imprimir(l->window->info->contenido,espacios);
                //cout<<"Fin "<<l->window->info->nombre<<endl;
            }

            gonext(l);
        }
    }
    l->window=aux;
}
void imprimir_2(TList<Truta*> *l, int espacios)
{
    espacios++;
    TLNode<Truta*>*aux=l->window;

    if(!isEmpty(l))
    {
        golast(l);
        while(!isEnd(l))
        {
            //cout<<"|";
            for(int i=0; i<espacios; i++)
            {
                cout<<" ";
            }
            cout<<"- "<<l->window->info->nombre<<endl;
            if(l->window->info->contenido!=NULL)
            {

                //cout<<"   ";
                golast(l->window->info->contenido);
                imprimir_2(l->window->info->contenido,espacios);
                //cout<<"Fin "<<l->window->info->nombre<<endl;
            }

            goprev(l);
        }
    }
    l->window=aux;
}
TList<Truta*> *create_ruta(TList<Tnombres> *nombres,string elemento)
{
    bool unica=true;
    TLNode<Tnombres> *aux=nombres->first;
    while(aux!=NULL)
    {
        string a=convertir(elemento),b=convertir(aux->info.derecha);
        if(a==b)
        {
            unica=false;
        }
        aux=aux->next;
    }
    if(unica)
    {
        return NULL;
    }
    else
    {
        TList<Truta*> *lista=create_list<Truta*>();
        TLNode<Tnombres> *aux2=nombres->first;
        while(aux2!=NULL)
        {
            //cout<<nombres->window->info.derecha<<" "<<aux2->info.derecha<<": "<<endl;
            string a=convertir(elemento),b=convertir(aux2->info.derecha);
            if(a==b&&aux2->info.usado==false)
            {
                TList<Truta*> *lista2=create_list<Truta*>();
                Truta *info2= new Truta;
                info2->nombre=aux2->info.izquierda;
                lista2=create_ruta(nombres,info2->nombre);
                info2->contenido=lista2;
                agregar(lista,info2);
                aux2->info.usado=true;
                //cout<<"iguales"<<endl;
            }
            aux2=aux2->next;
            /*imprimir(subruta);
            cout<<"----------------"<<endl;*/
        }
        return lista;
    }
}
TList<Truta*> * buscar_fichero(TList<string> *direccion,TList<Truta*> *principal)
{
    TLNode<Truta*> *aux=principal->first;
    while(aux!=NULL)
    {
        //cout<<"nombre: "<<aux->info->nombre<<"<----->"<<direccion->window->info<<endl;
        if(aux->info->nombre==direccion->window->info)
        {
            if(direccion->window->info==direccion->last->info)
            {
                return aux->info->contenido;
            }
            else
            {
                gonext(direccion);
                return buscar_fichero(direccion,aux->info->contenido);
            }
        }
        aux=aux->next;
    }
}
void mostrar_fichero( TList<Truta*> *principal)
{
    TList<string> *direccion= create_list<string>();
    leer_direccion(direccion);
    //print(direccion);
    TList<Truta*> *nodo_aux;
    gofirst(direccion);
    nodo_aux=buscar_fichero(direccion,principal);
    if(nodo_aux==NULL)
    {
        cout<<"No tiene elementos el fichero."<<endl;
    }
    else if(isEmpty(nodo_aux))
    {
        cout<<"No tiene elementos el fichero."<<endl;

    }
    else
    {
        cout<<"a. Ascendente      b. Descendente"<<endl;
        char x;
        cin>>x;
        cout<<"Contenido: "<<endl;
        if(x=='a')
        {
            imprimir(nodo_aux,-1);
        }
        else
        {
            imprimir_2(nodo_aux,-1);
        }
    }
}
void leer_direccion(TList<string> *direccion)
{
    string datodir;
    char s;
    int m=0;
    cout<<"Digite la direcion: "<<endl;
    while(datodir!="end")
    {
        if(m==0)
        {
            cin.ignore();
        }
        else
        {
            cin>>s;
        }

        if(s=='"')
        {
            getline(cin,datodir,'"');
        }
        else
        {

            cin>>datodir;
        }

        if(datodir!="end")
        {
            push_back(direccion,datodir);
        }
        m++;
    }
}
void leer_archivo(TList<Tnombres> *nombres, fstream &lectura)
{
    string a,b;
    char c;
    while(lectura>>c)
    {
        if(c=='"')
        {
            getline(lectura, a, '"');
            //cout<<a<<endl;
            lectura>>c;
            //cout<<c<<endl;
            if(c=='"')
            {
                getline(lectura, b,'"');
            }
            else
            {
                lectura.seekg(-1,ios::cur);
                lectura>>b;
                //cout<<b<<endl;
            }
        }
        else
        {
            lectura.seekg(-1,ios::cur);
            lectura>>a;
            lectura>>c;
            if(c=='"')
            {
                getline(lectura,b,'"');
            }
            else
            {
                lectura.seekg(-1,ios::cur);
                lectura>>b;
            }
        }
        Tnombres info;
        info.izquierda=a;
        info.derecha=b;
        annex(nombres,info);
    }

}
void crear_nombres( TList<Tnombres> *nombres,TList<Truta*> *principal)
{
    gofirst(nombres);
    while(!isEnd(nombres))
    {
        //cout<<"-----------------------------------------"<<endl;
        bool unica= true;
        TLNode<Tnombres> *aux=nombres->first;
        while(aux!=NULL)
        {
            //cout<<nombres->window->info.derecha<<" "<<aux->info.izquierda<<": ";
            string a=convertir(nombres->window->info.derecha), b=convertir(aux->info.izquierda);
            aux=aux->next;
            if(a==b)
            {
                unica=false;
                //cout<<"iguales"<<endl;
            }
            else
            {
                //cout<<"diferentes"<<endl;
            }
        }
        if(unica&&nombres->window->info.usado==false)
        {
            Truta *info=new Truta;
            info->nombre=nombres->window->info.derecha;
            TList<Truta*> *subruta=create_list<Truta*>();
            TLNode<Tnombres> *aux2=nombres->first;
            while(aux2!=NULL)
            {
                //cout<<nombres->window->info.derecha<<" "<<aux2->info.derecha<<": "<<endl;
                string a=convertir(nombres->window->info.derecha),b=convertir(aux2->info.derecha);
                if(a==b&&aux2->info.usado==false)
                {
                    TList<Truta*> *subruta2=create_list<Truta*>();
                    Truta *info2= new Truta;
                    info2->nombre=aux2->info.izquierda;
                    subruta2=create_ruta(nombres,aux2->info.izquierda);
                    info2->contenido=subruta2;
                    agregar(subruta,info2);
                    aux2->info.usado=true;
                    //cout<<"iguales"<<endl;
                }
                aux2=aux2->next;
                /*imprimir(subruta);
                cout<<"----------------"<<endl;*/
            }
            info->contenido=subruta;
            agregar(principal,info);
            nombres->window->info.usado=true;
            //erase(nombres);
        }
        gonext(nombres);
    }
}
int main(int argc, char *argv[])
{

    // imprimir(principal->first->info->contenido->first->info->contenido/*->first->info->contenido->first->info->contenido*/,espacios);
    /*gofirst(nombres);
    while(!isEnd(nombres))
    {
        erase(nombres);
    }*/
    int opc;
    while(opc!=4)
    {
        fstream lectura;
        TList<Tnombres> *nombres=create_list<Tnombres>();
        TList<Truta*> *principal=create_list<Truta*>();
        cout<<"----------------------------------------"<<endl<<"1. Generar estructura."<<endl<<"2. Buscar fichero."<<endl<<"3. Calcular reporte."<<endl<<"4. Salir."<<endl<<"----------------------------------------"<<endl;
        cin>>opc;
        if(opc==1)
        {
            lectura.open("entrada.txt",ios::binary|ios::in);
            leer_archivo(nombres,lectura);
            crear_nombres(nombres,principal);
            cout<<"a. Ascendente      b. Descendente"<<endl;
            char x;
            cin>>x;
            if(x=='a')
            {
                imprimir(principal,-1);
            }
            else
            {
                imprimir_2(principal,-1);
            }
            lectura.close();
        }
        if(opc==2)
        {
        //"una direccion debe tener este formato, A: ""Mis Documentos" "Contabilidad Paralela"" \empresa \end"<<endl;
            lectura.open("entrada.txt",ios::binary|ios::in);
            leer_archivo(nombres,lectura);
            crear_nombres(nombres,principal);
            lectura.close();
            mostrar_fichero(principal);
        }
        if(opc==3)
        {
            TList<string> *rgenerados = create_list<string>();
            /*string sincalhoja;*/
            //print(rgenerados);
            /* cout<<"Digite el nombre de la hoja de calculo: ";
             cin>>sincalhoja;*/
            cout<<"Digite el nombre de la carpeta: ";
            string carpeta;
            char c;
            cin>>c;
            if(c=='"')
            {
                getline(cin,carpeta,'"');
            }
            else
            {
                cin>>carpeta;
            }
            calcular_hoja();
            rgenerados=reporte();
            lectura.open("entrada.txt",ios::out|ios::app);
            gofirst(rgenerados);
            lectura<<" ";
            while(!isEnd(rgenerados))
            {
                lectura<<rgenerados->window->info<<" "<<carpeta<<endl;
                gonext(rgenerados);
            }
            lectura.close();
            cout<<endl<<"Se ha generado su reporte."<<endl;
        }
    }
    return 0;
}

