#include <stdio.h>
#include <iostream>
using namespace std;

int getColorInfo(int W, int B)
{   

    int totalSum = W+B;
    int remainder = totalSum % 2;

    int colorInfo;
    if(totalSum == 0)
    {
        colorInfo = -1;
    }
    
    if(remainder == 0 && totalSum != 0)
    {           
        colorInfo = 0;
    }

    else if(remainder != 0)
    {
        if(W % 2 != 0)
        {
            colorInfo = 1;
        }

        else if(B % 2 != 0)
        {
            colorInfo = 2;
        }
    }

    return colorInfo;   
}

int main()
{

    int n;
    cout << "Enter the no. of test cases:";
    cin >> n;
 
    int tempArr[n][2];

    for(int k=0;k<n;k++)
    {
        for(int j=0;j<2;j++)
        {
            cin >> tempArr[k][j];            
        }
    }

    for(int i=0;i<n;i++)
    {   
        int totalWhiteSocks;
        int totalBlackSocks;
        for(int l=0;l<2;l++)
        {   
            if(l==0)
            {
                totalWhiteSocks = tempArr[i][l];
            }
            else
            {
                totalBlackSocks = tempArr[i][l];
                
            }

            //cout << tempArr[i][l];
        }
        //cout <<"\n";
        cout << getColorInfo(totalWhiteSocks, totalBlackSocks) <<"\n";
    }

return 0;
}
