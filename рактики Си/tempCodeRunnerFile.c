#include <wchar.h>
#include <stdio.h>
#include <wctype.h>

int main() {
    const wchar_t *text = L"I am thinking of re-covering my sofa";
    int count = 0;
    int length = wcslen(text);

    for (int i = 1; i < length - 1; i++) {  // Начинаем с 1, чтобы избежать ошибки доступа по индексу -1
        if (text[i] == L'-' && iswalpha(text[i - 1]) && iswalpha(text[i + 1])) {
            count++;
        }
    }

    int result = count;

    wprintf(L"Number of pairs of words with the symbol '-': %d\n", result);

    // Чтение строки из файла
    FILE *file = fopen("input.txt", "r");
    if (file) {
        wchar_t buffer[256];
        while (fgetws(buffer, sizeof(buffer)/sizeof(buffer[0]), file)) {
            // Обработка строки из файла (примерно так же, как выше)
            int file_length = wcslen(buffer);
            for (int i = 1; i < file_length - 1; i++) {
                if (buffer[i] == L'-' && iswalpha(buffer[i - 1]) && iswalpha(buffer[i + 1])) {
                    count++;
                }
            }
        }
        fclose(file);
        wprintf(L"Total number of pairs from file with the symbol '-': %d\n", count);
    } else {
        wprintf(L"Failed to open the file.\n");
    }

    return 0;
}
