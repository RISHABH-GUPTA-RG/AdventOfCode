#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool is_repeating(string s, int i);

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
            int len = num.length();
            for (int j = 2; j <= len; j++)
                if (is_repeating(num, j))
                {
                    cout << i << endl;
                    sum += i;
                    break;
                }
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}

bool is_repeating(string s, int i)
{
    ll n = s.length();
    if (n % i != 0)
        return false;

    ll partLen = n / i;
    string part = s.substr(0, partLen);

    string formed = "";
    for (int j = 0; j < i; j++)
    {
        formed += part;
    }
    return formed == s;
}