#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main(int argc, char **argv) {
    if (argc == 1) {
        // Read from standard input
        char *map = read_map_from_stdin();
        if (map) {
            process_map(map);
            free(map);
        }
    } else {
        // Process each file provided as an argument
        for (int i = 1; i < argc; i++) {
            char *map = read_map_from_file(argv[i]);
            if (map) {
                process_map(map);
                free(map);
            }
            if (i < argc - 1) {
                printf("\n");
            }
        }
    }
    return 0;
}
