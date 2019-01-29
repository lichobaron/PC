#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
struct Thoja
{
    int filas,columnas;
    string **matriz;
};
struct Tcoor
{
    char *x;
    char *y;
};
void llenarhoja (Thoja hoja,ifstream &lectura)
{
    string dato;
    for(int j=0; j<hoja.filas; ++j)
    {
        for(int k=0; k<hoja.columnas; ++k)
        {
            lectura>>dato;
            hoja.matriz[j][k]=dato;
        }
    }
}
int buscar (Thoja hoja,char *dato)
{
    string c;
    Tcoor coor;
    int n1=0,n2,n3,cont=0;
    coor.x=new char[50];
    coor.y=new char [50];
    while(dato[cont]>=65&&dato[cont]<=90)
    {
        coor.x[cont]=dato[cont];
        cont++;
        if(cont>1)
        {
            n1=25+n1;
        }
    }
    coor.x[cont]='\0';
    int i=0;
    while(dato[cont]>=48&&dato[cont]<=57)
    {
        coor.y[i]=dato[cont];
        cont++;
        i++;
    }
    coor.y[i]='\0';
    cont=0,i=0;
    while(coor.x[cont]!='\0')
    {
        n1=n1+coor.x[cont]-65;
        cont++;
    }
    while(coor.y[i]!='\0')
    {
        n2=coor.y[i]-49;
        i++;
    }
    for(int j=0; j<hoja.filas; j++)
    {
        if(j==n2)
        {
            for(int k=0; k<hoja.columnas; k++)
            {
                if(k==n1)
                {
                    c=hoja.matriz[j][k];
                    n3=atoi(c.c_str());
                    return n3;
                }
            }
        }
    }
}

int operar_celda (Thoja hojac,char *dato)
{
    int num,sum=0, cont=0,tam;
    char* celda=new char [50];
    if(dato[0]!='=')
    {
        num=atoi(dato);
        return num;
    }
    else
    {
        tam=tamanochar(dato);
        for(int i=1; i<tam; ++i)
        {
            if(dato[i]!='+')
            {
                celda[cont]=dato[i];
                cont++;
            }
            else
            {
                celda[cont]='\0';
                sum=sum+buscar(hojac,celda);
                cont=0;
            }
        }
        celda[cont]='\0';
        sum=sum+buscar(hojac,celda);
        itoa(sum,celda,10);
        operar_celda(hojac,celda);
    }
}
void imprimirhoja (Thoja hojac,ofstream &escritura_hoja)
{
    for(int i=0; i<hojac.filas; i++)
    {
        for(int j=0; j<hojac.columnas; j++)
        {
            escritura_hoja<<hojac.matriz[i][j]<<" ";
        }
        escritura_hoja<<endl;
    }
}

void calcular_hoja()
{
        ifstream lectura;
        lectura.open("hojasincalcular.txt");
        ofstream escritura;
        escritura.open("hojacalculada.txt");
        int cases;
        Thoja hojac;
        lectura>>cases;
        for(int i=0; i<cases; ++i)
        {
            //lectura>>hojac.filas>>hojac.columnas;
            lectura>>hojac.columnas>>hojac.filas;
            hojac.matriz = new string*[hojac.filas];
            for(int j = 0; j < hojac.filas; j++)
            {
                string* aux = new string[hojac.columnas];
                hojac.matriz[j] = aux;
            }
            llenarhoja(hojac,lectura);
            char* dato=new char [50];
            char* dato2=new char [50];
            int num;
            for(int m=0; m<hojac.filas; ++m)
            {
                for(int n=0; n<hojac.columnas; n++)
                {
                    dato=stoc(hojac.matriz[m][n]);
                    num=operar_celda(hojac,dato);
                    itoa(num,dato2,10);
                    hojac.matriz[m][n]=dato2;
                }
            }
            imprimirhoja(hojac,escritura);
        }
        lectura.close();
        escritura.close();
}
