#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> v(n, vector<int>(n, 0));

    cout << "Welcome to the 2048 Game!" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
