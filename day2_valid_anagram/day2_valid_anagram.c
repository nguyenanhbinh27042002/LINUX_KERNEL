#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LEN_MAX 10000
unsigned char s[LEN_MAX];
unsigned char t[LEN_MAX];

bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t)) return false;

    int count[256] = {0};

    for (int i = 0; s[i] != '\0'; i++)
        count[(unsigned char)s[i]]++;

    for (int j = 0; t[j] != '\0'; j++)
    {
        count[(unsigned char)t[j]]--;
        if (count[(unsigned char)t[j]] < 0)
            return false;
    }

    return true;
}

int main(void)
{
    printf("Enter two strings s and t:\n");
    scanf("%s",s);
    scanf("%s",t);
    bool result = isAnagram(s, t);

    if (result)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
