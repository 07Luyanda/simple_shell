#include "shell.h"

int is_interactive(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

int is_delimiter(char c, char *delim) {
    while (*delim) {
        if (*delim == c) {
            return 1;
        }
        delim++;
    }
    return 0;
}

int is_alpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int custom_atoi(char *s) {
    int i = 0, sign = 1, flag = 0, output = 0;
    unsigned int result = 0;

    while (s[i] != '\0' && flag != 2) {
        if (s[i] == '-') {
            sign *= -1;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        } else if (flag == 1) {
            flag = 2;
        }

        i++;
    }

    output = (sign == -1) ? -result : result;
    return output;
}
