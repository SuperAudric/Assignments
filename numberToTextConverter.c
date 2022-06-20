/* Program that counts spaces and new lines in an input. */

#include <stdio.h>

int main() {
	char tens[11][12] = {"", "Ten ", "Twenty ", "Thirty ", "Fourty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety ", "One Hundred"};
	char ones[10][6] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	char edgeCases[10][20] = { "Zero","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen" };
	printf("Insert number between 0 and 100\n");
	int yourNum;
	scanf("%i", &yourNum);
	if ((yourNum > 10 & yourNum < 20) | (yourNum == 0))
	{ /*deals with the edge cases of 0 and the teens*/
		int tempID = 0;
		if (yourNum != 0) {
			tempID = yourNum - 10;
		}
		printf("\n%s", edgeCases[tempID]);
	}
	else {
		printf("\n%s%s", tens[yourNum / 10], ones[yourNum % 10]);   /*Main logic*/
	}

  return 0;
}