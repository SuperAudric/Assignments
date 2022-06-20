#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
int score = 0;
void end_game(int intsig)
{
	printf("\nFinalscore: %i\n", score);
	exit(0);
}
int catch_signal(int intsig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(intsig, &action, NULL);
}
void times_up(int intsig)
{
	puts("\nTIME'S UP!");
	raise(SIGINT);
}
void error(char* msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}
void testPalindrome(int len)
{
	char s[len];
	int i, j;
	printf("Enter a word of length %d:\n", len);
	fflush(stdin);
	gets(s);
	for (i = 0, j = len - 1;i < j;i++, j--) {
		if (s[i] != s[j]) {
			raise(SIGINT);
			break;
		}
	}
}
int main()
{
	catch_signal(SIGALRM, times_up);
	catch_signal(SIGINT, end_game);
	for (int i = 3;i < 20;i++)
	{
		alarm(i * 10 - 10);
		testPalindrome(i);
		score++;
	}
	return 0;
}