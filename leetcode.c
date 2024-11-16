#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* longestCommonPrefix(char**, int);

int main(){
    int strsSize = 3;
    char** strs = (char **)malloc(strsSize*sizeof(char *));
    strs[0] = "flower";
    strs[1] = "flight";
    strs[2] = "flow";
    char *common = longestCommonPrefix(strs, 3);
}

char* longestCommonPrefix(char** strs, int strsSize) {

    if(strsSize <= 0){
        return "";
    }
    
    char *prefix = strs[0];
    int length = strlen(prefix);

    for(int i = 1; i<strsSize; i++){
        char* string = strs[i];
        for(int j = 0; j<length; j++){
            if(string[j] != prefix[j]){
                prefix[j] = '\0';
                length = j;
            }
        }
    }
    return prefix;
}

