#include<stdio.h>
struct student
{
	char name[100];
	int scores[100];
	float avg;
	char grade;
};
typedef struct student Student;

struct gradebook
{
	int totalStudents;
	int totalScores;
	char courseName[100];
	float weight[100];
	Student student[100];
};
typedef struct gradebook Gradebook;

Student input_one_student(int n)
{
	Student s;
	scanf("%s",s.name);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s.scores[i]);
	}
	return s;
}
Gradebook input_n_student()
{
	Gradebook g;
	scanf("\n");
	scanf("%[^\n]%*c",g.courseName);
	scanf("%d %d",&g.totalStudents,&g.totalScores);
	for(int i=0;i<g.totalScores;i++)
	{
		scanf("%f",&g.weight[i]);
	}
    for(int i=0;i<g.totalStudents;i++)
	{
		g.student[i]=input_one_student(g.totalScores);
	}
	return g;
}
int input_n_gradebooks(Gradebook G[])
{
	int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
	    G[i]=input_n_student();
    }
    return n;
}
Student compute_grade_one_student(Gradebook g,Student s)
{
    float tWeight=0.0;
    for(int i=0;i<g.totalScores;i++)
    {
	    s.avg+=g.weight[i]*s.scores[i];
        tWeight+=g.weight[i];
    }
    if(s.avg < 100*g.totalScores)
	    s.avg/=tWeight;

    if(s.avg <=100 && s.avg>=90)
    	s.grade='A';
    else if(s.avg < 90 && s.avg>=80)
    	s.grade='B';
    else if(s.avg <80 && s.avg>=70)
        s.grade='C';
    else if(s.avg <70 && s.avg>=60)
	    s.grade='D';
    else
	    s.grade='F';
    return s;
}
void compute_grade_n_students(int n,Gradebook G[])
{
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<G[i].totalStudents;j++)
		{
			G[i].student[j]=compute_grade_one_student(G[i],G[i].student[j]);
		}
    }
}
void print_grade_one_student(Student s)
{
	printf("%s \t",s.name);
	printf("%.2f %c\n",s.avg,s.grade);
}
void print_grade_n_students(int n,Gradebook G[])
{
	for(int i=0;i<n;i++)
    {	
        puts(G[i].courseName);
        for(int j=0;j<G[i].totalStudents;j++)
		{
			print_grade_one_student(G[i].student[j]);
		}
	printf("\n");
	}
}
int main()
{
    Gradebook G[100];
    int n=input_n_gradebooks(G);
    compute_grade_n_students(n,G);
    print_grade_n_students(n,G);
}
