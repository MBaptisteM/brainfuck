#include "brainfuck.h"

int main(int argc, char* argv[]){

    if (argc < 2)
        errx(EXIT_FAILURE, "not file entered");

    FILE *code_file = fopen(argv[1], "r");

    if (code_file == NULL){
        errx(EXIT_FAILURE, "file %s impossible to find", argv[1]);
    }

    char code[10000];
    if (fread(code, 1, 10000, code_file))
        errx(EXIT_FAILURE, "file %s impossible to read", argv[1]);
        
    char *actual_character = code;

    char memory[10000];
    char* head = memory;

    char* loop_stack[1000];
    int stack_size = 0;
    

    while (*actual_character != EOF){
        switch(*actual_character){
            case '+':
                (*head)++;
                break;
            case '-':
                (*head)--;
                break;
            case '>':
                head++;
                break;
            case '<':
                head--;
                break;
            case '[':
                if (*head != 0){
                    loop_stack[stack_size] = actual_character;
                    stack_size++;
                }
                else{
                    int count = 1;
                    while (count > 0){
                        actual_character++;
                        if (*actual_character == ']')
                            count--;
                        else if (*actual_character == '[')
                            count++;
                    }
                }
                break;
            case ']':
                stack_size--;
                actual_character = (loop_stack[stack_size] - 1);
                break;
            case '.':
                printf("%c", *head);
                break;
            case ',':
                char user_char;
                if (scanf("%c", &user_char))
                    errx(EXIT_FAILURE, "Imput impossible to read");
                *head = user_char;
                break;
            default:
                break;
        }
        actual_character++;
    }
    printf("\n");

    fclose(code_file);

    return EXIT_SUCCESS;
}