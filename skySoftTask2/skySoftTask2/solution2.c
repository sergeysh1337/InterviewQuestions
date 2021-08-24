#include<stdio.h>    
#include<stdlib.h>  
#include<math.h>
#pragma warning(disable : 4996);



unsigned int task2(unsigned int val1)
{
	int digit;
	unsigned int val2 = 0, temp;
	unsigned int  i= 1;
	while( val1 != 0 )
	{
		// extracting the last hex digit of input number
		digit = val1 % 16;
		val1 /= 16;
		// moving the digit to the correct position J digits left
		temp = digit * i;
		//multiple J by 10 to put the next digit into right place
		i *= 10;
		//storing the result into the output
		val2 += temp;
	}
	return val2;
}

int main() {
	unsigned int val1, val2;
	printf("enter number:\n");
	scanf("%d", &val1);
	//supposing that the input is valid
	val2 = task2(val1);
	printf("res is : %d", val2);

}