#include <stdio.h>
#include <stdlib.h>

void get_stats(const int *tab, int n, int *min, int *max, double *avg)
{
    int sum = 0;

    *min = tab[0];
    *max = tab[0];

    for (int i = 0; i < n; i++) {
        if (tab[i] < *min) {
            *min = tab[i];
        }
        if (tab[i] > *max) {
            *max = tab[i];
        }
        sum += tab[i];
    }

    *avg = (double)sum / n;
}

int main(void)
{
    int n;
    int *tab = NULL;
    int min, max;
    double avg;

    printf("Podaj liczbe elementow: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Blad: n musi byc > 0\n");
        return 1;
    }

    tab = (int *)malloc(n * sizeof(int));
    if (tab == NULL) {
        printf("Blad alokacji pamieci\n");
        return 1;
    }

    printf("Podaj %d liczb:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    get_stats(tab, n, &min, &max, &avg);

    printf("min=%d max=%d avg=%.2f\n", min, max, avg);

    free(tab);
    tab = NULL;

    return 0;
}
