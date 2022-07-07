
class DSU {
public:
	vi par;
	vi rank;
	DSU(int n)
	{
		par.resize(n);
		rep(i,0,n) par[i] = -1;
	}
	int find_set(int v)
	{
		if(v == par[v])
			return v;
		return par[v] = find_set(par[v]);
	}
	void make_set(int v)
	{
		par[v] = v;
		rank[v] = 0;
	}
}