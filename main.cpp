#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Initialization.h"
#include "PrintToFile.h"
#include "MatrixOperation.h"

int main(int argc,char *argv[])
{
	int i,j,k;
	
	char *Directory1,*Directory2;
	Directory1 = "Array.dat";
	Directory2 = "Matrix.dat";

	//************动态数组（二维）***********//
	double *x,*b,*r,*r_new,*p,*ArrayTemp;
	double **Matrix;
	double error,error0 = 1.0e-6;
	double alpha,beta;
	int n = 20;
	int Bandwidth = 5;

	Matrix = (double**)malloc(n*sizeof(double*));
	for(i=0;i<n;i++)
	{
		*(Matrix+i) = (double*)malloc(n*sizeof(double));
	}

	x = (double*)malloc(n*sizeof(double));
	b = (double*)malloc(n*sizeof(double));
	r = (double*)malloc(n*sizeof(double));
	r_new = (double*)malloc(n*sizeof(double));
	p = (double*)malloc(n*sizeof(double));
	ArrayTemp = (double*)malloc(n*sizeof(double));

	InitializeMatrix(Matrix,n,n,0.0);
	InitializeArray(x,n,0.0);
	InitializeArray(b,n,1.0);
	MatrixDefinition(Matrix,n,Bandwidth);

	//Conjugate Gradient//
	//Initialization//
	InitializeArray(x,n,0.0);
	MatrixMultiply(Matrix,x,ArrayTemp,n,n);
	for(i=0;i<n;i++)
	{
		r[i] = b[i] - ArrayTemp[i];
		p[i] = r[i];
	}
	k = 0;
	error = sqrt(Dotproduct(r,r,n));
	//Iteration//
	while(error>error0)
	{
		MatrixMultiply(Matrix,p,ArrayTemp,n,n);
		alpha = Dotproduct(r,r,n)/Dotproduct(p,ArrayTemp,n);
		for(i=0;i<n;i++)
		{
			x[i] += alpha*p[i];
			r_new[i] = r[i] - alpha*ArrayTemp[i];
		}
		error = sqrt(Dotproduct(r_new,r_new,n));
		printf("Iteration number = %d, error = %12E\n",k,error);
		beta = Dotproduct(r_new,r_new,n)/Dotproduct(r,r,n);
		for(i=0;i<n;i++)
		{
			p[i] = r_new[i] + beta*p[i];
			r[i] = r_new[i];
		}
		k++;
	}
	printf("\n");
	PrintArray(x,Directory1,"x",n);
	system("pause");
	

	
	
	PrintArray(b,Directory1,"b",n);
	PrintMatrix(Matrix,Directory2,"A",n,n);
	//************基本变量***********//
	//声明//
	//char *aaa = "hahahaha";
	//char *bbb = "国庆节！";
	//double pi = 3.14159265358;
	//int c = 10;
	//int i,j;
	//
	//printf("Hello World.\n\n");
	//printf("%s, %s\n\n",aaa,bbb);
	//printf("%-16.11lf,%16.11lf\n",pi,pi);
	//printf("%f,%20e\n",pi,pi);
	//printf("%d,%10d\n",c,c);

	//************静态数组***********//
	//声明//
	//int Array1[10];
	//float Array2[10];
	//double Array3[10];
	////初始化//
	//for(i=0;i<10;i++)
	//{
	//	Array1[i] = 0;
	//	Array2[i] = 0.0;
	//	Array3[i] = (double)i;
	//}
	////声明//
	//double Matrix[5][5];
	////初始化//
	//for(i=0;i<5;i++)
	//{
	//	for(j=0;j<5;j++)
	//	{
	//		Matrix[i][j] = 0.0;
	//	}
	//}

	//************条件判断***********//
	//If Else//
	//for(i=0;i<m;i++)
	//{
	//	for(j=0;j<n;j++)
	//	{
	//		if(i == j)
	//		{
	//			Matrix[i][j] = 1.0;
	//		}
	//		else if(i < j)
	//		{
	//			Matrix[i][j] = 0.0;
	//		}
	//		else
	//		{
	//			Matrix[i][j] = 2.0;
	//		}
	//		printf("%6.2lf ",Matrix[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	//Switch//
	//for(i=0;i<m;i++)
	//{
	//	for(j=0;j<n;j++)
	//	{
	//		switch (i)
	//		{
	//		case 0:
	//			Matrix[i][j] = 0.0;
	//			break;
	//		case 1:
	//			Matrix[i][j] = 1.0;
	//			break;
	//		case 2:
	//			Matrix[i][j] = 2.0;
	//			break;
	//		case 3:
	//			Matrix[i][j] = 3.0;
	//			break;
	//		case 4:
	//			Matrix[i][j] = 4.0;
	//			break;
	//		}
	//		printf("%6.2lf ",Matrix[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");

	//************循环结构***********//
	//double error = 10.0;
	//int num = 0;
	//while(error > 1.0)
	//{
	//	error -= 1.0;
	//	num++;
	//}
	//printf("%d\n",num);
	//
	//system("pause");

	return 0;
}
