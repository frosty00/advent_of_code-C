#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 26
#define STRNO 251

int compare(char*, char*);
char* compare_all(char[][STRLEN+1], size_t, size_t);
void intersect(char*, char*);

int main () {
    FILE* fp;

    fp = fopen("advent.txt", "r");
    char buffer[STRLEN];
    char strings[STRNO][STRLEN+1];
    char result[STRLEN];
    
    size_t i = 0;

    while (fgets(buffer, 255, (FILE*) fp) != NULL) {
        memcpy(strings[i], buffer, STRLEN);
        i++;
    }
    for(size_t x=0; x<STRNO; x++) {
        compare_all(strings, x, STRNO);
    }
}

char* compare_all(char strings[][STRLEN+1], size_t index, size_t len) {
    char result[STRLEN];
    for(size_t i = 0; i<len; i++){
        if(i == index) {
           continue;
        }
        int character_diff = compare(strings[index], strings[i]);
        if(character_diff == 1){
            printf("%s and %s differ by only one character\n", strings[index], strings[i]);
            intersect(strings[index], strings[i]);
        }
    }
     return strings[index];

}

int compare(char* string1, char* string2) {
    int count = 0;
    for (size_t i = 0; i < STRLEN; i++) {
        if (string1[i] != string2[i]) {
            count++;
        }
        if (count>1){
            return count;
        }
    }
    return count;
}


void intersect(char* string1, char* string2) {
    static char result[STRLEN];
    int missing;
    printf("%s %s inside intersect\n", string1, string2);
    for(size_t i = 0; i<STRLEN; i++){
        printf("%s %s %zu\n", string1, string2, i);
        if (string1[i] == string2[i]) {
            result[i] = string1[i];
        }else {
            missing = i;
        }
    }
    memmove(&result[missing],&result[missing+1],STRLEN-missing);        
    printf("%s\n", result);
}
