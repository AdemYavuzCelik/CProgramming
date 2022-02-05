#include <iostream>
#include "lal.h"
#include <typeinfo> 
#include <time.h>
int main() {
	int row = 5;
	int col = 5;
	int row1 = 5;
	int col1 = 5;

	srand(time(0));
	//Matrix entries:
	double* entries = (double*)malloc((row * col) * sizeof(double));
	for (int i = 0; i < row * col; i++)
		entries[i] = rand() % 10;
	//2.Matrix entries:
	double* entries1 = (double*)malloc((row1 * col1) * sizeof(double));
	for (int i = 0; i < row1 * col1; i++)
		entries1[i] = rand() % 10;
	//Vector entries:
	double* ventries = (double*)malloc((row) * sizeof(double));
	for (int i = 0; i < row; i++) {
		ventries[i] = rand() % 10;
	}
	//2.Vector entries:
	double* ventries1 = (double*)malloc((row) * sizeof(double));
	for (int i = 0; i < row; i++) {
		ventries1[i] = rand() % 10;
	}
	//Matrix oluşturma constructor parametreli:
	Matrix matrixA(entries, row, col);
	Matrix matrixB(entries1, row1, col1);
	//Parametresiz constructor ile matrix nesnesi olutşurma:
	Matrix matrixC;
	Matrix carpim;
	//Vector olusturma
	Vector vectorA(ventries, row);
	Vector vectorB(ventries1, row1);
	Vector vectorC;
	cout << endl;
	cout << "\tMatrix addition:" << endl;
	//Operator+ overloading Matrix
	//Matrix yazdırma
	matrixC = matrixA + matrixB;
	cout << "Matrix A: " << endl;
	matrixA.print();
	cout << "Matrix B: " << endl;
	matrixB.print();
	cout << "Matrix C: ";
	matrixC.print();
	//Operator- overloading Matrix
	//Matrix yazdırma
	cout << endl;
	cout << "\tMatrix subtraction:" << endl;
	matrixC = matrixA - matrixB;
	cout << "Matrix A: " << endl;
	matrixA.print();
	cout << "Matrix B: " << endl;
	matrixB.print();
	cout << "Matrix C: ";
	matrixC.print();
	cout << "\t Matrix multiplication:" << endl;
	//Operator* overloading Matrix
	//Matrix yazdırma
	matrixC = matrixA * matrixB;
	cout << "Matrix A: " << endl;
	matrixA.print();
	cout << "Matrix B: " << endl;
	matrixB.print();
	cout << "Matrix C: ";
	matrixC.print();
	//Operator* Vector*Matrix
	//Matrix yazdırma
	cout << "Matrix multiplication Vector:" << endl;
	carpim = matrixA * vectorA;
	cout << "Matrix A: " << endl;
	matrixA.print();
	cout << "Vector A: " << endl;
	vectorA.print();
	cout << "Matrix carpim: " << endl;
	carpim.print();
	//Esitlik kontrol
	cout << "is matrix A equal to matrix B: ";
	matrixA == matrixB ? cout << "True" << endl : cout << "False" << endl;
	cout << endl;

	//Vector+ overloading
	//Vector yazdırma
	cout << endl;
	cout << "\tVectors addition:" << endl;
	vectorC = vectorA + vectorB;
	cout << "Vector A: " << endl;
	vectorA.print();
	cout << "Vector B: " << endl;
	vectorB.print();
	cout << "Vector C: " << endl;
	vectorC.print();
	//Vector- overloading
	//Vector yazdırma
	cout << endl;
	cout << "\tVectors subtraction:" << endl;
	vectorC = vectorA - vectorB;
	cout << "Vector A: " << endl;
	vectorA.print();
	cout << "Vector B: " << endl;
	vectorB.print();
	cout << "Vector C: " << endl;
	vectorC.print();
	double d;
	//Vector* overloading
	//Vector yazdırma
	cout << endl;
	cout << "Vector Dot Product" << endl;
	d = vectorA * vectorB;
	cout << "Vector A: " << endl;
	vectorA.print();
	cout << "Vector B: " << endl;
	vectorB.print();
	cout << "Vector dot product : " << d << endl;
	//Esitlik kontrol
	cout << "is vector A equal to vector B: ";
	vectorA == vectorB ? cout << "True" << endl : cout << "False" << endl;
	//Operar++
	cout << "Operator++ " << endl;
	vectorA++;
	vectorA.print();
	//++Operator
	cout << "++Operator " << endl;
	++vectorA;
	vectorA.print();
	cout << "Matris transpose" << endl;
	Matrix matrixD;
	cout << "Matrix A" << endl;
	matrixA.print();
	cout << "A transpose -> Matrix D" << endl;
	matrixD = transpose(matrixA);
	matrixD.print();
	cout << endl <<"Norm Calculator" << endl;
	cout << "Matrix A:" << endl;
	matrixA.print();
	d = norm(matrixA);
	cout << "matrix A'l2 norm: " << d << endl;
	cout << "Vector A:" << endl;
	vectorA.print();
	d = norm(vectorA);
	cout << "Vector A'l2 norm:" << d << endl;


	cout << "Vector Array" << endl;
	int m = 2;
	int p = 2;
	Vector* vectorArray = (Vector*)malloc((m) * sizeof(Vector));
	vectorArray[0] = vectorA;
	vectorArray[1] = vectorB;
	for (int i = 0; i < m; i++) {
		cout << typeid(vectorArray[i]).name()<<endl;
		vectorArray[i].print();
	}
	//  Matrix m7;
	//  m7.vector2Array(vectorArray, m, p);
	//  m7*/.print();


	cout << "Matrix&Vector array" << endl;
	Vector* v5 = new Vector(entries, row);
	Vector* v6 = new Vector(entries, row);
	Matrix* m5 = new Matrix(entries, row, col);
	Matrix* m6 = new Matrix(entries, row, col);
	Matrix* matrixVector[] = { v5,v6,m5,m6 };
	for (int i = 0; i < 4; i++) {
		cout << typeid(matrixVector[i]).name();
		matrixVector[i]->print();
	}
}