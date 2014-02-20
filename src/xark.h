#ifndef XARK_H /* IF XARK_H */
#define XARK_H

struct XARK_FUNCTION {
	unsigned char FUNCTION_HASH[20];//TODO add compile flag for low-memory version without SHA-1 hashes
	int FUNCTION_ADDRESS;//Address of the function this XARK_FUNCTION struct represents
} XARK_FUNCTION;

struct XARK_MODULE {
	unsigned char MODULE_HASH[20];
	struct XARK_FUNCTION* XARK_FUNCTION_ARRAY_POINTER;//pointer to the first element of the array of XARK_FUNCTION structs
	int XARK_FUNCTION_ARRAY_LENGTH;//Length of array pointed to by XARK_MODULE->XARK_FUNCTION_ARRAY_ADDRESS
	//pointer to array of XARK_FUNCTION structs
} XARK_MODULE;


struct XARK_MODULE * XARK_REGISTER_MODULE(unsigned char MODULE_HASH[20], int FUNCTIONS_LENGTH);
//XARK_REGISTER_MODULE(unsigned char MODULE_HASH[20], int FUNCTIONS_LENGTH);//MODULE_HASH SHA-1 checksum of module name, FUNCTIONS_LENGTH number of functions int this module

int XARK_REGISTER_FUNCTION(struct XARK_MODULE * module, int FUNC_INDEX, unsigned char FUNC_HASH[20], int FUNC_ADDR);

int XARK_PROXY(int FUNC_ADDR);

int XARK_GET_FUNCTION(unsigned char FUNC_HASH[20]);

#endif /* ENDIF XARK_H */
