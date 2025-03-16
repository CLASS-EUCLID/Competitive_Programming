    #include <bits/stdc++.h>
	// 16.03.25
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int x,y;
        cin >> x >> y;
        if(x%2 == y%2)
        {
            cout << "3\n";
            int x1 = (3*x-y)/2, x2 = (3*x-y)/2;
            while(x1 > y || x2 < y)
            {
                x1--;
                x2++;
            }
            cout << x1 << " " << y << " " << x2;

        }
        else
        {
            cout << "4\n";
            int x1 = 2*x-y, x2 = 2*x-y;
            while(x1 > y || x2 < y)
            {
                x1--;
                x2++;
            }
            cout << x1 << " " << y << " " << y << " " << x2;
        }

    }
