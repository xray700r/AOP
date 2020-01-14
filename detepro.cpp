#include <iostream>
#include <cmath>
#include "deter.h"
using namespace std;
matrica::matrica()
{
	//array[4][4]={0};
	//minore[3][3]={0};
	min_det=0;
	//min_2_2[2][2]={0};
	contx=0;
	conty=0;
	total=0;
		
}
	
void matrica::find_min()
{
	
	matrica fun;
	for(int dx=0;dx<3;dx++)
	{
	fun.calc_det(minore[dx][0], dx);
	}

	
}

void matrica::m_2()
{
	min_det=((min_2_2[1][1])*(min_2_2[2][2]))-((min_2_2[2][1])*(min_2_2[1][2]));
}
void matrica::calc_det(int z, int pos)
{
	matrica fx;
	for(int x=0;x<3;x++)
	{
	for(int y=0;y<3;y++)
	{
		for(int x1=0;x1<2;x1++)
	{
	for(int y1=0;y1<2;y1++)
	{
		if(x!=pos && y!=pos)
		{min_2_2[x1][y1]=minore[x][y];}	
       			
	}
		}
	fx.m_2();
	total+=min_det*z*pow(-1,pos+1);
	}
		}

	cout<<"The det of the array is:|A|="<<total<<endl;
}




void matrica::print()
{
	for(int a=0; a<4; a++)
	{
	for(int b=0; b<4; b++)
	{ 
		cout<<array[a][b]<<' ';
	}
	cout<<endl;

}
	
	
	
void matrica::int_s(int al)
{
	 
	
	
	
	/*for (int plx=contx;plx<contx+1;plx++)
	{
	for (int ply=conty;ply<conty+1;ply++)
	{
		array[plx][ply]=num;
	
	}
	}

	

	conty=1;
	contx=1;*/
	int a=0;
	int b=0;
	for(; a<4; a++)
	{
	for(; b<4; b++)
	{
	array[a][b]=al;
	
	
	}}
	
}