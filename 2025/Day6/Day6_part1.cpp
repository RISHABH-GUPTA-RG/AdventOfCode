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

template <typename T>
void printMat(vector<vector<T>> &mat)
{
    //     cout<<mat.size()<<endl;
    //     cout<<mat[0].size();
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
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

    vector<vector<ll>> mat;
    for (auto &line : lines)
    {
        stringstream ss(line);
        ll x;
        vector<ll> row;
        while (ss >> x)
        {
            row.push_back(x);
        }
        mat.push_back(row);
    }

    printMat(mat);

    ll resSum = 0;

    for (int i = 0; i < ops.size(); i++)
    {
        if (ops[i] == '+')
        {
            ll sum = 0;
            for (auto &x : mat)
                sum += x[i];
            resSum += sum;
        }
        else
        {
            ll mul = 1;
            for (auto &x : mat)
                mul *= x[i];
            resSum += mul;
        }
    }

    cout<<resSum;
}