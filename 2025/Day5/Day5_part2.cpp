#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    // ifstream file("./test.txt");
    ifstream file("./input.txt");

    string line;
    vector<pair<ll, ll>> ranges;
    ll count = 0;

    while (getline(file, line))
    {
        if (line.empty())
        {
            break;
        }

        ll a, b;
        char dash;
        stringstream ss(line);
        ss >> a >> dash >> b;
        ranges.push_back({a, b});
    }

    sort(ranges.begin(), ranges.end());

    int len = ranges.size();
    ll currL = ranges[0].first;
    ll currR = ranges[0].second;

    for (int i = 1; i < len; i++)
    {
        ll L = ranges[i].first;
        ll R = ranges[i].second;

        if (L <= currR)
        {
            currR = max(currR, R);
        }
        else
        {
            cout << currL << " " << currR << endl;
            count += currR - currL + 1;
            currL = L;
            currR = R;
        }
    }
    cout << currL << " " << currR << endl;
    count += currR - currL + 1;
    cout << "Final answer: " << count << endl;
}