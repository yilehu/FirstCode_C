void MatrixDefinition(double **Matrix,int m,int Bandwidth)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
		Matrix[i][i] = (double)Bandwidth;
		if(i <= m-Bandwidth)
		{
			k = Bandwidth;
		}
		else
		{
			k = m - i;
		}
		for(j=1;j<k;j++)
		{
			Matrix[i][i+j] = Bandwidth - j;
			Matrix[i+j][i] = Bandwidth - j;
		}
	}
}

void MatrixMultiply(double **A,double *x,double *b,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		b[i] = 0.0;
		for(j=0;j<n;j++)
		{
			b[i] += A[i][j]*x[j];
		}
	}
}

double Dotproduct(double *a,double *b,int n)
{
	double temp = 0.0;
	for(int i=0;i<n;i++)
	{
		temp += a[i]*b[i];
	}
	return temp;
}
