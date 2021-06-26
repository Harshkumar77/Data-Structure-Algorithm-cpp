#include <iostream>
using namespace std;

/**
 * Heap Sort
 * 
 * Time complexity : O (N log N) 
 * Space complexity : O ( 1 )
 */

/**
 * Heapify meaning here =>
 * To heapify a BT in which 1 element is miss placed and is present at top
 * 
 * 1. Bring largest node top for a given node
 * 2. Heapifying the subtree where node is swapped
*/

void heapify(int a[], int N, int i)
{
    int l = 2 * i + 1; // left child of current node
    int r = 2 * i + 2; // right child of current node
    int largest = i;
    if (a[l] > a[largest] and l < N)
        largest = l;
    if (a[r] > a[largest] and r < N)
        largest = r;
    if (largest != i)
        swap(a[largest], a[i]), heapify(a, N, largest);
}
void print(int a[], int N)
{
    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

/**
 * In HeapSort we dont actually create a tree
 * But the same analogy we apply of array
 * 
 * 1. HEAPIFY(literal heapify) complete tree using the above heapify
 *      function
 * 2. swaping largest element with last unsorted element
 * 3. Calling heapify for rest of the array
 * 
*/
void heapSort(int a[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(a, N, i);

    // Since the heapify function completely heapify
    // we start calling function from down to top ignoring leaf elements

    for (int i = N - 1; i >= 0; i--)
        swap(a[i], a[0]), heapify(a, i, 0);
}

signed main()
{
    int N;
    cin >> N;
    int a[N];
    for (int &x : a)
        cin >> x;
    heapSort(a, N);
    for (int x : a)
        cout << x << ' ';
}