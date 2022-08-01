# include <stdio.h>
# include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* first, * second;
    char c1;
    char c2;

    if (argc != 3)
        printf("The argument is too less.\n");
    if ((first = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Can not open the file: %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((second = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Can not open the file: %s", argv[2]);
        exit(EXIT_FAILURE);
    }


    do
    {
        c1 = fgetc(first);
        if (c1 != '\n' && c1 != EOF)
            putchar(c1);
        else
        {
            putchar('\n');
            while ((c2 = fgetc(second)) != EOF)
            {
                if (c2 != '\n')
                    putchar(c2);
                else if (c1 == EOF)
                    putchar(c2);
                else 
                    break;
            }            
            putchar('\n');
        }
    } while (c1 != EOF);

    return 0;

}