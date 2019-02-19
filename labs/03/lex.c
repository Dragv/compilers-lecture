#include<stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");

    if(file == NULL){
        printf("Error opening file");
        return 0;
    }

    FILE * fp;
    int i;
    /* open the file for writing*/
    fp = fopen ("lex.out","w");

    int c;
    while((c = getc(file)) != EOF){
        if (c == '/') {
            if ((c = getc(file)) == '/') {
                int temp;
                while((temp = getc(file)) != '\n');
                c = getc(file);
            }
        }
        char lineString[80];
        if(c == 'f'){
            while((c = getc(file)) != '\n'){
                if(isalpha(c)){
                    fprintf (fp, "floatdcl id ");
                    printf("floatdcl id ");
                    break;
                }
                if(c == '='){
                    fprintf (fp, "id assign ");
                    printf("id assign ");
                }
                if(isdigit(c)) {
                    int f = 0;
                    while((c = getc(file)) != '\n'){
                        if(c == '.'){
                            f = 1;
                            break;
                        }
                    }
                    if(f == 1){
                        fprintf (fp, "fnum ");
                        printf("fnum ");
                    } else {
                        fprintf (fp, "inum ");
                        printf("inum ");
                    }
                    ungetc(c, file);
                }
                if(isalpha(c)) {
                    fprintf (fp, "id ");
                    printf("id ");
                }
                if(c == '+') {
                    fprintf (fp, "plus ");
                    printf("plus ");
                }
            }
            fprintf (fp, "\n");
            printf("\n");
        } else if (c == 'i') {
            while((c = getc(file)) != '\n'){
                if(isalpha(c)){
                    fprintf (fp, "intdcl id ");
                    printf("intdcl id ");
                    break;
                }
                if(c == '='){
                    fprintf (fp, "id assign ");
                    printf("id assign ");
                }
                if(isdigit(c)) {
                    int f = 0;
                    while((c = getc(file)) != '\n'){
                        if(c == '.'){
                            f = 1;
                            break;
                        }
                    }
                    if(f == 1){
                        fprintf (fp, "fnum ");
                        printf("fnum ");
                    } else {
                        fprintf (fp, "inum ");
                        printf("inum ");
                    }
                    ungetc(c, file);
                }
                if(isalpha(c)) {
                    fprintf (fp, "id ");
                    printf("id ");
                }
                if(c == '+') {
                    fprintf (fp, "plus ");
                    printf("plus ");
                }
            }
            fprintf (fp, "\n");
            printf("\n");
        } else if (c == 'p') {
            while((c = getc(file)) != '\n'){
                if(isalpha(c)){
                    fprintf (fp, "print id ");
                    printf("print id ");
                    break;
                }
                if(c == '='){
                    fprintf (fp, "id assign ");
                    printf("id assign ");
                }
                if(isdigit(c)) {
                    int f = 0;
                    while((c = getc(file)) != '\n'){
                        if(c == '.'){
                            f = 1;
                            break;
                        }
                    }
                    if(f == 1){
                        fprintf (fp, "fnum ");
                        printf("fnum ");
                    } else {
                        fprintf (fp, "inum ");
                        printf("inum ");
                    }
                    ungetc(c, file);
                }
                if(isalpha(c)) {
                    fprintf (fp, "id ");
                    printf("id ");
                }
                if(c == '+') {
                    fprintf (fp, "plus ");
                    printf("plus ");
                }
            }
            fprintf (fp, "\n");
            printf("\n");
        } else if (isalpha(c)) {
            while((c = getc(file)) != '\n'){
                if(c == '='){
                    fprintf (fp, "id assign ");
                    printf("id assign ");
                }
                if(isdigit(c)) {
                    int f = 0;
                    while((c = getc(file)) != '\n'){
                        if(c == '.'){
                            f = 1;
                            break;
                        }
                    }
                    if(f == 1){
                        fprintf (fp, "fnum ");
                        printf("fnum ");
                    } else {
                        fprintf (fp, "inum ");
                        printf("inum ");
                    }
                    ungetc(c, file);
                }
                if(isalpha(c)) {
                    fprintf (fp, "id ");
                    printf("id ");
                }
                if(c == '+') {
                    fprintf (fp, "plus ");
                    printf("plus ");
                }
                
            }
            fprintf (fp, "\n");
            printf("\n");
        }
    }

    return 0;
}