#ifndef VECTHEAD_H
#define VECTHEAD_H

class vector{

	int* p;
	int* q;
	int a;
    	int* x;
	int* x1;
	int E;
	int num;
	int iT;
	
public:

	vector();
	vector(int);
	~vector();
	void printvect(vector& w);
	void printcolumn(vector& w);
	void insert();
	void insertrational();
	void printrational(vector& w);
	void printall(vector& w);
	double calculate(double);
	void derivate(int);
	bool root(double);
	bool control(vector& w,vector& z);
	int countrem(vector& div);
	vector& operator/(vector& div);
	vector& operator=(vector& div);
	vector& operator+(vector& div);
	vector& operator-(vector& div);
	vector& operator &(int k);
	void Simplify(vector& sim);
	void S_space(vector& sim);
	vector& operator /=(int k);
	void Rshift(vector& div);
	void Lshift(vector& div);
	void ErrorTo(double& a);
	vector& operator *(vector& div);
	void mcd(vector& div);
	vector& operator ,(vector& div);
	vector& operator %(vector& div);
};
#endif
