#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream file("./Day1_input.txt");
    ifstream file("./Day1_training.txt");
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
            dial -= val;
            break;
        case 'R':
            dial += val;
            break;
        default:
            cerr << "Invalid direction: " << dir << endl;
            continue;
        }
        cout << "Dial position: " << dial << endl;
        dial = ((dial % 100) + 100) % 100; // Wrap around between 0 and 99
        cout << "Modded dial position: " << dial << endl;

        if (dial == 0)
        {
            count++;
        }
    }
    cout << "Dial reached 0! Count: " << count << endl;
}