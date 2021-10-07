#if 0
/*
��Դ��C��ָ���һ��
���ܣ�����ָ����λ�ã��Լ��ַ��������Դ�ӡָ��λ��֮����ַ���
example��
 0 3 10 12 -1 (˵����0�е���3�У���10���Լ���12���ַ������ᱻ��ӡ)
 input :Hello there , how are you?
 output:o ther how are
*/
#include<stdio.h>
#include<stdlib.h>N 
#include<string.h>
#define	MAX_COLS 20		/*���ܴ��������к�*/
#define MAX_INPUT 1000	/*ÿ�������е���󳤶�*/
int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input,
	int n_columns, int const columns[]);
int main(void) {
	int n_columns;		/*���д�����б��*/
	int colums[MAX_COLS];		/*��Ҫ���������*/
	char input[MAX_INPUT];		/*���������е�����*/
	char ouput[MAX_INPUT];		/*��������е�����*/
	/*
	��ȡ���б��
	*/
	n_columns = read_column_numbers( colums, MAX_COLS );
	/*
	��ȡ������ʹ�ӡʣ���������
	*/
	while (gets(input)!=NULL)		/*get()�������ܣ������뻺������ȡһ���ַ���������input��ָ��Ŀռ�*/
	{
		printf("Origina input: %s\n", input);		/*��ӡԭʼ������ֵ*/
		rearrange(ouput, input, n_columns, colums);
		printf("Rearranged line: %s\n", ouput);		/*��ӡָ��λ�ú���ַ���*/
	}
	return EXIT_SUCCESS;	/*���߲���ϵͳִ�гɹ�*/
}
	/*
	��ȡ�б�ţ���������涨��Χ�������
	*/
int read_column_numbers(int columns[], int max) {
	int num = 0;
	int ch;
	/*��ȡ�б�ţ��������ȡ����С��0��ֹͣ*/
	while (num < max && scanf("%d",&columns[num]) == 1 
		&& columns[num] >=0)
	{
		num += 1;
	}
	/*ȷ���Ѷ�ȡ�ı��Ϊż����һ����ʼ��Ӧһ������*/
	if (num % 2 !=0)
	{
		puts("Last column number is not paired");
		exit(EXIT_FAILURE);
	}
	/*���������а������һ�����ֵ��ǲ�������*/
	while ((ch = getchar()) != EOF && ch != '\n');
	return num;
}
	/*���������У���ָ���е��ַ�������һ���������NULL��β*/
void rearrange(char* output, char const* input,
	int n_columns, int const columns[]) {
	int col;	/*columns������±�*/
	int output_col;		/*����м�����*/
	int len;	/*�����еĳ���*/
	len = strlen(input);
	output_col = 0;
	for ( col = 0; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;
		/*��������н���������������������ͽ�������*/
		if (columns[col] >= len || output_col == MAX_COLS - 1)
			break;
		/*�������ռ䲻������ֻ���ƿ������ɵ�����*/
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		/*������ص�����*/
		strcpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}
#endif // 0