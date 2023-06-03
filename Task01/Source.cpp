#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int ROWS = 20;
const int COLUMNS = 40;

//printing the grid function

void printGrid(int currentRow, int currentColumn, int startRow, int startColumn, int endRow, int endColumn) {


    for (int row = 1; row <= ROWS; row++) {
        for (int col = 1; col <= COLUMNS; col++) {
            if (row == startRow && col == startColumn)
                cout << "A";
            else if (row == endRow && col == endColumn)
                cout << "B";
            else if (row == currentRow && col == currentColumn)
                cout << "x";
          
            else
                cout << "-";
        }
        cout << '\n';
    }
    cout << '\n';
}

void plotCurrentPosition(int currentRow, int currentColumn, int startRow, int startColumn, int endRow, int endColumn) {
    // Function to plot the current position and the grid
    // This function prints the grid with the current position marked as 'x'

    // Clear the console
     system("cls");

    // Print the grid
    printGrid(currentRow, currentColumn, startRow, startColumn, endRow, endColumn);

    // Delay for 100 milliseconds

    milliseconds delay(100);
    auto startTime = steady_clock::now();
    while (steady_clock::now() - startTime < delay) {
        // Wait until 100 milliseconds have passed
    }
}

void findPath(int startRow, int startColumn, int endRow, int endColumn) {
    // Function to find the path from start to end, implementing path-finding algorithm 
    // Fmove column by column until we reach the end column
    int currentRow = startRow;
    int currentColumn = startColumn;

    // Check if start and end positions are the same
    if (currentRow == endRow && currentColumn == endColumn) {
        plotCurrentPosition(currentRow, currentColumn, startRow, startColumn, endRow, endColumn);
        return;
    }

    // Move towards the end position
    while (currentColumn != endColumn) {
        // Increment or decrement the column based on the end position
        if (currentColumn < endColumn)
            currentColumn++;
        else
            currentColumn--;

        plotCurrentPosition(currentRow, currentColumn, startRow, startColumn, endRow, endColumn);
    }

    // Move towards the end row
    while (currentRow != endRow) {
        // Increment or decrement the row based on the end position
        if (currentRow < endRow)
            currentRow++;
        else
            currentRow--;

        plotCurrentPosition(currentRow, currentColumn, startRow, startColumn, endRow, endColumn);
    }
}

int main() {

   

    int startRow, startColumn, endRow, endColumn;

    // let the user enter the starting point
    cout << "Enter the starting point (A):\n";
    cout << "Row (1-20): ";
    cin >> startRow;
    cout << "Column (1-40): ";
    cin >> startColumn;

    // let the zser enter the ending point
    cout << "Enter the endpoint (B):\n";
    cout << "Row (1-20): ";
    cin >> endRow;
    cout << "Column (1-40): ";
    cin >> endColumn;

    // Call the function to find and plot the path
    findPath(startRow, startColumn, endRow, endColumn);

    return 0;
}

