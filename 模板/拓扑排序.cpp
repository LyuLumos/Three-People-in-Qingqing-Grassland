int topu(int n)
{
    queue<int>q;
    for(int i=1;i<=n;++i)
    {
        _in[i] = in[i];  ///in[i]��ʾ��i���ڵ�����
        if(!in[i]) q.push(i);
    }
    vector<int>ans; bool res = 0;
    while(!q.empty())
    {
        if(q.size()!=1) res = 1;  ///˵�����д��ڶ��ֿ���
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(int v:G[u])
        {
            if(--_in[v]==0) q.push(v);
        }
    }
    if(ans.size()!=n) return -1; ///˵���л���������
    if(res) return 0; ///������������Ψһ
    return 1; ///�����������в�Ψһ
}
