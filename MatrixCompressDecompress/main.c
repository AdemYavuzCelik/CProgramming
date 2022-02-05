/*
 ============================================================================
 Name        : bp3_hw2.c
 Author      : Adem Yavuz Celik
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compress.h"
#define SATIR 6
#define SUTUN 6
int nzboyut;
int main() {
	int **A;
	int *nz;
	int *col_ind;
	int *row_ind;
	int *row_ptr;
	int *col_ptr;
	int **crsA;
	int **ccsA;
	int **ccA;
	int *rows;
	int *cols;

	srand((unsigned) time(0));
	int i, j;
	A = (int**) malloc(sizeof(int*) * SATIR);		//matris oluþturma
	for (i = 0; i < SUTUN; i++) {
		A[i] = (int*) malloc(sizeof(int) * SUTUN);
	}
	for (i = 0; i < SATIR; i++) {
		for (j = 0; j < SUTUN; j++) {
			A[i][j] = rand() % 9 + 1;				//matrise random sayý atma
		}
	}
	A[0][1] = 0;									//matrise sýfýr atma
	A[0][3] = 0;
	A[0][4] = 0;
	A[1][3] = 0;
	A[1][1] = 0;
	A[1][5] = 0;
	A[2][1] = 0;
	A[2][2] = 0;
	A[2][0] = 0;
	A[3][1] = 0;
	A[3][5] = 0;
	A[3][4] = 0;
	A[4][4] = 0;
	A[4][0] = 0;
	A[4][2] = 0;
	A[5][3] = 0;
	A[5][5] = 0;									//matrise sýfýr atma


	
	for (i = 0; i < SATIR; i++) {
		for (j = 0; j < SUTUN; j++) {
			if (A[i][j] != 0) {
				nzboyut++;							//nz dizisi boyutunu belirleme
			}
		}
	}
	nz = (int*) malloc(sizeof(int) * nzboyut);		//nz pointerýna adres atama

	col_ind = (int*) malloc(sizeof(int) * nzboyut);	//col_ind pointerýna adres atama
	row_ind = (int*) malloc(sizeof(int) * nzboyut); //row_ind pointerýna adres atama

	row_ptr = (int*) malloc(sizeof(int) * SATIR + 1);//row_ptr pointerýna adres atama
	*(row_ptr + SATIR) = nzboyut;					 //son elemanýna nz boyut deðerini atama
	col_ptr = (int*) malloc(sizeof(int) * SATIR + 1);//col_ptr pointerýna adres atama
	*(col_ptr + SATIR) = nzboyut;					 //son elemanýna nz boyut deðerini atama

    rows = (int*) malloc(sizeof(int) * nzboyut);
	cols = (int*) malloc(sizeof(int) * nzboyut);


	printf("**********************************************************\n");
	printf("\n");
	printf("\n");
	printf("		****CRS SPARSE MATRIX****");
	printf("\n");
	printf("\n");
	printf("\n**********************************************************\n");

	printf("\n   A MATRISI \n");

	for (i = 0; i < SATIR; i++) {
		for (j = 0; j < SUTUN; j++) {
			printf("%d  ", A[i][j]);		//Matrisi yazdýrma
		}
		printf("\n");
	}
	printf("\n");
	compress_CRS(A, nz, col_ind, row_ptr); //CRS metod istenilen parametrelerin verilmesi
	printf("---------------------------------------------------------\n");
	printf("\n CRS metodu ile olusan diziler\n");
	printf("\n     nz dizisi : [");
	for (i = 0; i < nzboyut; i++) {
		printf("%d-", *(nz + i));		//pointer aritmetiði ile nz dizisini yazdýrma
	}
	printf("]");
	printf("\ncol_ind dizisi : [");
	for (i = 0; i < nzboyut; i++) {
		printf("%d-", *(col_ind + i)); //pointer aritmetiði ile col_ind dizisini yazdýrma
	}
	printf("]");
	printf("\nrow_ptr dizisi : [");
	for (i = 0; i < SATIR+1; i++) {
		printf("%d-", *(row_ptr + i));//pointer aritmetiði ile row_ptr dizisini yazdýrma
	}
	printf("]");
	printf("\n---------------------------------------------------------\n");

	crsA = decompress_CRS(nz, col_ind, row_ptr);//decompress metod istenilen parametrelerin verilmesi

	printf("\n DeCRS metodu ile olusan yeni matris\n");
	printf("\n  CRSA MATRISI \n");
	for (i = 0; i < SATIR; i++) {
		for (j = 0; j < SUTUN; j++) {
			printf("%d  ", crsA[i][j]);		//olusan yeni matrisin yazdýrýlmasý
		}
		printf("\n");
	}
	printf("\n**********************************************************\n");
	printf("\n");
	printf("\n");
	printf("		****CCS SPARSE MATRIX****");
	printf("\n");
	printf("\n");
	printf("\n**********************************************************\n");
	printf("\n   A MATRISI\n");

	for (i = 0; i < SATIR; i++) {
		for (j = 0; j < SUTUN; j++) {
			printf("%d  ", A[i][j]);
		}
		printf("\n");
	}

	compress_CCS(A, nz, row_ind, col_ptr); //CCS metod istenilen parametrelerin verilmesi
	printf("\n---------------------------------------------------------\n");
	printf("\n CSS metodu ile olusan diziler\n");
	printf("\n     nz dizisi : [");
	for (i = 0; i < nzboyut; i++) {
		printf("%d-", *(nz + i));	//pointer aritmetiði ile nz dizisini yazdýrma
	}
	printf("]");
	printf("\nrow_ind dizisi : [");
	for (i = 0; i < nzboyut; i++) {
		printf("%d-", *(row_ind + i));//pointer aritmetiði ile row_ind dizisini yazdýrma
	}
	printf("]");
	printf("\ncol_ptr dizisi : [");
	for (i = 0; i < SATIR+1; i++) {
		printf("%d-", *(col_ptr + i));//pointer aritmetiði ile col_ptr dizisini yazdýrma
	}
	printf("]");
	printf("\n---------------------------------------------------------\n");
	printf("\n DeCCS metodu ile olusan yeni matris\n");
	printf("\n  CCSA MATRISI \n");
	ccsA = decompress_CCS(nz, row_ind, col_ptr); //decompress metod istenilen parametrelerin verilmesi
	for (i = 0; i < SATIR; i++) {
		for (j = 0; j < SUTUN; j++) {
			printf("%d  ", ccsA[i][j]);			//olsuan yeni matrisin yazdýrýlmasý
		}
		printf("\n");
	}
	printf("\n**********************************************************\n");
	printf("\n");
	printf("\n");
	printf("		****CC SPARSE MATRIX****");
	printf("\n");
	printf("\n");
	printf("\n**********************************************************\n");
	printf("\n   A MATRISI\n");
	for (i = 0; i < SATIR; i++) {
			for (j = 0; j < SUTUN; j++) {
				printf("%d  ", A[i][j]);		//Matrisi yazdýrma
			}
			printf("\n");
		}
	compress_IJ(A,nz,rows,cols);
	printf("\n---------------------------------------------------------\n");
	printf("\n CC metodu ile olusan diziler\n");
	printf("\n  nz dizisi : [");
	for (i = 0; i < nzboyut; i++) {
		printf("%d-", *(nz + i));	//pointer aritmetiði ile nz dizisini yazdýrma
	}
	printf("]");
	printf("\nrows dizisi : [");
	for (i = 0; i < nzboyut; i++) {
		printf("%d-", *(rows + i));//pointer aritmetiði ile rows dizisini yazdýrma
	}
	printf("]");
	printf("\ncols dizisi : [");
	for (i = 0; i < nzboyut; i++) {
		printf("%d-", *(cols + i));//pointer aritmetiði ile cols dizisini yazdýrma
	}
	printf("]");
	printf("\n---------------------------------------------------------\n");
		printf("\n DeCC metodu ile olusan yeni matris\n");
		printf("\n  CCA MATRISI \n");
		ccA = decompress_IJ(nz, rows, cols); //decompress metod istenilen parametrelerin verilmesi
		for (i = 0; i < SATIR; i++) {
			for (j = 0; j < SUTUN; j++) {
				printf("%d  ", ccA[i][j]);			//olsuan yeni matrisin yazdýrýlmasý
			}
			printf("\n");
		}
		printf("\nProgramdan cikmak icin bir tusa basiniz...\n");
	 	getch();
	return 0;
}


