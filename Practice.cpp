#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include <vector>
using namespace std;

map<int, int> combination;
int Count = 0;

void getcombination(int n, int area)
{
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
        {
            int remainder = area % i;
            if (remainder == 0)
            {
                int quotient = area / i;
                if (quotient != 1)
                    combination.insert(pair<int, int>(i, quotient));
            }
        }
    }
}

void findRectangles(const vector<vector<int>> &m, int Totalsum, int x, int y)
{
    // finding row and column size
    int rows = m.size();
    int sum = 0;
    int temp = 0;
    int columns = m[0].size();

    // scanning the matrix
    for (int y1 = 0; y1 < rows; y1++)
    {
        for (int x1 = 0; x1 < columns; x1++)
        {
            for (int y2 = y1 + 1; y2 < rows; y2++)
            {
                for (int x2 = x1 + 1; x2 < columns; x2++)
                {
                    sum = 0;

                    // cout<<y2<<";"<<y1;
                    if (y2 - y1 == x - 1 && x2 - x1 == y - 1)
                    {
                        for (int a = y1; a <= y2; a++)
                        {
                            for (int b = x1; b <= x2; b++)
                            {

                                temp = m[a][b];
                                sum = sum + temp;
                            };
                        };
                        cout << "Sum is:" << sum << "\n";
                        if (Totalsum > sum)
                        {
                            Count++;
                        };
                    }
                };
            };
        };
    };

    //return true;
}

int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    int n = a[0], area = a[1], sum = a[2];
    const int m = a[0];
    vector<vector<int>> vec;
    int input;
    int *tempArr = new int[m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tempArr[j];
        }
        vector<int> v1;
        for (int k = 0; k < n; k++)
        {
            v1.push_back(tempArr[k]);
        }
        vec.push_back(v1);
    }

    // for (int i = 0; i < n; i++) //for entering input sequencially
    // {
    //     vector<int> v1;
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << "A[" << i << "][" << j << "]=";
    //         cin >> input;
    //         v1.push_back(input);
    //     }
    //     vec.push_back(v1);
    // }

    //cout << "Vector size: " << vec.size() << "\n"; //for printingVectorsize
    
    // for (int i = 0; i < vec.size(); i++) // for printing matrix
    // {
    //     for (int j = 0; j < vec[i].size(); j++)
    //         cout << vec[i][j] << " ";
    //     cout << endl;
    // }
    getcombination(n, area);

    map<int, int>::iterator itr;
    for (itr = combination.begin(); itr != combination.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
        findRectangles(vec, sum, itr->first, itr->second);
    }
    cout << "Count is:" << Count;
}
