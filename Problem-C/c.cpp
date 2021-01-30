#include <bits/stdc++.h>
using namespace std;
string s[100001];
int num[127];
vector<int> c[1000001][5];
int cnt[100001];
char lst[100001];
vector<pair<int, int>> ans1, ans2;
int main()
{
    num['a'] = 0;
    num['e'] = 1;
    num['o'] = 2;
    num['i'] = 3;
    num['u'] = 4;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        for (auto j : s[i])
            if (j == 'a' || j == 'e' || j == 'o' || j == 'i' || j == 'u')
                ++cnt[i], lst[i] = j;
        c[cnt[i]][num[lst[i]]].push_back(i);
    }
    int ans = 0, sum = 0;
    for (int i = 1; i <= 1000000; ++i)
    {
        int tot = 0;
        for (int j = 0; j < 5; ++j)
            tot += c[i][j].size(), ans += c[i][j].size() >> 1;
        sum += tot & 1;
    }
    ans = min(ans, (n - sum) / 4);
    printf("%d\n", ans);
    for (int i = 1; i <= 1000000; ++i)
        for (int j = 0; j < 5; ++j)
            while (ans2.size() < ans && c[i][j].size() >= 2)
            {
                ans2.push_back({c[i][j][0], c[i][j][1]});
                c[i][j].erase(c[i][j].begin());
                c[i][j].erase(c[i][j].begin());
            }
    for (int i = 1; i <= 1000000; ++i)
    {
        vector<int> C;
        for (int j = 0; j < 5; ++j)
            for (auto k : c[i][j])
                C.push_back(k);
        while (ans1.size() < ans && C.size() >= 2)
        {
            ans1.push_back({C[0], C[1]});
            C.erase(C.begin());
            C.erase(C.begin());
        }
    }
    for (int i = 0; i < ans; ++i)
    {
        cout << s[ans1[i].first] << ' ' << s[ans2[i].first] << endl;
        cout << s[ans1[i].second] << ' ' << s[ans2[i].second] << endl;
    }
    return 0;
}
