#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basic Tokenizer
typedef struct {
    char *source;
    size_t position;
} Lexer;

Lexer create_lexer(char *source) {
    Lexer lexer = {source, 0};
    return lexer;
}

char next_char(Lexer *lexer) {
    return lexer->source[lexer->position++];
}

void skip_whitespace(Lexer *lexer) {
    while (lexer->source[lexer->position] == ' ' ||
           lexer->source[lexer->position] == '\n') {
        lexer->position++;
    }
}

// Simple Variable Storage
typedef struct {
    char *name;
    void *value;
} Variable;

Variable variables[100];
size_t variable_count = 0;

void set_variable(char *name, void *value) {
    for (size_t i = 0; i < variable_count; ++i) {
        if (strcmp(variables[i].name, name) == 0) {
            variables[i].value = value;
            return;
        }
    }
    variables[variable_count].name = strdup(name);
    variables[variable_count].value = value;
    variable_count++;
}

void* get_variable(char *name) {
    for (size_t i = 0; i < variable_count; ++i) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    return NULL;
}

// Execute Print Function
void print(char *text) {
    printf("%s\n", text);
}

// Parser and Executor
void execute(char *source) {
    Lexer lexer = create_lexer(source);
    skip_whitespace(&lexer);
    while (lexer.position < strlen(source)) {
        skip_whitespace(&lexer);
        if (strncmp(&lexer.source[lexer.position], "print", 5) == 0) {
            lexer.position += 5;
            skip_whitespace(&lexer);
            char text[256];
            if (lexer.source[lexer.position] == '(') {
                lexer.position++;
                sscanf(&lexer.source[lexer.position], "%[^\"]", text);
                print(text);
            }
            lexer.position += strlen(text) + 1;
        }
        lexer.position++;
        
    }
}

// Main Function for Testing
int main() {
    char code[] = "print(\"Hello, SimpleC!\")";
    execute(code);
    return 0;
}
