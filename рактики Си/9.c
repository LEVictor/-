#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int cicle(int);
int sortArr(int[], int);
int findMaxNumInColsAndRows(int[ROWS][COLS]);
int SquareNumInArr(int *, int[]);

double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);


int main() {
    system("chcp 65001");
    int k;
    double n1;
    double n2;
    char operator;
    double result;

    int (*num)(int) = cicle;
    num(k);

    int numbers[] = {5, 12, 7, 3, 9, 25, 8, 10, 15};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int (*num2)(int[], int) = sortArr;
    num2(numbers, n);


    int array[ROWS][COLS] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    int (*num3)(int[ROWS][COLS]) = findMaxNumInColsAndRows;
    num3(array);

    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int *originalArray = (int *) malloc(size * sizeof(int));

    int (*num4)(int *, int[]) = SquareNumInArr;
    num4(&size, originalArray);



    double (*add_ptr)(double, double) = add;
    double (*subtract_ptr)(double, double) = subtract;
    double (*multiply_ptr)(double, double) = multiply;
    double (*divide_ptr)(double, double) = divide;

    double (*operations[4])(double, double) = { add_ptr, subtract_ptr, multiply_ptr, divide_ptr };
    char operators[4] = { '+', '-', '*', '/' }; // Соответствующие операторы

    printf("Введите выражение (например, 3.5 + 2.2): ");
    scanf("%lf %c %lf", &n1, &operator, &n2);

    for (int i = 0; i < 4; i++) {
        if (operator == operators[i]) {
            result = operations[i](n1, n2);
            printf("Результат: %lf\n", result);
            return 0;
        }
    }

    printf("Ошибка: Неизвестный оператор!\n");

    return 0;
}


int findMaxNumInColsAndRows(int array[ROWS][COLS]) {


    int rowMax[ROWS] = {0};
    int colMax[COLS] = {0};


    for (int i = 0; i < ROWS; i++) {
        int maxRowValue = array[i][0];

        for (int j = 1; j < COLS; j++) {
            if (array[i][j] > maxRowValue) {
                maxRowValue = array[i][j];
            }
        }

        rowMax[i] = maxRowValue;
    }


    for (int j = 0; j < COLS; j++) {
        int maxColValue = array[0][j];

        for (int i = 1; i < ROWS; i++) {
            if (array[i][j] > maxColValue) {
                maxColValue = array[i][j];
            }
        }

        colMax[j] = maxColValue;
    }


    printf("Максимальные значения в каждой строке:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Строка %d: %d\n", i, rowMax[i]);
    }


    printf("\nМаксимальные значения в каждом столбце:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Столбец %d: %d\n", j, colMax[j]);
    }

    return 0;
}



int SquareNumInArr(int *size , int originalArray[]) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < *size; ++i) {
        scanf("%d", &originalArray[i]);
    }

    int *squaresArray = (int *)malloc(*size * sizeof(int));

    int squaresIndex = 0;
    for (int i = 0; i < *size; ++i) {
        if (originalArray[i] % 2 == 0) {
            squaresArray[squaresIndex++] = originalArray[i] * originalArray[i];
        }
    }

    printf("Массив квадратов четных чисел:\n");
    for (int i = 0; i < squaresIndex; ++i) {
        printf("%d ", squaresArray[i]);
    }

    free(originalArray);
    free(squaresArray);



    return 0;
}




int cicle(int k){
    while (k!=4)
    {
        printf("введите число 4 чтобы остановить цикл");
        scanf("%d", &k);

    }
    return 0;
}

int sortArr(int numbers[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (numbers[j] < numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
}

    printf("\nТоп 3 самых больших чисел: %d, %d, %d\n", numbers[0], numbers[1], numbers[2]);

    return 0;
}




double add(double a, double b) {
    return a + b;
}


double subtract(double a, double b) {
    return a - b;
}


double multiply(double a, double b) {
    return a * b;
}


double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Ошибка: Деление на ноль!\n");
        return 0;
    }
}
