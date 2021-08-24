#include<stdio.h>    
#include<stdlib.h>  
#include<math.h>
#pragma warning(disable : 4996);
void print_binary(unsigned int number)
{
	if (number >> 1) {
		print_binary(number >> 1);
	}
	putc((number % 2) ? '1' : '0', stdout);
}

unsigned int task1(unsigned int val1)
{
	int digit;
	unsigned int val2 = 0, temp;
	unsigned int  j = 0;


	while (val1 != 0)
	{
		// extracting the last digit of input number
		digit = val1 % 10;
		val1 /= 10;
		// moving the digit to the correct position J bits left
		temp = digit * (int)pow(2, j);
		//increasing J by 4 to put the next digit into right place
		j += 4;
		//storing the result into the output
		val2 += temp;
	}
	return val2;
}

int main() {
	unsigned int val1,val2;
	printf("enter number:\n");
	scanf("%d", &val1);
	//supposing that the input is valid
	val2 = task1(val1);
	printf("result is : ");
	print_binary(val2);
}

