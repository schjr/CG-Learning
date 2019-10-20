#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define murloc malloc//rexxar dislikes murlocs
float score;
float average = 0;
int numOfScores = 0;
int oriSize = 5;
int curSize = 5;
int powNum = 0;
int main()
{
	float* scores;
	scores = (float*)malloc(sizeof(float) * 5);
	printf("Please type scores to be calculated:\n");
	while (1 == 1)
	{
		scanf("%f", &score);
		if (score == (-1))
		{
			for (int i = 0; i < (numOfScores); i++)
			{
				//printf("Average score: %.2f\n", scores[i]);
				average += scores[i];
			}
			average /= (numOfScores);
			break;
		}
		scores[numOfScores] = score;
		
		if ((numOfScores + 1)  == curSize )
		{
			//scores = (float*)realloc(scores,sizeof(float) * 5 * pow(2, ((numOfScores + 1)) / 5));
			//oriSize = (5 * pow(2, ((numOfScores + 1)) / 5)) / 2;
			//curSize = (5 * pow(2, ((numOfScores + 1)) / 5));
			powNum++;
			scores = (float*)realloc(scores,sizeof(float) * 5 * pow(2,powNum));
			curSize = (5 * pow(2, powNum));
			oriSize = curSize / 2;
			printf("(resize) from %d to %d\n", oriSize, curSize);
		}
		numOfScores++;
	}
	printf("Average score: %.2f\n", average);
	free(scores);
	return 0;
}