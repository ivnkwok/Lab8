#include "header.h"

int main(void) {
	//task1
	/*
	FILE* infile = fopen("input.txt", "r");
	int count = 0;
	int num = 0;
	int nums[1000];
	int j;
	//fill array
	for (count = 0; fscanf(infile, "%d", &num) != -1; count++)
	{
		nums[count] = num;
	}
	//reverse array
	j = count;
	for (int i = 0; i < count / 2; i++)
	{
		num = nums[i];
		nums[i] = nums[--j];
		nums[j] = num;
	}
	//print array
	for (int i = 0; i < count; i++)
	{
		printf("%d ", nums[i]);
	}
	*/

	/*
	//task2
	int nums[20];
	int nums2[101];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 101; i++)
	{
		nums2[i] = 0;
	}
	for (int i = 0; i < 20; i++)
	{
		nums[i] = rand() % 100;
		nums2[nums[i]]++;
	}
	*/

	//task3
	int word[] = { 'h', 'a', 'n', 'g', 'm', 'a', 'n' };
	char found[] = "_______";
	int len = 7;
	int first = 1;
	char guessed[26];
	char guess;
	int guesses = 0;
	int guessMax = 7;
	while (guesses <= guessMax) {
		printf("Guess count: %d/%d\n", guesses, guessMax);
		printf("Enter a letter to be guessed: \n");
		scanf(" %c", &guess);
		guess = toupper(guess);
		//if not guessed
		if (guessed[guess - 'A'] != guess) {
			guessed[guess - 'A'] = guess;
			first = 1;
			for (int i = 0; i < len; i++)
			{
				if (toupper(word[i]) == guess) {
					if (first == 1) {
						guesses--;
					}
					found[i] = guess;
					first = 0;
				}
			}
			printf(found);
			printf("\n");
			
		}
		//if guessed
		else if (guessed[guess-'A'] == guess) {
			printf("Already guessed\n");
			guesses--;
		}
		//if word found
		if (strchr(found, '_') == NULL) {
			printf("wow congratulations");
			break;
		}
		if (guesses == guessMax) {
			printf("You Lost\nWord: ");
			for (int i = 0; i < len; i++)
			{
				printf("%c", toupper(word[i]));
			}
			break;
		}
		guesses++;
	}
}