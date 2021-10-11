#include<iostream>

using namespace std;

const int GRIDSIZE = 50;

void display(bool grid[GRIDSIZE][GRIDSIZE])
{
    const char* cellImage[2] = { "  ", " *" };
    for (int i = 1; i < GRIDSIZE; i++)
    {
        for (int j = 1; j < GRIDSIZE; j++)
        {
            cout << cellImage[grid[i][j]];
        }
        cout << endl;
    }
}

void copy(bool grid[GRIDSIZE][GRIDSIZE], bool grid2[GRIDSIZE][GRIDSIZE]) {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            grid2[i][j] = grid[i][j];
        }
    }
}

void live_or_die(bool grid[GRIDSIZE][GRIDSIZE]) {
    bool grid2[GRIDSIZE][GRIDSIZE] = {};
    copy(grid, grid2);
    for (int i = 1; i <= GRIDSIZE; i++) {
        for (int j = 1; j <= GRIDSIZE; j++) {
            int alive = 0;
            for (int k = -1; k < 2; k++) {
                for (int l = -1; l < 2; ++l) {
                    if ((!(k == 0 && l == 0)) && (grid2[i + k][j + l])) {
                        ++alive;
                    }
                }
            }
            if (alive < 2) { grid[i][j] = false; }
            else if (alive == 3) { grid[i][j] = true; }
            else if (alive > 3) { grid[i][j] = false; }
        }
    }
}

int main() {
    bool grid[GRIDSIZE][GRIDSIZE] = {};
    display(grid);
    live_or_die(grid);

    while (1) {
        display(grid);
        live_or_die(grid);

        system("CLS");
    }
}