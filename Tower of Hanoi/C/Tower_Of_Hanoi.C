#include<stdio.h>
#include<conio.h>

void towerofHanoi(int n, char source, char destination, char spare)
{
	if (n == 1)
	{
		printf("\nMove disk 1 from rod %c to rod %c.", source, destination);
		return;
	}

	towerofHanoi(n-1, source, spare, destination);
	{
		printf("\nMove disk %d from rod %c to rod %c.", n, source, destination);
	}

	towerofHanoi(n-1, spare, destination, source);
}

void main()
{
	int n;
	clrscr();

	printf("\nEnter the number of disks: ");
	scanf("%d",&n);

	printf("\nThe sequence of moving the disks are as: \n");
	towerofHanoi(n, 'A', 'C', 'B');
	getch();
}
