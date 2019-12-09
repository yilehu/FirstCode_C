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

void MatrixDefinition_Banded(double **Matrix,int m,int Bandwidth)
{
	int i,j,k;
	for(i=0;i<m;i++)
	{
	
		for(j=0;j<Bandwidth;j++)
		{
			if(i>Bandwidth-j-2)
			{
				Matrix[i][j] = j+1;
				
			}
			if(i<m-(Bandwidth-1-j))
			{
				Matrix[i][2*Bandwidth-2 - j] = j+1;
			}
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

void MatrixMultiply_Banded(double **A,double *x,double *b,int m,int n,int Bandwidth)
{
	int i,j;
	for(i=0;i<Bandwidth-1;i++)
	{
		b[i] = 0.0;
		for(j=Bandwidth-1-i;j<n;j++)
		{
			b[i] += A[i][j]*x[i-(Bandwidth-1)+j];
		}
	}
	for(i=Bandwidth-1;i<m-Bandwidth+1;i++)
	{
		b[i] = 0.0;
		for(j=0;j<n;j++)
		{
			b[i] += A[i][j]*x[i-(Bandwidth-1)+j];
		}
	}
	for(i=m-Bandwidth+1;i<m;i++)
	{
		b[i] = 0.0;
		for(j=0;j<Bandwidth-1+m-i;j++)
		{
			b[i] += A[i][j]*x[i-(Bandwidth-1)+j];
		}
	}
}

double Dotproduct(double *a,double *b,int n)
{
	double temp = 0.0000;
	for(int i=0;i<n;i++)
	{
		temp += a[i]*b[i];
	}
	return temp;
}
