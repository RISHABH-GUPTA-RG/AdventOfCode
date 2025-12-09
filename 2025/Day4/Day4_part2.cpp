#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printArr(vector<vector<T>> &arr)
{
    for (const auto &row : arr)
    {
        for (const auto &val : row)
        {
            cout << val;
        }
        cout << endl;
    }
}

int main()
{
    // ifstream file("./test.txt");
    ifstream file("./input.txt");
    string line;

    vector<vector<char>> diag;
    while (getline(file, line))
    {
        vector<char> v(line.begin(), line.end());
        diag.push_back(v);
    }

    int n = diag.size();
    int m = diag[0].size();

    printArr(diag);
    cout << endl;

    vector<vector<int>> arr(n + 2, vector<int>(m + 2, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (diag[i][j] == '@')
                arr[i + 1][j + 1] = 1;

    int row = arr.size();
    int col = arr[0].size();

    int count = 0;
    int res = 0;
    do
    {
        vector<vector<int>> arr2 = arr;
        count = 0;
        for (int i = 1; i < row - 1; i++)
        {
            for (int j = 1; j < col - 1; j++)
            {
                if (arr[i][j] == 1 &&
                    arr[i - 1][j - 1] +
                            arr[i - 1][j] +
                            arr[i - 1][j + 1] +
                            arr[i][j - 1] +
                            arr[i][j + 1] +
                            arr[i + 1][j - 1] +
                            arr[i + 1][j] +
                            arr[i + 1][j + 1] <
                        4)
                {
                    arr2[i][j] = 0;
                    count++;
                    res++;
                }
            }
        }
        printArr(arr);
        cout << count << endl;
        arr = arr2;
    } while (count > 0);

    cout << count << endl;
    cout << res << endl;
}