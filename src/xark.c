#include "xark.h"

#include<stdio.h>
#include "../../XARK-CORE-MEMORY/src/xark_mem.c"

//struct XARK_MODULE{
//	
//}

struct XARK_MODULE * XARK_REGISTER_MODULE(unsigned char MODULE_HASH[20], int FUNCTIONS_LENGTH){
	//TODO Implement parameter checking here
	struct XARK_MODULE *module = malloc(sizeof(struct XARK_MODULE));//move allocation to XARK_MEM
	//strcpy(module->MODULE_HASH, MODULE_HASH);
	module->XARK_FUNCTION_ARRAY_POINTER = XARK_MEM_FUNCTION_ARRAY_ALLOC(FUNCTIONS_LENGTH);

	return module;
}

int XARK_REGISTER_FUNCTION(struct XARK_MODULE * module, int FUNC_INDEX, unsigned char FUNC_HASH[20], int FUNC_ADDR){
	//TODO parameter checking here!
	struct XARK_FUNCTION * xk_func = &module->XARK_FUNCTION_ARRAY_POINTER[FUNC_INDEX];

	xk_func->FUNCTION_ADDRESS = FUNC_ADDR;
	printf("function address: %d registerd at XARK_FUNCTION: %d\n", FUNC_ADDR, &module->XARK_FUNCTION_ARRAY_POINTER[FUNC_INDEX]);
}

//TESTS
int function_to_call(int x, int y){
	return x+y;
}

int function_to_call2(int x, int y, int z){
	return x+y;
}

int func(){
	int func_address = &function_to_call;
	printf("%d\n", func_address);

	int (*call_func)(int, int) = NULL;
      	call_func = func_address;
	int ret = (*call_func) (7,8);
	printf("%d\n", ret);

	func_address = &function_to_call2;
	printf("%d\n", func_address);

	//int (*call_func)(int, int) = NULL;
      	call_func = func_address;
	ret = (*call_func) (7,8);
	printf("%d\n", ret);	

	return 0;
}

int main(void){
	printf("Hello World\n");
	int number = 8;
	struct XARK_STACK *stack = XARK_STACK_PUSH(0, number);
	stack = XARK_STACK_PUSH(stack, number+1);
	stack =XARK_STACK_PUSH(stack, number+2);
	stack =XARK_STACK_PUSH(stack, number+3);

	printf("%d\n", stack->pointer);
	stack = XARK_STACK_POP(stack);
	printf("%d\n", stack->pointer);
	stack = XARK_STACK_POP(stack);
	printf("%d\n", stack->pointer);
	stack = XARK_STACK_POP(stack);

	func();
	struct XARK_MODULE * module = XARK_REGISTER_MODULE(NULL, 3);
	printf("Module address: %d\n", module);
	XARK_REGISTER_FUNCTION(module, 0, NULL, &main);
}



