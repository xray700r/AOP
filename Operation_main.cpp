#include <iostream>
#include <fstream>
#include <iomanip>
//#include <conio.h>
#include <cmath>
#include "deter.h"
#include "vecthead.h"

using namespace std;

void welcome()
{
		
	
	cout<<"The program works as follows:\nThe operators are mathematical so the math rules apply to them.\nOn the command prompt you enter the requested data.\nThe program makes possible to focus on two objects:\nYour input and the result of the calculation with the focus command.\nThe prompt is O:?>_for the choices you have to do and O:/>_for the operators.\n";
	cout<<"_____________________________________________________________________________\n\a";







}

int prompt()
{
	char OPer;
	int RET;
	cout<<"0:/>";
	cin>>OPer;

	switch(OPer)
	{
	case '+':
		RET=1;
		break;

	case '-':
		RET=2;
		break;
	case '*':
		RET=3;
		break;
	case 'D':
		RET=4;
		break;
	case 'x':
		RET=5;
		break;
	case 'T':
		RET=6;
		break;
	case 'P':
		RET=7;
		break;
	case 'J':
		RET=8;
		break;
	case 'f':
		RET=9;
		break;
	case 'F':
		RET=10;
		break;
	case 'k':
		RET=11;
		break;
	case '/':
		RET=12;
		break;
	case 's':
		RET=14;
		break;
	case 'c':
		RET=15;
		break;
	case 't':
		RET=16;
		break;
	case 'p':
		RET=17;
		break;
	case 'G':
		RET=18;
		break;
	case 'S':
		RET=19;
		break;
	case 'i':
		RET=20;
		break;
	case 'M':
		RET=21;
		break;
	case 'm':
		RET=22;
		break;
	case 'L':
		RET=23;
		break;
	case '?':
		cout<<"Help:\nARRAY OPERATOR CHART:\n+:Sum of two NxN arrays.\n-:Difference of two NxN arrays.\n*:Product of two NxN arrays.\nx:tr of a NxN array.\nD: Det of a 3x3 or 4x4 array.\nT:Transposed of NxN array.\nP:character polynomial of NxN.\nJ:Jacobi iteration matrix.\nf:focus on the matrix\nF: Focus on value\nk: Multiply the NxN array with a constant\nt: Find A-kI\np: Raise to n_power a matrix\nG: Gauss-Jordan CAC for the inverse.\nS: Gauss_Seidel iteration calculations.\nM: Gauss_matrix for triangularization\nL: Definite Linear system solution(Gauss method).\n";
		cout<<"\nPOLYNOMIAL OPERATOR CHART:\n+:Sum of two polynomials.\n-:Difference of two polynomials.\n*:Product of two polynomials.\n/: Division rest of two polynomials.\nx:Calculate next alpha for tangent method.\nD: Derivate of n degree of a polynomial.\nT:Interpolation Newton Table. \nP:Root Proof for a polynomial.\nf: focus on the polynomial\nF: Focus on value\nk: multiply the polynomial with a constant\ns: Calculate Sturm series for a polynomial.\n";
		
		RET=0;
		break;
	default:
		cout<<"You have entered an invalid operator!\n";
	break;	
	}

	return RET;


}
void change(int& deg)
{	char c;

	cout<<"Change Degree?(Y/N)\n";
	cout<<"0:?>";
	cin>>c;
	if(c=='y')
	{	cout<<"New degree\n";
	cin>>deg;
	}
	
}
void chooseRat(matrica& R)
{
	char r='y';
	
	cout<<"You want to enter a rational element matrix or a integer one\nPress I for integer R for rational!\n";
	cout<<"[ "<<']'<<"\b\b";
	cin>>r;
	if(r=='i')
		R.insertmatrix();
	else
		R.Ratioinsertmatrix();
	
}
void chooseRatP(vector& V)
{
	char r='y';
	
	cout<<"You want to enter a rational element polynomial or a integer one\nPress I for integer R for rational!\n";
	cout<<"[ "<<']'<<"\b\b";
	cin>>r;
	if(r=='i')
		V.insert();
	else
		V.insertrational();
	
}
void choosevect(matrica::Gauss_elem& V)
{
	char r='y';
	
	cout<<"You want to enter a rational element polynomial or a integer one\nPress I for integer R for rational!\n";
	cout<<"[ "<<']'<<"\b\b";
	cin>>r;
	if(r=='i')
		V.inserTVinteg();
	else
		V.inserTVector();
	
}

int main()
{
	welcome();
	
    
	char ch, type, er;//='y';
	int Dim;
	int Value_focus=0, value2=0,Value_focusP=0, valueP2=0,ka=1;
	do{	
	cout<<"What type of math class you want to work on?\nEnter P for_Polynomial and M for_Array\n";
	cout<<"0:?>";
	cin>>type;
	if(type=='M'){
	cout<<"Define your array entering first the dimension and then the elements\n";
	cin>>Dim;
	
	matrica A(Dim);
	chooseRat(A);
	
	//A.Ratioinsertmatrix();
	matrica Temp(Dim);
	cout<<"The array you entered!\n";
	A.ratiomatprint(A);
	
	
	do{
    switch (prompt()) {
	
	case 1:
	
	{
	
	matrica B(Dim);
	B=A;
	Temp.insertmatrix();
	Temp=B+Temp;
	Temp.ratiomatprint(Temp);
	
	}
	break;
	case 9:
	
	{
	matrica T(Dim);

	T=A;
	
	A=Temp;

	Temp=T;
	cout<<"The matrix on which you are working:\n";
	A.ratiomatprint(A);
	for(int ln=0; ln<8*Dim; ln++)
	{cout<<'_';}
	cout<<endl;
	Temp.ratiomatprint(Temp);
	}
	break;
	case 10:
	{
	int Tm;

	Tm=Value_focus;
	
	Value_focus=value2;

	value2=Tm;
	cout<<"The value on which you are working:"<<Value_focus<<"\n___________\n"<<value2<<endl;
	}
	break;
	
	case 2:
	{
	matrica B(Dim);
	B=A;
	Temp.insertmatrix();
	Temp=B-Temp;
	Temp.ratiomatprint(Temp);	
	}
	break;

	case 3: 
	
	{
	matrica B(Dim);
	B=A;
	Temp.insertmatrix();
	char premult;
	cout<<"Premultiply or post multiply(P/O)\nMatrix1*Matrix2 or Matrix2*Matrix1!\nO:!>";
	cin>>premult;
	if(premult=='o')
	{Temp.ProductRational(Temp,B);
	 Temp.ratiomatprint(Temp);}	
	else
	{
	Temp.ProductRational(B,Temp);
	 B.ratiomatprint(B);	
	}
	}
	break;
	case 4:
	{
	if(Dim==3)
	{Value_focus=A.DET3(A);}
	else
	{
	if(Dim==4)
	{Value_focus=A.DET4(A);}
	}

	cout<<"det|A|="<<Value_focus<<endl;		
	}
	break;
	case 5:
	{
	Value_focus=A.trAx(A);
	cout<<"trA="<<Value_focus<<endl;
	}
	break;

	case 6:
		{
		Temp*=A;
		Temp.ratiomatprint(Temp);	
		}
	
		break;
	case 7:
		{
	matrica C(2);
	matrica B(3);
	for(int a=0; a<4;a++)
	{	
	for(int b=0; b<4;b++){
		if(a!=b){
	A.ISOlatematrix(a,b,A,C);
	C.ratiomatprint(C);
	cout<<"____________________________num of times/2\n";
		}
	
		}	
	}
	
	for(int a1=0; a1<4;a1++)
	{	
	for(int b1=0; b1<4;b1++){
		if(a1!=b1){
	A.ISOlatematrix(a1,b1,A,B);
	B.ratiomatprint(B);
	cout<<"____________________________num of times/3\n";
		}
	
		}	
	}
	cout<<"s1=trA="<<A.trAx(A)<<endl;
	cout<<"s2="<<A.sigma(A,2)<<endl;
	
	cout<<"s3="<<A.sigma(A,3)<<endl;
	cout<<"s4=det|A|="<<A.DET4(A)<<endl;
	cout<<"Character equation for the matrix is:x^4-"<<A.trAx(A)<<"x^3+"<<A.sigma(A,2)<<"x^2-"<<A.sigma(A,3)<<"x+"<<A.DET4(A)<<endl;
	}
		break;


	case 8:
	{
	Temp=A;
	Temp.jacmat(Temp);
	Temp.mcd(Temp);
	Temp.ratiomatprint(Temp);	
	}
	break;
	case 11:
	{

	cout<<"Enter the value of the constant:\n";
	cin>>value2;
	Temp=A;
	Temp&value2;
	Temp.ratiomatprint(Temp);	
	}
	break;
	case 16:
	{
	matrica I(Dim);
	cout<<"Enter the value of the constant:\n";
	cin>>value2;
	Temp=A;
	I.createIdentic(I);
	Temp=Temp-(I&value2);
	Temp.ratiomatprint(Temp);
	cout<<"Enter the exponent of the expression\n";
	cin>>value2;
	matrica T1(Dim);
	T1=Temp;
	
	T1.Pow(T1, value2);	
	
	T1.ratiomatprint(T1);	
	}
	break;
	case 17:
	{
	cout<<"Enter the exponent of the expression\n";
	cin>>value2;
	
	Temp=A;
	
	Temp.Pow(Temp, value2);	
	
	Temp.ratiomatprint(Temp);	
	}
	break;
	case 18:
		{int f=1;
	matrica II(Dim);
	II.createIdentic(II);
	Temp=A;
	do{
	int row, rowadd;
	cout<<"Enter the row on which you will operate.\n";
	cin>>row;cout<<"Enter the coeff to multiply.\n";
	cin>>ka; f*=ka;
	cout<<"Enter the row you will add.\n";
	cin>>rowadd;
	cout<<"Enter the coeff to multiply.\n";
	cin>>value2;
	
	cout<<"Operation:"<<ka<<"["<<row<<"]";
	(value2<0) ? cout<<' ': cout<<'+';
	cout<<"["<<rowadd<<"]"<<endl;
	
	Temp.Gauss_Jordan(Temp, II,value2,1,row,rowadd);	
	
	Temp.ratiomatprint(Temp);
	
	cout<<"_______________________________________\n";
	II.ratiomatprint(II);
	cout<<"Press q_to quit!\n";
	}while(cin.get()!='q');
	cout<<"1/"<<f<<"*IA\n";}
	break;
	case 19:
	{
	
	Temp=A;

	Temp.ratiomatprint(Temp);
	
	//Temp.TriMat(Temp);	
	cout<<"You must find (D-E)^-1\n";
	}
	break;
	case 20:
	{
	Temp=A;
	cout<<"The polynomial for the tridiag matrix is:\n";

	Temp.ratiomatprint(Temp);
	
	//Temp.TriMat(Temp);	
	cout<<"You must find (D-E)^-1\n";
	}
	break;
	case 21:
	{
	Temp=A;
	matrica::Gauss_elem D(Dim);
	matrica B(Dim);
	cout<<"The Gauss_matrix for A are:\n";
	D.Gauss_Elematrix(B,Temp);
	cout<<"The triangular matrix At is:\n";
	Temp.ratiomatprint(Temp);
	cout<<"The DET of A is:";
	Temp.trAx(Temp);
	cout<<endl;
	}
	break;
	case 22:
	{
	Temp=A;
	matrica::Gauss_elem Vector(Dim);
	choosevect(Vector);
	cout<<"The product of the operation A*x=\n";
	Vector.MatrixXVector(Temp,Vector);
	Vector.prinTVector();
	}
	break;
	case 23:
	{
	Temp=A;
	matrica::Gauss_elem D(Dim);
	cout<<"Enter the known terms vector!\n";
	//D.inserTVector();
	matrica I(Dim);
	I.createIdentic(I);
	cout<<"The Gauss_matrix for A are:\n";
	D.Gauss_Elematrix(I,Temp);
	cout<<"The solution of the system Ax=b:\nmatrix At is:\n";
	Temp.ratiomatprint(Temp);
	I.ratiomatprint(I);
	cout<<"The column of the known terms:\n";
	//D.prinTVector();
	cout<<endl;
	}
	break;

	case 0: cout<<"Remember that these operators are mathematical!\n";
		break;
	default:
	cout<<"Matrix operator not correct!\n";
	break;}

	cout<<"Do you want to continue?(y/n)"<<endl;
	cout<<"0:?>";
	cin>>ch;
	while(ch!='y'&& ch!='n')
	{cout<<"______Enter a correct choice!______\n Y to continue N to exit!\n";
	cin>>ch;}
	
	}while(ch!='n');
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////
	if(type=='P')
	{
	cout<<"Define your polynomial entering first the degree and then the parameters:\n";
	cin>>Dim;
	
	vector P(Dim);
	
	chooseRatP(P);
	cout<<"The polynomial you entered!\nP(x)=";
	P.printrational(P);
	vector TEmp(Dim);
	
	
	do{
    switch (prompt()) {
	
	case 1:
	
	{
	vector P1(Dim);
	change(Dim);
	vector P2(Dim);
	
	P1=P;
	P2.insert();
	TEmp=P1+P2;
	cout<<"P+P1=";
	TEmp.printrational(TEmp);
	
	}
	break;
	case 9:
	
	{
	vector PT(Dim);

	PT=P;
	
	P=TEmp;

	TEmp=PT;
	cout<<"The polynomial on which you are working:\n";
	P.printrational(P);
	for(int ln=0; ln<8*Dim; ln++)
	{cout<<'_';}
	cout<<endl;
	TEmp.printrational(TEmp);
	}
	break;
	case 10:
	{
	int T1m;

	T1m=Value_focusP;
	
	Value_focusP=valueP2;

	valueP2=T1m;
	cout<<"The value on which you are working:"<<Value_focusP<<"\n___________\n"<<valueP2<<endl;
	}
	break;
	
	case 2:
	{
	vector P1(Dim);
	change(Dim);
	vector P2(Dim);
	
	P1=P;
	P2.insert();
	TEmp=P1-P2;
	cout<<"P-P1=";
	TEmp.printrational(TEmp);
	}
	break;

	case 3: 
	
	{
	vector P1(Dim);
	change(Dim);
	vector P2(Dim);
	
	P1=P;
	cout<<"You'll enter a rational polynomial(Y/N)!";
	cin>>type;
	if(type=='y')
	{P2.insertrational();}
	else
	{P2.insert();}
	TEmp=P1*P2;	
	TEmp.mcd(TEmp);
	cout<<"P*P1=";
	TEmp.printrational(TEmp);	
	}
	break;
	case 4:
	{
	
	vector P1(Dim);
	TEmp=P1,P;	
	cout<<"P'=";
	//TEmp.mcd(TEmp);
	TEmp.printrational(TEmp);
		
	}
	break;
	case 5:
		{
	vector P1(Dim);	
	P1=P1,P;
	int alpha=0;
	double s;

	do{

	cout<<" alpha+1=alpha-P(x)/P'(x):\n";
		cout<<"Enter the values of alpha\n";
		cin>>s;
		while(er!='n')
		{
		P.ErrorTo(s);
		cout<<"Alpha is @"<<alpha<<"="<<s<<endl;
		cout<<"__________________________________________________\n";
		cout<<"P("<<s<<")="<<P.calculate(s);
		(P.calculate(s)>0)? cout<<"positive(+)": cout<<"negative(-)";
		(P.calculate(s)!=0)? cout<<"Aproximation":cout<<"this is the ROOT";
		cout<<endl;
		cout<<"__________________________________________________\n";
		
		cout<<"@"<<alpha<<"="<<s<<"-P("<<s<<")/"<<"P'("<<s<<")\n";
		
		s=s-(P.calculate(s)/P1.calculate(s));
		alpha++;
		cout<<"_____________________________\nContinue!(y/n)\n";
		cin>>er;

		}	
		cout<<"To continue with other polynomials press any key!To quit press C\n";
		cin>>er;
		cout<<"__________________________________________________\n";
		
	}while(er!='c');
		}
	break;

	case 7:
	do{
	double r;
			cout<<"Enter the hypotetical root to proof\n";
			while(cin>>r)
			{
			if(P.root(r))
				cout<<"This is a [ROOT] of the polynomial!\n";
			else 
				cout<<"This is [NOT] a root of the polynomial!\n";
		
			
			cout<<"Enter another number to continue.Press C to exit!\n";
			
			for(int line=0;line<50;line++)
			{cout<<"_";}
			cout<<endl;
			}
		cin.clear();
		cin>>er;
		}while(er!='c');	
		break;
	case 6:
		{
	int Points;
			cout<<"Enter the number of points to use for the interpolation:\n";
			cin>>Points;
			Points-=1;
			vector c(Points);
		    vector b(Points);
			vector t(Points);
			cout<<"Enter the first column of X:\n";
			c.insertrational();
			cout<<"Enter the second column ofY:\n";
			b.insertrational();
		         
		
		cout<<"The columns:\n";
		cout<<"X|\t";
		c.printcolumn(c);
		cout<<"Y|\t";
		b.printcolumn(b);
		for(int Iterate=0; Iterate<Points; Iterate++)
		{
		 
		 b=b%c;
		cout<<"DD"<<Iterate+1<<"|\t";
		t=b;
		t.mcd(t);
		t.printcolumn(t);
		 }
	}
		break;


	case 8:
	{
	cout<<"??\n";	
	}
	break;
	case 11:
	{
	cout<<"Enter the value of the constant:\n";
	cin>>value2;
	TEmp=P;
	TEmp&value2;
	TEmp.printrational(TEmp);	
	}
	break;
	case 12:
	{
	vector P1(Dim);
	change(Dim);
	vector P2(Dim);
	
	P1=P;
	P2.insertrational();
	TEmp=P1/P2;
	cout<<"P/P1=";
	TEmp.mcd(TEmp);
	TEmp.printrational(TEmp);	
	}
	break;
	case 14:
	{
	vector P1(Dim);
	//change(Dim);
	//vector P2(Dim);
	int pol=2;

	cout<<"P0(x)=";
	P.printrational(P);
	vector TEmp(Dim);
	vector P2(Dim);
	P1=P;

	P2,P1;

	

	cout<<"P1(x)=";
	P2.printrational(P2);
	cout<<"=>\n";
	P2.Simplify(P2);
	P2.printrational(P2);
	vector A(Dim);
	
	do{
	A=P1;
	//cout<<"A\n";
	//A.printall(A);
	

	
	TEmp=A/P2;

	//TEmp.mcd(TEmp);
	
	cout<<"Sturm series polynomial P"<<pol++<<"(x)\n";
	TEmp=TEmp&-1;
	//TEmp.mcd(TEmp);
	TEmp.printrational(TEmp);
	
	cout<<"Automatic simplify or not!(Y/N)\n";
	cout<<"O:?>";
	cin>>type;
	if(type=='y')
	{TEmp.Simplify(TEmp);}
	else
	{TEmp.insertrational();}
	cout<<"Simplified!:\n";
	//TEmp.mcd(TEmp);
	TEmp.printrational(TEmp);
	TEmp.S_space(TEmp);
	//TEmp.printall(TEmp);
	//cout<<"/////////\n";
	P2.S_space(P2);

	//P2.printall(P2);
	P1=P2;

	//cout<<"P1\n";
	//P1.printall(P1);
	
    	
	P2=TEmp;
	//cout<<"P2\n";
	//P2.printall(P2);
	cout<<"Press q to quit!\n";
	}while(cin.get()!='q');

	}
	break;
	case 15:
	do{int s;
	cout<<"Enter the values of the variable to calculate the expression\n";
	while(cin>>s)
	{	
	cout<<"P("<<s<<")="<<P.calculate(s)<<endl;
	cout<<"__________________________\n";
	}
		
		cin.clear();
		cin>>er;
		
	}while(er!='c');
	break;
	case 0: cout<<"Remember that these operators are mathematical!\n";
		break;
	default:
	cout<<"Polynomial operator not correct!\n";
	break;}

	cout<<"Do you want to continue?(y/n)"<<endl;
	cout<<"0:?>";
	cin>>ch;
	while(ch!='y'&& ch!='n')
	{cout<<"______Enter a correct choice!______\n Y to continue N to exit!\n";
	cin>>ch;}
	
	}while(ch!='n');
	}	
	cout<<"Do you want to EXIT the program?(y/n)"<<endl;
	cout<<"0:?>";
	cin>>ch;
	while(ch!='y'&& ch!='n')
	{cout<<"______Enter a correct choice!______\n Y to exit N to continue!\n";
	cin>>ch;}
	
	}while(ch!='y');
	
	return 0;
}
