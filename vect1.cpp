#include <iostream>
#include <cmath>
//#include <conio.h>
#include <malloc.h>
using namespace std;
#include "vecthead.h"
void vector::printvect(vector& w)
{
	
	
	cout<<"P"<<num<<"(x)=";
		for(int n=0; n<w.a; n++)
	{
		
			(*(w.p+n)==1&&n!=w.a-1) ? cout<<' ': cout<<*(w.p+n);
			((w.a-n-1)==0) ? cout<<' ': cout<<"x^"<<w.a-n-1;
			(*(w.p+n+1)<0) ? cout<<' ' : cout<< '+';
	
	}
	num++;	
				//cout<<endl;
			cout<<"Printvect called"<<endl;
}
void vector::printcolumn(vector& w)
{
	
	
	
		for(int n=0; n<w.a; n++)
	{
		
			cout<<*(w.p+n);
			
			(*(w.x+n)==1 || *(w.x+n)==0 || *(w.p+n)==0) ? cout<<' ':cout<<'/'<<*(w.x+n)<<' ';
			
	
	}
	
		cout<<endl;
		cout<<endl;
}
void vector::printrational(vector& w)
{
	
	
	
		for(int n=0; n<w.a; n++)
	{
		
			//cout<<"w.a="<<w.a<<endl;

			(*(w.p+n)==1&&n!=w.a-1&&*(w.x+n)==1||*(w.p+n)==0)  ? cout<<' ': cout<<*(w.p+n);
			(*(w.x+n)==1) ? cout<<' ':cout<<'/'<<*(w.x+n)<<' ';
			((w.a-n-1)==0||*(w.p+n)==0) ? cout<<' ': cout<<"x^"<<w.a-n-1;
			(*(w.p+n+1)<0||*(w.p+n)==0 || n==w.a-1) ? cout<<' ' : cout<< '+';
	
	}
	
		cout<<endl;
		cout<<endl;
		cout<<"Printrational called"<<endl;
}

vector::vector()
{
	p=0;
	q=0;
	a=0;
	x=0;
	x1=0;
	num=0;
	E=0;
	iT=0;
	
}
vector::vector(int d)
{
	a=d+1;
	p=new int[a];
	x=new int[a];

	for(int n=0; n<a; n++)
	{
		
		*(p+n)=0;
		*(x+n)=1;
		
	}
	num=0;	
	iT=0 ;
}

vector::~vector()
{
	
	delete[] p;
	delete[] x;
	
}
void vector::insertrational()
{
	char slash;
	cout<<"Enter the parameters in decreasing order of the exponent (Higher to Lower) \n(For the rational ones use : to divide the enumerator from the divider):\n";	
	for(int r=0; r<a; r++)
	{
	cin>>*(p+r);
	cin>>slash;
	if(slash==':')
	{cin>>*(x+r);
	cout<<"x^"<<a-r-1<<" \n";}
	else
		cout<<"x^"<<a-r-1<<" \n";

	}
	cout<<"Insert the Error limit E<10^-n\n";
	cin>>E;
	cout<<"____________________________________\n";
	
}

void vector::insert()
{
	
	cout<<"Enter the parameters in decreasing order of the exponent:\n";	
	for(int r=0; r<a; r++)
	{
	cin>>*(p+r);
	
	}
	cout<<"Insert the Error limit E<10^-n\n";
	cin>>E;
	cout<<"____________________________________\n";
	
}

double vector::calculate(double l)
{
	
	double total=0;
	int exp=a-1;
	for(int r=0; r<a; r++)
	{		
		total+=*(p+r)*pow(l,exp);
		exp--;	
	}
	//cout<<"The calculated value for the expression is:\n"<<total<<endl;
	return total;

}
void vector::derivate(int c)
{
	int exp1=a-1;

	cout<<"The numbers in the brackets are the exponents of the polynomial derivate.\n";
	if(c==1)
	{
	cout<<"P'(x)=";
		for(int r=0; r<a; r++)
	{		
		cout<<exp1*(*(p+r))<<"x^"<<exp1-1;
		*(p+r+1)<=0 ? cout<<' ' :cout<<'+';
		exp1--;	
	}

		cout<<endl;}
	else
	{
	int exp2=a-1;
	cout<<"P''(x)=";
		for(int r=0; r<a; r++)
	{		
		cout<<exp2*(exp2-1)*(*(p+r))<<"x^"<<exp2-2;
		*(p+r+1)<=0 ? cout<<' ' :cout<<'+';
		exp2--;	
	}

		cout<<endl;
	}

}
vector& vector::operator/(vector& div)
{
//////////////////////////////////////////////
	
	vector REMAIN(a-1);
	if(this!=&div)
	{
	
	int Q_uotientp=1,Q_uotientx=1;
	


	for(int r1=0; r1<a; r1++)
	{
	*(REMAIN.p+r1)=*(p+r1);
	*(REMAIN.x+r1)=*(x+r1);
	}
	vector Temp(div.a-1);
	/*cout<<"REMAIN AFTER COPY\n";
	REMAIN.printrational(REMAIN);*/
	
	if(a>=div.a)
	{
		do{
		Temp=div;
		/*cout<<"Temp=div\n";
	    Temp.printrational(Temp);*/
		//cout<<"REMAIN.p="<<*(REMAIN.p)<<*(Temp.p)<<*(REMAIN.x)<<*(Temp.x)<<endl;
		Q_uotientp=*(REMAIN.p)*(*(div.x));
		Q_uotientx=*(REMAIN.x)*(*(div.p));
		/*cout<<"Q_uotientp="<<Q_uotientp<<endl;
		cout<<"Q_uotientx="<<Q_uotientx<<endl;
		cout<<"REMAIN.a-div.a="<<REMAIN.a-div.a<<endl;*/
		for(int iter=0; iter<REMAIN.a-div.a;iter++)
		{
		Temp.Rshift(Temp);	
		}
		/*cout<<"Temp.Rshift(Temp);\n";
	    Temp.printrational(Temp);
		Mod=Q_uotientp%Q_uotientx;*/
		
		Temp=Temp&Q_uotientp;
	         
		Temp=Temp/=Q_uotientx;

		/*cout<<"Temp&Q_uotientp;\n";
		cout<<"Temp&Q_uotientx;\n";
	    Temp.printrational(Temp);
		cout<<"REMAIN\n";
	    REMAIN.printrational(REMAIN);*/


		REMAIN=REMAIN-Temp;

		/*cout<<"REMAIN-Temp\n";
	    REMAIN.printrational(REMAIN);*/

		REMAIN.Lshift(REMAIN);

		/*cout<<"REMAIN.Lshift(REMAIN);\n";
	    REMAIN.printrational(REMAIN);*/

		}while(REMAIN.a>=div.a);
	//REMAIN.a>=div.a getch()!='w' // jus don't use getch() for Linux g++ compiling conio.h is only MSDOS
	*this=REMAIN;
	
		}
	else
	{
		vector null(0);
		cout<<"The divisor is greater than the divider!\n";
		*this=div;
		
	
	}
	
	}
	
	return *this;

//////////////////////////////////////////////
	


}
vector& vector::operator=(vector& div)//ok now
{
	if(this!=&div)
	{
	if(a>=div.a){
	for(int r=0; r<a; r++)
	{
	
	*(p+r)=*(div.p+r);
	*(x+r)=*(div.x+r);

	if(r>div.a)
	{*(p+r)=0;
	 *(x+r)=1;}
	
		}
		}
	else
	{
	int* px=p;
	int* xx=x;
	q= new int[div.a];
	x1= new int[div.a];
	
	
	for(int r1=0; r1<div.a; r1++)
	{
	
	*(q+r1)=*(div.p+r1);
	//if(_heapchk()!=_HEAPOK)
     //cout<<"OK\n";
	*(x1+r1)=*(div.x+r1);		

	}
	
	p=q;
	x=x1;

	delete[] px;
	delete[] xx;

	
	}
	a=div.a;
	}

	return *this;
	
}

bool vector::root(double root)
{
	double tmp=0;
	double remainder=0;
	vector pm1(a-2);
	int s=1;
	*(pm1.p)=*p;
	tmp=*p;
	while (s<a)
	{
	remainder=0;
	remainder+=*(p+s)+tmp*root;
	//cout<<"("<<remainder<<")\t";
	tmp=remainder;
	if(s<a-1&&s>0)
	{*(pm1.p+s)=remainder;}

	s++;
	}
	cout<<endl;

	cout<<"The n-1 degree polynomial\n";
	pm1.printvect(pm1);
	cout<<"Remain:["<<remainder<<"]\n";
	if (remainder==0)
		return true;
	else 
		return false;
}
vector& vector::operator+(vector& div)
{
//////////////////////////////////////////////
	if(this!=&div)
	{
	
	if(a>div.a){
	
	for(int r2=0; r2<a; r2++)
	{	
		
		if(r2>=a-div.a)
		{*(p+r2)+=*(div.p+r2-1);}
	}
	
	
		}
	else{
	if(a==div.a){
	
	for(int r2=0; r2<a; r2++)
	{	
		
		if(r2>=a-div.a)
		{*(p+r2)+=*(div.p+r2);}
	}
	
	
	}
	else
	{
	int* px=p;
	q= new int[div.a];
	
	for(int r2=0; r2<div.a; r2++)
	{	
	*(q+r2)=*(div.p+r2);
	}
	
	for(int r1=div.a-a; r1<div.a; r1++)
	{	
	*(q+r1)+=*(div.p+r1);
	}
	p=q;

	delete[] px;
	a=div.a;
	}}
	
	}


	return *this;
	
	 
	
//////////////////////////////////////////////


}
// this is a strange situation cause the logic of the 
// the events is ok but the program causes
// logic errors or memory errors
vector& vector::operator-(vector& div)
{
//////////////////////////////////////////////
	if(this!=&div)
	{

	

	if(a>div.a){
	
	for(int r2=0; r2<a; r2++)
	{	
		
		if(r2>=a-div.a)
		{//*(p+r2)-=*(div.p+r2-1);
			//*(p+r2)=*(p+r2)*(*(div.x+r2))-*(x+r2)*(*(div.p+r2));
			//*(x+r2)=*(x+r2)*(*(div.x+r2));
		}
	}
	
	
		}
	else{
	if(a==div.a){
	
	for(int r2=0; r2<a; r2++)
	{	
		
		
		//*(p+r2)-=*(div.p+r2);
		if(*(x+r2)!=*(div.x+r2))
		{*(p+r2)=*(p+r2)*(*(div.x+r2))-*(x+r2)*(*(div.p+r2));
		*(x+r2)=*(x+r2)*(*(div.x+r2));}
		else
		{
		if(*(x+r2)==*(div.x+r2))
		{
		*(p+r2)-=(*(div.p+r2));
		//*(x+r2)=*(x+r2)*(*(div.x+r2));
			
		
		
		}
		
		
		}
		
	}
	
	
	}
	else
	{
	int* px=p;
	q= new int[div.a];
	
	for(int r2=0; r2<div.a; r2++)
	{	
	*(q+r2)=*(div.p+r2);
		//*(p+r2)=*(p+r2)*(*(div.x+r2))-*(x+r2)*(*(div.p+r2));
		//*(x+r2)=*(x+r2)*(*(div.x+r2));
	}
	
	for(int r1=div.a-a; r1<div.a; r1++)
	{	
	*(q+r1)-=*(div.p+r1);
		//*(q+r1)=*(p+r1)*(*(div.x+r1))-*(x+r1)*(*(div.p+r1));
		//*(x+r1)=*(x+r1)*(*(div.x+r1));
	}
	p=q;

	delete[] px;
	a=div.a;
	}}
	
	}

	return *this;
}
vector& vector::operator &(int k)
{
//////////////////////////////////////////////
	//int mod;
		
	for(int r1=0; r1<a; r1++)
	{
	*(p+r1)*=k;
	/*if(k!=0)	
	{mod=*(x+r1)%k;

	if(mod==0)
	{*(x+r1)/=k;}
	else
	{*(p+r1)*=k;}}*/
	
	}

	return *this;
	
	 
	
//////////////////////////////////////////////


}
void vector::Simplify(vector& sim)
{
//////////////////////////////////////////////
	int mod, k=1, min,max,mod1;
		

	vector mcd(sim.a-1);
	vector mcd1(sim.a-1);
	
	bool ordered;

	for(int cpy=0;cpy<mcd1.a;cpy++)
	{
	*(mcd1.x+cpy)=abs(*(sim.x+cpy));
	*(mcd1.p+cpy)=0;
	}


	do{

	ordered=true;

	for(int d=0;d<mcd1.a-1;d++)
	{
	if(*(mcd1.x+d)>*(mcd1.x+d+1))
	{mod=*(mcd1.x+d);

	*(mcd1.x+d)=*(mcd1.x+d+1);

	*(mcd1.x+d+1)=mod;
	
	ordered=false;}	

	}
	
	}while(!ordered);


/*	for(int d1=0;d1<mcd1.a;d1++)
	{
	cout<<*(mcd1.x+d1)<<' ';	
	}
	cout<<endl;*/
	for(int de=0;de<mcd1.a-1;de++)
	{
	*(mcd1.p+de)=abs(*(mcd1.x+de)-*(mcd1.x+de+1));	
	}

/*	for(int d2=0;d2<mcd1.a;d2++)
	{
	cout<<*(mcd1.p+d2)<<' ';	
	}*/
	
	int pr=1;
	
	for(int rs=0; rs<mcd1.a-1; rs++)
	{
	//cout<<"delta:"<<*(mcd1.x+rs)-*(mcd1.x+rs+1)<<endl;
	if(*(mcd1.p+rs)!=0)
		{pr*=*(mcd1.x+rs)+*(mcd1.p+rs);}
	///coming soon
	
	}
	
	//	cout<<pr<<endl;

	/*	cout<<pr<<endl;

    for(int d2=0;d2<mcd1.a;d2++)
	{
	cout<<*(mcd1.p+d2)<<' ';	
	}
	
	cout<<endl;*/

	
	//for(int h=0; h<mcd1.a; h++){
	//	k*=*(mcd1.x+h);}

	k=pr;
	//cout<<k<<"is k"<<endl;

	for(int r1=0; r1<sim.a; r1++)
	{
	
	
	if(k!=0)	
	{

	
	mod=k/(*(sim.x+r1));
	mod1=k%(*(sim.x+r1));

	if((*(sim.x+r1))==1||(*(sim.x+r1))==-1)
	{*(sim.p+r1)*=k;}
	else
	{

	if(mod1==0)
	{*(sim.p+r1)*=mod;}
	else
	{*(sim.p+r1)*=1;}}


	*(sim.x+r1)=1;


	if(*(sim.x+r1)==-1)
	{*(sim.x+r1)*=-1;
	 *(sim.p+r1)*=-1;}
	}
	}
///////////////////////////////////////////////////

	
	
	
	
	
	
	
	

///////////////////////////////////////////////////
//this part is ok look up^^^^^^
	mcd=sim;


	for (int setm=0; setm<sim.a; setm++)
	{
	if(*(sim.p+setm)!=0)	
	{min=abs(*(sim.p+setm));
	 break;}
	}

	max=min;

	for(int rm=0; rm<sim.a; rm++)
	{
		
		if(abs(*(sim.p+rm))<min && *(sim.p+rm)!=0)		
		{min=abs(*(sim.p+rm));}

		if(abs(*(sim.p+rm))>max)
		{max=abs(*(sim.p+rm));}
		
	}
	//cout<<min<<"is this?\n";
	ordered=true;


	for(int rm1=0; rm1<mcd.a; rm1++)
	{
		//cout<<min<<"is this?\n";
		//why it goes min=0 ?
		mod=*(mcd.p+rm1)%min;
		if(mod!=0)		
		{ordered=false;}		
		
	}

	/*if(!ordered)
		cout<<"False\n";
	else
		cout<<"True\n";*/


	int cnt=1;
	if(!ordered)
	{
	ordered=true;
	
	
	do{
	cnt++;
	//cout<<cnt<<"is cnt\n";
	for(int rm1=0; rm1<mcd.a; rm1++)
	{
		mod=*(mcd.p+rm1)%cnt;
		if(mod!=0)		
		{ordered=false;}}
		
	}while(!ordered&&cnt<=max);
	min=cnt;
	if(ordered)
	{
		//cout<<min<<"is this?\n";
	for(int r2=0; r2<sim.a; r2++)
	{
		*(sim.p+r2)/=min;}}
	}
	else
	{
	
	if(ordered)
	{
		//cout<<min<<"is this?\n";
	for(int r2=0; r2<sim.a; r2++)
	{
		*(sim.p+r2)/=min;}}}

//////////////////////////////////////////////

		
//////////////////////////////////////////////

}
vector& vector::operator /=(int k)
{
//////////////////////////////////////////////
	int mod;
		
	for(int r1=0; r1<a; r1++)
	{
	
	if(k!=0)	
	{mod=*(p+r1)%k;

	if(mod==0)
	{*(p+r1)/=k;}
	else
	{*(x+r1)*=k;}
	}
	}

	return *this;
	
	 
	
//////////////////////////////////////////////


}
void vector::mcd(vector& div)
{

	int tmp=1;
	int mcd=1;

	for(int r1=0; r1<div.a; r1++)
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
	/*if(this!=&div)
	{
	if(a>=div.a){
	for(int r=0; r<a; r++)
	{
	
	*(p+r)=*(div.p+r);
	if(r>div.a)
	{*(p+r)=0;}
	
		}
		}
	else
	{
	int* px=p;
	q= new int[div.a];
	
	
	
	for(int r1=0; r1<div.a; r1++)
	{	
	*(q+r1)=*(div.p+r1);
	}
	p=q;

	delete[] px;
	
	}
	a=div.a;
	}

	return *this;
	int mcd(int alfa, int beta)
{	int resto;
	while (beta != 0)
	{	resto = alfa % beta;
		alfa = beta;
		beta = resto;
	}
	return alfa;
}
	
	
	
	
	}
	
	
	*/
//////////////////////////////////////////////	
}
int vector::countrem(vector& div)
{
	int countZERO=0;
	for(int c=0; c<div.a && *(div.p)==0; c++)
	{
	 countZERO++;
	}

	return a-countZERO;
}
vector& vector::operator *(vector& div)//ok now
{
	
///////////////////////////////////////////////
	
	int dim=a+div.a;
	vector Prod(dim-2);
	
	if(this!=&div)
	{
	
	for(int r=0; r<a; r++)
	{
	
	for(int r1=0; r1<div.a; r1++)
	{
	//cout<<"r="<<r<<"r1="<<r1<<"r1+r"<<r1+r<<endl;
	*(Prod.p+r1+r)=*(Prod.p+r1+r)*(*(x+r)*(*(div.x+r1)))+*(p+r)*(*(div.p+r1))*(*(Prod.x+r1+r));
	*(Prod.x+r1+r)*=(*(x+r)*(*(div.x+r1)));
	//cout<<"this"<<*(Prod.p+r1+r)<<endl;
	}
		
	}
	
	//the algorithmic operation is ok
	//but the program rejects the return of 
	//the Prod vector class object
	//resolved when found that the = operator
	//had a little mistake in the code never 
	//noticed before
	
	*this=Prod;
	
	}
	//Prod.printrational(Prod);

	return *this;
//////////////////////////////////////////////
	
}
vector& vector::operator%(vector& div)//ok now
{
	
	vector DD1of(a-1);
	
	if(this!=&div)
	{
	if(a==div.a){

	int Rational;
	for(int r=1; r<a-iT; r++)
	{
	
	
	Rational=(*(p+r+iT)*(*(x+iT))-*(p+iT)*(*(x+r+iT)))%(*(div.p+r+iT)*(*(div.x+iT))-*(div.p+iT)*(*(div.x+r+iT)));
	
	if(Rational==0&& !(*(x+iT)!=1||*(x+r+iT)!=1||*(x+r+iT)!=1||*(div.x+iT)!=1||*(div.x+iT)!=1||*(div.x+r+iT)!=1))
	{*(DD1of.p+r+iT)=(*(p+r+iT)*(*(x+iT))-*(p+iT)*(*(x+r+iT)))/(*(div.p+r+iT)*(*(div.x+iT))-*(div.p+iT)*(*(div.x+r+iT)));}
	else
	{
		
	
		//*(DD1of.p+r+iT)=*(div.p+iT)*(*(x+r+iT))-*(div.p+iT)*(*(div.x+r+iT));
		//&&(*(x+iT)!=1||*(x+r+iT)!=1||*(x+r+iT)!=1||*(div.x+iT)!=1||*(div.x+iT)!=1||*(div.x+r+iT)!=1)
		//*(DD1of.x+r+iT)=*(div.p+r+iT)*(*(DD1of.x+r+iT))-(*div.p+iT)*(*(DD1of.x+r+iT));
		//&&(*(p+r+iT)-*(p+iT))%(*(div.p+r+iT)-*(div.p+iT)==0)
		//for Y  (*(x+iT))*(*(x+r+iT)*(*(div.x+iT))*(*(div.x+r+iT))
		*(DD1of.p+r+iT)=(*(p+r+iT)*(*(x+iT))-*(p+iT)*(*(x+r+iT)))*(*(div.x+iT))*(*(div.x+r+iT));
		
		//for X (*(div.x+iT))*(*(div.x+r+iT)								   |for the ratio
		*(DD1of.x+r+iT)=(*(div.p+r+iT)*(*(div.x+iT))-*(div.p+iT)*(*(div.x+r+iT)))*(*(x+iT)*(*(x+r+iT)));
		//cout<<"this is y"<<*(DD1of.p+r+iT)<<endl;
		//cout<<"this is x"<<*(DD1of.x+r+iT)<<endl;
	}

		
	
	}//not ok in this point
		}
	*this=DD1of;
	iT++;
	//cout<<"iT is:"<<iT<<endl;
	//cout<<iT<<endl;maybe pay attention to 
	// z2-z1/x2-x1
	//good shot but it has to be iterative 
	}

	return *this;
	
}
vector& vector::operator ,(vector& div)
{



//////////////////////////////////////////////
	vector Derive(a-2);
	
	if(this!=&div)
	{
		
	int exp=div.a-1;
		for(int r=0; r<Derive.a; r++)
	{		
		*(Derive.p+r)=*(div.p+r)*(exp--);
		
		
	}
	
	*this=Derive;
	
	}

	return *this;	
//////////////////////////////////////////////
}
void vector::Rshift(vector& div)
{


	vector R_shift(div.a);
	for(int j=0; j<R_shift.a; j++)
	{
	
		if(j<div.a)
		{
			
			
		*(R_shift.p+j)=*(div.p+j);
		*(R_shift.x+j)=*(div.x+j);
		
		}
		else
		{
		if(j>div.a)
		{*(R_shift.p+j)=0;
		 *(R_shift.x+j)=1;}
		
		}
	
	}
	
	div=R_shift;

		
	

}
void vector::Lshift(vector& div)
{


	vector L_shift(div.a-2);
	for(int j=1; j<div.a; j++)
	{
	
		if(j<L_shift.a)
		{
			
			
		*(L_shift.p+j-1)=*(div.p+j);
		*(L_shift.x+j-1)=*(div.x+j);
		
		
		}
		else
		*(L_shift.p+j-1)=*(div.p+j);
		*(L_shift.x+j-1)=*(div.x+j);
		
	
	}
	
	div=L_shift;

		
	

}
void vector::printall(vector& w)
{
	
	
	
		for(int n=0; n<w.a; n++)
	{
		
		     cout<<*(w.p+n);
			 cout<<'/'<<*(w.x+n)<<' ';
			 cout<<"x^"<<w.a-n-1;
			(*(w.p+n+1)<0) ? cout<<' ' : cout<< '+';
	
	}
	
		cout<<endl;
		cout<<endl;
}
bool vector::control(vector& w, vector& z)
{
	if(w.a-z.a-1>=0)
		return true;
	else
		return false;

}
void vector::S_space(vector& sim)
{

	while(*sim.p==0){
	sim.Lshift(sim);}


}
void vector::ErrorTo(double& a)
{
	int tru;
	double re;

	tru=a*pow(10,E);
	//cout<<tru<<"is tru\n";
	re=tru/pow(10,E);
	//cout<<re<<"is re\n";
	a=re;

}
