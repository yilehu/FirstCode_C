#include <stdio.h>

void PrintToFile(double **Matrix,int mm,int nn,double *CoordX,double *CoordY,double *CoordZ,int i,char *Directory,char *ArrayName,double var1)
{
	FILE *fp;
	errno_t err;
	err = fopen_s(&fp,Directory, "w+");

	//fp = fopen("file.txt","w+");

	fprintf(fp,"Array's name is: %s, Pi = %20E\n",ArrayName,var1);
	int j,k;
	for(j=0;j<i;j++)
	{
		fprintf(fp,"    %16.11lf    %16.11lf    %16.11lf\n",CoordX[j],CoordY[j],CoordZ[j]);
	}

	for(j=0;j<mm;j++)
	{
		for(k=0;k<nn;k++)
		{
			fprintf(fp,"%16.11lf",Matrix[j][k]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

void PrintMatrix(double **Matrix,char *Directory,char *MatrixName,int m,int n)
{
	FILE *fp;
	errno_t err;
	err = fopen_s(&fp,Directory, "w+");

	fprintf(fp,"Matrix's name is: %s, Number of rows = %d, Number of Columns = %d\n",MatrixName,m,n);
	printf("Matrix's name is: %s, Number of rows = %d, Number of Columns = %d\n",MatrixName,m,n);
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fp,"%16.11lf",Matrix[i][j]);
			printf("%16.11lf",Matrix[i][j]);
		}
		fprintf(fp,"\n");
		printf("\n");
	}
	fclose(fp);
}
