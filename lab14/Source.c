#define N 100
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void task1(double* ptr_array, int size);
double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
void task2(double* ptr_array, int size);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	double array[N];
	int size;

	printf("Введите размер массива (до %d): ", N);
	scanf("%d", &size);
	printf("\n");

	task1(array, size);
	task2(array, size);

	return 0;
}

void task1(double* ptr_array, int size) {

	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	calc_elements(ptr_array, size);
	put_elements(ptr_array, size);

}

double* full_elements(double* ptr_array, int size) {

	double start = 1, end = 3;
	double step = (end - start) / (size - 1.);

	for (int i = 0; i < size; i++) {
		*(ptr_array + i) = start * start * start - 4 * start * start + 2;
		start += step;
	}

	return ptr_array;
}

int put_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {
		printf("%f\n", *(ptr_array + i));
	}

	return 0;
}

double* calc_elements(double* ptr_array, int n) {

	for (int i = 0; i < n; i++) {
		*(ptr_array + i) = *(ptr_array + i) * -1;
	}

	return ptr_array;
}

void task2(double* ptr_array, int size) {

	int begin, end;
	double element;

	printf("Для поиска суммы введите элемент, с которого считать сумму, и элемент, до которого считается сумма: ");
	scanf("%d %d", &begin, &end);
	printf("\n");
	printf("Введите элемент, который нужно найти в массиве: ");
	scanf("%lf", &element);
	printf("\n");

	printf("Сумма элементов массива от %d до %d: %f\n", begin, end, sum_elements(ptr_array, begin, end));
	printf("Индекс элемента %f в массиве: %d\n", element, find_element(ptr_array, size, element));
}

double sum_elements(double* ptr_array, int begin, int end) {

	double res = 0;

	for (int i = begin; i <= end; i++)  res += *(ptr_array + i);

	return res;
}

int find_element(double* ptr_array, int n, double element) {

	int i = 0;

	while (i < n) {

		if (*(ptr_array + i) == element) return i;

		i++;
	}

	return -1;
}