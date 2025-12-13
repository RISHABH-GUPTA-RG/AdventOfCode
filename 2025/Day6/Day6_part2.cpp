#include <bits/stdc++.h>
using namespace std;

#define ll long long

template <typename T>
void printArr(vector<T> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " " << endl;
    }
}

int main()
{
    // ifstream file("./test.txt");
    ifstream file("./input.txt");
    string line;

    vector<string> lines;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    string ops_line = lines.back();
    lines.pop_back();

    vector<char> ops;
    for (auto &x : ops_line)
    {
        if (x == ' ')
            continue;
        ops.push_back(x);
    }

    // printArr(lines);

    vector<vector<ll>> mat;
    vector<ll> nums;
    for (int i = 0; i < lines[0].size(); i++)
    {
        string num = "";

        for (int j = 0; j < lines.size(); j++)
        {
            if (lines[j][i] == ' ')
                continue;
            num += lines[j][i];
        }
        stringstream ss(num);
        ll x;
        if (ss >> x)
        {
            cout << x << endl;
            nums.push_back(x);
        }
        else
        {
            printArr(nums);
            mat.push_back(nums);
            nums.clear();
        }
    }
    mat.push_back(nums);

    ll resSum = 0;
    int row = 0;

    for (int i = 0; i < mat.size(); i++)
    {
        long long acc = (ops[i] == '+') ? 0 : 1;
        for (auto x : mat[i])
            acc = (ops[i] == '+') ? acc + x : acc * x;
        resSum += acc;
    }

    cout << "Final answer : " << resSum << endl;
}
