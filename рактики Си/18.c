#include <wchar.h>
#include <stdio.h>
#include <wctype.h>

int main() {
    wchar_t text[256];  // Buffer to hold the input text
    int count = 0;

    wprintf(L"Please enter a line of text: ");
    if (fgetws(text, 256, stdin) == NULL) {
        wprintf(L"Failed to read input\n");
        return 1;
    }

    size_t length = wcslen(text);  // Use size_t for length

    for (size_t i = 1; i < length - 1; i++) {  // Use size_t for the loop index
        if (text[i] == L'-' && iswalpha(text[i - 1]) && iswalpha(text[i + 1])) {
            count++;
        }
    }

    // Open the output file for writing
    FILE *file = fopen("output.txt", "w");
    if (file) {
        fwprintf(file, L"Number of pairs of words with the symbol '-': %d\n", count);
        fclose(file);
    } else {
        wprintf(L"Failed to open output file\n");
        return 1;
    }

    return 0;
}
