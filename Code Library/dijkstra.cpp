
const int INF = MAX_INT;
const int MX = 100001;
vi dist(MX);
vii adj;
int n;
void dijkstra(int s)
{
	rep(i,0,n) dist[i] = INF;
	dist[s] = 0;
	priority_queue<pii, vii, greater<pii>> q;
	q.push(pii(0, s));
	while(!q.empty())
	{
		pii p = q.top();
		q.pop();
		int d = p.first;
		int u = p.second;
		if(d > dist[u])
			continue;

		for(auto x : adj[u])
		{
			int v = x.first;
			int w = x.second;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u]+w;
				q.push(pii(dist[v], v));
			}
		}
	}
}