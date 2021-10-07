#if 0
/*
来源：C和指针第一章
功能，输入指定的位置，以及字符串，可以打印指定位置之间的字符串
example：
 0 3 10 12 -1 (说明第0列到第3列，第10列以及第12的字符串将会被打印)
 input :Hello there , how are you?
 output:o ther how are
*/
#include<stdio.h>
#include<stdlib.h>N 
#include<string.h>
#define	MAX_COLS 20		/*所能处理的最大列号*/
#define MAX_INPUT 1000	/*每个输入行的最大长度*/
int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input,
	int n_columns, int const columns[]);
int main(void) {
	int n_columns;		/*进行处理的列标号*/
	int colums[MAX_COLS];		/*需要处理的列数*/
	char input[MAX_INPUT];		/*容纳输入行的数组*/
	char ouput[MAX_INPUT];		/*容纳输出行的数组*/
	/*
	读取串列标号
	*/
	n_columns = read_column_numbers( colums, MAX_COLS );
	/*
	读取、处理和打印剩余的输入行
	*/
	while (gets(input)!=NULL)		/*get()函数功能，从输入缓存区读取一个字符串到变量input所指向的空间*/
	{
		printf("Origina input: %s\n", input);		/*打印原始的输入值*/
		rearrange(ouput, input, n_columns, colums);
		printf("Rearranged line: %s\n", ouput);		/*打印指定位置后的字符串*/
	}
	return EXIT_SUCCESS;	/*告诉操作系统执行成功*/
}
	/*
	读取列标号，如果超出规定范围则不予理会
	*/
int read_column_numbers(int columns[], int max) {
	int num = 0;
	int ch;
	/*读取列标号，如果所读取的数小于0则停止*/
	while (num < max && scanf("%d",&columns[num]) == 1 
		&& columns[num] >=0)
	{
		num += 1;
	}
	/*确定已读取的标号为偶数，一个开始对应一个结束*/
	if (num % 2 !=0)
	{
		puts("Last column number is not paired");
		exit(EXIT_FAILURE);
	}
	/*丢弃该行中包含最后一个数字的那部分内容*/
	while ((ch = getchar()) != EOF && ch != '\n');
	return num;
}
	/*处理输入行，将指定列的字符连接在一起，输出行以NULL结尾*/
void rearrange(char* output, char const* input,
	int n_columns, int const columns[]) {
	int col;	/*columns数组的下标*/
	int output_col;		/*输出列计数器*/
	int len;	/*输入行的长度*/
	len = strlen(input);
	output_col = 0;
	for ( col = 0; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;
		/*如果输入行结束或输出行数组已满，就结束任务*/
		if (columns[col] >= len || output_col == MAX_COLS - 1)
			break;
		/*如果输出空间不够，则只复制可以容纳的数据*/
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		/*复制相关的数据*/
		strcpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}
#endif // 0