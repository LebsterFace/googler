#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#pragma once

char* urlencode(char* originalText) {
    // allocate memory for the worst possible case (all characters need to be encoded)
    char* encodedText = (char *)malloc(sizeof(char)*strlen(originalText)*3+1);
    
    const char *hex = "0123456789abcdef";
    
    int pos = 0;
    for (int i = 0; i < strlen(originalText); i++) {
        if (('a' <= originalText[i] && originalText[i] <= 'z')
            || ('A' <= originalText[i] && originalText[i] <= 'Z')
            || ('0' <= originalText[i] && originalText[i] <= '9')) {
                encodedText[pos++] = originalText[i];
            } else {
                encodedText[pos++] = '%';
                encodedText[pos++] = hex[originalText[i] >> 4];
                encodedText[pos++] = hex[originalText[i] & 15];
            }
    }
    encodedText[pos] = '\0';
    return encodedText;
}

char* get_arguments(int argc, char* argv[]) {
	int strsize = 0;
		for (int i = 1; i < argc; i++) {
		strsize += strlen(argv[i]);
		if (argc > i + 1) strsize++; // For space
	}

	char* result;
	result = malloc(strsize);
	result[0] = '\0';

	for (int i = 1; i < argc; i++) {
		strcat(result, argv[i]);
		if (argc > i+1) strcat(result, " ");
	}

	return result;
}