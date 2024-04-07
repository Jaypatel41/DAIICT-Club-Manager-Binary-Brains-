#include <iostream>
#include <utility>
#include <list>
#include <string>

using namespace std;

void editString(string &clubname)
{
    if (clubname.size() > 0 && (clubname[0] >= 'a' && clubname[0] <= 'z'))
    {
        clubname[0] -= 32; // Convert lowercase to uppercase
    }

    for (int i = 1; i < clubname.size(); i++)
    {
        if (clubname[i] >= 'A' && clubname[i] <= 'Z')
        {
            clubname[i] += 32; // Convert uppercase to lowercase
        }
    }
}

int ClubIndex(list<pair<int, string>> &ls, string clubname)
{
    for (const auto &pair : ls)
    {
        if (pair.second == clubname)
        {
            return pair.first;
        }
    }
    cout << "No such club currently present at a time.\n\n";
    return 100;
}

string ClubName(list<pair<int, string>> &ls, int num)
{
    for (const auto &pair : ls)
    {
        if (pair.first == num)
        {
            return pair.second;
        }
    }
    cout << "No such club currently present at a time.\n\n";
    return " ";
}
