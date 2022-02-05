#ifndef LAL_H_
#define LAL_H_
#include <iostream>

using namespace std;

class Matrix {
	friend Matrix transpose(const Matrix&);
	friend double norm(const Matrix&);
public:

	Matrix();
	Matrix(double*, int, int);
	~Matrix();
	void print(void);
	Matrix vector2Array(Matrix[], int, int);
	Matrix operator+(const Matrix&);
	bool operator==(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
protected:
	double* entries;
	int rows;
	int cols;
};

class Vector : public Matrix {
public:

	Vector();
	Vector(double*, int);
	~Vector();
	double* getEntries();
	void print(void);
	Vector operator+(const Vector&);
	bool operator==(const Vector&);
	Vector operator-(const Vector&);
	double operator*(const Vector&);
	Vector operator++();
	Vector operator++(int);
private:
	double l2norm;
};
#endif