/*
        /////////  /////      ////     ///
        //        //   //    //  // // //
        //////   //    //   //   //   //
            //  // /// //  //        //
      //////// //      // //        //
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define rep(i, s, n) for (ll i = s; i < n; i++)
#define For(i, s, l) for (ll i = l; i >= s; i--)
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define umap unordered_map
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define lb() lower_bound()
#define ub() upper_bound()
#define S second
#define F first
#define PI 3.14159265358979323846
#define bits_all_odds 0X55555555
#define bits_all_even 0XAAAAAAAA
#define fix(num, dig) cout << fixed << setprecision(dig) << num
//fill(all(vec), 1);to fill vector with a number
//if (S.count(key)) returns 1 if set or map contain key else return 0
ll nCr(ll n, ll r)
{
    r = min(r, n - r);
    if (r < 0)
        return 0;
    if (r == 0)
        return 1;
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
    {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}
ll logn(int val, int base) { return (val > base - 1) ? 1 + logn(val / base, base) : 0; }
//ll logn(int val, int base) { return (base > val - 1) ? 1 + logn(base / val, val) : 0; }
ll power(ll a, ll b)
{
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    ll m1 = power(a, b / 2);
    if (b % 2)
        return m1 * m1 * a;
    return m1 * m1;
}
bool isprime(ll a)
{
    if (a <= 1)
        return false;
    if (a == 2 || a == 3)
        return true;
    if (a % 2 == 0 || a % 3 == 0)
        return false;
    for (ll i = 5; i * i <= a; i = i + 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
            return false;
    }
    return true;
}
/*********************/ /*********************/ /*********************/ /*********************/ //
void solve()
{
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    
    rep(i,0,n/2)
    {
        if(s[i]=='?'&&s[n-i-1]!='?')
        {
            s[i]=s[n-i-1];
        }
        else if(s[n-i-1]=='?'&&s[i]!='?')
        {
            s[n-i-1]=s[i];
        }
        else if(s[i]!='?'&&s[n-i-1]!='?'&&s[i]!=s[n-i-1])
        {
            cout<<-1<<endl;
            return;
        }
    }
    rep(i, 0, n)
    {
        if (s[i] == '0')
            a--;
        else if (s[i] == '1')
            b--;
    }
    if(a<0||b<0)
    {
        cout<<-1<<endl;
        return;
    }
    rep(i,0,n/2)
    {
        if(s[i]=='?'&&s[n-i-1]=='?')
        {
            if(a>1)
            {
                a-=2;
                s[i]='0';
                s[n-i-1]='0';

            }
            else if(b>1)
            {
                b-=2;
                s[i]='1';
                s[n-i-1]='1';
            }
            else
            {
                cout<<-1<<endl;
                return;
            }

        }
    }
    if(a<0||b<0)
    {
        cout<<-1<<endl;
        return;
    }

    if(n%2)
    {
        if(s[n/2]=='?')
        {
            if(a>0)
                s[n/2]='0';
            else if(b>0)
            {
                s[n/2]='1';
            }
            else
            {
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<s<<endl;



    // // rep(i, 0, n)
    // // {
    // //     if (s[i] == '?')
    // //     {
    // //         break;
    // //     }
    // //     else
    // //         l++;
    // // }
    // // for (int i = n - 1; i >= 0; i--)
    // // {
    // //     if (s[i] == '?')
    // //         break;
    // //     else
    // //         r--;
    // // }
    // if (a < 0 && b < 0)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // while (l <= r)
    // {
    //     if (l == r)
    //     {
    //         if (s[l] == '?')
    //         {
    //             if (a > 0)
    //                 s[l] = '0';
    //             else if (b > 0)
    //                 s[r] = '1';
    //             else
    //             {
    //                 // deb(1);
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //     }
    //     else if (s[l] == s[r] &&s[l]== '?')
    //     {
    //         if (a > 1)
    //         {
    //             s[l] = '0';
    //             s[r] = '0';
    //             a -= 2;
    //         }
    //         else if (b > 1)
    //         {
    //             s[l] = '1';
    //             s[r] = '1';
    //             b -= 2;
    //         }
    //         else
    //         {
    //             // deb(2);
    //             cout << -1 << endl;
    //             return;
    //         }
    //     }
    //     else if (s[l] == '?' && s[r] != '?')
    //     {
    //         if (s[r] == '0')
    //         {
    //             if (a > 0)
    //             {
    //                 s[l] = '0';
    //                 a--;
    //             }
    //             else
    //             {
    //                 // deb(3);
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //         else
    //         {
    //             if (b > 0)
    //             {
    //                 s[l] = '1';
    //                 b--;
    //             }
    //             else
    //             {
    //                 // deb(4);
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //     }
    //    else if (s[r] == '?' && s[l] != '?')
    //     {
    //         if (s[l] == '0')
    //         {
    //             if (a > 0)
    //             {
    //                 s[r] = '0';
    //                 a--;
    //             }
    //             else
    //             {
    //                 // deb(5);
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //         else
    //         {
    //             if (b > 0)
    //             {
    //                 s[r] = '1';
    //                 b--;
    //             }
    //             else
    //             {
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //     }
    //     else if((s[l]!='?')&&(s[r]!='?'&&s[r]!=s[l]))
    //     {

    //         // deb(6);
    //         cout << -1 << endl;
    //                 return;
    //     }
    //     else if((s[r]!='?')&&(s[l]!='?'&&s[r]!=s[l]))
    //     {

    //         // deb(7);
    //         cout << -1 << endl;
    //                 return;
    //     }
    //     // else if((s[l]=='0'||s[l]=='1')&&(s[r]!='?'||s[r]!=s[l]))
    //     // {
    //     // }
    //     // else if((s[r]=='0'||s[r]=='1')&&(s[l]!='?'||s[r]!=s[l]))
    //     // {
    //     //     deb(7);
    //     //     cout << -1 << endl;
    //     //             return;
    //     // }
    //     l++;
    //     r--;
    // }
    // if(a!=0&&b!=0)
    // {
    //     cout<<-1<<endl;
    //     return;
    // }
    // cout<<s<<endl;
}

signed main()
{
    Fast
        ll t;

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}