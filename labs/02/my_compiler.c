#include<stdio.h>

int main(int argc, char* argv[])
{
    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");

    if(file == NULL){
        printf("Error opening file");
        return 0;
    }

    int c;
    int braces = 0;
    int brackets = 0;
    int parenthesis = 0;
    int comments = 0;
    int strings = 0;

    while((c = getc(file)) != EOF){
        if (c == '/') {
            if ((c = getc(file)) != '/') {
                comments++;
            }
        } else if (c == '(') {
            parenthesis++;
        } else if (c == ')') {
            parenthesis--;
        } else if (c == '{') {
            brackets++;
        } else if (c == '}') {
            brackets--;
        } else if (c == '[') {
            braces++;
        } else if (c == ']') {
            braces--;
        } else if (c == '\'' || c == '"') {
            int temp;
            while((temp = getc(file)) != c) {
                if (temp = '\\') {
                    strings++;
                    break;
                }
            }
        }
    }

    if (braces > 0) {
        printf("Missing %d ]\n", braces);
    }

    if (braces < 0) {
        printf("Missing %d [\n", braces);
    }

    if (brackets > 0) {
        printf("Missing %d }\n", brackets);
    }

    if (brackets < 0) {
        printf("Missing %d {\n", brackets * -1);
    }

    if (parenthesis > 0) {
        printf("Missing %d )\n", parenthesis);
    }

    if (parenthesis < 0) {
        printf("Missing %d (\n", parenthesis);
    }

    if (comments > 0) {
        printf("Missing %d /\n", comments);
    }

    if (strings > 0) {
        printf("%d incomplete string declaration\n", strings);
    }

    return 0;
}
