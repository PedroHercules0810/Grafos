#include <stdio.h>
#include <stdlib.h>
int main()
{

    FILE *f;
    char *teste = (char*)malloc(sizeof(char));
    char *teste2 = (char*)malloc(sizeof(char));
    f = fopen("arch.csv", "r");
    if (f == NULL)
    {
        printf("erro ao abrir o arquivo");
        return 1;
    }

    while(fscanf(f,"%99[^;];%99[^;];%*[^\n]",teste,teste2) == 2){
    printf("%s;", teste);
    printf("%s", teste2);

    }
    


    fclose(f);

    return 0;
}