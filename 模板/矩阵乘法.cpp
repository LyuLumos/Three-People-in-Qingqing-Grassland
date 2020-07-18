
typedef vector<int> vec;
typedef vector<vec> mat;

///æÿ’ÛA*B
void mul(mat &A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();++i)
    {
        for(int j=0;j<B[0].size();++j)
        {
            C[i][j]=0;
            for(int k=0;k<B.size();++k)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    A = C;
}
