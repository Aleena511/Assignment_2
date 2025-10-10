#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    // base setup 
    srand(time(0));  // random seed

    int W, H;                 \
    int I;                      
    double p, w;                 
    int R = 5;                  
    int T = 30;    

    cout << "Enter grid width and height: ";
    cin >> W >> H;
    cout << "Enter initial number of infected individuals: ";
    cin >> I;
    cout << "Enter infection probability p (0..1): ";
    cin >> p;
    cout << "Enter worsening probability w (0..1): ";
    cin >> w;

    vector<vector<int>> grid(H, vector<int>(W, 0));    
    vector<vector<int>> daysinfected(H, vector<int>(W, 0)); 

    // randomly infect initial people
    for (int i = 0; i < I; i++) {
        int x = rand() % H;
        int y = rand() % W;
        if (grid[x][y] == 0)
            grid[x][y] = (rand() % 9) + 1;  // infection severity 1-9
        else
            i--;  // retry if already infected
    }

    // now we print grid 
    auto printgrid = [&](vector<vector<int>>& g) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (g[i][j] == 0) cout << ".";
                else if (g[i][j] == -1) cout << "R";
                else if (g[i][j] == 10) cout << "X";
                else cout << g[i][j];
            }
            cout << endl;
        }
    };

    cout << "\nInitial grid state:\n";
    printgrid(grid);

    //put it in a loop 
    for (int day = 1; day <= T; day++) {
        vector<vector<int>> newgrid = grid;
        vector<vector<int>> newdays = daysinfected;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int state = grid[i][j];

                // skip recovered or dead
                if (state == -1 || state == 10) continue;

                // infected logic
                if (state >= 1 && state <= 9) {
                    newdays[i][j]++;

                    // recover after R days
                    if (newdays[i][j] >= R) {
                        newgrid[i][j] = -1;
                        continue;
                    }

                    // severity evolution
                    double randW = (double)rand() / RAND_MAX;
                    if (randW < w) {
                        newgrid[i][j] = (state == 9) ? 10 : state + 1; // death if over 9
                    } else {
                        newgrid[i][j] = (state > 1) ? state - 1 : 1;
                    }
                }

                // infection spread
                if (state == 0) {
                    int maxInfSeverity = 0;

                    // check 4 neighbors
                    int dx[4] = {-1, 1, 0, 0};
                    int dy[4] = {0, 0, -1, 1};
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                            int neighbor = grid[ni][nj];
                            if (neighbor >= 1 && neighbor <= 9) {
                                double randP = (double)rand() / RAND_MAX;
                                if (randP < p) {
                                    int newseverity = (rand() % neighbor) + 1;
                                    if (newseverity > maxInfSeverity)
                                        maxInfSeverity = newseverity;
                                }
                            }
                        }
                    }
                    if (maxInfSeverity > 0)
                        newgrid[i][j] = maxInfSeverity;
                }
            }
        }

        grid = newgrid;
        daysInfected = newdays;

        // stats
        int healthy = 0, infected = 0, recovered = 0, dead = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int s = grid[i][j];
                if (s == 0) healthy++;
                else if (s >= 1 && s <= 9) infected++;
                else if (s == -1) recovered++;
                else if (s == 10) dead++;
            }
        }

        cout << "Day " << day << ": Healthy: " << healthy
             << ", Infected: " << infected
             << ", Recovered: " << recovered
             << ", Dead: " << dead << endl;
    }

    cout << "\nFinal grid state:\n";
    printgrid(grid);

    return 0;
}
