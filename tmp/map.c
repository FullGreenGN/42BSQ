#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "map.h"

#define BUF_SIZE 4096

static int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

char *read_map_from_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }
    
    char buffer[BUF_SIZE];
    int ret;
    char *map = NULL;
    int map_size = 0;

    while ((ret = read(fd, buffer, BUF_SIZE)) > 0) {
        char *new_map = realloc(map, map_size + ret + 1);
        if (!new_map) {
            free(map);
            close(fd);
            perror("Error allocating memory");
            return NULL;
        }
        map = new_map;
        memcpy(map + map_size, buffer, ret);
        map_size += ret;
    }
    if (map) {
        map[map_size] = '\0';
    }
    close(fd);
    return map;
}

char *read_map_from_stdin(void) {
    char buffer[BUF_SIZE];
    int ret;
    char *map = NULL;
    int map_size = 0;

    while ((ret = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0) {
        char *new_map = realloc(map, map_size + ret + 1);
        if (!new_map) {
            free(map);
            perror("Error allocating memory");
            return NULL;
        }
        map = new_map;
        memcpy(map + map_size, buffer, ret);
        map_size += ret;
    }
    if (map) {
        map[map_size] = '\0';
    }
    return map;
}

void process_map(char *map) {
    // Read the first line to get the map metadata
    int rows, cols;
    char empty, obstacle, full;
    sscanf(map, "%d%c%c%c\n", &rows, &empty, &obstacle, &full);
    
    // Calculate the number of columns
    char *p = strchr(map, '\n') + 1;
    for (cols = 0; p[cols] != '\n'; cols++);

    // Allocate DP array
    int **dp = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int *)malloc(cols * sizeof(int));
    }

    int max_size = 0;
    int max_i = 0;
    int max_j = 0;

    // Fill the DP array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (p[i * (cols + 1) + j] == empty) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    max_i = i;
                    max_j = j;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Replace the empty characters with the full character in the largest square
    for (int i = max_i; i > max_i - max_size; i--) {
        for (int j = max_j; j > max_j - max_size; j--) {
            p[i * (cols + 1) + j] = full;
        }
    }

    // Print the modified map
    printf("%s", p);

    // Free the DP array
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);
}
