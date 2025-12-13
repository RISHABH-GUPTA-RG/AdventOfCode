#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
vector<vector<long long>> dp;
int R, C;

long long solve(int r, int c)
{
    if (r >= R)
        return 1; 

    if (c < 0 || c >= C)
        return 0; 

    if (dp[r][c] != -1) 
        return dp[r][c];

    long long res = 0;

    if (grid[r][c] == '.' || grid[r][c] == 'S')
    {
        res = solve(r + 1, c);
    }
    else if (grid[r][c] == '^')
    {
        res = solve(r, c + 1) + solve(r, c - 1);
    }

    return dp[r][c] = res;
}

int main()
{
    ifstream file("input.txt");
    string line;

    while (getline(file, line))
    {
        grid.push_back(line);
    }

    R = grid.size();
    C = grid[0].size();

    int sr = -1, sc = -1;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (grid[r][c] == 'S')
            {
                sr = r;
                sc = c;
            }
        }
    }

    cout << sr << " " << sc << endl;

    dp.assign(R, vector<long long>(C, -1));

    cout << solve(sr, sc) << endl;

    return 0;
}
