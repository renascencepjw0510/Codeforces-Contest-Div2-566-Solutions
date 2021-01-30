#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 0, x, y;
char s[510][510];
int main()
{
    scanf("%d%d", &n, &m);
    memset(s, ' ', sizeof(s));
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 2; i < n; i++)
        for (int j = 2; j < m; j++)
            if (s[i][j] == '*' && s[i - 1][j] == '*' && s[i][j - 1] == '*' && s[i][j + 1] == '*' && s[i + 1][j] == '*')
                ++cnt, x = i, y = j;
    if (cnt != 1)
        return puts("NO"), 0;
    int xx = x, yy = y;
    while (s[xx][yy] == '*')
        s[xx][yy] = '.', --xx;
    xx = x, yy = y - 1;
    while (s[xx][yy] == '*')
        s[xx][yy] = '.', --yy;
    xx = x, yy = y + 1;
    while (s[xx][yy] == '*')
        s[xx][yy] = '.', ++yy;
    xx = x + 1, yy = y;
    while (s[xx][yy] == '*')
        s[xx][yy] = '.', ++xx;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j] != '.')
                return puts("NO"), 0;
    puts("YES");
    return 0;
}
