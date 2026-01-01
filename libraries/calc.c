/*/number.c*/

enum Operation{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	UNDEFINED,
};
//Works, but it actually edits what it receives, so it must be editable, which can be made using the array.
struct option_float process(char* arr, char** ptr, char* changed_ptr){
	u32 layer = 0;
	float result = 0;
	*changed_ptr = false;
	enum Operation op = UNDEFINED;
	for(u32 i = 0; arr[i] != '\0'; i++){
		switch(arr[i]){
			case ' ':
				break;
			case '+':
				op = ADD;
				break;
			case '-':
				op = SUBTRACT;
				break;
			case '*':
				op = MULTIPLY;
				break;
			case '/':
				op = DIVIDE;
				break;
			case ')':
				*ptr = &arr[i];
				*changed_ptr = true;
				break;												
			case '(':
				bool* changed_ptr;
				char** to_write_to;
				struct option_float opt = process_float(&arr[i], to_write_to, changed_ptr);
				if(*changed_ptr){
					i = *to_write_to;
				}
				if(opt.unactivated == 1){
					opt.unactivated = 1;
					return opt;
				}
				arr[i] = character;
				switch(op){
					case UNDEFINED:
						result = the_number;
						break;
					case ADD:
						result += the_number;
						break;					
					case SUBTRACT:
						result -= the_number;					
						break;
					case MULTIPLY:
						result *= the_number;					
						break;
					case DIVIDE:
						result /= the_number;
						break;
				}
				break;
			case ')':
				if(layer == 0){
					struct option_float flt;
					flt.unactivated = 0;
					flt.number = result;
					return flt;
				}
				layer -= 1;
				break;
			default:
				char* start = arr + i;
				while ((arr[i] == '.') || ((arr[i] >= '0') && (arr[i] <= '9'))){
					i++;
				}
				char character = arr[i];
				arr[i] = '\0';
				struct option_float opt = process_float(start);
				struct option_float flt;
				if(opt.unactivated == 1){
					flt.unactivated = 1;
					return flt;
				}
				arr[i] = character;
				float the_number = opt.number;
				if(op == UNDEFINED){
					result = the_number;
				}else if(op == ADD){
					result += the_number;
				}else if(op == SUBTRACT){
					result -= the_number;
				}else if(op == MULTIPLY){
					result *= the_number;
				}else if(op == DIVIDE){
					result /= the_number;
				}
				break;				
				
		}
	}
	struct option_float flt;
	flt.unactivated = 0;
	flt.number = result;
	return flt;
}
