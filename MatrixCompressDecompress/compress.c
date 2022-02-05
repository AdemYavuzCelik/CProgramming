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
			if (A[i][j] != 0) {				//matriste sýfýra eþit olmayan elemanlarý bulma
				*(nz + k) = A[i][j];		//bu elemanlarý nz dizisine atama
				*(col_ind + k) = j;			//bu elemanlarýn sutun indislerinin col_ind dizisine atama
				if (bayrak == 0) {			//her yeni satýrda sýfýrdan farklý ilk elemaný alabilmem için gereken flag
					*(row_ptr + m) = k;		//satýrýn ilk elemanýnýn row_ptr dizisine atama (nz+k) nzde karþýlýk gelen indisleri k deðiþkeni sayesinde atayabiliyorum
					m++;
					bayrak = 1;
				}
				k++;

			}
		}
	}
}

void compress_CCS(int **A, int *nz, int *row_ind, int *col_ptr) {
	int i, j;							//ayný iþlemler comress CRSdeki ile...
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
}										//ayný iþlemler comress CRSdeki ile...

int** decompress_CRS(int *nz, int *col_ind, int *row_ptr) {
	int **crsA;
	int i, j, k = 0, fark;			//gerekli  deðiþken ve matris oluþturulma aþamasý
	crsA = (int**) calloc(sizeof(int*), SATIR);
	for (i = 0; i < SUTUN; i++) {
		crsA[i] = (int*) calloc(sizeof(int), SUTUN);	//komple matrisi sýfýrlýyorum ki sýfýr atama iþlemi yapmamak için
	}

	for (i = 0; i < SATIR; i++) {
		fark = *(row_ptr + i + 1) - *(row_ptr + i); //  rowptrler arasýndaki fark satýrlardaki sýfýrdan farklý eleman sayýlarýný veriyor.
		for (j = 0; j < fark; j++) {
			crsA[i][*(col_ind + k)] = *(nz + k); //colind+k'den dönen deðer 0 dan farklý olan sayýlarýn sütun indislerini döndürüp
												 //matrisin sütun kýsmýna eþitleniyor.
												 //matrisin indisine  nz+k den gelen deðer atanýyor
			k++;
		}
	}

	return crsA;							//matrisi döndürme.
}

int** decompress_CCS(int *nz, int *row_ind, int *col_ptr) {
	int **ccsA;                							
	int i, j, k = 0, fark;								//gerekli  deðiþken ve matris oluþturulma aþamasý
	ccsA = (int**) calloc(sizeof(int*), SATIR);
	for (i = 0; i < SUTUN; i++) {
		ccsA[i] = (int*) calloc(sizeof(int), SUTUN);	//komple matrisi sýfýrlýyorum ki sýfýr atama iþlemi yapmamak için
	}
	for (i = 0; i < SATIR; i++) {
		fark = *(col_ptr + i + 1) - *(col_ptr + i);	//  colptrler arasýndaki fark sutunlardaki sýfýrdan farklý eleman sayýlarýný veriyor.
		for (j = 0; j < fark; j++) {
			ccsA[*(row_ind + k)][i] = *(nz + k);	//rowind+k'den dönen deðer 0 dan farklý olan sayýlarýn satýr indislerini döndürüp
													//matrisin satýr kýsmýna eþitleniyor.
			k++;									// //matrisin indisine  nz+k den gelen deðer atanýyor
		}												
	}
	return ccsA;									//matrisi döndürme.
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
																//3 dizininde boyutu ayný dönme sayým dizilerimin boyutlarýna
	int **ccA;													// baðlý olduðu için nzboyut parametresi gerekliydi.
		int i;
		ccA = (int**) calloc(sizeof(int*), SATIR);
		for (i = 0; i < SUTUN; i++) {
			ccA[i] = (int*) calloc(sizeof(int), SUTUN);			//calloc ile sýfýrlar atandý.
		}
		for (i = 0; i < nzboyut; i++) {
			ccA[*(rows+i)][*(cols+i)]=*(nz+i);				//row dizisi matrisin satýrlarýný tuttuðu için satýr kýsmýna
			}												//col dizisi matrisin sutunlarýný tuttuðu için sutun kýsmýna
															//yazýldý
		return ccA;									//en son matrisi döndürme.
	}


