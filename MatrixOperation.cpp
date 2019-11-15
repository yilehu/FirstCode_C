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
