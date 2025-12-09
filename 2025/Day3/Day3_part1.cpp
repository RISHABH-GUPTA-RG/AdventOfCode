#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("./input.txt");
    string line;

    int sum = 0;
    while (getline(file, line))
    {
        // cout<<line<<endl;
        int first = 0;
        for (int i = 0; i < line.length() - 1; i++)
        {
            if (line[i] > line[first])
            {
                first = i;
            }
        }

        int second = first + 1;
        for (int i = first + 1; i < line.length(); i++)
        {
            if (line[i] > line[second])
            {
                second = i;
            }
        }
        string f(1, line[first]);
        string s(1, line[second]);
        sum += stoi(f + s);
    }
    cout << sum;
}