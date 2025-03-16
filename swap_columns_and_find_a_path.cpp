    #include <bits/stdc++.h>
    using namespace std;
    // 16.03.25

    /*
1
2
4 -1
-2 5
    */
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin >> t;
        while(t--)
        {
            int n;
            cin >> n;
            vector<vector<int>> m(3,vector<int>(n,0));
            int vM = INT_MIN,indexM = 0, iM=0, jM=0;
            for(int i = 0;i<2;i++)
            {
                for(int j  =0;j<n;j++)
                {
                    cin >> m[i][j];
                }
            }
            if(n == 1)
            {
                cout << m[0][0] + m[1][0] << '\n';
                continue;
            }
            for(int i = 0;i<n;i++)
            {
                m[2][i] = m[0][i]-m[1][i];
                if((m[0][i]+m[1][i]-abs(m[2][i])) > vM)
                {
                    vM = m[0][i]+m[1][i]-abs(m[2][i]);
                    iM = m[0][i];
                    jM = m[1][i];
                    indexM = i;
                }
            }
            m[0].erase(m[0].begin()+indexM);
            m[1].erase(m[1].begin()+indexM);
            m[2].erase(m[2].begin()+indexM);
            int sorted;
            do
            {
                sorted = 1;
                for(int i = 0;i<n-2;i++)
                {
                    if(m[2][i] < m[2][i+1])
                    {
                        swap(m[0][i],m[0][i+1]);
                        swap(m[1][i],m[1][i+1]);
                        swap(m[2][i],m[2][i+1]);
                        sorted = 0;
                    }
                }
            }while(!sorted);
            int sum = 0;
            int i = 0;

            /*
            for(int i = 0;i<3;i++)
            {
                for(int j  =0;j<n-1;j++)
                {
                    cout << m[i][j] << " ";
                }
                cout << '\n';
            }
            */


            while(m[2][i]>=0 && i<n-1)
            {
                sum += m[0][i];
                i++;
            }
            while(i<n-1)
            {
                sum += m[1][i];
                i++;
            }
            sum = sum + iM + jM;
            cout << sum << '\n';
        }

    }
