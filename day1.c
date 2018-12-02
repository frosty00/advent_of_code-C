#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE* fp;
    char buffer[255];
    int cur;
    int i = 0;
    int s = 0;
    int inside(int*, int, ssize_t);
    int array[1000000];  // runs in O(n) time (a hash table or dict would run in O(1))

    fp = fopen("advent.txt", "r");
    fgets(buffer, 255, (FILE*) fp);
    
    while (1) {
	sscanf(buffer, "%d\n", &cur);
        s = s + cur;
        if (inside(array, s, i)) {
            printf("first double was %d\n", s);
            return s;
        }
        array[i] = s;
        i++;
        if (fgets(buffer, 255, (FILE*) fp) == NULL) {
            fseek(fp, 0, SEEK_SET); // goto start of file
            fgets(buffer, 255, (FILE*) fp); // overwrite buffer
        }
    }
    fclose(fp);
}

int inside(int* hist, int val, ssize_t len) {
    for (int i = 0; i < len; i++) {
	if (hist[i] == val) {
  	    return 1;
	}
    }
    return 0;
}
