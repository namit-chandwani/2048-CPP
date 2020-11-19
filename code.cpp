#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4, i, j;
    vector<vector<int>> v(n, vector<int>(n, 0));
    srand(time(0));
    cout << "Welcome to the 2048 Game!" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    i = rand() % n;
    j = rand() % n;
    v[i][j] = 2;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
