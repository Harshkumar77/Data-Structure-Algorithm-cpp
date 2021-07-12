#include <iostream>
#include <unordered_map>
// TODO: add cmts damm
using namespace std;

void printSubarraySum0(int a[], int N)
{
    int sarr = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        string ar = "";
        for (int j = i; j < N; j++)
        {
            sum += a[j];
            ar.append(to_string(a[j]) + " ");
            if (sum == 0)
                cout << ar << '\n', sarr++;
        }
    }
    cout << "Number of subarray of sum 0 : " << sarr << '\n';
}

int subarraySum0(int a[], int N)
{
    unordered_map<int, int> fx;
    int cnt = 0, prefixSum = 0;
    for (int i = 0; i < N; i++)
        prefixSum += a[i], fx[prefixSum]++;
    cnt += fx[0];
    for (unordered_map<int, int>::iterator i = fx.begin(); i != fx.end(); i++)
    {
        int freq = (*i).second;
        cnt += (freq) * (freq - 1) / 2;
    }
    return cnt;
}

int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int &x : a)
        cin >> x;
    printSubarraySum0(a, N);
    cout << subarraySum0(a, N);
}