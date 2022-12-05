#include <stdio.h>

int getMax(int list[], int n) {
    int mx = list[0];
    int i;
    for (i = 1; i < n; i++)
        if (list[i] > mx)
            mx = list[i];
    return mx;
}

void countSort(int list[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(list[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(list[i] / exp) % 10] - 1] = list[i];
        count[(list[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        list[i] = output[i];
}

static void sort(void)
{
	int m = getMax(list, n);

    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(list, n, exp);
}
 
int main()
{
    return 0;
}
