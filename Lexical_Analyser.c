#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
Name:Lavanya R
Date:
Description:BUILD A SIMPLE LEXICAL ANALYZERTHAT IDENTIFIES KEYWORDS,OPERATORS, AND IDENTIFIERS FROM AN INPUT FILE
Sample Input:
Sample Output:
*/

// List of C language keywords to be identified
char keywords[][10] = { "int", "float", "char", "double", "if","else", "while", "for", "return", "void"};

// List of operators that the analyzer should detect
char operators[] = "+-*/=%<>!&|";

// Function to check if a given string is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1; // If matched, return 1 (true)
    }
    return 0;  // If not matched, return 0 (false)
}

// Function to check if a character is an operator
int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1; // If matched, return 1 (true)
    }
    return 0; // If not matched, return 0 (false)
}

int main() {
    FILE *fp;
    char ch, str[100];
    int i;

    // Open the input file that contains  code
    fp = fopen("input.c", "r");  // Input file name
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

     // Read the file character by character until EOF (End of File)
    while ((ch = fgetc(fp)) != EOF) {
	 // Check if the character is alphabetic (starting of identifier or keyword)
        if (isalpha(ch)) {  // Identifier or Keyword
            i = 0;
            str[i++] = ch;
            ch = fgetc(fp);
	    // Continue collecting characters that are alphanumeric or underscore
            while (isalnum(ch) || ch == '_') {
                str[i++] = ch;
                ch = fgetc(fp);
            }
            str[i] = '\0';

	    // Move one character back for proper scanning
            fseek(fp, -1, SEEK_CUR); // Go one character back

	    // Check if the collected string is a keyword
            if (isKeyword(str))
                printf("%s : Keyword\n", str);
            else
                printf("%s : Identifier\n", str);
        }
	 // Check if the character is an operator
        else if (isOperator(ch)) {
            printf("%c : Operator\n", ch);
        }
        // Skip numbers, whitespaces, punctuations for simplicity
    }

    // Close the file after processing
    fclose(fp);
    return 0;
}



