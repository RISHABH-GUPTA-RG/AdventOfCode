#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream file("./test.txt");
    ifstream file("./input.txt");
    string line;
    vector<string> diag;
    while (getline(file, line))
    {
        diag.push_back(line);
    }

    int R = diag.size();
    int C = diag[0].size();
    pair<int, int> S;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (diag[i][j] == 'S')
            {
                S = {i, j};
            }
        }
    }
    deque<pair<int, int>> beams;
    set<pair<int, int>> seen;

    beams.push_back(S);
    seen.insert(S);
    auto add = [&](int r, int c)
    {
        if (seen.count({r, c}))
            return;
        seen.insert({r, c});
        beams.push_back({r, c});
    };

    int count = 0;
    while (!beams.empty())
    {
        auto [r, c] = beams.front();
        beams.pop_front();

        if (diag[r][c] == '.' || diag[r][c] == 'S')
        {
            if (r == R - 1)
                continue;
            ;
            add(r + 1, c);
        }
        else
        {
            count++;
            add(r, c + 1);
            add(r, c - 1);
        }
    }
    cout << count;
}