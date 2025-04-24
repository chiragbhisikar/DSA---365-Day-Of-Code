#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> umapp;
    string s = "mera name joker";

    // insertion
    // first way
    pair<string, int> p1 = make_pair("mera", 2);
    umapp.insert(p1);

    // second way
    pair<string, int> p2("joker", 3);
    umapp.insert(p2);

    // third way
    umapp["chirag"] = 1;

    cout << umapp["chirag"] << endl;
    cout << umapp.at("chirag") << endl;

    // size
    cout << "size = " << umapp.size() << endl;

    // check presence
    cout << "is chirag Present = " << (umapp.count("chirag") ? "Yes" : "No") << endl;
    cout << "is unknownKey Present = " << (umapp.count("unknownKey") ? "Yes" : "No") << endl;

    // erase
    umapp.erase("chirag");
    cout << "size = " << umapp.size() << endl;

    // traversal
    for (auto i : umapp)
    {
        cout << "umapp[" << i.first << "] = " << i.second << endl;
    }

    cout << "\nUsing Iterator " << endl;
    // iterator
    unordered_map<string, int>::iterator it = umapp.begin();
    while (it != umapp.end())
    {
        cout << "umapp[" << it->first << "] = " << it->second << endl;
        it++;
    }

    return 0;
}