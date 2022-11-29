#include <bits/stdc++.h>
using namespace std;

int getRankOfNumber(int arr[], int n, int x)
{
    int count = 0;
    bool temp = false;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= x)
            count++;
        if(arr[i] == x)
            temp = true;
    }
    if(temp == true)
        count--;
    return count;
}

int main()
{
    int n;
    cout << "Enter a size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cout << "Enter a element to find rank: ";
    cin >> x;
    cout << "Rank of number " << x << " is " << getRankOfNumber(arr, n, x);
    return 0;
}