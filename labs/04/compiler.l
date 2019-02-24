%{
#include <stdio.h>
%}

%%
\/\/.*[\n]                      printf("COMMENT\n");
f                               printf("floatdcl");
i                               printf("intdcl");
p                               printf("print");
[a-eghj-oq-z]                   printf("id");
([0-9]+)|([0-9]+"."[0-9]+)      printf("num");
=                               printf("assign");
\+                              printf("plus");
\-                              printf("minus");
\*                              printf("mult");
\/                              printf("div");
%%

int main(int argc, char **argv) {
    FILE    *fd;

    if (argc == 2)
    {
        if (!(fd = fopen(argv[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
        yyset_in(fd);
        yylex();
        fclose(fd);
    }
    else
        printf("Usage: a.out filename\n");
    return (0);
}

