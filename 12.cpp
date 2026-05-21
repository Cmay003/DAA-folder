#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char arr[n];

    int freq[26] = {0};

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i] - 'a']++;
    }

    int maxFreq = 0;
    char ans;

    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            ans = i + 'a';
        }
    }

    if(maxFreq == 1)
        cout << "No Duplicates Present";
    else
        cout << ans << " - " << maxFreq;

    return 0;
}