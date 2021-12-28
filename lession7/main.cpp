
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    char data;
} Node;

typedef struct
{
    Node *head;
    unsigned int size;
} Stack;

void init(Stack *list)
{
    list->head = NULL;
    list->size = 0;
}

bool push(Stack *stack, char data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "Stack overflow!\n");
        return false;
    }
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
    return true;
}

char pop(Stack *list)
{
    char data;
    Node *tmp;

    if (list->size == 0)
        return -1;
    data = list->head->data;
    tmp = list->head;
    list->size--;
    if (list->size == 0)
    {
        list->head = NULL;
    }
    else
    {
        list->head = list->head->next;
    }
    free(tmp);
    return data;
}

void freeList(Stack *list)
{
    Node *tmp;

    while (list->size > 0)
    {
        tmp = list->head;
        list->size--;
        if (list->size > 0)
            list->head = list->head->next;
        free(tmp);
    }
    free(list);
}

char corrOpenBracket(char bracket)
{
    switch (bracket)
    {
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    }
    return '\0';
}

int isBracketsBalanced(char *string)
{
    char c, open_bracket;
    Stack *bracket_stack = (Stack *)malloc(sizeof(Stack));

    for (int i = 0; (c = string[i]) != '\0'; i++)
    {
        switch (c)
        {
        case '(':
        case '[':
        case '{':
            if (!push(bracket_stack, c))
                return 0;
            break;
        case ')':
        case ']':
        case '}':
            open_bracket = pop(bracket_stack);
            if (open_bracket != '\0' && open_bracket == corrOpenBracket(c))
                continue;
            else
                return 0;
        }
    }
    if (bracket_stack->size != 0)
        return 0;
    freeList(bracket_stack);
    return 1;
}

void printLinkedList(Stack *list)
{
    int list_size = list->size;
    Node *current_node = list->head;

    while (list_size > 0)
    {
        printf("[%c]", current_node->data);
        list_size--;
        if (list_size > 0)
            current_node = current_node->next;
    }
    printf("\n");
}

int copyLinkedList(Stack *dest, Stack *src)
{
    int src_list_size = src->size;
    Node *src_current_node = src->head;
    Node *dest_current_node = dest->head;

    while (src_list_size > 0)
    {
        Node *dest_new_node = (Node *)malloc(sizeof(Node));
        if (dest_new_node == NULL)
            return 0;
        dest_new_node->data = src_current_node->data;
        dest_new_node->next = NULL;
        if (dest->size == 0)
        {
            dest->head = dest_new_node;
        }
        else
        {
            dest_current_node->next = dest_new_node;
        }
        dest_current_node = dest_new_node;
        dest->size++;
        src_list_size--;
        if (src_list_size > 0)
            src_current_node = src_current_node->next;
    }
    return 1;
}

int isListSorted(Stack *list)
{
    int list_size = list->size;
    Node *current_node = list->head;
    char max_val;

    while (list_size > 0)
    {
        if (current_node == list->head)
            max_val = current_node->data;
        if (current_node->data >= max_val)
        {
            max_val = current_node->data;
        }
        else
        {
            return 0;
        }
        list_size--;
        if (list_size > 0)
            current_node = current_node->next;
    }
    return 1;
}

int main()
{
    //первое задание
    char *test_strings[] = {"()", "([])()", "{}()", "([{}])", ")(", "())({)", "(", "]})", "([(])", "(2+(2*))", "[2/{5*(4+7)}]", NULL};

    printf("Первое задание:\n");

    for (int i = 0; test_strings[i] != NULL; i++)
    {

        printf("\t%s: скобки в %s правильной последовательности!\n", test_strings[i],
               isBracketsBalanced(test_strings[i]) ? "\b" : "не");
    }

    // второе задание
    Stack *list = (Stack *)malloc(sizeof(Stack));
    Stack *list_copy = (Stack *)malloc(sizeof(Stack));

    printf("\n2. Копирование односвязного списка:\n");

    init(list);
    push(list, 't');
    push(list, 's');
    push(list, 'e');
    push(list, 't');

    init(list_copy);
    if (!copyLinkedList(list_copy, list))
    {
        fprintf(stderr, "Ошибка!\n");
        return 1;
    }

    printf("Исхлодник:\n\t");
    printLinkedList(list);

    printf("Копия:\n\t");
    printLinkedList(list_copy);

    freeList(list);
    freeList(list_copy);

    // 3. Проверка отсортированности связного списка
    Stack *sorted_list = (Stack *)malloc(sizeof(Stack));
    Stack *unsorted_list = (Stack *)malloc(sizeof(Stack));
    Stack *test_lists[] = {sorted_list, unsorted_list};

    printf("\n3. Проверка отсортированности связного списка:\n");

    init(test_lists[0]);
    push(test_lists[0], 'd');
    push(test_lists[0], 'c');
    push(test_lists[0], 'b');
    push(test_lists[0], 'a');

    init(test_lists[1]);
    push(test_lists[1], 'i');
    push(test_lists[1], 'u');
    push(test_lists[1], 'y');
    push(test_lists[1], 'r');

    for (int i = 0; i < 2; i++)
    {
        printLinkedList(test_lists[i]);
        int isSorted = isListSorted(test_lists[i]);
        if (isSorted)
        {
            printf("\tСписок  отсортирован\n");
        }
        else
        {
            printf("\tСписок не  отсортирован\n");
        }
        freeList(test_lists[i]);
    }

    return 0;
}
