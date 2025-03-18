#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define K 1000000 
#define LEN 8 
struct record {
	int key;
	char word[LEN];
};

struct recordlist {
	struct record* records;
	int size;
	int power;
};

void create(struct recordlist* list) {
	list->power = 10;
	list->records = (struct record*)malloc(list->power * sizeof(struct record));
	list->size = 0;
}

void add(struct recordlist* list, int key, const char* word) {
	if (list->size == list->power) {
		list->power *= 2;
		list->records = (struct record*)realloc(list->records, list->power * sizeof(struct record));
	}
	list->records[list->size].key = key;
	strcpy(list->records[list->size].word, word);
	list->size++;
}

void my_free(struct recordlist* list) {
	free(list->records);
}

int main() {
	struct recordlist recs[K + 1];
	for (int i = 0; i <= K; i++) {
		create(&recs[i]);
	}
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int key;
		char word[LEN];
		scanf("%d %s", &key, word);
		add(&recs[key], key, word);
	}
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j < recs[i].size; j++) {
			printf("%d %s\n", recs[i].records[j].key, recs[i].records[j].word);
		}
		my_free(&recs[i]);
	}
	return 0;
}
