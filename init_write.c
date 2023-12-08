//
//  Cédric Champeix
//

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

void init_write() {
    char *dirname = "maps_files";

    struct stat s = {0};

    if (stat(dirname, &s) == 0) {
        printf("The maps_saves folder hasn't been deleted.");
        exit(EXIT_FAILURE);
    }
    mkdir(dirname, S_IRWXU);

}
