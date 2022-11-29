#include <iostream>
#include <vector>
using namespace std;
int binarySearch(int key, int a[], int l, int h)
{
    int mid = (l + h) / 2;
    if (h < l)
        return -1;
    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        return binarySearch(key, a, mid + 1, h);
    else
        return binarySearch(key, a, l, mid - 1);
}

int search(int a[], int n, int target)
{
    int x = 0, ans = 0;
    bool temp = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            x = i + 1;
            temp = true;
            break;
        }
    }
    if (temp == true)
    {
        if (target <= a[n - 1])
            ans = binarySearch(target, a, x, n - 1);
        else
            ans = binarySearch(target, a, 0, x - 1);
    }
    else
        ans = binarySearch(target, a, 0, n - 1);
    
    return ans;
}
int main()
{
    int n, element;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter a element to search: ";
    cin >> element;
    int ans;
    ans = search(a, n, element);
    if(ans == -1)
        cout << "Element is not present in array.";
    else 
        cout << "Element is present at index " << ans << ".\n";
    return 0;
}