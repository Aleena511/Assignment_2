#include <iostream>
#include <cmath>    
using namespace std;

int main() {.
    const int height = 20;

    // range of x values 
    double xmin, xmax;
    cout << "Enter range of x (e.g. -6.28 6.28): ";
    cin >> xmin >> xmax;

    // range for y = sin(x)
    double ymin = -1.0, ymax = 1.0;

    // create the grid and fill with spaces
    char grid[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = ' ';
        }
    }

    // draw x-axis 
    int mid_y = height / 2;
    for (int j = 0; j < width; j++) {
        grid[mid_y][j] = '-';
    }

    // draw y-axis (vertical middle line)
    int mid_x = width / 2;
    for (int i = 0; i < height; i++) {
        grid[i][mid_x] = '|';
    }

    // plot the sine wave
    for (int j = 0; j < width; j++) {
        
        double x = xmin + (xmax - xmin) * j / (width - 1);

        // calculate y = sin(x)
        double y = sin(x);

        // map y to grid row
        int i = (int)((y - ymin) / (ymax - ymin) * (height - 1));

        // invert y to match terminal top-down coordinates
        i = height - 1 - i;

        // place '*' for the sine point
        if (i >= 0 && i < height)
            grid[i][j] = '*';
    }

    // print time
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
