#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
struct Treporte
{
    string numsem,undprod,undvend,utiloper,utilneta;
};


TList <string> *reporte()
{
    TList <string> *rgenerados=create_list<string>();
    ifstream nombres;
    nombres.open("nombres.txt");
    string n,aux;
    char *c=new char[50];
    while(getline(nombres,n,'\n'))
    {
        aux=pegar(n);
        c=stoc(aux);
        annex(rgenerados,aux);
        ofstream escritura;
        escritura.open(c);
        ifstream lectura;
        lectura.open("hojacalculada.txt");
        Thoja hoja;
        if(!lectura)
        {
            cout<<"No existe la hoja de calculo.";
        }
        else
        {
            char dato[50];
            int cont=0;
            Treporte reporte;
            escritura<<"HAIRY PETER S.A."<<endl<<n<<endl<<"Bogotá"<<endl;
            escritura<<endl<<"Después de un análisis detallado de cada movimiento de efectivo realizado en la semana ";
            while(lectura)
            {
                lectura.getline(dato,50,'\n');
                cont++;
            }
            lectura.close();
            lectura.open("hojacalculada.txt");
            if(lectura)
            {
                lectura.getline(dato,50,'\n');
                int i=0,u=0;
                while(dato[u]!='\0')
                {
                    if(dato[u]==' ')
                    {
                        i++;
                    }
                    u++;
                }
                i++;
                hoja.columnas=i;
            }
            hoja.filas=cont-1;
            hoja.matriz = new string*[hoja.filas];
            for(int j = 0; j < hoja.filas; j++)
            {
                string* aux = new string[hoja.columnas];
                hoja.matriz[j] = aux;
            }
            lectura.close();
            lectura.open("hojacalculada.txt");
            llenarhoja(hoja,lectura);
            for(int i=0; i<hoja.filas; ++i)
            {
                for(int j=0; j<hoja.columnas; ++j)
                {
                    if(i==0 && j==0)
                    {
                        reporte.undvend=hoja.matriz[i][j];
                    }
                    if(i==0 && j==hoja.columnas-1)
                    {
                        reporte.numsem=hoja.matriz[i][j];
                    }
                    if(i==hoja.filas-1 && j==0)
                    {
                        reporte.utiloper=hoja.matriz[i][j];
                    }
                    if(i==hoja.filas-1 && j==hoja.columnas-1)
                    {
                        reporte.undprod=hoja.matriz[i][j];
                    }
                    if(i==hoja.filas/2-1 && j==hoja.columnas/2-1)
                    {
                        reporte.utilneta=hoja.matriz[i][j];
                    }
                }
            }
            escritura<<reporte.numsem<<" se obtuvieron los siguientes datos:"<<endl<<endl<<"\tUnidades Producidas "<<reporte.undprod<<endl;
            escritura<<"\tUnidades Vendidas "<<reporte.undvend<<endl;
            escritura<<"\tUtilidad operacional "<<reporte.utiloper<<endl;
            escritura<<"\tUtilidad Neta "<<reporte.utilneta<<endl<<endl;
            escritura<<"Coordial saludo."<<endl<<endl;
            escritura<<"Departamento de finanzas."<<endl;
        }
    escritura.close();
    lectura.close();
    }
    nombres.close();
    print(rgenerados);
    return rgenerados;
}

