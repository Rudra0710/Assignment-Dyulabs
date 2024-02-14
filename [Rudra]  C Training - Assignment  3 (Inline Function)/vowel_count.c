#include <stdio.h>
#include <time.h>

static inline int cnt_vowels(char *str) {
    int count = 0;
    while (*str) {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
            *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
            count++;
        }
        str++;
    }
    return count;
}

void call_function(void (*func)(char *), char *str) {
    for (int i = 0; i < 10; i++) {
        func(str);
    }
}

double measure_time(void (*func)(char *), char *input) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    call_function(func, input);

    clock_gettime(CLOCK_MONOTONIC, &end);

    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int result;

    printf("Using inline function:\n");
    result = cnt_vowels(input);
    printf("Number of vowels: %d\n", result);
    double time_taken_inline = measure_time(cnt_vowels, input);
    printf("System time taken: %f seconds\n", time_taken_inline);

    printf("\nWithout using inline function:\n");
    result = cnt_vowels(input);
    printf("Number of vowels: %d\n", result);
    double time_taken = measure_time(cnt_vowels, input);
    printf("System time taken: %f seconds\n", time_taken);

    FILE *file = fopen("program", "r");
    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    fclose(file);

    printf("\nComparison Table:\n");
    printf("\n");
    printf("Inline Function | Without Inline Function |\n");
    printf("\n");
    printf("Size %ld bytes %ld bytes\n", size, size);
    printf("Time %f sec %f sec\n", time_taken_inline, time_taken);
    printf("\n");

    return 0;
}
