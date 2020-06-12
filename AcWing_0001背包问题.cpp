#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }

    cout << f[n][m] << endl;
    return 0;
}

//优化空间复杂度
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int N, V;  //N表示物品数量，V表示背包容积
    cin >> N >> V;
    vector<int> v(N + 1, 0);  //v[i]表示第i个物品的体积
    vector<int> w(N + 1, 0);  //w[i]表示第i个物品的价值
    for (int i = 1; i <= N; ++i)
        cin >> v[i] >> w[i];
    //要注意dp数组的大小，列是代表背包的容积
    //vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));  //dp[i][j]表示前i个物品，在背包容积为j的条件下，所能获得的最大价值
    vector<int> f(V + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = V; j >= 0; --j) //如果从左到右遍历，那么会重复使用元素   
        {
            if (j >= v[i])
            {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
            //cout << f[j] <<" ";
        }
        //cout << endl;
    }

    cout << f[V];
    return 0;
}