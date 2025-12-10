#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ifstream file("./input.txt");

    string line;
    vector<pair<ll, ll>> ranges;
    int count = 0;

    bool readingRanges = true;
    cout << "Ranges: " << endl;

    while (getline(file, line))
    {
        if (line.empty())
        {
            readingRanges = false;
            cout << "Numbers in range: " << endl;

            continue;
        }

        if (readingRanges)
        {
            ll a, b;
            char dash;
            stringstream ss(line);
            ss >> a >> dash >> b;
            cout << a << dash << b << endl;
            ranges.push_back({a, b});
        }
        else
        {
            ll x = stoll(line);
            for (auto &p : ranges)
            {
                if (x >= p.first && x <= p.second)
                {
                    cout << x << endl;
                    count++;
                    break;
                }
            }
        }
    }
    cout << "Final answer: " << count << endl;
}