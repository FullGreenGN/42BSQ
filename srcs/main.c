#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateGrid(int x, int y, int density, const char* filename) {
    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Print the filename as the Perl script does
    fprintf(file, "%d.ox\n", y);

    // Seed the random number generator
    srand(time(0));

    // Generate the grid
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if ((rand() % (y * 2)) < density) {
                fprintf(file, "o");
            } else {
                fprintf(file, ".");
            }
        }
        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s x y density\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int density = atoi(argv[3]);

    char filename[20];
    snprintf(filename, sizeof(filename), "%d.ox", y);

    generateGrid(x, y, density, filename);

    return 0;
}
