#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

void addTile(vector<vector<int>> &v, int n, int &empty, int &sum)
{
    int i, j, k;
    do
    {
        i = rand() % n;
        j = rand() % n;
    } while (v[i][j] != 0);
    k = rand() % 2;
    v[i][j] = k == 0 ? 2 : 4;
    sum += v[i][j];
    empty--;
}
void moveUp(vector<vector<int>> &v, int n)
{
    for (int j = 0; j < n; j++)
    {
        int currPos = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] != 0)
            {
                v[currPos][j] = v[i][j];
                currPos++;
            }
        }
        for (int i = currPos; i < n; i++)
        {
            v[i][j] = 0;
        }
    }
}
void moveDown(vector<vector<int>> &v, int n)
{
    for (int j = 0; j < n; j++)
    {
        int currPos = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i][j] != 0)
            {
                v[currPos][j] = v[i][j];
                currPos--;
            }
        }
        for (int i = 0; i <= currPos; i++)
        {
            v[i][j] = 0;
        }
    }
}
void moveLeft(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int currPos = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != 0)
            {
                v[i][currPos] = v[i][j];
                currPos++;
            }
        }
        for (int j = currPos; j < n; j++)
        {
            v[i][j] = 0;
        }
    }
}
void moveRight(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int currPos = n - 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[i][j] != 0)
            {
                v[i][currPos] = v[i][j];
                currPos--;
            }
        }
        for (int j = 0; j <= currPos; j++)
        {
            v[i][j] = 0;
        }
    }
}

void mergeUp(vector<vector<int>> &v, int n, int &empty, int &maxScore)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i][j] != 0 && v[i][j] == v[i + 1][j])
            {
                v[i][j] *= 2;
                maxScore = max(maxScore, v[i][j]);
                for (int k = i + 1; k < n - 1; k++)
                {
                    v[k][j] = v[k + 1][j];
                }
                v[n - 1][j] = 0;
                empty++;
            }
        }
    }
}
void mergeDown(vector<vector<int>> &v, int n, int &empty, int &maxScore)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (v[i][j] != 0 && v[i][j] == v[i - 1][j])
            {
                v[i][j] *= 2;
                maxScore = max(maxScore, v[i][j]);
                for (int k = i - 1; k > 0; k--)
                {
                    v[k][j] = v[k - 1][j];
                }
                v[0][j] = 0;
                empty++;
            }
        }
    }
}

void mergeLeft(vector<vector<int>> &v, int n, int &empty, int &maxScore)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (v[i][j] != 0 && v[i][j] == v[i][j + 1])
            {
                v[i][j] *= 2;
                maxScore = max(maxScore, v[i][j]);
                for (int k = j + 1; k < n - 1; k++)
                {
                    v[i][k] = v[i][k + 1];
                }
                v[i][n - 1] = 0;
                empty++;
            }
        }
    }
}
void mergeRight(vector<vector<int>> &v, int n, int &empty, int &maxScore)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (v[i][j] != 0 && v[i][j] == v[i][j - 1])
            {
                v[i][j] *= 2;
                maxScore = max(maxScore, v[i][j]);
                for (int k = j - 1; k > 0; k--)
                {
                    v[i][k] = v[i][k - 1];
                }
                v[i][0] = 0;
                empty++;
            }
        }
    }
}
void printArrow()
{
    cout << "                                          __      " << endl;
    cout << "                                         |..|     " << endl;
    cout << "                                         |..|     " << endl;
    cout << "                                         |..|     " << endl;
    cout << "                                        _|..|_    " << endl;
    cout << "                                        \\..../    " << endl;
    cout << "                                         \\../     " << endl;
    cout << "                                          \\/      " << endl;
    cout << endl;
}

void printMatrix(vector<vector<int>> &v, int n, int &sum)
{
    cout << "Current State:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "                                  -";
        for (int j = 0; j < n; j++)
        {
            // if (i == 0)
            // {
            cout << "----";
            // }
        }
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                cout << "                                  | ";
            }
            if (v[i][j] == 0)
            {
                cout << "  | ";
                continue;
            }
            cout << v[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "                                  -";
    for (int j = 0; j < n; j++)
    {
        cout << "----";
    }
    cout << endl;

    cout << "Sum: " << sum << endl;
    if (sum != 8)
    {
        printArrow();
    }
}
void welcomeMessage()
{
    cout << "                                            ________________________________________________________ " << endl;
    cout << "                                           |                                                        |" << endl;
    cout << "                                           |               Welcome to the 2048 Game!                |" << endl;
    cout << "                                           |________________________________________________________|" << endl;
    cout << endl;
}
void endMessage()
{
    cout << "                                            ___________________________________________________ " << endl;
    cout << "                                           |                                                   |" << endl;
    cout << "                                           |   \U0001F389    Congrats! You have won this game.    \U0001F389   |" << endl;
    cout << "                                           |___________________________________________________|" << endl;
    cout << endl;
}

int main()
{
    int n = 4, i, empty, maxScore = 0, flag = 0, sum = 0, prevSum = 0, prevEmpty = 0, prevMaxScore = 0;
    char move;
    vector<vector<int>> v(n, vector<int>(n, 0));
    stack<vector<vector<int>>> st;

    empty = n * n;

    srand(time(0));
    welcomeMessage();
    addTile(v, n, empty, sum);
    addTile(v, n, empty, sum);
    printMatrix(v, n, sum);

    while (empty != 0)
    {
        st.push(v);
        if (sum == 8)
        {
            endMessage();
            flag = 1;
            break;
        }
        else if (sum > 8)
        {
            cout << "Sum has exceeded 8" << endl;
            st.pop();
            v = st.top();
            cout << "Matrix reverted to previous state. \n"
                 << endl;
            printMatrix(st.top(), n, sum);
            sum = prevSum, empty = prevEmpty, maxScore = prevMaxScore;
        }
        // cout << "Enter move: (u: UP, d: DOWN, l: LEFT, r: RIGHT)" << endl;
        // cin >> move;
        i = rand() % 4;
        move = (i == 0) ? 'u' : ((i == 1) ? 'd' : ((i == 2) ? 'l' : 'r'));
        string moveDir = "";
        moveDir = (move == 'u') ? "UP" : ((move == 'd') ? "DOWN" : ((move == 'l') ? "LEFT" : "RIGHT"));
        cout << "The move is: " << move << " (" << moveDir << ")" << endl;
        cout << endl;
        prevSum = sum, prevEmpty = empty, prevMaxScore = maxScore;
        usleep(1000000);
        switch (move)
        {
        case 'u':
            moveUp(v, n);
            mergeUp(v, n, empty, maxScore);
            break;
        case 'd':
            moveDown(v, n);
            mergeDown(v, n, empty, maxScore);
            break;
        case 'l':
            moveLeft(v, n);
            mergeLeft(v, n, empty, maxScore);
            break;
        case 'r':
            moveRight(v, n);
            mergeRight(v, n, empty, maxScore);
            break;
        default:
            cout << "Invalid move. Try again!" << endl;
            continue;
        }

        addTile(v, n, empty, sum);
        printMatrix(v, n, sum);
    }
    if (!flag)
    {
        cout << "Game over! Your score is: " << maxScore << endl;
    }
    return 0;
}