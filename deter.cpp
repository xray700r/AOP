#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include "deter.h"
using namespace std;
int convert(string segment)
{
	int num=0,num1=1,itmirr=segment.length();
	
	string::const_iterator c=segment.begin();
	
	while( c!=segment.end())
	{
	if(*c=='-')
	{num1*=-1;}
	else
	{num+=(static_cast<int>(*c)-48)*pow(10,itmirr-1);}
	
	
	++c;
	--itmirr;
	}
	//cout<<num<<endl;

	return num*num1;
}
matrica::matrica()
{

	min_det=0;
	total=0;
	total1=0;
////////////	
	p=0;
	//v=0;
	x=0;
	d=0;
	dc=0;
////////////

	for(int a1=0; a1<4; a1++)
	{
	for(int b1=0; b1<4; b1++)
	{
	
	array[a1][b1]=1;
	
	}}

	//array[4][4]={1,0,2,3,
				// 1,2,3,0,
				 //4,5,1,0,
				 //1,0,1,0};//for test but memebers cannot be initialized like this anyway
	

	for(int a2=0; a2<3; a2++)
	{
	for(int b2=0; b2<3; b2++)
	{
	minore[a2][b2]=0;
	
	}}

	for(int a3=0; a3<2; a3++)
	{
	for(int b3=0; b3<2; b3++) 
	{
	min_2_2[a3][b3]=0;
	
	}}
	
}
matrica::matrica(int a)
{
	d=a*a;
	dc=a;
	
	p=new int[d];
	x=new int[d];
//	v=new int[a];
	
	for(int i=0; i<d; i++)
	{
	*(p+i)=0;
	*(x+i)=1;
	}
/*	for(int i1=0; i1<dc; i1++)
	{
	*(v+i)=0;
	}*/
	
}
void matrica::Ratioinsertmatrix()
{
	char ch='.';
	cout<<"Insert the matrix by rows!\nRational matrix elems with | instead of fractional line:\n";

	for(int i=0; i<d; i++)
	{
	
	cin>>*(p+i);

	cin>>ch;
	
	
	if(ch=='/')
	{cin>>*(x+i);
	}
	
	
	
	}
	cout<<"Insertion finished!\n";
}
void matrica::insertmatrix()
{

	cout<<"Insert the matrix by rows:\n";

	for(int i=0; i<d; i++)
	{
	
	cin>>*(p+i);
	
	}
	cout<<"Insertion finished!\n";
}

void matrica::inserTString()
{
/*the main idea is to insert a unique 
string in order to take the entire matrix
in once and then to count the spaces between nums
to control the element flow in order to insert in the matrix
the elements in order*/

	string str;
	string segment;
	cout<<"Now enter the array elements separate each by a ','\n";
	cin>>str;
	//cout<<str<<endl;

	string::const_iterator i=str.begin();
	int	counter=0,num=0;

	
	//string::const_iterator c=str.begin();
	while(i!=str.end())
	{	
	
	if(*i!=',')
	segment+=*i;
	else
	{num=convert(segment);
	 segment="0";
	if(counter<d)
	*(p+counter)=num;
	++counter;
	}

	
	++i;
	}	
	//cout<<endl;


	/*for(int c1=0; c1<d; c1++)
	{
	cout<<*(p+c1)<<' ';
	
	
	}
	cout<<endl;*/





}
void matrica::matprint(matrica& w)
{
	int mod;
	for(int i=0; i<d; i++)
	{
	
	cout<<*(w.p+i)<<'\t';
	mod=(i+1)%dc;

	if(mod==0)
	cout<<endl;
	
	}
	
}
void matrica::ratiomatprint(matrica& w)
{
	int mod;
	for(int i=0; i<d; i++)
	{
	
	cout<<*(w.p+i);
	(*(w.x+i)!=1&&*(w.x+i)!=0&&*(w.p+i)!=0)? cout<<'/'<<*(w.x+i)<<'\t':cout<<'\t';
	mod=(i+1)%dc;

	if(mod==0)
	cout<<endl;
	
	}
	
}
int matrica::isolate(int mult)
{
	int v;
	
	
	for(int i=1; i<4; i++)
	{
	v=0;
	for(int j=0; j<4; j++) 
	{		
		
		if(j!=mult)	
		{
		 minore[i-1][v]=array[i][j];
		v++;}
			
	
	}}

	return array[0][mult];
}
	
void matrica::find_min(int z)
{
	//cout<<"total from m_2//and z"<<total<<"//"<<z<<endl;
	total+=z; 	
		
}

int matrica::m_2(int m, int num)
{
	
	min_det=(pow((-1),(m+2))*(((min_2_2[0][0])*(min_2_2[1][1]))-((min_2_2[1][0])*(min_2_2[0][1])))*num);
	//cout<<"num//mindet"<<num<<"//"<<min_det<<endl;
	return min_det;

}
int matrica::calc_det(int pos)
{
	int v2;
	for(int x=1;x<3;x++)
	{
	v2=0;
	for(int y=0;y<3;y++)
	{
		if(y!=pos)
		{min_2_2[x-1][v2]=minore[x][y];
		v2++;}	
       	
	
	}}	
	return minore[0][pos];
}




void matrica::print(int dim)
{

	
	
	for(int a=0; a<dim; a++)
	{
	for(int b=0; b<dim; b++)
	{	
		if(dim==4)
		cout<<array[a][b]<<"\t";
		 
		if(dim==3)
		cout<<minore[a][b]<<"\t";
		if(dim==2)
		cout<<min_2_2[a][b]<<"\t";
	}
	cout<<endl;
	
}
	
}	
	
void matrica::int_s()
{
	for(int a=0; a<4; a++)
	{
	for (int b=0; b<4; b++)
	{
	
	cin>>array [a][b];	
	}
		
	}
	
}


int matrica::gettot()
{

	return total1;

}


int matrica::getarray(int x, int y)
{

	return array[x][y];

}

matrica::~matrica()
{
	//cout<<"Destructor:"<<total<<endl;
	delete[] p;
	delete[] x;
	//delete[] v;
	//delete[] x;//the destructor could not
	//deallocate two arrays in once it's a
	//little strange so it's better to think
	//as of deleting this line but it's not logic
	//if you declare a class vector that 
	//has a vector instead you can't allocate
	//in memory two different vectors
	
}

void matrica::settot()
{
	total=0;
	total1=0;
	
}


void matrica::fixmult(int zd, int mx)
{

	//cout<<"total before"<<total<<endl;
	total1+=pow(-1,(zd+2))*mx*total;
	//cout<<"total//zd//mx//"<<total<<"//"<<zd<<"//"<<mx<<endl;

}
void matrica::setmindet()
{
	for(int s=0; s<2; s++)
	{
	for(int d=0; d<2; d++) 
	{
	min_2_2[s][d]=0;
	
	}}


}
void matrica::fixit()
{

	total=0;
}
matrica& matrica::operator +(matrica& mx)
{
	if(this!=&mx)
	{
	for(int i=0; i<d; i++)
	{
	*(p+i)=*(p+i)*(*(mx.x+i))+*(x+i)*(*(mx.p+i));
	*(x+i)=*(x+i)*(*(mx.x+i));
	}
	}
	return *this;

}
matrica& matrica::operator *=(matrica& mx)
{

	
	if(this!=&mx)
	{
	
	for(int i=0; i<dc;i++)
	{
	for(int j=0; j<dc;j++)
	{
	*(p+j+dc*i)=*(mx.p+i+mx.dc*j);
	*(x+j+dc*i)=*(mx.x+i+mx.dc*j);
	}	
	}
	/*int count=-1;//that's true cause it's one cycle more
	for(int i=dc-1; i>=0;i--)
	{
	count++;
	for(int j=0; j<dc;j++)
	{
	*(p+j+dc*count)=*(mx.p+j+mx.dc*i);
	}	
	}*/


	}

	return *this;

}
matrica& matrica::operator -(matrica& mx)
{
	if(this!=&mx)
	{
	for(int i=0; i<d; i++)
	{
	*(p+i)=*(p+i)*(*(mx.x+i))-*(x+i)*(*(mx.p+i));
	*(x+i)=*(x+i)*(*(mx.x+i));
	}
	}
	return *this;

}
matrica& matrica::operator =(matrica& mx)
{
	
	if(this!=&mx)
	{
	if(d==mx.d)
	{
	
	for(int i=0; i<d; i++)
	{
	*(p+i)=*(mx.p+i);
	*(x+i)=*(mx.x+i);
	}
	
	}
	}
	return *this;

}
matrica& matrica::operator *(matrica& mx)
{
	
	
/*	
	int tot;
	matrica prod;
	for (int z1=0; z1<4; z1++){
	for(int w=0; w<4; w++)
	{	
	for (int z=0; z<4; z++){
	tot+=array[w][z1]*mx.array[z1][w];
	
	
	}
	prod.array[w][z1]*=0;
	prod.array[w][z1]+=tot;
	tot=0;
	}
	}
	return prod;*/
	matrica PrOd(dc);
	
	int ptot=0;
	
	if(this!=&mx)
	{
	
	for(int j1=0; j1<dc; j1++){
	
	for(int i=0; i<dc ; i++){
	
	for(int j=0; j<dc ; j++)
	{
		ptot+=*(p+j+(i*dc))*(*(mx.p+(j*mx.dc)+j1));
	
	}
	
	*(PrOd.p+(i*PrOd.dc)+j1)=ptot;
	ptot=0;
	}
	}
	//PrOd.matprint(PrOd);

    *this=PrOd;
//////////////////////////////////////////	
	
	}
	return *this;
}
matrica& matrica::operator&(int k)
{
	int mod;
	for(int i=0; i<d; i++)
	{
	
	mod=*(x+i)%k;
	if(mod==0)
	{
	*(x+i)=*(x+i)/k;	
	}
	else
	{*(p+i)*=k;}
	}
	return *this;
}
// pay attention to the operator redefined for the class
matrica& matrica::operator [](int k)
{
	int mod;	
 
	for(int i=0; i<dc;i++)
	{
	
	mod=*(p+i)%k;
	if(mod==0)
	{
	*(p+i)=*(p+i)/k;	
	}
	else
	{*(x+i)*=k;}
		
	}
		
	return *this;
	
}
void matrica::isolatematrix(int& r, matrica& mx, matrica& isol)
{

    int v=0, h=0;
	for(int i=0; i<mx.dc;i++)
	{
	
	if(i!=mx.dc*r&&v==isol.dc){h++;}
	v=0;
	for(int j=0; j<mx.dc;j++)
	{
	if(j!=r&&i!=0){
	*(isol.p+v+isol.dc*h)=*(mx.p+j+mx.dc*i);
		//cout<<*(mx.p+j+mx.dc*i)<<' ';
	//you don't have to give a generic row 
	//or line since you've selected it as 
	//the method requests one of the first rows
	//or columns
	v++;
	}
	}
	//cout<<endl;
	}
	r=*(p+r);
	//cout<<endl;
}
void matrica::ISOlatematrix(int& r,int& k, matrica& mx, matrica& isol)
{

    int v=0, h=0,t;

	if(isol.dc>2)
	{t=r;}
	else
	{t=k;}

	for(int i=0; i<mx.dc;i++)
	{
	
	if(i!=mx.dc*t&&i!=mx.dc*r&&v==isol.dc){h++;}
	v=0;
	for(int j=0; j<mx.dc;j++)
	{
	if(j!=r&&i!=r&&j!=t&&i!=t){
	*(isol.p+v+isol.dc*h)=*(mx.p+j+mx.dc*i);
	//cout<<*(mx.p+j+mx.dc*i)<<' ';
	//attention to k=r; it creates an infinite
	//cycle
	v++;
	}
	}
	//cout<<endl;
	}
	
	//cout<<endl;
}
int matrica::mx2(matrica& mx)
{
	int det=0;

	det=*p*(*(p+3))-*(p+2)*(*(p+1));
	
	return det;
}
int matrica::DET3(matrica& mx)
{
	
	total=0;
	
	int t1=0;
    matrica C(mx.dc-1); 
for(int t=0;t<mx.dc; t++)
	{
	t1=t;	
	mx.isolatematrix(t1, mx, C);
	//C.matprint(C);
	total+=pow(-1, t)*t1*C.mx2(C);
		/*cout<<t<<endl;
		cout<<"pow:"<<pow(-1, t);
		cout<<"elem:"<<t1;
		cout<<"min2x2:"<<C.mx2(C);
		cout<<"total:"<<total;*/
	}
	
	return total;
}
int matrica::DET4(matrica& mx)
{
	
	total1=0;
	
	int t1=0;
    matrica C(mx.dc-1); 
for(int t=0;t<mx.dc; t++)
	{
	t1=t;	
	mx.isolatematrix(t1, mx, C);
	//C.matprint(C);
	total1+=pow(-1, t)*t1*C.DET3(C);
		/*cout<<t<<endl;
		cout<<"pow:"<<pow(-1, t);
		cout<<"elem:"<<t1;
		cout<<"min2x2:"<<C.mx2(C);
		cout<<"total:"<<total;*/
	}
	
	return total1;
}
void matrica::jacmat(matrica& mx)
{
	
	matrica Hj(mx.dc);

	for(int i=0;i<mx.dc;i++)
	{
		
	for(int j=0;j<mx.dc;j++)
	{
	if(i!=j)
	{*(Hj.p+i*dc+j)=*(mx.p+i*dc+j);
	 *(Hj.p+i*dc+j)*=(-1);}
	
	*(Hj.x+i*dc+j)=*(mx.p+i*(dc+1));
	}
	
	}
	

	/*
	for(int j1=0;j1<mx.dc;j1++)
	{
		
	cout<<*(mx.p+j1*(dc+1))<<endl;
	//*(Hj.x+i*dc+j)=
	}*/

	mx=Hj;

}
int matrica::trAx(matrica& mx)
{
	total=1;
	total1=1;
	int mod=1;
	

	for(int i=0;i<mx.dc;i++)
	{
		total*=*(mx.p+i*(mx.dc+1));
		total1*=*(mx.x+i*(mx.dc+1));
	//Vect.Gauss_fromMatrix(value,i,ratio);
	//just to decide total+= or total*= 
	}
	
	
	cout<<"trA="<<total<<'/'<<total1;
	if(total1!=0){
	mod=total%total1;}
	if(mod==0)
	cout<<'='<<total/total1<<endl;
	return total;


}
int matrica::sigma(matrica& mx, int s)
{
	total1=0;
	matrica C(s);
	for(int a=0; a<mx.dc;a++)
	{	
	for(int b=0; b<mx.dc;b++){
	if(a!=b)
	{mx.ISOlatematrix(a,b,mx,C);
	
	if(s==2)
	{total1+=C.mx2(C);}
	else
	if(s==3)
	{total1+=C.DET3(C);}
	else
	if(s==4)
	{total1+=C.DET4(C);}

	
	
	}
	}}


	return total1/=s;
}
void matrica::createIdentic(matrica& mx)
{
	
	for(int i=0;i<mx.dc;i++)
	{
	*(mx.p+i*(dc+1))=1;
	*(mx.x+i*(dc+1))=1;}


}
void matrica::Pow(matrica& mx, int e)
{


    matrica PrOd(mx.dc);
	matrica mx1(mx.dc);
	int ptot=0,j2=0;
	mx1=mx;
	if(e!=1){
	for(int ex=0; ex<e-1; ex++){
	
	for(int j1=0; j1<dc; j1++){
	
	for(int i=0; i<dc ; i++){
	
	for(int j=0; j<dc ; j++)
	{
		ptot+=*(mx1.p+j+(i*dc))*(*(mx.p+(j*mx.dc)+j1));
	
	}
	
	*(PrOd.p+(i*PrOd.dc)+j1)=ptot;
	ptot=0;
	}
	}
	mx1=PrOd;
	}

	mx=PrOd;}
	else{
	cout<<"The matrix is A^1=A\n";}

}
void matrica::Gauss_Jordan(matrica& mx,matrica& Id, int k1,int k2, int col, int add)
{
	
	for(int i=0; i<dc;i++)
	{
	if(k2!=1){
	*(mx.p+i+dc*(col-1))*=k2;
	*(Id.p+i+dc*(col-1))*=k2;
	}
	*(mx.p+i+dc*(col-1))+=k1*(*(mx.p+i+dc*(add-1)));
	*(Id.p+i+dc*(col-1))+=k1*(*(Id.p+i+dc*(add-1)));
	}



}
void matrica::TriMat(matrica& mx, matrica& trs, matrica& tri, matrica& dia)
{

	matrica TrInf(mx.dc);

	matrica TrSup(mx.dc);
	
	matrica Diag(mx.dc);


	for(int i=0; i<mx.dc; i++)
	{
	
	for(int j=0; j<mx.dc; j++)
	{
	if(j<i)
	{
	*(TrInf.p+mx.dc*i+j)=*(mx.p+mx.dc*i+j);
	}
	if(j>i)
	{
	*(TrSup.p+mx.dc*i+j)=*(mx.p+mx.dc*i+j);
	}
	if(j==i)
	{
	*(Diag.p+mx.dc*i+j)=*(mx.p+mx.dc*i+j);
	}
	
	}
	
	}
	trs=TrSup;
	tri=TrInf;
	dia=Diag;
	/*TrSup.matprint(TrSup);
	TrSup&-1;
	cout<<"The F matrix is\n";
	TrSup.matprint(TrSup);
	TrInf&-1;
	cout<<"The E matrix is\n";
	TrInf.matprint(TrInf);
	Diag-TrInf;
	cout<<"The D-E matrix is:\n";
	Diag.matprint(Diag);*/
	//mx=Diag;

}
void matrica::Sim2_diag(matrica& mx)
{


	matrica Sim(mx.dc);
for(int i=dc-1; i>=0 ; i--){
	
	for(int j=dc-1; j>=0 ; j--)
	{
		
	*(Sim.p+j+dc*i)=*(mx.p+j*dc+i);
	cout<<*(Sim.p+j+dc*i)<<' ';

		
	}
	cout<<endl;
	}
	mx=Sim;


}
void matrica::Process_tr(matrica& mx)
{

	matrica tRi(mx.dc);
	matrica tRi1(mx.dc);
	matrica tRs(mx.dc);
	matrica dIa(mx.dc);
	matrica IdI(mx.dc);
	int mod, delem,outcnt=0, mod2=1;
	cout<<"Process initialized\n";
	mx.TriMat(mx,tRs,tRi,dIa);
	IdI.createIdentic(IdI);
	int n=mx.dc;

	for(int i=0; i<mx.dc; i++)
	{
	delem=*(mx.p+i+mx.dc*i);
	outcnt++;
	//cout<<delem<<"is delem\n";
	for(int j=outcnt; j<mx.dc; j++)
	{
	
	
	if(outcnt>0)
	{mod=delem%(*(mx.p+mx.dc*j+i));
	//cout<<*(tRi.p+mx.dc*j+i)<<'\t';
	//cout<<mod<<"is mod\n";
	if(mod==0){
	mod=delem/(*(mx.p+mx.dc*j+i));
	cout<<"mod=0=>multiples\n"<<*(mx.p+i+mx.dc*i)<<"diag\t"<<*(mx.p+mx.dc*j+i)<<"tri\t"<<"i,j"<<i<<','<<j<<endl;
	mx.Gauss_Jordan(mx,IdI,-mod,mod2,j+1,i+1);
	}
	
	}
	mx.matprint(mx);
	cout<<"//////////////\n";
	IdI.matprint(IdI);
	}
	//cout<<endl;
	}
cout<<"Process finished\n";
	//mx=tRi;
}
///////////////////////////////////////////////////////////////////////////////
void matrica::Gauss_elem::vectorprod(Gauss_elem& mv1, Gauss_elem& mv2, matrica& E)
{

	int temp, temprat;
	
for(int i=0; i<nc ; i++){
	
	for(int j=0; j<nc ; j++)
	{
	temp=*(mv1.v+j)*(*(mv2.v+i));
	temprat=*(mv1.xv+j)*(*(mv2.xv+i));
	E.inTerfacetoMatrica(E, j, i,temp, temprat)	;
	
	}
	
	
	}
	
	/*cout<<"From vectorprod:\n";
		E.ratiomatprint(E);
		cout<<"/////////\n";*/
}
void matrica::Gauss_elem::inserTVector()
{
	char ch;
	cout<<"Enter your vector by column or as it is transposed by row!\n";
	for(int i=0; i<nc; i++)
	{
	
	cin>>*(v+i);

	cin>>ch;
	
	
	if(ch=='/')
	{cin>>*(xv+i);
	}
	
	
	
	}
	

	cout<<"Vector insertion finished!\n";
}
void matrica::Gauss_elem::inserTVinteg()
{
for(int i=0; i<nc; i++)
	{
	cin>>*(v+i);
	}
	cout<<"Vector insertion finished!\n";
}
void matrica::Gauss_elem::prinTVector()
{
	
	for(int e=0;e<nc;e++)
	{
	cout<<'|'<<*(v+e);
	(*(xv+e)==1) ? cout<<' ':cout<<'/';
		
		
		cout<<'|'<<endl;	
	}

	
}
void matrica::Gauss_elem::Gauss_Elematrix(matrica& mx ,matrica& W)
{

	int delem=0,delemrat,cnt=1,c=nc;//,i=1;
	matrica I(c);
	matrica L(c);
	matrica L1(c);
	matrica R(c);
	matrica CpY(c);
	CpY=W;
	bool sgn;
	Gauss_elem e(c);
	Gauss_elem e1(c);
	e.HandleInitMatrix(W);
	I.createIdentic(I);
	L=I;
	L1=I;
	

for(int i=0; i<c-1; i++)
	{
	
	I.NULLMatrix(I);

	I.createIdentic(I);
	R.NULLMatrix(R);
	e.NULLVECTOR(e);
	e1.NULLVECTOR(e1);
	W.inTerfacetoGauss(W,i,i,delem,delemrat);	
	//cout<<delem<<"is delem\n";
	e1.createBasE(e1,i);
	//e1.prinTVector();
	e.Constmult(e,i,W,delem,delemrat);
	//e.prinTVector();
	e1.vectorprod(e1,e,R);
	//R.ratiomatprint(R);
	R.mcd(R);
	
	//cout<<"R and I for test purposes\n";
	//R.ratiomatprint(R);
	L+R;
	//cout<<"Identic I:\n";
	//I.ratiomatprint(I);
	I-R;
	

	cout<<"Gauss Matrix M"<<i<<"is:\n";
	I.ratiomatprint(I);
	
	//mx.ProductRational(L1,mx);

	I.ProductRational(I,W);
	I.mcd(I);
	
	

	W=I;
	cout<<"Result of heap_"<<i<<"is:\n";
	I.ratiomatprint(I);
    sgn=W.testDiag(W);
	if(sgn)
	cnt*=-1;

	CpY=I;
    
/*	cout<<"matrica from write matrix CpY\n";
	CpY.ratiomatprint(CpY);
	cout<<">>>>>>>>>>>>>>>\n";*/
	}

	W=CpY;
	//mx=L1; //trying to get the inverse of
	//the matrix by the elematrix funciton
	
	cout<<"Matrix L for the LR factorization, using Gauss method!\n";
	L.ratiomatprint(L);
	cout<<"_____________________________________\n";
	cout<<"Coefficient to multiply the DET because of switching:"<<cnt<<endl;
		
}
void matrica::Gauss_elem::createBasE(Gauss_elem& e, int pos)
{

	*(e.v+pos)=1;
	//e.prinTVector();


}
void matrica::Gauss_elem::Constmult(Gauss_elem& e, int k,matrica& E, int diag, int diagrat)
{
	
	
	int val=0, rati;
	for(int j=0; j<e.nc; j++)
	{
	if(j>k)
	{E.inTerfacetoGauss(E,j, k, val,rati);
	//cout<<val<<rati<<"val/ ratio\n";
	*(e.v+j)=val*diagrat;
	
	*(e.xv+j)=diag*rati;
	}	
	
	}	
	
	

}
void matrica::Gauss_elem::VectorDiff(Gauss_elem& e,Gauss_elem& e1)
{
	
	
	for(int c=0; c<e.nc; c++)
	{
	
	*(e.v+c)-=*(e1.v+c);
	
	
	}

}
void matrica::Gauss_elem::proDmatrix(Gauss_elem& A, Gauss_elem& mx)
{
	
	


	
//////////////////////////////////////////	
	
	

}
matrica::Gauss_elem::Gauss_elem()
{
		
	
////////////	
	
	v=0;
	nc=0;
	
////////////

	
	
}
matrica::Gauss_elem::Gauss_elem(int a)
{
	nc=a;	
	v=new int[a];
	xv=new int[a];
	for(int i=0; i<nc; i++)
	{
	*(v+i)=0;
	*(xv+i)=1;
	}
	
}
matrica::Gauss_elem::~Gauss_elem()
{
	
	delete[] v;
	delete[] xv;
}

void matrica::inTerfacetoMatrica(matrica& M, int j, int i, int& val, int& valrat)
{


   *(M.p+j+(i*M.dc))=val;
   *(M.x+j+(i*M.dc))=valrat;


}
void matrica::inTerfacetoGauss(matrica& M, int j, int i, int& val, int& valrat)
{


   val=*(M.p+i+(j*M.dc));
   valrat=*(M.x+i+(j*M.dc));

}
matrica::Gauss_elem& matrica::Gauss_elem::operator =(Gauss_elem& m)
{
	
	if(this!=&m)
	{
	for(int i=0;i<nc;i++)
	{
	
	*(v+i)=*(m.v+i);
	
	
	}
	}

	return *this;
}
void matrica::ProductRational(matrica& A,matrica& B)
{
	matrica PrOd(A.dc);
	matrica::Gauss_elem Vector(A.dc);
	int ptot=0,c=A.dc,prodN=1,prodD=1;

  for(int j1=0; j1<c; j1++){
	
	for(int i=0; i<c ; i++){
	
	for(int j=0; j<c ; j++)
	{
		//ptot+=*(A.p+j+(i*c))*(*(B.p+(j*c)+j1));

		prodN=*(A.p+j+(i*c))*(*(B.p+(j*c)+j1));
		prodD=*(A.x+j+(i*c))*(*(B.x+(j*c)+j1));
		//cout<<prodD<<"is prod D\n";
		Vector.Gauss_fromMatrix(prodN,j,prodD);
		
			
	}
	ptot=Vector.VectorNorma(Vector,prodD);
	//cout<<Vector.VectorNorma(Vector,prodD)<<endl;
	*(PrOd.p+(i*c)+j1)=ptot;
	*(PrOd.x+(i*c)+j1)=prodD;
	ptot=0;
	}
	}
	//PrOd.matprint(PrOd);

    A=PrOd;




}
int  matrica::Gauss_elem::VectorNorma(Gauss_elem& e,int& Pro)
{
	
	int Sigma=0, Prod=1;
	for(int c=0; c<e.nc; c++)
	{
		for(int s=0;s<e.nc; s++)
		{	if(s!=c)
		{*(e.v+c)*=*(e.xv+s);}
		}
	Sigma+=*(e.v+c);
	Prod*=*(e.xv+c);
	
	}
	Pro=Prod;
	//cout<<Sigma<<'/'<<Prod<<"S/P\n";
	return Sigma;
}
void matrica::Gauss_elem::Gauss_fromMatrix(int val, int pos,int rat)
{

	
	*(v+pos)=val;
	
	*(xv+pos)=rat;


}
void matrica::NULLMatrix(matrica& mx)
{

	for(int i=0; i<d;i++)
	{
	*(mx.p+i)=0;
	*(mx.x+i)=1;
	}

}
void matrica::mcd(matrica& div)
{

	int tmp=1;
	int mcd=1;

	for(int r1=0; r1<div.d; r1++)
	{
	//mcd*=*(x+r1);
	if(*(div.x+r1)!=0){
	mcd=*(div.p+r1)%*(div.x+r1);
	if(mcd==0)
	{*(div.p+r1)/=*(div.x+r1);
	 *(div.x+r1)=1;}
	else
	{
		mcd=*(div.p+r1);
		tmp=*(div.x+r1);
		int rest;
	while (tmp != 0)
	{	rest = mcd % tmp;
		mcd = tmp;
		tmp = rest;
	}
	*(div.p+r1)/=mcd;
	*(div.x+r1)/=mcd;
	}
	}
	}

	

//////////////////////////////////////////////	
}
	
void matrica::Gauss_elem::NULLVECTOR(Gauss_elem& E)
{
	for(int i=0; i<E.nc;i++)
	{	
	*(E.v+i)=0;
	*(E.xv+i)=1;	
	}

}
/* Just trying to get harder on the argument of triangularization
if the program encounters a zero element on the principal diagonal 
it behaves automatically like doing the Gauss array but for the triangularization 
of certain arrays it is necessary to switch some rows so it has to be controlled in some 
way */
bool matrica::testDiag(matrica& mx)
{
	
	bool sgn=false;
	matrica::Gauss_elem V(mx.dc);
	for(int i=0; i<mx.dc;i++)
	{	
	if(*(mx.p+(mx.dc+1)*i)==0)
	{
	sgn=true;
	V.SWreadrow(mx,i);
	cout<<"A zero has been detected in the diagonal!\nAs a result the Gauss method is no longer valid for the LR factorization.\n\a";
	break;

	}	
	}

	return sgn;
	



}
void matrica::Gauss_elem::SWreadrow(matrica& mx, int row)
{
	matrica::Gauss_elem vector(nc);
	matrica::Gauss_elem vector1p(nc);
	
	int val, valrat;
	//trying to fix a zero in end of main diag
	
	for(int i=0; i<nc; i++)
	{
	mx.inTerfacetoGauss(mx,row,i,val,valrat);
	*(vector.v+i)=val;
	*(vector.xv+i)=valrat;
	mx.inTerfacetoGauss(mx,row+1,i,val,valrat);
	*(vector1p.v+i)=val;
	*(vector1p.xv+i)=valrat;
	}
	if(row+1<nc)
	{
		//vector.prinTVector();
		//vector1p.prinTVector();
	//vector.Switch(vector,vector1p);
	vector.SWwriterow(mx,vector1p,vector,row);

	}
	

}
void matrica::Gauss_elem::Switch(Gauss_elem& vectorA, Gauss_elem& vectorB)
{
	
	matrica::Gauss_elem vectorC(nc);

		vectorC=vectorA;
		vectorA=vectorB;
		vectorB=vectorC;
		vectorA.prinTVector();
		vectorB.prinTVector();

}
void matrica::Gauss_elem::SWwriterow(matrica& mx, Gauss_elem& A,Gauss_elem& B,int row)
{
	matrica::Gauss_elem vector(nc);
	matrica::Gauss_elem vector1p(nc);
	
	int val, valrat;
	for(int i=0; i<nc; i++)
	{
	val=*(A.v+i);
	//cout<<val<<'|'<<valrat<<'\n';
	valrat=*(A.xv+i);
	mx.inTerfacetoMatrica(mx,i,row,val,valrat);
	
	val=*(B.v+i);
	valrat=*(B.xv+i);
	mx.inTerfacetoMatrica(mx,i,row+1,val,valrat);
	}
	/*cout<<"matrica from write matrix\n";
	mx.ratiomatprint(mx);
	cout<<">>>>>>>>>>>>>>>\n";*/
}
void matrica::Gauss_elem::HandleInitMatrix(matrica& mx)
{
	int val, valrat,swRow=0,swRow1=0;
	matrica::Gauss_elem line(nc);
	for(int j=0; j<nc; j++)
	{
	mx.inTerfacetoGauss(mx,j,j,val,valrat);	
	
	*(line.v+j)=val;

	}
	if(*line.v==0)
	{
	swRow=0;
	swRow1=nc-1;
	}
	else
	{
	if(*(line.v+nc-1)==0)
	{
	swRow=nc-1;
	swRow1=0;
	
	
	}
	
	}



	matrica::Gauss_elem vector(nc);
	matrica::Gauss_elem vector1p(nc);
	
	
	
	for(int i=0; i<nc; i++)
	{
	mx.inTerfacetoGauss(mx,swRow,i,val,valrat);
	*(vector.v+i)=val;
	*(vector.xv+i)=valrat;
	mx.inTerfacetoGauss(mx,swRow1,i,val,valrat);
	*(vector1p.v+i)=val;
	*(vector1p.xv+i)=valrat;
	}
	
		//vector.prinTVector();
		//vector1p.prinTVector();
	vector.SWwriterowHandle(mx,vector1p,vector,swRow,swRow1);

	

}
void matrica::Gauss_elem::SWwriterowHandle(matrica& mx, Gauss_elem& A,Gauss_elem& B,int swRow,int swRow1)
{
	matrica::Gauss_elem vector(nc);
	matrica::Gauss_elem vector1p(nc);
	
	int val, valrat;
	for(int i=0; i<nc; i++)
	{
	val=*(A.v+i);
	//cout<<val<<'|'<<valrat<<'\n';
	valrat=*(A.xv+i);
	mx.inTerfacetoMatrica(mx,i,swRow,val,valrat);
	
	val=*(B.v+i);
	valrat=*(B.xv+i);
	mx.inTerfacetoMatrica(mx,i,swRow1,val,valrat);
	}
	/*cout<<"matrica from write matrix\n";
	mx.ratiomatprint(mx);
	cout<<">>>>>>>>>>>>>>>\n";*/
}
void matrica::Gauss_elem::MatrixXVector(matrica& mx, Gauss_elem& V)
{


	int temp,temprat;
	Gauss_elem Prod(V.nc);
	Gauss_elem Prodret(V.nc);
	
	for(int i=0; i<nc ; i++){
	
	for(int j=0; j<nc ; j++)
	{
	
	mx.inTerfacetoGauss(mx, i, j,temp, temprat)	;
	*(Prod.v+j)=*(V.v+j)*temp;
	*(Prod.xv+j)=*(V.xv+j)*temprat;
	}
	*(Prodret.v+i)=Prod.VectorNorma(Prod,temp);
	*(Prodret.xv+i)=temp;
	
	}
	
	/*cout<<"From MatrixXVector:\n";
		V.ratiomatprint(V);
		cout<<"/////////\n";*/
	V=Prodret;

}
/*pretty good idea to switch the rows for the vector
but it has to be called from the handle functions over all the program 
so it is a little messy to go on with this*/
void matrica::Gauss_elem::VectorSWitch(int row1, int row2, Gauss_elem& S)
{
	int a,ar,br,b;

	a=*(S.v+row1);
	ar=*(S.xv+row1);
	b=*(S.v+row2);
	br=*(S.xv+row2);

	*(S.v+row1)=b;
	*(S.xv+row1)=br;
	*(S.v+row2)=a;
	*(S.xv+row2)=ar;

}