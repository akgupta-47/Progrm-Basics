#include <bits/stdc++.h>
using namespace std;
void calc_move(vector<int> &randomf, int **input, int u, int n)
{
    int z[8] = {-n, -n + 1, 1, n + 1, n, n - 1, -1, -n - 1};

    for (int i = 1; i <= 8; i++)
    {
        if (input[u - 1][i] == 1)
        {
            int move;
            move = (z[i - 1]) + (input[u - 1][0]);
            randomf.push_back(move);
        }
    }
}
bool search(int **given_arr, int **input, int src, int dest, int v, int *pred, int n)
{
    list<int> queue;
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        pred[i] = -1;
    }
    visited[src] = true;
    queue.push_back(src);
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();
        vector<int> randomf;
        calc_move(randomf, input, u, n);
        for (int i = 0; i < randomf.size(); i++)
        {
            if (visited[randomf[i]] == false)
            {
                visited[randomf[i]] = true;
                pred[randomf[i]] = u;
                queue.push_back(randomf[i]);

                if (randomf[i] == dest)
                    return true;
            }
        }
    }

    return false;
}

void chotaD(int **given_arr, int **input, int s, int dest, int v, int n)
{
    if (s == dest)
    {
        cout << dest << endl;
        return;
    }
    int pred[v];

    if (search(given_arr, input, s, dest, v, pred, n) == false)
    {
        return;
    }
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

int main()
{
    int n, m, s, count = 1;
    cin >> m >> n >> s;
    int **given_arr = new int *[m];
    for (int i = 0; i < m; i++)
        given_arr[i] = new int[n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            given_arr[i][j] = count;
            count++;
        }
    }
    int total = n * m;
    int **input = new int *[total];
    for (int i = 0; i < total; i++)
    {
        input[i] = new int[9];
    }
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> input[i][j];
        }
    }

    chotaD(given_arr, input, s, 1, total, n);
    chotaD(given_arr, input, s, n, total, n);
    chotaD(given_arr, input, s, ((n * (m - 1)) + 1), total, n);
    chotaD(given_arr, input, s, total, total, n);
    return 0;
}