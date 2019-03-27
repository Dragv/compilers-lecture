%{
#include <stdio.h>
%}

%%
\/\/.*[\n]                      { /* DO NOTHING BECAUSE OF COMMENT */ }
f                               fprintf(yyget_out(), "floatdcl");
i                               fprintf(yyget_out(), "intdcl");
p                               fprintf(yyget_out(), "print");
[a-eghj-oq-z]                   fprintf(yyget_out(), "id");
([0-9]+"."[0-9]+)               fprintf(yyget_out(), "fnum");
([0-9]+)                        fprintf(yyget_out(), "inum");
=                               fprintf(yyget_out(), "assign");
\+                              fprintf(yyget_out(), "plus");
\-                              fprintf(yyget_out(), "minus");
\*                              fprintf(yyget_out(), "mult");
\/                              fprintf(yyget_out(), "div");
\n                              fprintf(yyget_out(), "\n");
%%

int main(int argc, char **argv) {
    FILE    *fd;
    FILE    *yyout;

    if (argc == 2)
    {
        if (!(fd = fopen(argv[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
        yyout = fopen("tokens.out", "w"); 
        yyset_in(fd);
        yyset_out(yyout);
        yylex();
        fclose(fd);
    }
    else
        printf("Usage: a.out filename\n");
    return (0);
}

