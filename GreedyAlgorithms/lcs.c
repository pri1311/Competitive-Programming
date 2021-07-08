#include <stdio.h>
#include <stdlib.h>

char *longestCommonSubsequence(char a[], char b[]) {
    char *lcs = malloc(100*sizeof(char));
    int i = 0, j = 0, k = 0;
    while (a[i] && b[j]) {
        if (a[i] == b[j]) {
            lcs[k++] = a[i++];
            j++;
        } 
        else 
            i += 1;
    }
    lcs[k] = '\0';
    return lcs;
}

int main() {
    char string1[100], string2[100];
    printf("String 1: ");
    scanf(" %s", string1);
    printf("String 2: ");
    scanf(" %s", string2);
    printf("%s", longestCommonSubsequence(string1, string2));
    return 0;
}