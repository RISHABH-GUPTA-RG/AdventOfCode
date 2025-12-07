#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    // ifstream file("./test.txt");
    ifstream file("./input.txt");
    if (!file)
    {
        cerr << "Error Reading file" << endl;
        return 1;
    }

    string line;
    ll sum = 0;

    // Splitting the lines to different ranges
    while (getline(file, line, ','))
    {
        // Splitting each line to ranges
        string s = line;
        ll pos = s.find('-');
        ll start = stoll(s.substr(0, pos));
        ll end = stoll(s.substr(pos + 1));

        // Getting Ranges
        // cout << start << " " << end << endl;
        for (ll i = start; i <= end; i++)
        {
            string num = to_string(i);
            ll len = num.length();
            if (len % 2 == 0)
            {
                ll mid = len / 2;
                string firstHalf = num.substr(0, mid);
                string secondHalf = num.substr(mid);
                if (firstHalf == secondHalf)
                {
                    cout << firstHalf << secondHalf << endl;
                    sum += i;
                }
            }
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}