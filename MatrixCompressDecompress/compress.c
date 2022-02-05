#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compress.h"
#define SATIR 6
#define SUTUN 6
extern int nzboyut;
void compress_CRS(int **A, int *nz, int *col_ind, int *row_ptr) {
	int i, j;
	int k = 0;
	int bayrak;
	int m = 0;
	for (i = 0; i < SATIR; i++) {
		bayrak = 0;
		for (j = 0; j < SUTUN; j++) {
			if (A[i][j] != 0) {				//matriste s�f�ra e�it olmayan elemanlar� bulma
				*(nz + k) = A[i][j];		//bu elemanlar� nz dizisine atama
				*(col_ind + k) = j;			//bu elemanlar�n sutun indislerinin col_ind dizisine atama
				if (bayrak == 0) {			//her yeni sat�rda s�f�rdan farkl� ilk eleman� alabilmem i�in gereken flag
					*(row_ptr + m) = k;		//sat�r�n ilk eleman�n�n row_ptr dizisine atama (nz+k) nzde kar��l�k gelen indisleri k de�i�keni sayesinde atayabiliyorum
					m++;
					bayrak = 1;
				}
				k++;

			}
		}
	}
}

void compress_CCS(int **A, int *nz, int *row_ind, int *col_ptr) {
	int i, j;							//ayn� i�lemler comress CRSdeki ile...
	int k = 0;
	int bayrak;
	int m = 0;
	for (i = 0; i < SATIR; i++) {
		bayrak = 0;
		for (j = 0; j < SUTUN; j++) {
			if (A[j][i] != 0) {
				*(nz + k) = A[j][i];
				*(row_ind + k) = j;
				if (bayrak == 0) {
					*(col_ptr + m) = k;
					m++;
					bayrak = 1;
				}
				k++;
			}
		}
	}
}										//ayn� i�lemler comress CRSdeki ile...

int** decompress_CRS(int *nz, int *col_ind, int *row_ptr) {
	int **crsA;
	int i, j, k = 0, fark;			//gerekli  de�i�ken ve matris olu�turulma a�amas�
	crsA = (int**) calloc(sizeof(int*), SATIR);
	for (i = 0; i < SUTUN; i++) {
		crsA[i] = (int*) calloc(sizeof(int), SUTUN);	//komple matrisi s�f�rl�yorum ki s�f�r atama i�lemi yapmamak i�in
	}

	for (i = 0; i < SATIR; i++) {
		fark = *(row_ptr + i + 1) - *(row_ptr + i); //  rowptrler aras�ndaki fark sat�rlardaki s�f�rdan farkl� eleman say�lar�n� veriyor.
		for (j = 0; j < fark; j++) {
			crsA[i][*(col_ind + k)] = *(nz + k); //colind+k'den d�nen de�er 0 dan farkl� olan say�lar�n s�tun indislerini d�nd�r�p
												 //matrisin s�tun k�sm�na e�itleniyor.
												 //matrisin indisine  nz+k den gelen de�er atan�yor
			k++;
		}
	}

	return crsA;							//matrisi d�nd�rme.
}

int** decompress_CCS(int *nz, int *row_ind, int *col_ptr) {
	int **ccsA;                							
	int i, j, k = 0, fark;								//gerekli  de�i�ken ve matris olu�turulma a�amas�
	ccsA = (int**) calloc(sizeof(int*), SATIR);
	for (i = 0; i < SUTUN; i++) {
		ccsA[i] = (int*) calloc(sizeof(int), SUTUN);	//komple matrisi s�f�rl�yorum ki s�f�r atama i�lemi yapmamak i�in
	}
	for (i = 0; i < SATIR; i++) {
		fark = *(col_ptr + i + 1) - *(col_ptr + i);	//  colptrler aras�ndaki fark sutunlardaki s�f�rdan farkl� eleman say�lar�n� veriyor.
		for (j = 0; j < fark; j++) {
			ccsA[*(row_ind + k)][i] = *(nz + k);	//rowind+k'den d�nen de�er 0 dan farkl� olan say�lar�n sat�r indislerini d�nd�r�p
													//matrisin sat�r k�sm�na e�itleniyor.
			k++;									// //matrisin indisine  nz+k den gelen de�er atan�yor
		}												
	}
	return ccsA;									//matrisi d�nd�rme.
}

void compress_IJ(int **A, int *nz, int *rows, int *cols){
	int indis=0;
	int i,j;
		for (i = 0; i < SATIR; i++) {
			for (j = 0; j < SUTUN; j++) {
				if (A[i][j] != 0) {
					*(nz+indis)=A[i][j];
					*(rows+indis)=i;
					*(cols+indis)=j;
					indis++;
				}
			}
		}
}

int **decompress_IJ(int *nz, int *rows, int *cols){
																//3 dizininde boyutu ayn� d�nme say�m dizilerimin boyutlar�na
	int **ccA;													// ba�l� oldu�u i�in nzboyut parametresi gerekliydi.
		int i;
		ccA = (int**) calloc(sizeof(int*), SATIR);
		for (i = 0; i < SUTUN; i++) {
			ccA[i] = (int*) calloc(sizeof(int), SUTUN);			//calloc ile s�f�rlar atand�.
		}
		for (i = 0; i < nzboyut; i++) {
			ccA[*(rows+i)][*(cols+i)]=*(nz+i);				//row dizisi matrisin sat�rlar�n� tuttu�u i�in sat�r k�sm�na
			}												//col dizisi matrisin sutunlar�n� tuttu�u i�in sutun k�sm�na
															//yaz�ld�
		return ccA;									//en son matrisi d�nd�rme.
	}


