#include <iostream>
#include <cstring>
using namespace std;
char * stoc(string b);
string convertir(string a)
{
    for (int i=0; i<a.size(); ++i)
    {
        if(a[i]>=97&&a[i]<=122)
        {
            a[i]=a[i]-32;
        }
    }
    return a;
}
string pegar(string palabra)
{
    char*aux=stoc(palabra);
    char aux2[50];
    int tam=0;
    while(aux[tam]!='\0')
    {
        if(aux[tam]!=' ')
        {
            aux2[tam]=aux[tam];
        }
        else
        {
            aux2[tam]=aux[tam+1];
            aux++;
        }
        tam++;
    }
    aux2[tam]='\0';
    strcat(aux2,".txt");
    tam=0;
    while(aux2[tam]!='\0')
    {
        if(aux2[tam]>='A'&& aux2[tam]<='Z')
        {
            aux2[tam]=aux2[tam]+32;
        }
        tam++;
    }
    return aux2;
}
int tamanostring(string a)
{
    int cont=0;
    while(a[cont]!=NULL)
    {
        cont++;
    }
    return cont;
}
char * stoc(string b)
{
    char *cadena=new char[50];
    int tam=tamanostring(b);
    for(int i=0; i<tam; ++i)
    {
        cadena[i]=b[i];
    }
    cadena[tam]='\0';
    return cadena;
}
int tamanochar(char* dato)
{
    int tam=0;
    while(dato[tam]!='\0')
    {
        tam++;
    }
    return tam;
}
