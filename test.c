
#include <stdio.h>
void	shell_clear()
{
	
    printf("\033[H");// 커서를 터미널의 시작 위치로 이동
	printf("\033[B");// 커서를 내림
    printf("\033[K");// 현재 줄을 지움
	printf("\033[B");// 커서를 내림
    printf("\033[K");// 현재 줄을 지움
	printf("\033[B");// 커서를 내림
    printf("\033[K");// 현재 줄을 지움
	printf("\033[B");// 커서를 내림
    printf("\033[K");// 현재 줄을 지움
    
}
#include <unistd.h>
int main()
{
	printf("1\n");
	printf("1\n");
	printf("1\n");
	sleep(1);
	printf("\033[A");
	printf("\033[K");
}