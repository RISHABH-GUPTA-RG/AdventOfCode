#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    // ifstream file("./test.txt");
    ifstream file("./input.txt");
    if (!file)
    {
        cerr << "can't read file";
    }

    string line;
    ll sum = 0;
    while (getline(file, line))
    {
        int target_num = 12;
        int n = line.size();

        string ans = "";

        for (int i = 0; i < n; i++)
        {
            while (ans.size() && ans.size() + (n - i) > target_num && ans.back() < line[i])
                ans.pop_back();
            if (ans.size() < target_num)
                ans += line[i];
        }
        cout << ans << endl;
        sum += stoll(ans);
    }
    cout << sum << endl;
}