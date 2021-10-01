#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool prime[10000];

void initsieve()
{
    memset(prime, true, 10000);
    for (int i = 2; i * i <= 9999; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 9999; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int bfs(char src[5], char dest[5])
{
    bool vis[10000];
    int dist[10000];
    queue<int> q;
    memset(dist, 0, sizeof(dist));
    q.push(atoi(src));
    dist[atoi(src)] = 0;
    int d = atoi(dest);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        // create its children
        // add its children to q
        char ch[5];
        sprintf(ch, "%d", f);
        int cursit = dist[f];
        for (int i = 0; i < 4; i++)
        {
            char dig = ch[i];
            for (int j = '1'; j <= '9'; j++)
            {
                if (ch[i] != j)
                {
                    ch[i] = j;
                    int chint = atoi(ch);
                    if (prime[chint] && !vis[chint])
                    {
                        q.push(chint);
                        vis[chint] = true;
                        dist[chint] = cursit + 1;
                        if (chint == d)
                            return dist[chint];
                    }
                }
            }
            ch[i] = dig;
        }
    }
    return dist[d];
}

int main()
{
    initsieve();
    char c1[5], c2[5];
    cin.getline(c1, '\n');
    cin.getline(c2, '\n');
    cout << bfs(c1, c2);
    return 0;
}