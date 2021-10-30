#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/*create function to transform a decimal number to binary. Although there are several functions in many libraries capable of doing this, 
I wanted to program this section to show my knowledge regarding this topic as it is a method of studying introduction to computer networks.*/
int* transbtod(int a)
{
	int i, unidad[8]={128,64,32,16,8,4,2,1}, numbin[8];
	for(i=0; i<8; i++)
	{
		
		if(a>=unidad[i])
		{
			a=a-unidad[i];
			numbin[i]=1;			
		}
		else
		{
			numbin[i]=0;
		}
		cout<<numbin[i]<<endl;
	}
	return numbin;
}

int octet_detect(int b)
{
	int b_count, power_256;
	b_count=3;
	if(b>pow(256.0, b_count))
	{
		cout<<"Cannot handle that many host."<<endl;
	}
	else
	{
		do
		{
			
			power_256=pow(256.0, b_count);
			b_count--;
		}
		while (b<power_256);
	}
	return b_count+1;
}
//int mask;
//mask is between 255.0.0.0 to 255.255.255.252
//int bool[4][8];

int main(int argc, char *argv[]) {
	int* host;
	int numero;//Para numero que se convierte a binario
	int j;//Contador para realizar array para necesidades
	int k, l;//contador para realizar sorteo
	int m; //contador para funcion de deteccion de octeto
	int temporal;
	int maximum;
	/*cin>>numero;
	int* binario=transbtod(numero);
	for(q=0; q<8; q++)
	{
		cout<<*binario;
		binario++;
	}*/
	int subnetnum;//Para obtener el número de subredes que se necesitan
	cout<<"Please input the quantity of subnets"<<endl;
	cin>>subnetnum;
	host = new int[subnetnum];
	//int* host= (int*)malloc(subnetnum*sizeof(int));
	if(!host)
	{
		cout<<"Memory allocation failed.";
		exit(1);
	}
	for (j=0; j<subnetnum; j++)
	{
		cout<<"Favor de ingresar necesidad "<<j+1<<endl;
		//cin>>host[j];
		cin>>*(host + j);
		host[j]=host[j]+2;
		while(host[j]<4)
		{
		cout<<"Necesita un valor mayor o igual a 2"<<endl;
		cin>>*(host + j);
		host[j]=host[j]+2;
		}
	}
	//Sorting the pointer starting with the largest necessity
	for (k=0; k<subnetnum; k++)
	{
		for(l=k+1; l<subnetnum; l++)
		{
			if(host[l]>host[k])
				{
				temporal=*(host + k);
				*(host + k)=*(host + l);;
				host[l]=temporal;
			}
		}
	}
		cout<<"\n\n"<<endl;
	//int w;//contador para imprimir necesidades, para prueba
	/*
	for (j=0; j<subnetnum; j++)
	{
		cout<<host[j]<<endl;
	}
	*/
	//To determine all posible subnets available
	//what I need to know to see if it can use all combinations: counter to see if the available host are bigger than the necessities 
	for (k=0; k<subnetnum; k++)
	{
	octet_detect(host[m]);
	}
	return 0;
	delete[] host;
}

