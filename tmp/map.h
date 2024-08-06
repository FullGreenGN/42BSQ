#ifndef MAP_H
#define MAP_H

char *read_map_from_file(const char *filename);
char *read_map_from_stdin(void);
void process_map(char *map);

#endif
