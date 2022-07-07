class SegmentTree {
public:
	vll segt;
	SegmentTree(ll n) {
		segt.resize(4*n+1);
	}
	void build(ll cur, ll l, ll r, vi& a)
	{
		if(l == r)
		{
			segt[cur] = a[start];
			return;
		}
		ll mid = (l+r)/2;
		build(2*cur, l, mid, a);
		build(2*cur+1, mid+1, r, a);
		// Merge 
		segt[cur] = segt[2*cur] + segt[2*cur + 1];
	}
	ll query(ll cur, ll l, ll r, ll qs, ll qe)
	{
		if(l >= qs && e <= qe)
			return segt[cur];
		if(l > qe || e < qs)
			return -1;
		ll mid = (l+r)/2;
		// Merge
		ll ans=query(2*cur, l, mid, qs, qe)+query(2*cur+1, mid+1, r, qs, qe);
		return ans;
	}
	void update(ll cur, ll l, ll r, ll pos, ll val)
	{
		if(l == r)
		{
			segt[cur] = val;
			return;
		}
		if(l > pos || r < pos)
			return;
		ll mid = (l+r)/2;
		update(2*cur, l, mid, pos, val);
		update(2*cur+1, mid+1, r, pos, val);
		//Merge
		segt[cur] = segt[2*cur] + segt[2*cur+1];
	}
}