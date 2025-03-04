#include <stdio.h> 
 
typedef struct DateTime_s { 
    int year, month, day; 
    int hours, minutes, seconds; 
} DateTime; 
 
DateTime min(const DateTime *arr, int cnt) { 
    DateTime minDate = arr[0]; 
 
    for (int i = 1; i < cnt; i++) { 
        if (arr[i].year < minDate.year || 
            (arr[i].year == minDate.year && arr[i].month < minDate.month) || 
            (arr[i].year == minDate.year && arr[i].month == minDate.month && arr[i].day < minDate.day) || 
            (arr[i].year == minDate.year && arr[i].month == minDate.month && arr[i].day == minDate.day && arr[i].hours < minDate.hours) || 
            (arr[i].year == minDate.year && arr[i].month == minDate.month && arr[i].day == minDate.day && arr[i].hours == minDate.hours && arr[i].minutes < minDate.minutes) || 
            (arr[i].year == minDate.year && arr[i].month == minDate.month && arr[i].day == minDate.day && arr[i].hours == minDate.hours && arr[i].minutes == minDate.minutes && arr[i].seconds < minDate.seconds)) { 
            minDate = arr[i]; 
        } 
    } 
 
    return minDate; 
} 
 
int main() { 
    int N; 
    scanf("%d", &N); 
    DateTime dates[N]; 
 
    for (int i = 0; i < N; i++) { 
        scanf("%d %d %d %d %d %d", &dates[i].year, &dates[i].month, &dates[i].day, &dates[i].hours, &dates[i].minutes, &dates[i].seconds); 
    } 
 
    DateTime earliestDate = min(dates, N); 
    printf("%d %d %d %d %d %d\n", earliestDate.year, earliestDate.month, earliestDate.day, earliestDate.hours, earliestDate.minutes, earliestDate.seconds); 
 
    return 0; 
}

