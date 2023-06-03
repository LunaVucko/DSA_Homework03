#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int ROWS = 20;
const int COLUMNS = 40;

void printGrid(const vector<vector<char>>& grid, int currentRow, int currentColumn, int startRow, int startColumn, int endRow, int endColumn) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            if (row == startRow && col == startColumn)
                cout << "A";
            else if (row == endRow && col == endColumn)
                cout << "B";
            else if (row == currentRow && col == currentColumn)
                cout << "x";
            else
                cout << grid[row][col];
        }
        cout << '\n';
    }
    cout << '\n';
}

void findShortestPath(vector<vector<char>>& grid, int startRow, int startColumn, int endRow, int endColumn) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(ROWS, vector<bool>(COLUMNS, false));
    vector<vector<pair<int, int>>> prev(ROWS, vector<pair<int, int>>(COLUMNS));

    q.emplace(startRow, startColumn);
    visited[startRow][startColumn] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int row = current.first;
        int col = current.second;

        // Check if the current node is the destination
        if (row == endRow && col == endColumn) {
            // Update the grid with the shortest path
            while (row != startRow || col != startColumn) {
                grid[row][col] = 'x';
                int prevRow = prev[row][col].first;
                int prevCol = prev[row][col].second;
                row = prevRow;
                col = prevCol;
            }
            break;
        }

        // Explore the neighbors (up, down, left, right)
        vector<pair<int, int>> neighbors = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (const auto& neighbor : neighbors) {
            int newRow = row + neighbor.first;
            int newCol = col + neighbor.second;

            // Check if the neighbor is within the grid boundaries and is not an obstacle
            if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLUMNS && grid[newRow][newCol] != '#' && !visited[newRow][newCol]) {
                q.emplace(newRow, newCol);
                visited[newRow][newCol] = true;
                prev[newRow][newCol] = { row, col };
            }
        }
    }
}

int main() {
    vector<vector<char>> grid(ROWS, vector<char>(COLUMNS, '-'));

    int startRow, startColumn, endRow, endColumn;

    // let the user enter the starting point
    cout << "Enter the starting point (A):\n";
    cout << "Row (1-20): ";
    cin >> startRow;
    cout << "Column (1-40): ";
    cin >> startColumn;

    // let the user enter the ending point
    cout << "Enter the endpoint (B):\n";
    cout << "Row (1-20): ";
    cin >> endRow;
    cout << "Column (1-40): ";
    cin >> endColumn;

    // Add obstacles to the grid
    grid[5][10] = '#';
    grid[6][10] = '#';
    grid[7][10] = '#';
    grid[8][10] = '#';
    grid[9][10] = '#';
    grid[10][10] = '#';
    grid[11][10] = '#';

    // Call the function to find and plot the path
    findShortestPath(grid, startRow - 1, startColumn - 1, endRow - 1, endColumn - 1);

    // Print the final grid with the shortest path
    printGrid(grid, startRow - 1, startColumn - 1, startRow - 1, startColumn - 1, endRow - 1, endColumn - 1);

    return 0;
}
