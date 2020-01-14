#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "deter.h"
using namespace std;
void welcome()
{
	cout<<"##########Welcome to the CALCULUS program for the array functions!##########\n"
		   <<"#####Although it may seem obsolete in the graphical features,#####\n"
		   <<"#####the algorithms implemented make possible some operations#####\n"
		   <<"##on arrays that are a time loss in problem solutions and calculations.##\n";
}

int meny ()
{
	cout<<"Choose one of the following operations to use:(Press number to select!)\n"
		<<"1.Find the DET of a 4x4 array\n"
		<<"2.Find the sum of two NxN arrays\n"
		<<"3.Find the product of two arrays NxN\n"
		<<"4.Multiply an array NxN with a constant k\n"
		<<"5.Find the DET of a 3x3 array\n"
		<<"6.Jacobi iteration matrix\n"
		<<"7.Character equation of a matrix.\n";
		
	int cs=0;
	while(cin>>cs){
	if(cs<=0)
	{cout<<"You must enter a valid selection!";}
	else
	return cs;
	}
	return 0;
	//meny must be expanded when multiple dim arrays will be used ex to allocate in memory
}
/*C++ copyright of the programmer VIV*/
int main()
{
	matrica fn;
	char ch;//='y';
	int b;
	fstream fl;
	
	fl.open("dres.txt", ios::out);
	welcome();
	do{
    switch (meny()) {
	
	case 1:
	
	{
	cout<<"Enter the elements for the array 4x4 to find the det\n";
	fl<<"Enter the elements for the array 4x4 to find the det\n";
	
	fn.int_s();
	cout<<"The array you entered:\n";
	fl<<"The array you entered:\n";
	fn.print(4);
	for(int a=0; a<4; a++)
	{
	for(int b=0; b<4; b++)
	{
		fl<<fn.getarray(a,b)<<"\t";
		
	}
	fl<<endl;
	
	}

	cout<<"Now the prog will calculate the det of the array\n";
	fl<<"Now the prog will calculate the det of the array\n";
	
	for(int snd=0; snd<2; snd++)
	{cout<<"\a";}

	for(int dz=0;dz<4;dz++)
	{
	fn.fixit(); 
	b=fn.isolate(dz);	
	for(int dx=0;dx<3; dx++)
	{
	
	

	fn.find_min(fn.m_2(dx,fn.calc_det(dx)));
	fn.setmindet();
	
	}
	fn.fixmult(dz, b);
	}
	cout<<"The det of the array is:|A|="<<fn.gettot()<<endl;
	fl<<"The det of the array is:|A|="<<fn.gettot()<<endl;
	
	for(int ln=0; ln<50; ln++)
	{fl<<"_";}
	 
	fl<<endl;
	
	fn.settot();}
	
	
	
	break;
	
	
	case 2:
	{

	 int dim;
	 cout<<"Enter dimension N for the NxN matrix\n";
	 cin>>dim;
	 cout<<"Enter the elements of A "<<dim<<'x'<<dim<<" array!\n";
	 
	 matrica A(dim);
	 matrica B(dim);
	 A.insertmatrix();
	 cout<<"Enter the elements of B "<<dim<<'x'<<dim<<" array!\n";
	 B.insertmatrix();
	 cout<<"Array A is:\n";
	 A.matprint(A);
	 cout<<"Array B is:\n";
	 B.matprint(B);
	 B=B-A;
	 cout<<"Array C=A-B is:\n";
	 B.matprint(B);}
	break;

	case 3: 
	
	{int dim;
			cout<<"Enter the dimension of the matrix NxN\n";
			cin>>dim;
			matrica B(dim);	
			matrica A(dim);
			A.Ratioinsertmatrix();
			B.Ratioinsertmatrix();
			cout<<"Array A is:\n";
			A.ratiomatprint(A);
			cout<<"Array B is:\n";
			B.ratiomatprint(B);
			
			B.ProductRational(A,B);
			cout<<"Array A*B is:\n";
			A.mcd(A);
			A.ratiomatprint(A);
	}

		break;
	case 4:
		{
		int dim, l;
	 cout<<"Enter dimension N for the NxN matrix\n";
	 cin>>dim;
	 cout<<"Enter the elements of A "<<dim<<'x'<<dim<<" array!\n";
	 
	 matrica A(dim);
	
	 A.insertmatrix();
	 cout<<"Enter the elements of B "<<dim<<'x'<<dim<<" array!\n";
	 
	 cout<<"Array A is:\n";
	 A.matprint(A);
	 cout<<"Enter the k constant for the multiplication\n";
	 cin>>l;
	 A=A&l;
	 cout<<"Array A*"<<l<<"is:\n";
	 A.matprint(A);
		}
		break;
	case 5:
		{
				
	matrica D(3);
			
	cout<<"Enter the elements for the array 3x3 to find the det\n";
	D.insertmatrix();	
	cout<<"The array you entered A=:\n";
	D.matprint(D);	
	cout<<"det|A|="<<D.DET3(D)<<endl;	

	/*
	matrica D(4);			
	cout<<"Enter the elements for the array 4x4 to find the det\n";
	D.insertmatrix();	
	cout<<"The array you entered A=:\n";
	D.matprint(D);	
	cout<<"det|A|="<<D.DET4(D)<<endl;
	*/
		}
		break;
	case 6:
		{

			int dim;
			
			cout<<"Enter the dimension of the array NxN\n";
			cin>>dim;
			//matrica Hj(dim);
			matrica A(dim);
	cout<<"Enter the elements of A "<<dim<<'x'<<dim<<" array!\n";
	A.insertmatrix();	
	cout<<"The array you entered A=:\n";
	A.matprint(A);	
	cout<<"The Jacobi iteration matrix is Hj:\n";
    A.jacmat(A);
	A.ratiomatprint(A);

	
		}
		break;
	case 7:
		{

	//*matrica::Gauss_elem D(3);
	//matrica::Gauss_elem D1(4);
	
	//*a.Ratioinsertmatrix();
	//*D.inserTVector();
	//D1.inserTVector();
	//matrica M(4);
	//M.Ratioinsertmatrix();
	//a=M;
	//D.prinTVector();
	//D1.prinTVector();
	//D.vectorprod(D,D1,a);
	//D.Gauss_Elematrix(D,a);
	//*D.MatrixXVector(a,D);
	//*D.prinTVector();
	//a.ProductRational(a,M);
	//cout<<"Triangular matrix At:\n";
	//a.ratiomatprint(a);
	int dim;
	cout<<"Insert the dimension of the array\n";
	cin>>dim;
	matrica a(dim);
	a.inserTString();
	a.matprint(a);

	}
		break;
	case 0: cout<<"This is strange!";
		break;
	default:
	cout<<"This is strange too!";
	break;}

	cout<<"Do you want to continue?(y/n)"<<endl;
	cin>>ch;
	while(ch!='y'&& ch!='n')
	{cout<<"______Enter a correct choice!______\n Y to continue N to exit!\n";
	cin>>ch;}
	
	}while(ch!='n');

	fl.close();
	return 0;


}