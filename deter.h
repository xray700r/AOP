#ifndef DETER_H
#define DETER_H
#include <fstream>
//struct number{int num; number* ptr;};

class matrica{

private:


    
	int array[4][4];
	int minore[3][3];
	int min_2_2[2][2];
	int min_det;
	int total;
	int total1;
	int* p;
	
	int* x;
	int d;
	int dc;
	
public:


	void find_min(int);
	int calc_det(int);
	void print(int);
	void int_s();
	int m_2(int, int);
	int isolate(int);
	int gettot();
	void fixmult(int, int);
	int getarray(int, int);
	void settot();
	void setmindet();
	void fixit();
////////////////////////////////////	
	matrica();
	matrica(int);
	~matrica();
	int DET4(matrica& mx);
	int DET3(matrica& mx);
	int mx2(matrica& mx);
	void matprint(matrica& w);
	void ratiomatprint(matrica& w);
	void insertmatrix();
	void Ratioinsertmatrix();
	void isolatematrix(int& r, matrica& mx, matrica& isol);
	void ISOlatematrix(int& r,int& k, matrica& mx, matrica& isol);
	matrica& operator+(matrica& mx);
	matrica& operator-(matrica& mx);
	matrica& operator&(int k);
	matrica& operator=(matrica& mx);
	matrica& operator*=(matrica& mx);
	matrica& operator*(matrica& mx);
	matrica& operator[](int k);
	void createIdentic(matrica& mx);
	void Pow(matrica& mx, int e);
	void Sim2_diag(matrica& mx);
	void jacmat(matrica& mx);
	void TriMat(matrica& mx, matrica& trs, matrica& tri, matrica& dia);
	int trAx(matrica& mx);
	void Process_tr(matrica& mx);
	void Constmult(matrica& e, int k);
	void Gauss_Jordan(matrica& mx,matrica& Id, int k1,int k2, int col, int add);
	int sigma(matrica& mx, int s);
	void inTerfacetoMatrica(matrica& M, int j, int i, int& val, int& valrat);
	void inTerfacetoGauss(matrica& M, int j, int i, int& val, int& valrat);
	void ProductRational(matrica& A,matrica& B);
	void NULLMatrix(matrica& mx);
	void mcd(matrica& div);
	bool testDiag(matrica& mx);
	void inserTString();
	////////////////////////////////////



	class Gauss_elem{

private:
	
	int* v;
	int* xv;
	int nc;
	

public:
	
	Gauss_elem();
	Gauss_elem(int);
	~Gauss_elem();
	void prinTVector();
	void createBasE(Gauss_elem& e, int pos);
	void inserTVector();
	void inserTVinteg();
	void proDmatrix(Gauss_elem& A, Gauss_elem& mx);
	void Gauss_Elematrix(matrica& mx, matrica& W);
	void vectorprod(Gauss_elem& mv1, Gauss_elem& mv2, matrica& a);
	void VectorDiff(Gauss_elem& e,Gauss_elem& e1);
	int VectorNorma(Gauss_elem& e,int& Pro);
	void Gauss_fromMatrix(int val, int pos,int rat);
	void Constmult(Gauss_elem& e, int k,matrica& E,int diag, int diagraT);
	void NULLVECTOR(Gauss_elem& E);
	void Switch(Gauss_elem& vectorA, Gauss_elem& vectorB);
	Gauss_elem& operator =(Gauss_elem& m);
	void SWreadrow(matrica& mx, int row);
	void SWwriterow(matrica& mx, Gauss_elem& A,Gauss_elem& B,int row);
	void HandleInitMatrix(matrica& mx);
	void SWwriterowHandle(matrica& mx, Gauss_elem& A,Gauss_elem& B,int swRow,int swRow1);
	void MatrixXVector(matrica& mx,Gauss_elem & V);
	void VectorSWitch(int row1, int row2, Gauss_elem& S);
	
	};
};


#endif