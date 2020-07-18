
priority_queue<int> q1; //大根堆
priority_queue<int, vector<int>, greater<int> > q2; //小根堆

inline void insert(int x)
{
	if(!q2.size() || x > q2.top()) q2.push(x);
	else q1.push(x);
	if(q1.size() > q2.size() + 1) { q2.push(q1.top()); q1.pop(); }
	if(q2.size() > q1.size() + 1) { q1.push(q2.top()); q2.pop(); }
}
