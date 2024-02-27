#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 32
#define FLAGSIZE 64

void win() {
    char buf[FLAGSIZE];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL) {
        printf("Erreur: 'flag.txt' n'est pas dans votre directory.\n");
        exit(1);
    }

    fgets(buf, FLAGSIZE, f);
    printf("%s", buf);
    fclose(f);
}

void vulnerable_function() {
    char buf[BUFSIZE];
    printf("Tentez votre chance ?  : ");
    gets(buf);

    printf("La Chance vous sourit ?\n");
    if (strcmp(buf, "win") == 0) {
        printf("Bien jouer !\n");
        win();
    } else {
        printf("Mince, retentez votre chance.\n");
    }
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);

    vulnerable_function();

    return 0;
}