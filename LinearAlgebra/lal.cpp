#include <iostream>
#include <math.h>
#include "lal.h"

Matrix::Matrix() = default;
Matrix::Matrix(double* entries, int rows, int cols) {
	this->entries = entries;
	this->rows = rows;
	this->cols = cols;
}
Matrix::~Matrix() = default;
void Matrix::print() {
	if (rows == 0 && cols == 0) {
		cout << "No value in Matrix" << endl;
	}
	for (int i = 0; i < rows * cols; i++) {
		if (i % cols == 0) {
			cout << endl;
		}
		cout << entries[i] << "\t";
	}
	cout << endl;
}
//Matrix Matrix::vector2Array(Matrix vectorArray[], int m , int p){
//		Matrix temp;
//		temp.rows = m;
//		temp.cols = p;
//		int k = 0;
//		double* entries = (double*)malloc((m * p) * sizeof(double));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < p; j++) {
//				entries[k] = vectorArray[i].entries[j];
//				k++;
//			}
//		}
//		temp.entries = entries;
//		return temp;
//}
Matrix Matrix::operator+(const Matrix & oth) {
	Matrix temp;
	if (rows == oth.rows && cols == oth.cols) {
		temp.cols = oth.cols;
		temp.rows = oth.rows;
		temp.entries = (double*)malloc((rows * cols) * sizeof(double));

		for (int i = 0; i < oth.rows * oth.cols; i++)
			temp.entries[i] = entries[i] + oth.entries[i];

		return temp;
	}
	else {
		cout << "Rows and Cols should be equal" << endl;
		return temp;
	}
}
Matrix Matrix::operator-(const Matrix & oth) {
	Matrix temp;
	if (rows == oth.rows && cols == oth.cols) {
		temp.cols = oth.cols;
		temp.rows = oth.rows;
		temp.entries = (double*)malloc((rows * cols) * sizeof(double));
		for (int i = 0; i < rows * cols; i++)
			temp.entries[i] = entries[i] - oth.entries[i];

		return temp;
	}
	else {
		cout << "Rows and Cols should be equal" << endl;
		return temp;
	}
}
bool Matrix::operator==(const Matrix & oth) {
	if (rows != oth.rows && cols != oth.cols) {
		return false;
	}
	else {
		for (int i = 0; i < rows * cols; i++) {
			if (entries[i] != oth.entries[i]) {
				return false;
			}
		}
	}
	return true;
}
Matrix Matrix::operator*(const Matrix & oth) {
	Matrix temp;
	if (cols == oth.rows) {
		temp.rows = oth.rows;
		temp.cols = oth.cols;
		temp.entries = (double*)malloc((rows * oth.cols) * sizeof(double));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < oth.cols; j++) {
				int sum = 0;
				for (int k = 0; k < cols; k++){
					sum = sum + entries[i * cols + k] * oth.entries[k * oth.cols + j];
				}
				temp.entries[i * oth.cols + j] = sum;
			}
		}
		return temp;
	}
	else {
		cout << "First matrix's col should be equal to second matrix's/vector's row " << endl;
		return temp;
	}


}
Vector::Vector() = default;
Vector::Vector(double* entries, int rows) {
	this->entries = entries;
	this->rows = rows;
	this->cols = 1;
	double toplam = 0;
	//cevap=(1^2)+(2^2)+(3^2)(4^2)(5^2) 
	for (int i = 0; i < rows * cols; ++i) {
		toplam += entries[i] * entries[i];
	}
	double norm = sqrt(toplam);
	l2norm = norm;
	cout << "l2norm: " << l2norm << endl;
}
Vector::~Vector() = default;
double* Vector::getEntries() {
	return entries;
}
void Vector::print() {
	if (rows == 0) {
		cout << "No value in Matrix" << endl;
	}
	for (int i = 0; i < rows; i++)
		cout << entries[i] << endl;
	cout << endl;
}
Vector Vector::operator+(const Vector & oth) {
	Vector temp;

	if (rows == oth.rows) {
		temp.rows = rows;
		temp.rows = rows;
		temp.entries = (double*)malloc((rows) * sizeof(double));
		for (int i = 0; i < rows; i++)
			temp.entries[i] = entries[i] + oth.entries[i];

		return temp;
	}
	else {
		cout << "Rows should be equal" << endl;
		return temp;
	}

}
bool Vector::operator==(const Vector & oth) {
	if (rows != oth.rows) {
		return false;
	}
	else {
		for (int i = 0; i < rows; i++) {
			if (entries[i] != oth.entries[i]) {
				return false;
			}
		}
	}
	return true;
}
Vector Vector::operator-(const Vector & oth) {
	Vector temp;

	if (rows == oth.rows) {
		temp.rows = rows;
		temp.rows = rows;
		temp.entries = (double*)malloc((rows) * sizeof(double));
		for (int i = 0; i < rows; i++)
			temp.entries[i] = entries[i] + oth.entries[i];

		return temp;
	}
	else {
		cout << "Rows should be equal" << endl;
		return temp;
	}
}
double Vector::operator*(const Vector & oth) {
	double temp = 0;
	if (rows == oth.rows) {
		for (int i = 0; i < rows; i++)
			temp= entries[i] * oth.entries[i];
		return temp;
	}
	else {
		cout << "Rows should be equal "<< endl;
		return temp;
	}
}
Vector Vector::operator++() {
	for (int i = 0; i < rows; i++) {
		this->entries[i] = this->entries[i] + 1.0;
	}
	return Vector(this->entries, rows);
}
Vector Vector::operator++(int) {
	for (int i = 0; i < rows; i++) {
		this->entries[i] = this->entries[i] + 1.0;
	}
	return Vector(this->entries, rows);
}

Matrix transpose(const Matrix & oth) {
	Matrix temp;
	temp.entries = (double*)malloc((oth.rows * oth.cols) * sizeof(double));
	for (int i = 0; i < oth.rows; ++i) {
		for (int j = 0; j < oth.cols; ++j) {
			temp.entries[j * oth.rows + i] = oth.entries[i * oth.cols + j];
		}
	}
	temp.cols = oth.rows;
	temp.rows = oth.cols;
	cout << endl;
	return temp;
}

double norm(const Matrix & oth) {
	double toplam = 0.;
	for (int i = 0; i < oth.rows*oth.cols; ++i) {
		toplam += oth.entries[i] * oth.entries[i];
	}
	double norm = sqrt(toplam);
	return norm;
}



