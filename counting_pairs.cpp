#include <bits/stdc++.h>
// 15.03.25
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x, y;
    int t;
    cin >> t;
    while(t--)
    {
        long long sum = 0;
        cin >> n >> x >> y;
        vector<int> v(n);
        for (int i = 0; i < n; i++){ cin >> v[i]; sum+=v[i]; }
        sort(v.begin(),v.end());
        long long cnt = 0;
        for(int i  =0;i<n-1;i++)
        {
            auto low = lower_bound(v.begin()+i+1,v.end(),sum-v[i]-y);
            auto high = upper_bound(v.begin()+i+1,v.end(),sum-v[i]-x);
            cnt = cnt + (high-low);
        }
        cout << cnt << '\n';

    }

}
