#include<stdio.h>
#include<string.h>
typedef struct worker
{
	char name[100];
	float wage;
	int mins;
	float hours;
	float gross;
} Worker;

typedef struct worker_mins
{
	char name[100];
	int visited;
	int mins;
} W_mins;

typedef struct record
{
	int m;
	int n;
} Record;

Worker input_one_worker()
{
	Worker w;
	scanf("%s", w.name);
	scanf("%f", &w.wage);
	return w;
}
W_mins input_one_worker_minutes()
{
	W_mins w;
	scanf("%s", w.name);
	scanf("%d", &w.mins);
	return w;
}
void input_n_worker(Record *R, Worker W[], W_mins M[])
{
	scanf("%d", &R->n);
	for (int i = 0; i < R->n; i++)
	{
		W[i] = input_one_worker();
	}
	scanf("%d", &R->m);
	for (int i = 0; i < R->m; i++)
	{
		M[i] = input_one_worker_minutes();
	}
}
void compute(Record R, Worker W[], W_mins M[])
{
	for (int i = 0; i < R.n; i++)
	{
		W[i].mins = 0;
		W[i].gross = 0;
	}
	for (int j = 0; j < R.m; j++)
	{
		M[j].visited = 0;
	}

	for (int i = 0; i < R.n; i++)
	{
		for (int j = 0; j < R.m; j++)
		{
			if (M[j].visited == 0 && strcmp(W[i].name, M[j].name) == 0)
			{
				W[i].mins += M[j].mins;
				M[j].visited = 1;
			}
		}
	}
	for (int i = 0; i < R.n; i++)
	{
		if (W[i].mins > 0)
		{
			float h = W[i].mins / 60.0;
			W[i].hours = h;
			if (h <= 40)
				W[i].gross = h * W[i].wage;
			else
				W[i].gross = 40 * W[i].wage + (h - 40) * 1.5 * W[i].wage;
		}

	}
}
void display(Record R, Worker W[])
{
	for (int i = 0; i < R.n; i++)
	{
		if (W[i].mins > 0)
			printf("%s: %.2f hours, $%.2f\n", W[i].name, W[i].hours, W[i].gross);
	}
}
int main()
{
	Record R;
	Worker W[100];
	W_mins M[100];
	input_n_worker(&R, W, M);
	compute(R, W, M);
	display(R, W);
	return 0;
}
