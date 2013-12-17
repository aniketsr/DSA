#include <memory.h>
#include <stdlib.h>
#include "stack.h"
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack* stack;

void tearDown(){
    free(stack->elements);
    free(stack);
}

typedef struct {
    int accNo;
    int balance;
} Account;

int areAccountsEqual(Account expected,Account actual){
        return expected.accNo == actual.accNo && expected.balance == actual.balance;
}


void test_creates_a_stack_of_3 (){
        stack = create(3);
        ASSERT(3 == stack->length);
        ASSERT(0 == stack->top);
};

void test_adds_the_integers_to_stack(){
        int* num = malloc(sizeof(int));
        *num = 2;
        stack = create(1);
        push(stack, num);
        ASSERT(2 == **(int**)stack->elements);
        ASSERT(1 == stack->top);
        ASSERT(1 == stack->length);
}

void test_adds_the_double_to_yhe_stack(){
        double *nums = malloc(sizeof(double)*2);
        nums[0] = 34.0;nums[1] = 11.5;
        stack = create(2);
        push(stack, &nums[0]);
        push(stack, &nums[1]);
        ASSERT(34.0 == **(double**)getElement(stack, 0));
        ASSERT(11.5 == **(double**)getElement(stack, 1));
        ASSERT(2 == stack->top && 2 == stack->length);
}

void test_adds_Strings_to_stack(){
        String* names = malloc(sizeof(String)*2);
        strcpy(names[0], "ram");
        strcpy(names[1], "sham");
        stack = create(2);
        push(stack, &names[0]);
        push(stack, &names[1]);
        ASSERT(0 == strcmp(names[0], *(char**)getElement(stack, 0)));
        ASSERT(0 == strcmp(names[1], *(char**)getElement(stack, 1)));
}

void test_doubles_the_length_of_stack_when_stack_is_full(){
    int nums[3];
    int result;
    nums[0] = 10;nums[1] = 2;nums[2] = 1;
    stack = create(3);
    push(stack, &nums[0]);
    push(stack, &nums[2]);
    push(stack, &nums[1]);
    ASSERT(3 == stack->length);
    ASSERT(push(stack, &nums[0]));
    ASSERT(6 == stack->length);
    ASSERT(4 == stack->top);
    ASSERT(10 == **(int**)getElement(stack, 3));
}


void test_pops_the_top_element_from_the_stack(){
    int nums[4];
    int* result;
    nums[0] = 10;nums[1] = 42;nums[2] = 15;nums[3] = 25;
    stack = create(3);
    push(stack, &nums[0]);
    push(stack, &nums[2]);
    push(stack, &nums[1]);
    push(stack, &nums[3]);
    result = pop(stack);
    ASSERT(25 == *result);
    ASSERT(3 == stack->top);
};

void test_pops_the_top_element_from_the_stack_Strings(){
    String nums[2];
    char* result;
    strcpy(nums[0], "raman");
    strcpy(nums[1], "sinu");
    stack = create(2);
    push(stack, &nums[0]);
    push(stack, &nums[1]);
    result = pop(stack);
    ASSERT(0 == strcmp("sinu", result));
    ASSERT(1 == stack->top);
};

void test_remove_on_empty_stack(){
        void* result;
        stack = create(5);
        result = pop(stack);
        ASSERT(NULL == result);
}