#include <stdio.h>
#include <stdlib.h>

struct node {
	int val, len;
	struct node *next;
};

void lis(int *v, int len)
{
	int i;
	int l;
	struct node *p;
	struct node *n;
	
	l = len;
	n = calloc(len, sizeof *n);
	for (i = 0; i < len; i++)
		n[i].val = v[i];

	for (l = len; i--; ) 
	{
		// find longest chain that can follow n[i]
		for (p = n + i; p++ < n + len; ) {
			if (p->val > n[i].val && p->len >= n[i].len)
			{
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}

	// find longest chain
	for (i = 0, p = n; i < len; i++)
		if (n[i].len > p->len) p = n + i;

	do printf(" %d", p->val); while ((p = p->next));
	putchar('\n');

	free(n);
}

int main(void)
{
	int y[] = {1, 9, 3, 2, 4, 6, 7, 5, 1, 5, 13, 8, 9, 14, 10, 11, 12, 40, 3, 45, 57, 90, 60, 15, 99};

	lis(y, sizeof(y) / sizeof(int));
	// system("leaks a.out");
	return 0;
}
