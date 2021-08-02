#include <iostream>
#include <vector>
using namespace std;

/**
 * A program for getting adjacency matrix and adjacency list for a graph entered by user
 * Assumption :
 *  All elements in graph are from 1 to N (Number of vertices)
*/

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> adjacency_matrix(vertices + 1, vector<int>(vertices + 1, 0));
    vector<vector<int>> adjacency_list(vertices + 1, vector<int>(0));
    int x, y;
    for (int i = 1; i <= edges; i++)
    {
        cin >> x >> y;
        adjacency_matrix[x][y] = 1;
        adjacency_matrix[y][x] = 1;
        // edge between element x and element y in matrix

        adjacency_list[x].push_back(y);
        adjacency_list[y].push_back(x);
    }
    cout << "********************* Adjacency Matrix *********************\n";
    for (int i = 1; i <= vertices; i++, cout << '\n')
        for (int j = 1; j <= vertices; j++)
            cout << adjacency_matrix[i][j] << ' ';

    cout << "********************* Adjacency List *********************\n";

    for (int i = 1; i <= vertices; i++, cout << '\n')
    {
        cout << i << " ---> ";
        for (int x : adjacency_list[i])
            cout << x << ' ';
    }

    return 0;
}