#include <stdio.h>
#include <time.h>
  int count_vowels(char *str);

 int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    clock_t start_time = clock();
    int vowel_count = count_vowels(str);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Number of vowels: %d\n", vowel_count);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}

int count_vowels(char *str) {
    int vowels = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels++;
        }
    }
    return vowels;
}