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

    int key;
    cin >> key;

    sort(arr, arr + n);

    int i = 0, j = n - 1;

    while(i < j)
    {
        int sum = arr[i] + arr[j];

        if(sum == key)
        {
            cout << arr[i] << " " << arr[j];
            return 0;
        }
        else if(sum < key)
            i++;
        else
            j--;
    }

    cout << "No Such Elements Exist";

    return 0;
}