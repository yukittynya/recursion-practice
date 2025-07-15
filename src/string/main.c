#include <stdio.h>
#include <stdbool.h>

int stringLength(char* str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + stringLength(++str);
    }
}

void reverseString(char* start, char* end) {
    if (start >= end) return;

    char temp = *start;
    *start = *end;
    *end = temp;

    reverseString(++start, --end);
}

bool isPalindrome(char* start, char* end) {
    if (start >= end) return true;

    if (*start != *end) {
        return false;
    }

    return isPalindrome(++start, --end);
}

int countChar(char* str, char target) {
    if (*str == '\0') {
        return 0;
    }

    if (*str == target) {
        return 1 + countChar(++str, target);
    } else {
        return countChar(++str, target);
    } 
}

int main(int argc, char *argv[]) {
    char test[] = "string nya :3";

    int len = stringLength(test);

    printf("stringLength(test): %d\n", len);

    reverseString(test, test + len - 1);
    printf("reverseString(test): %s\n", test);

    char palindrome[] = "rbobrbob";

    if (isPalindrome(palindrome, palindrome + stringLength(palindrome) - 1)) {
        printf("%s is a palindrome\n", palindrome);
    } else {
        printf("%s is not a palindrome\n", palindrome);
    }

    printf("countChar(palindrome, b): %d\n", countChar(palindrome, 'b'));
}
