#include <bits/stdc++.h>
using namespace std;

//15.03.25
  
/*
1. calculez suma curenta
2. numarul de aparitii a nr. 2 respectiv 3
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        string k;
        cin >> k;
        int sum = 0;
        int tw=0,tr=0;
        int len = k.size();
        for(int i = 0;i<len;i++)
        {
            if(k[i] == '2')
                tw++;
            if(k[i] == '3')
                tr++;
            sum+=k[i]-'0';
        }
        int found = 0;
        for(int i = 0;i<=tw;i++)
        {
            for(int j = 0;j<=tr;j++)
            {
                if((sum+i*2+j*6)%9==0)
                {
                    cout << "YES\n";
                    found = 1;
                    j = tr;
                    i = tw;
                }
            }
        }
        if(!found)
        {
            cout << "NO\n";
        }
    }

}
