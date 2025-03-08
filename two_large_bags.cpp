    #include <bits/stdc++.h>
     
    using namespace std;
     
     
    void solve()
    {
        vector<int> f(1004,0);
        set<int> v;
        int n;
        cin >> n;
        int tmp;
        for(int i = 0;i<n;i++)
        {
            cin >> tmp;
            f[tmp]++;
            v.insert(tmp);
        }
     
        while(!v.empty())
        {
     
            auto it = v.begin();
            int cur = *it;
            if(f[cur]==1)
            {
                cout << "NO\n";
                return;
            }
            f[cur]-=2;
            if(f[cur])
            {
                v.insert(cur+1);
            }
            f[cur+1] += f[cur];
            f[cur] = 0;
            v.erase(cur);
        }
        cout << "YES\n";
        return;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin >> t;
        while(t--)
        {
            solve();
        }
        return 0;
    }
