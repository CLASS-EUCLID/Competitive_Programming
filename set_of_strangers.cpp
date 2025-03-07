#include <iostream>
#include <algorithm>
#include <vector>
// 070325 
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,n,m;
    vector<vector<int>> v(703, vector<int>(703  ,0));
    vector<int> f(701*701+1,0);
    cin >> x;
    while(x--)
    {
        cin >> n >> m;
        fill(f.begin(),f.begin()+ n * m + 1,0);
        for (int i = 0; i <= n+1; ++i) {
            fill(v[i].begin(), v[i].begin() + m + 2, 0);
        }

        int atleastone = 0;
        for(int i =1;i<=n;i++)
            for(int j = 1;j<=m;j++)
                cin >> v[i][j];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(!f[v[i][j]])
                {
                    f[v[i][j]] = 1;
                }
                if(f[v[i][j]]==1)
                {
                        if(v[i-1][j] == v[i][j]){
                            f[v[i][j]] = 2;atleastone = 1;

                        }
                        else if(v[i+1][j] == v[i][j])
                        {
                            f[v[i][j]] = 2;atleastone = 1;

                        }
                        else if(v[i][j+1] == v[i][j])
                        {
                            f[v[i][j]] = 2;atleastone = 1;

                        }
                        else if(v[i][j-1] == v[i][j])
                        {
                            f[v[i][j]] = 2;atleastone = 1;

                        }
                }
            }
        }
        int sum = 0;
        int clrs = 0;
        for(int i = 0;i<=n*m;i++)
        {
            sum += f[i];
            if(f[i])
                clrs++;
        }

        if(atleastone)
        {
            cout << sum-2 << '\n';
        }
        else
            cout << sum-1 << '\n';
    }
    return 0;
}
