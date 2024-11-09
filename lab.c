#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    FILE *file;
    char ch;
    int characters=0;
    int lines=1;
    int numbers=0;
    int vowels=0;
    int consonants=0;
    int words=0;
    file=fopen("sample.c","r");
    ch=fgetc(file);
    if (file == NULL) 
    {
        printf("Error opening file\n");
        return 1;
    }
    while(ch!=EOF)
    {
        characters++;
        if(ch==' '||ch=='\t'||ch=='\n'||ch=='\0')
        {
            words++;
        }
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            vowels++;
        }
        if(ch=='\n'||ch=='\0')
        {
            lines++;
        }
        if(ch>48 && ch<57)
        {
            numbers++;
        }
        if (ch==';'||ch=='{'||ch=='}') 
        {
            lines++;
            words++;
        }
        if(characters>0)
        {
            words++;
            lines++;
        }
    }
    consonants=characters-vowels;
    printf("\n");
    printf("characters:%d",characters);
    printf("numbers:%d",numbers);
    printf("vowels:%d",vowels);
    printf("consonants:%d",consonants);
    printf("words:%d",words);
    printf("lines:%d",lines);
    fclose(file);
    return 0;
}