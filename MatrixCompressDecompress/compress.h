#ifndef COMPRESS_H_
#define COMPRESS_H_
void compress_IJ(int **A, int *nz, int *rows, int *cols);
int **decompress_IJ(int *nz, int *rows, int *cols);
void compress_CRS(int **A, int *nz, int *col_ind,int *row_ptr);
int **decompress_CRS(int *nz, int *col_ind, int *row_ptr);
void compress_CCS(int **A, int *nz, int *row_ind,int *col_ptr);
int **decompress_CCS(int *nz, int *row_ind, int *col_ptr);
#endif

