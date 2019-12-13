#ifndef _MATRIXOPERATION_ 
#define _MATRIXOPERATION_ 

void MatrixDefinition(double **Matrix,int m,int Bandwidth);

void MatrixDefinition_Banded(double **Matrix,int m,int Bandwidth);

void MatrixMultiply(double **A,double *x,double *b,int m,int n);

void MatrixMultiply_Banded(double **A,double *x,double *b,int m,int n,int Bandwidth);

double Dotproduct(double *a,double *b,int n);

#endif