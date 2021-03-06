#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int minPerimeter(int n) 
{ 

    int l = sqrt(n); 
    //cout<<l;
    int sq = l * l; 
  
    // if n is a perfect square 
    if (sq == n)  
        return l * 4; 
    else
    { 
        // Number of rows  
        long long int row = n / l;  
  
        // perimeter of the  
        // rectangular grid  
        long long int perimeter  
                      = 2 * (l + row);  
  
        // if there are blocks left  
        if (n % l != 0)  
            perimeter += 2; 
        return perimeter; 
    } 
} 
  
int main() 
{ 
    //int n = 3;
    int n;
    cout << "Enter the no. of test cases:";
    cin >> n;
    int tempVal;
    
    vector<int> v;
    for(int k=0;k<n;k++)
    {
        cin >> tempVal;
        v.push_back(tempVal);
    }
    for(auto itr : v)
    {   
        //cout << "value to check is:"<<itr<<"\n";
        cout << minPerimeter(itr)<<"\n";
    }
    //cout << minPerimeter(n);
    return 0; 
} 
