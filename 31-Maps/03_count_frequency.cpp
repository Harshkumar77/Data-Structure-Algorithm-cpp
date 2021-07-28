#include <iostream>
#include <unordered_map>
/**
 * Program to count frequency of elements in an array
 * TC - O(N)
 * SC - O(N)
*/
void printFx(int a[], int N)
{
    // increasing the frequency of each element in map
    std::unordered_map<int, int> um;
    for (int i = 0; i < N; i++)
        um[a[i]]++;
    for (std::pair<int, int> p : um)
        std::cout << p.first << " -> " << p.second << '\n';
}

int main()
{
    int N;
    std::cin >> N;
    int a[N];
    for (int &x : a)
        std::cin >> x;
    printFx(a, N);
}