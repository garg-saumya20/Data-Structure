//CodeChef Problem


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

bool ok(vector< pair< ll,ll > > &v, ll m, ll l, ll w) 
{
	ll sum = 0;
	for(auto x: v) {
		if(x.first + x.second*m<l)
			continue;
		sum += x.first+x.second*m;
		if(sum>=w) return true;
	}
	return false;
}


int main()
{
	ll n, w, l;
	cin >> n >> w >> l;
	vector< pair< ll, ll > > v;
	for(int i=0; i<n; i++) {
		ll h, r;
		cin >> h >> r;
		v.pb({h, r});
	}
	
	ll lo = 0;
	ll hi = 1000000000;
    
	ll ans = 0;
	while(lo<hi) {
		ll mid = (lo+hi)/2;
		if(ok(v, mid, l, w)) {
			hi = mid;
			ans = mid;
		}
		else lo = mid+1;
	}
	cout << ans << endl;
	//cout << min(hi, lo) << endl;
	return 0;
}
