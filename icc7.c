//
// Created by Mies VanBeek on 2026-03-13.
//
#include <stdio.h>
#include <stdlib.h>
#include "icc7.h"

#define MAX_LEN 256

int read_words(char *filename, char arr[][MAX_LEN]) {
    int numWords = 0;
    FILE* file;

    if ((file = fopen(filename, "r")) == NULL) {
        printf("%s can’t be opened\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, " %s", arr[numWords]) != EOF) {
        numWords++;
    }

    return numWords;
}

int count_unique_chars(char *s) {
    int uniqueChar = 0;
    int chars[26];
    for (int i = 0; i < sizeof(s); i++) {
        if (chars[*(s+i)-'a'] == 0) {
            chars[*(s+i)-'a'] = 1;
            uniqueChar++;
        }
    }

    return uniqueChar;
}

void swap(char* xp, char* yp){
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_words(char arr[][MAX_LEN], int n) {
    int i, j;
    int swapped = 0;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (count_unique_chars(arr[j]) > count_unique_chars(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
            if (count_unique_chars(arr[j]) == count_unique_chars(arr[j + 1])) {
                if (arr[j][0] > arr[j + 1][0]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = 1;
                }
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == 0)
            break;
    }

}