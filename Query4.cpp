#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countFreq(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
        {
            res++;
            j = 0;
        }
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter the no. of test cases:";
    cin >> n;

    int tempArr[n][3];
    string InputStrings[n];
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                cin >> InputStrings[k];
            }

            else
            {

                cin >> tempArr[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        //cout << InputStrings[i] << "\n";
        string str = InputStrings[i];
        int stringSize = tempArr[i][0];
        int tSum = tempArr[i][1];

        int count = stringSize - tSum;
        vector<int> maxFreq;

        //cout <<"count is:"<<count;
        //cout << str;
        for (int l = 0; l <= count; l++)
        {
            string s;
            s += str.at(l);     // append the first character
            s += str.at(l + 1); // append the second character
            s += str.at(l + 2);

            //cout << str.at(i)<<"\n";
            //strArr.push_back(str.at(i));

            //cout<< "Frequency of:" << s << "is:"<<countFreq(s, str);
            maxFreq.push_back(countFreq(s, str));
        }
        cout << "Max Frequency is:" << *max_element(maxFreq.begin(), maxFreq.end()) << "\n";
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int l = 0; l < 3; l++)
    //     {
    //         if (l == 2)
    //         {
    //             cout << tempArr[i][l-2];
    //            //cout << countFreq(tempArr[i][l], tempArr[i][l-1], tempArr[i][l-2]);
    //         }
    //     }
    // }
    return 0;
}