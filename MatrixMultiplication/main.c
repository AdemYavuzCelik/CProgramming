
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


float matrixMatrixMultiplyijk(float **dizi, float **dizi2 ,float **dizi3 ,int boyut) {
	int i,j,k;
	for( i=0; i < boyut; i++){
		for(j=0;  j< boyut; j++){
 			for(k=0; k<boyut;k++){ 
			dizi3[i][j] = dizi3[i][j] + dizi[i][k] * dizi2[k][j];
			}
		}
	}
	return **dizi3;
}
float matrixMatrixMultiplyikj(float **dizi, float **dizi2 ,float **dizi3 ,int boyut) {
	int i,j,k;
	for( i=0; i < boyut; i++){
		for(k=0;  k< boyut; k++){
 			for(j=0; j<boyut; j++){ 
			dizi3[i][j] = dizi3[i][j] + dizi[i][k] * dizi2[k][j];
			}
		}
	}
	return **dizi3;
}
float matrixMatrixMultiplyjik(float **dizi, float **dizi2 ,float **dizi3 ,int boyut) {
	int i,j,k;
	for( j=0; j < boyut; j++){
		for(i=0;  i< boyut; i++){
 			for(k=0; k<boyut;k++){ 
			dizi3[i][j] = dizi3[i][j] + dizi[i][k] * dizi2[k][j];
			}
		}
	}
	return **dizi3;
}
float matrixMatrixMultiplyjki(float **dizi, float **dizi2 ,float **dizi3 ,int boyut) {
	int i,j,k;
	for( j=0; j < boyut; j++){
		for(k=0;  k< boyut; k++){
 			for(i=0; i<boyut;i++){ 
			dizi3[i][j] = dizi3[i][j] + dizi[i][k] * dizi2[k][j];
			}
		}
	}
	return **dizi3;
}
float matrixMatrixMultiplykij(float **dizi, float **dizi2 ,float **dizi3 ,int boyut) {
	int i,j,k;
	for( k=0; k < boyut; k++){
		for(i=0;  i< boyut; i++){
 			for(j=0; j<boyut;j++){ 
			dizi3[i][j] = dizi3[i][j] + dizi[i][k] * dizi2[k][j];
			}
		}
	}
	return **dizi3;
}
float matrixMatrixMultiplykji(float **dizi, float **dizi2 ,float **dizi3 ,int boyut) {
	int i,j,k;
	for( k=0; k < boyut; k++){
		for(j=0;  j< boyut; j++){
 			for(i=0; i<boyut;i++){ 
			dizi3[i][j] = dizi3[i][j] + dizi[i][k] * dizi2[k][j];
			}
		}
	}
	return **dizi3;
}
int main(){
	int i, j, k,boyut;
	float **ptr, **ptr2, **ptr3;	
	srand(time(NULL));
	float randomSayi,randomSayi2;
	printf("Lutfen matrisin boyutunu giriniz: ");
	scanf("%d",&boyut);
	ptr = (float **) malloc(sizeof(float *) * boyut);
	ptr2 = (float **) malloc(sizeof(float *) * boyut);
	ptr3 = (float **) malloc(sizeof(float *) * boyut);
	
	for(i=0; i<boyut; i++){
 		ptr[i] = (float *)malloc(sizeof(float) * boyut);
 		ptr2[i] = (float *)malloc(sizeof(float) * boyut);
 		ptr3[i] = (float *)malloc(sizeof(float) * boyut);
	}
	
	for(i=0; i< boyut; i++){
		for(j=0; j< boyut; j++){
			randomSayi=((float)rand()/(float)(RAND_MAX)) * 10.0;
			ptr[i][j] = randomSayi;
			randomSayi2=((float)rand()/(float)(RAND_MAX)) * 10.0;
			ptr2[i][j] = randomSayi2;
		}
	}
	
    clock_t baslangic = clock();
    
//Döngü Sýralarý:

	matrixMatrixMultiplyijk(ptr, ptr2,ptr3, boyut);
	
//	matrixMatrixMultiplyikj(ptr, ptr2,ptr3, boyut);

//	matrixMatrixMultiplyjik(ptr, ptr2,ptr3, boyut);

//	matrixMatrixMultiplyjki(ptr, ptr2,ptr3, boyut);

//	matrixMatrixMultiplykij(ptr, ptr2,ptr3, boyut);

//	matrixMatrixMultiplykji(ptr, ptr2,ptr3, boyut);

     clock_t son = clock();
     double gecenSure = (double)(son - baslangic) / CLOCKS_PER_SEC;
     printf("Calisma Suresi: %.4f",gecenSure);
     printf("\nProgramdan cikmak icin bir tusa basiniz...\n");
	 getch();
     

return 0;
}
