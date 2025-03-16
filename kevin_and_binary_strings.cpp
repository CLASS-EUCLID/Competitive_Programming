#include <bits/stdc++.h>
// 16.03.25
using namespace std;

string k;
string x;
int cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {

        cin >> k;
        int len = k.size();
        x = k;
        reverse(x.begin(),x.end());
        for(int i = 0;i<len;i++)
        {
            if(x[i] == '0')
                x[i] = '1';
            else
                x[i] = '0';
        }
        int zeroes = 0;
        int index = 0;
        for(int i = len-1;i>=0;i--)
        {
            if(x[i]=='0')
                zeroes++;
            if(x[i]=='1')
            {
                index = i+1;
                break;
            }
        }
        /*
        1 10011
        ~ = 1100
        */
        x.erase(index,zeroes);
        reverse(x.begin(),x.end());
        if(x.empty())
            x = "0";
        int xlen = x.size();

        for(int i = 0;i<xlen;i++)
        {
            string sub = x.substr(0,i+1);
            if(k.find(sub) == string::npos  || ((len - k.find(sub)) <= xlen))
            {
                if(x[i] == '0')
                    x[i] = '1';
                else
                    x[i] = '0';
            }
        }
        cout << k.find(x) + 1 << " " <<  x.size() + k.find(x) << " 1 " << k.size() << '\n';
    }
}
