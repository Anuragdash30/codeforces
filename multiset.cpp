#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
// Big two primes
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define vii vector<ii>
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
void pr(int x) {cout << x;}
void prl(int x) {cout << x << endl;}
// typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;
//bool isPrime(int N){ for(int i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
int cbrt(int x) { int lo = 1, hi = min(2000000ll, x); while (hi - lo > 1) {int mid = (lo + hi) / 2; if (mid * mid * mid < x) {lo = mid;} else hi = mid;} if (hi * hi * hi <= x) return hi; else return lo;}
const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int N =  (int)(1 * 1e6 + 10);
int arr[N];
void update(int ind, int val)
{
    while(ind<=N)
    {
        arr[ind]=arr[ind]+val;
        ind=ind+(ind&(-ind));
    }
}
int sum(int n)
{   int l=0;
    while(n>0)
    {
        l=l+arr[n];
        n=n-(n&(-n));

    }
    return(l);
}
int remove(int ind)
{   int totsum=0;
    int curr=0;
    int i=19;
    int tot;
    while(i>=0)
    {   int tot=arr[1<<i];
        
        if(tot<ind&&1<<i<N)
        {   curr=1<<i;
            totsum=totsum+arr[1<<i]; 
            i--;
            while(i>=0&&totsum<N)
            {   totsum=totsum+arr[curr+1<<i];
                if(totsum<ind)
                {
                    curr=curr+1<<i;
                }
                else
                {
                    totsum=totsum-arr[curr+1<<i];
                    
                }
                
                i--;
            }
    
        }
        i--;
    }
    return(curr+1);
}
signed main()
{   fio;
    int T = 1;
    // cin >> T;
    
    while (T--) {
        int n, q;
        cin >> n >> q;
 
        for0(i, n) {
            int num;
            cin >> num;
 
            update(num, 1);
        }
 
        while (q--) {
            int x;
            cin >> x;
 
            if (x > 0)
            {
                update(x, 1);
            }
            else {
                x = -1 * x;
                int num = remove(x);
 
                update(num, -1);
            }
        }
 
        int ans = sum(N);
 
        if (!ans) prl(0);
        else {
            for1(i, n) {
                if (sum(i) > 0) {
                    prl(i);
                    break;
                }
            }
        }
    }
}
 