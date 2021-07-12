#include <iostream>
#include <unordered_map>

void printFx(int a[], int N)
{
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
//TODO: Add cmnt
