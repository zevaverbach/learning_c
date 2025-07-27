#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 512

int main()
{
    const char filename[] = "pithy.txt";
    FILE *fp;
    char buffer[BSIZE];
    char *line_of_text, *entry;
    int items;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    while (!feof(fp))
    {
        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
        if (entry == NULL)
        {
            fprintf(stderr, "Unable to allocate memory\n");
            exit(1);
        }
        line_of_text = fgets(buffer, BSIZE, fp);
        if (line_of_text == NULL)
            break;
        strlcpy(entry, buffer, BSIZE);
        printf("%d: %s", items, entry);
        items++;
    }

    fclose(fp);

    return 0;
}
