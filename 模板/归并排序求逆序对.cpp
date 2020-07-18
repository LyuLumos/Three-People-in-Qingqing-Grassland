int a[maxn],b[maxn];
ll cnt = 0;
void merge(int l,int r)
{
    if(l==r) return ;
    int mid = (l+r)/2;
    int i = l,j = mid+1;
    merge(l,mid);
    merge(mid+1,r);
    for(int k=l;k<=r;++k)
    {
        if(j>r || i<=mid&&a[i]<=a[j]) b[k] = a[i++];
        else b[k] = a[j++],cnt+=mid-i+1;
    }
    for(int k=l;k<=r;++k) a[k] = b[k];
}
