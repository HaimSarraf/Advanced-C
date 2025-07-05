#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    time_t calendar_start = time(NULL);
    clock_t cpu_start = clock();
    int count = 0;

    const long long iteration = 1000000000LL ;
    char answer = 'y';
    double x = 0.0;

    printf("Initial clock time = %lld\nInitial calendar time = %lld", (long long)cpu_start, (long long)calendar_start);

    while (tolower(answer) == 'y') {
        for (long long i =0LL; i<iteration  ; ++i) {
            x = sqrt(3.1415);
        }
        
        printf("%lld square roots completed.\n ", iteration*(++count));
        printf("Do you want to run some more (y/n)?\n");
        scanf("\n%c", &answer);
    }

    clock_t cpu_end = clock();
    time_t calendar_end = time(NULL);

    printf("Final clock time = %lld Final calendar time = %lld\n", (long long)cpu_end, (long long)calendar_end);
    printf("CPU time for %lld iterations is %.2lf seconds\n", iteration*count, (double)(cpu_end-cpu_start)/CLOCKS_PER_SEC);
    printf("Elapsed calendar time to execute the program is %.2lf seconds\n",  difftime(calendar_end, calendar_start)); 

    return 0;
}