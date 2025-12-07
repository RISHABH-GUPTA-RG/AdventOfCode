#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream file("./Day1_training.txt.txt");
    ifstream file("./Day1_input.txt");
    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int dial = 50;
    int count = 0;

    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;
        string dir = line.substr(0, 1);
        int val = stoi(line.substr(1));
        cout << "Direction: " << dir << ", Value: " << val << endl;
        switch (dir[0])
        {
        case 'L':
        {
            int q = val / 100;
            count += q;

            int r = val % 100;

            if (dial != 0 && dial - r < 0)
                count++;

            dial -= r;

            dial = ((dial % 100) + 100) % 100;
            cout << dial << endl;
            break;
        }
        case 'R':
        {
            int q = val / 100;
            count += q;

            int r = val % 100;

            if (dial + r > 100)
                count++;

            dial += r;

            dial = ((dial % 100) + 100) % 100;
            cout << dial << endl;
            break;
        }
        default:
            cerr << "Invalid direction: " << dir << endl;
            continue;
        }
        if (dial == 0)
            count++;
    }
    cout << "Dial reached 0! Count: " << count << endl;
}