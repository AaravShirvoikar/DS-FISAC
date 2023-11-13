#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int count_invalid_html_tags(const char* input_string) {
    char stack[MAX_SIZE];
    int top = -1;
    int count = 0;
    
    int len = strlen(input_string);
    
    for (int i = 0; i < len; i++) {
        if (input_string[i] == '#') {
            break;
        }
        
        if (input_string[i] == '<') {
            if (input_string[i + 1] == '/') {
                if (top >= 0 && stack[top] == input_string[i + 2]) {
                    top--;
                } else {
                    count++;
                }
            } else {
                top++;
                stack[top] = input_string[i + 1];
            }
        }
    }
    
    count += (top + 1);

    return count;
}

int main() {
    char input[MAX_SIZE];
    
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  
    
    int output = count_invalid_html_tags(input);

    printf("Count = %d\n",output);

    return 0;
}
