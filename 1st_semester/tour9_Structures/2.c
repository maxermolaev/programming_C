#include <stdio.h>
#include <string.h>

typedef struct Label_s {
    char name[16];
    int age;
} Label;

typedef struct NameStats_s {
    int cntTotal;
    int cntLong;
} NameStats;

typedef struct AgeStats_s {
    int cntTotal;
    int cntAdults;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) {
    oNames->cntTotal = 0;
    oNames->cntLong = 0;
    oAges->cntTotal = 0;
    oAges->cntAdults = 0;
    oAges->cntKids = 0;

    for (int i = 0; i < cnt; i++) {
        oNames->cntTotal++;
        if (strlen(arr[i].name) > 10) {
            oNames->cntLong++;
        }
        oAges->cntTotal++;
        if (arr[i].age >= 18) {
            oAges->cntAdults++;
        }
        if (arr[i].age < 14) {
            oAges->cntKids++;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Label labels[1001];

    for (int i = 0; i < N; i++) {
        scanf("%s %d let", labels[i].name, &labels[i].age);
    }

    NameStats nameStats;
    AgeStats ageStats;

    calcStats(labels, N, &nameStats, &ageStats);

    printf("names: total = %d\n", nameStats.cntTotal);
    printf("names: long = %d\n", nameStats.cntLong);
    printf("ages: total = %d\n", ageStats.cntTotal);
    printf("ages: adult = %d\n", ageStats.cntAdults);
    printf("ages: kid = %d\n", ageStats.cntKids);

    return 0;
}

