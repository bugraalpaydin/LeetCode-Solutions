#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s);

int main(){
    int size = 7;
    char *s = (char *)malloc(size*sizeof(char));
    strcpy(s, "([])");
    printf("%d", isValid(s));
}

bool isValid(char* s) {
    int stringLength = strlen(s);
    int headPointer = -1;
    char* stack = (char *)malloc(stringLength*sizeof(char));
    bool valid = false;
    for (int i = 0; i<stringLength; i++){
      if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
        headPointer++;
        stack[headPointer] = s[i];
      }  
      else {
        if(headPointer == -1)
            return false;
        if((s[i] == ')' && stack[headPointer--] != '(') || (s[i] == ']' && stack[headPointer--] != '[') || (s[i] == '}' && stack[headPointer--] != '{')){
          printf("%d\n", headPointer);
          return false;   
        }
      }
    }
      
    return (headPointer == -1);
}
