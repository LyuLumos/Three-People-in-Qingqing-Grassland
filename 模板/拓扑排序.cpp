int topu(int n)
{
    queue<int>q;
    for(int i=1;i<=n;++i)
    {
        _in[i] = in[i];  ///in[i]表示第i个节点的入度
        if(!in[i]) q.push(i);
    }
    vector<int>ans; bool res = 0;
    while(!q.empty())
    {
        if(q.size()!=1) res = 1;  ///说明序列存在多种可能
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(int v:G[u])
        {
            if(--_in[v]==0) q.push(v);
        }
    }
    if(ans.size()!=n) return -1; ///说明有环不能拓扑
    if(res) return 0; ///可以拓扑序列唯一
    return 1; ///可以拓扑序列不唯一
}
