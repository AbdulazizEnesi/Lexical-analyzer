#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(const char *word) {
    const char *keywords[] = {"if", "else", "while", "for", "int", "float", "return"};
    int count = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < count; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, word[100];
    int i = 0;

    printf("Enter code (end with $):\n");

    while ((ch = getchar()) != '$') {
        // Skip whitespace
        if (isspace(ch)) continue;

        // Comments (single-line //)
        if (ch == '/') {
            char next = getchar();
            if (next == '/') {
                // Skip the rest of the line
                while ((ch = getchar()) != '\n' && ch != '$');
                if (ch == '$') break;
                continue;
            } else {
                ungetc(next, stdin);
                printf("OPERATOR: /\n");
                continue;
            }
        }

        // Handle letters (keywords or identifiers)
        if (isalpha(ch)) {
            word[i++] = ch;
            while (isalnum(ch = getchar()) || ch == '_')
                word[i++] = ch;
            word[i] = '\0';
            i = 0;
            ungetc(ch, stdin);

            if (isKeyword(word))
                printf("KEYWORD: %s\n", word);
            else
                printf("IDENTIFIER: %s\n", word);
        }

        // Handle numbers (int or float)
        else if (isdigit(ch)) {
            word[i++] = ch;
            int isFloat = 0;

            while (isdigit(ch = getchar()) || ch == '.') {
                if (ch == '.') isFloat = 1;
                word[i++] = ch;
            }
            word[i] = '\0';
            i = 0;
            ungetc(ch, stdin);

            if (isFloat)
                printf("FLOAT: %s\n", word);
            else
                printf("NUMBER: %s\n", word);
        }

        // Handle relational operators
        else if (ch == '=' || ch == '!' || ch == '>' || ch == '<') {
            char next = getchar();
            if (next == '=') {
                printf("OPERATOR: %c=\n", ch);
            } else {
                ungetc(next, stdin);
                printf("OPERATOR: %c\n", ch);
            }
        }

        // Other operators
        else if (ch == '+' || ch == '-' || ch == '*') {
            printf("OPERATOR: %c\n", ch);
        }

        // Symbols and brackets
        else if (ch == ';')
            printf("SYMBOL: ;\n");
        else if (ch == '(' || ch == ')')
            printf("BRACKET: %c\n", ch);
        else if (ch == '{' || ch == '}')
            printf("BRACE: %c\n", ch);
    }

    return 0;
}
