int Trie[maxn][26],tot = 1;
int cnt[maxn];
char s[maxn];
void Insert(char *s)
{
    int n = strlen(s),p = 1;
    for(int i=0;i<n;++i)
    {
        int x = s[i]-'a';
        if(Trie[p][x]==0) Trie[p][x] = ++tot;
        p = Trie[p][x];
    }
    cnt[p]++;
}
int Search(char *s)
{
    int n = strlen(s),p = 1;
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        p = Trie[p][s[i]-'a'];
        ans+=cnt[p];
    }
    return ans;
}
