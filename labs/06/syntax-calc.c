#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// TRIMING FUNCTIONS FOUND AT http://www.martinbroadhurst.com/trim-a-string-in-c.html

char *ltrim(char *str, const char *seps)
{
    size_t totrim;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0) {
        size_t len = strlen(str);
        if (totrim == len) {
            str[0] = '\0';
        }
        else {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}

char *rtrim(char *str, const char *seps)
{
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}

char *trim(char *str, const char *seps)
{
    return ltrim(rtrim(str, seps), seps);
}

int Start();
int StartOne();
int StartTwo();
int StartThree();
int Assign();
int AssignOne();
int AssignTwo();
int Declaration();
int Output();
int Type();
int TypeOne();
int TypeTwo();
int Operation();
int Num();
int check();
int term(char* tok);

char *next, *s;
char tree[5048];

int term(char* tok) {
    if (next != NULL) {
        int compare = strcmp(trim(next, NULL), tok);
        int decision = 0;
        if (compare == 0) {
            decision = 1;
            next = strtok_r(s, " ", &s);
        }
        return decision;
    }
    return 0;
}

int OperationMinus() {
    int decision = term("minus");
    if (decision) {
        char toConcat[] = "minus";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int OperationMult() {
    int decision = term("mult");
    if (decision) {
        char toConcat[] = "mult";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int OperationDiv() {
    int decision = term("div");
    if (decision) {
        char toConcat[] = "div";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int OperationPlus() {
    int decision = term("plus");
    if (decision) {
        char toConcat[] = "plus";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int Operation() {
    char toConcat[] = "\nOperation -> ";
    strcat(tree, toConcat);

    char* streamSave;
    if (s != NULL)
        streamSave = (char *)malloc(strlen(s) * sizeof(char));
    char* save = (char *)malloc(strlen(next) * sizeof(char));
    char* treeSave = (char *)malloc(strlen(tree) * sizeof(char));

    save = strcpy(save, next);
    if (s != NULL)
        streamSave = strcpy(streamSave, s);
    treeSave = strcpy(treeSave, tree);

    int minusDetermination = OperationMinus();
    if (minusDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    if (s != NULL)
        s = strcpy(s, streamSave);
    strcpy(tree, treeSave);

    int multDetermination = OperationMult();
    if (multDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    if (s != NULL)
        s = strcpy(s, streamSave);
    strcpy(tree, treeSave);

    int divDetermination = OperationDiv();
    if (divDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    if (s != NULL)
        s = strcpy(s, streamSave);
    strcpy(tree, treeSave);

    int plusDetermination = OperationPlus();
    if (plusDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }

    next = strcpy(next, save);
    if (s != NULL)
        s = strcpy(s, streamSave);
    strcpy(tree, treeSave);

    free(save);
    if (s != NULL)
        free(streamSave);
    free(treeSave);

    return 0;
}

int NumOne() {
    int decision = term("inum");
    if (decision) {
        char toConcat[] = "inum";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int NumTwo() {
    int decision = term("fnum");
    if (decision) {
        char toConcat[] = "fnum";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int Num() {
    char toConcat[] = "\nNum -> ";
    strcat(tree, toConcat);
    char* streamSave;
    char* save = (char *)malloc(strlen(next) * sizeof(char));
    if (s != NULL)
      streamSave = (char *)malloc(strlen(s) * sizeof(char));
    char* treeSave = (char *)malloc(strlen(tree) * sizeof(char));
    save = strcpy(save, next);
    if (s != NULL)
      streamSave = strcpy(streamSave, s);
    treeSave = strcpy(treeSave, tree);

    int numOneDetermination = NumOne();
    if (numOneDetermination) {
        free(save);
        if (s != NULL)
          free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    if (s != NULL)
      s = strcpy(s, streamSave);
    strcpy(tree, treeSave);
    int numTwoDetermination = NumTwo();
    if (numTwoDetermination) {
        free(save);
        if (s != NULL)
          free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    if (s != NULL)
      s = strcpy(s, streamSave);
    strcpy(tree, treeSave);

    free(save);
    if (s != NULL)
      free(streamSave);
    free(treeSave);

    return 0;
}

int TypeOne() {
    int decision = term("intdcl");
    if (decision) {
        char toConcat[] = "\nType -> intdcl ";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int TypeTwo() {
    int decision = term("floatdcl");
    if (decision) {
        char toConcat[] = "\nType -> floatdcl ";
        strcat(tree, toConcat);
    }
    
    return decision;
}

int Type() {
    char* save = (char *)malloc(strlen(next) * sizeof(char));
    char* streamSave = (char *)malloc(strlen(s) * sizeof(char));
    char* treeSave = (char *)malloc(strlen(tree) * sizeof(char));

    save = strcpy(save, next);
    streamSave = strcpy(streamSave, s);
    treeSave = strcpy(treeSave, tree);

    int typeOneDetermination = TypeOne();
    if (typeOneDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    s = strcpy(s, streamSave);
    strcpy(tree, treeSave);
    int typeTwoDetermination = TypeTwo();
    if (typeTwoDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    s = strcpy(s, streamSave);
    strcpy(tree, treeSave);

    free(save);
    free(streamSave);
    free(treeSave);

    return 0;
}

int Assign() {
    char toConcat[] = "Assign ";
    strcat(tree, toConcat);
    char* save = (char *)malloc(strlen(next) * sizeof(char));
    char* streamSave = (char *)malloc(strlen(s) * sizeof(char));
    char* treeSave = (char *)malloc(strlen(tree) * sizeof(char));

    save = strcpy(save, next);
    streamSave = strcpy(streamSave, s);
    treeSave = strcpy(treeSave, tree);

    int assignOneDetermination = AssignOne();
    if (assignOneDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }
    strcpy(tree, treeSave);
    s = strdup(streamSave);
    strcpy(next, save);
    int assignTwoDetermination = AssignTwo();
    if (assignTwoDetermination) {
        free(save);
        free(streamSave);
        free(treeSave);
        return 1;
    }
    next = strcpy(next, save);
    s = strcpy(s, streamSave);
    strcpy(tree, treeSave);

    free(save);
    free(streamSave);
    free(treeSave);

    return 0;
}

int AssignOne() {
    char toConcat[] = "\nAssign -> id1, assign, id2, Operation, Num";
    strcat(tree, toConcat);
    int first = term("id");
    if (first == 0)
      return 0;
    int second = term("assign");
    if (second == 0)
      return 0;
    int third = term("id");
    if (third == 0)
      return 0;
    int fourth = Operation();
    if (fourth == 0)
      return 0;
    int fifth = Num();
    if (fifth == 0)
      return 0;
    return first 
        && second
        && third
        && fourth
        && fifth;
}

int AssignTwo() {
    char toConcat[] = "\nAssign -> id1, assign, Num";
    strcat(tree, toConcat);
    int first = term("id");
    int second = term("assign");
    int third = Num();
    return first 
        && second
        && third;
}

int Declaration() {
    char toConcatOne[] = "Declaration\n";
    char toConcatTwo[] = "Declaration -> Type, id";
    strcat(tree, toConcatOne);
    strcat(tree, toConcatTwo);

    int first = Type();
    int second = term("id");
    int decision = (first && second);
    return decision;
}

int OutputOne() {
    char treeSave[5048];
    strcpy(treeSave, tree);
    char toConcat[] = "\nOutput -> print, Num ";
    strcat(tree, toConcat);
    int first = term("print");
    int second = Num();
    int decision = (first && second);
    if (!decision) {
        strcpy(tree, treeSave);
    }
    return decision;
}

int OutputTwo() {
    int first = term("print");
    int second = term("id");
    int decision = (first && second);
    if (first) {
        char toConcat[] = "\nOutput -> print, id ";
        strcat(tree, toConcat);
    }
    return decision;
}

int Output() {
    char toConcat[] = "Output ";
    strcat(tree, toConcat);
    char* save = (char *)malloc(strlen(next) * sizeof(char));
    char* streamSave = (char *)malloc(strlen(s) * sizeof(char));
    char treeSave[5048];

    save = strcpy(save, next);
    streamSave = strcpy(streamSave, s);
    strcpy(treeSave, tree);

    int outputOneDetermination = OutputOne();
    if (outputOneDetermination) {
        free(save);
        free(streamSave);
        return 1;
    } 
    next = strcpy(next, save);
    s = strdup(streamSave);
    strcpy(tree, treeSave);
    int outputTwoDetermination = OutputTwo();
    if (outputTwoDetermination) {
        free(save);
        free(streamSave);
        return 1;
    }

    free(save);
    free(streamSave);
    return 0;
}

int StartOne() {
    return Assign();
}

int StartTwo() {
    return Declaration();
}

int StartThree() {
    return Output();
}

int Start() {
    next = strtok_r(s, " ", &s);
    char toConcat[] = "Start -> ";
    strcat(tree, toConcat);
    char* save = (char *)malloc(strlen(next) * sizeof(char));
    char* streamSave = (char *)malloc(strlen(s) * sizeof(char));
    char* treeSave = (char *)malloc(strlen(tree) * sizeof(char));
    save = strcpy(save, next);
    streamSave = strcpy(streamSave, s);
    treeSave = strcpy(treeSave, tree);

    int compare = strcmp(trim(next, NULL), "print");
    int decision = 0;
    if (compare == 0) {
        int startThreeDetermination = StartThree();
        if (startThreeDetermination) {
            free(save);
            free(streamSave);
            free(treeSave);
            return 1;
        }
    } else {
        int startOneDetermination = StartOne();
        if (startOneDetermination) {
            free(save);
            free(streamSave);
            free(treeSave);
            return 1;
        }
        next = strcpy(next, save);
        s = strcpy(s, streamSave);
        strcpy(tree, treeSave);
        int startTwoDetermination = StartTwo();
        if (startTwoDetermination) {
            free(save);
            free(streamSave);
            free(treeSave);
            return 1;
        }
    }


    free(save);
    free(streamSave);
    free(treeSave);

    return 0;
}

void read_words (FILE *f) {
    char buf[4086];
    int counter = 1;    
    while(fgets (buf, sizeof buf, f)!=NULL){        
        next = buf;
        s = next;
        int result = Start();
        if (result) {
            printf("Line %d accepted\n", counter++);
            printf("%s", tree);
        } else
        {
            printf("Syntax error at line %d \n", counter++);
            return;
        }
        strcpy(tree, "");
        printf("\n");
        printf("\n");
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error opening file");
        return 0;
    }

    read_words(file);

    fclose(file);

    return 0;
}