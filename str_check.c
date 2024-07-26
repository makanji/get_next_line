#include <stdlib.h>
#include <stdio.h>

char    *ft_strchr(const char *str, int char_checked )
{
    char *string;

    string = (char *)str;
    while (*string != '\0')
    {
        if (*string == (char)char_checked)
            return (string);
        string++;
    }
    if (char_checked == '\0')
        return (string);
    return (NULL);
}

int main()
{
    const char *str = "hello, foxy";
    int checked = 'f';
    char *result = ft_strchr(str, checked);
}

int main() {
    const char *testString = "Hello, World!";
    char ch = 'W';
    char *result = ft_strchr(testString, ch);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", ch, result - testString);
    } else {
        printf("Character '%c' not found.\n", ch);
    }

    // Test for null terminator
    result = ft_strchr(testString, '\0');
    if (result != NULL) {
        printf("Null terminator found at position: %ld\n", result - testString);
    }

    return 0;
}
