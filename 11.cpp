#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    sort(arr, arr + n);

    if(k > 0 && k <= n)
        cout << "Kth Smallest Element = " << arr[k - 1];
    else
        cout << "Not Present";

    return 0;
}