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

//�Ż��ռ临�Ӷ�
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int N, V;  //N��ʾ��Ʒ������V��ʾ�����ݻ�
    cin >> N >> V;
    vector<int> v(N + 1, 0);  //v[i]��ʾ��i����Ʒ�����
    vector<int> w(N + 1, 0);  //w[i]��ʾ��i����Ʒ�ļ�ֵ
    for (int i = 1; i <= N; ++i)
        cin >> v[i] >> w[i];
    //Ҫע��dp����Ĵ�С�����Ǵ��������ݻ�
    //vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));  //dp[i][j]��ʾǰi����Ʒ���ڱ����ݻ�Ϊj�������£����ܻ�õ�����ֵ
    vector<int> f(V + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = V; j >= 0; --j) //��������ұ�������ô���ظ�ʹ��Ԫ��   
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