    #include <bits/stdc++.h>
    // 16.03.25
    using namespace std;
    // maybe binary search instead of regular to find possible switchings
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin >> t;
        while(t--)
        {
            long long x,y;
            cin >> x >> y;
            vector<int> w(100000, 0); // x
            vector<int> e(100000, 0); // y
            long long rowx = (-1 + sqrt(1.0 + 8LL * x)) / 2;

            long long rowxy = (-1 + sqrt(1.0+8LL*(x+y)))/2;
            for(int i = 1;i<=rowx;i++)
            {
                w[i] = 1;
            }
            for(int i = rowx+1;i<=rowxy;i++)
            {
                e[i] = 1;
            }
            y += (rowx*(rowx+1))/2;
            x -= (rowx*(rowx+1))/2;
            y -= (rowxy*(rowxy+1))/2;
            int changed = 1;
            while(x && y && changed)
            {
                changed = 0;
                for(int i = 1;i<=rowxy;i++)
                {
                    if(e[i] && y+i>=rowxy+1 && x >= i)
                    {
                        x-=i;
                        y+=i;
                        y-=rowxy+1;
                        rowxy++;
                        e[i] = 0;
                        w[i] = 1;
                        changed = 1;
                    }
                }
                for(int i = 1;i<=rowxy;i++)
                {
                    if(w[i] && x+i>=rowxy+1 && y >= i)
                    {
                        y-=i;
                        x+=i;
                        x-=rowxy+1;
                        rowxy++;
                        w[i] = 0;
                        e[i] = 1;
                        changed = 1;
                    }
                }
            }
            cout << rowxy << '\n';
            //cout << x << " " << y;
            /*
            for(int i = 1;i<=rowx;i++)
            {
                cout << w[i] << " ";
            }
            cout << '\n';
            for(int i = 1;i<=rowxy;i++)
            {
                cout << e[i] << " ";
            }
            */

        }
    }
