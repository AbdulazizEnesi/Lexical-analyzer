#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check_balanced_symbols(const char *code) {
    int parentheses = 0, braces = 0;

    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '(') parentheses++;
        else if (code[i] == ')') parentheses--;
        else if (code[i] == '{') braces++;
        else if (code[i] == '}') braces--;

        if (parentheses < 0 || braces < 0)
            return false;
    }

    return parentheses == 0 && braces == 0;
}

bool is_valid_assignment(const char *line) {
    // Very basic check: contains '=' and ends with ';'
    return strchr(line, '=') && line[strlen(line) - 1] == ';';
}

bool is_valid_if_statement(const char *line) {
    return strstr(line, "if(") != NULL || strstr(line, "if (") != NULL;
}

int main() {
    char code[1000];
    printf("Enter your code (end with $):\n");

    fgets(code, sizeof(code), stdin);

    // Remove '$' at the end if it exists
    char *dollar = strchr(code, '$');
    if (dollar) *dollar = '\0';

    printf("\n--- Syntax Analysis Result ---\n");

    if (!check_balanced_symbols(code)) {
        printf("❌ Error: Unbalanced parentheses or braces.\n");
    } else if (is_valid_if_statement(code)) {
        printf("✅ Valid: IF statement syntax looks correct.\n");
    } else if (is_valid_assignment(code)) {
        printf("✅ Valid: Assignment statement detected.\n");
    } else {
        printf("⚠ Unknown or unsupported syntax.\n");
    }

    return 0;
}
