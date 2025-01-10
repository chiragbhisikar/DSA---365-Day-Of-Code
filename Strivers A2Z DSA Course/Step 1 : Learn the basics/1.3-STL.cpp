#include <bits/stdc++.h>
#include <utility>

using namespace std;
void printVector(vector<int> v)
{
    cout << "[ ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
       cout << *(it) << ", ";
    }
     cout << "]" << endl;
}
// Pairs are used to combine two values into a single object
/*
void explainPair()
{
    pair<int, int> p(1, 2);

    cout << "pair<int, int> p(1, 2) --> p.first -> " << p.first << " & p.second -> " << p.second << endl;

    pair<int, pair<int, int> > p1(1, p);

    cout << "\npair<int, pair<int, int> > p1(1, p) --> p1.first -> " << p1.first << " & p.second.first -> " << p1.second.first << " & p.second.second -> " << p1.second.second << endl;

    pair<int, int> arr[] = {pair<int, int>(1, 2), pair<int, int>(3, 4)};

    cout << "\npair<int, int> arr[] = {pair<int, int>(1, 2), pair<int, int>(3, 4)} --> \n";
    cout << "arr[0].first -> " << arr[0].first << " & arr[0].second -> " << arr[0].second << endl;
    cout << "arr[1].first -> " << arr[1].first << " & arr[1].second -> " << arr[1].second << endl;
}
*/
/*
void explainVector()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // emplace_back dynamically increases the size of the vector and push it
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<pair<int, int> > v1;
    v1.push_back(pair<int, int>(1, 2));
    v1.emplace_back(3, 4); // emplace_back dynamically increases the size of the vector and push it

    vector<int> v2(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v3(5); // {0, 0, 0, 0, 0} or garbage values
    vector<int> v4(5, 20); // {20, 20, 20, 20, 20}
    vector<int> v5(v2); // {100, 100, 100, 100, 100}

    cout << "v: [ ";
    // iterators --> v.begin(), v.end(), v.rbegin(), v.rend()
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
       cout << *(it) << ", ";
    }
    
    cout << "]\n" << "v[0]: "<< v[0] << " & v.at(0): " << v.at(0) << endl;
    cout << "v.front(): " << v.front() << " & v.back(): " << v.back() << endl;

    v.erase(v.begin() + 1,v.begin() + 3); // (start,end) -> v[1] to v[3] will be deleted -> v[1] , v[2]

    cout << "\nv.erase(v.begin() + 1,v.begin() + 3) -> ";
    printVector(v);
    v.insert(v.begin(), 0);
    cout << "v.insert(v.begin(), 0) -> ";
    printVector(v);

    cout << "v.size() --> "<< v.size() <<" & v.capacity() --> " << v.capacity() << endl;
    cout << "v.empty() --> "<< v.empty() <<" & v.clear() --> " << endl;
}
*/
void explainList(){
    list<int> ls;
    ls.push_back(1);
    // ls.emplace_back(3);
    ls.push_front(2);
}
int main()
{
    // explainPair();
    // explainVector();
    explainList();
    return 0;
}