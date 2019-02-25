#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char rand_cim;     //此变量负责储存用户的输入值

unsigned int rand_w_s;     //此变量负责保存随机数

unsigned int rand_w_s_p;     //此变量负责保存玩家输入的随机数

unsigned int rand_w;     //此变量记录随机数

unsigned int randon_t_2;     //此变量记录随机数生成次数

unsigned int rand_w_2;     //此变量记录随机数

unsigned int randon_t_3;     //此变量记录随机数生成次数

unsigned int rand_w_3;     //此变量记录随机数

unsigned int randon_t_4;     //此变量记录随机数生成次数

unsigned int rand_w_4;     //此变量记录随机数

unsigned int randon_t_5;     //此变量记录随机数生成次数

unsigned int rand_w_5;     //此变量记录随机数

unsigned int re_o_e;



unsigned int rand_dcm(char randon_ci);     //声明难度判断,随机数生成函数

unsigned int rand_dcm(char randon_ci){
/***************难度判断部分***************************/
	switch(randon_ci){
		case 'A':
		case 'a':goto randon_d_1;break;   		//如果是a,则生成的随机数R

		case 'B':
		case 'b':goto randon_d_2;break;     //如果是b,则生成的随机数R+R[2]

		case 'C':
		case 'c':goto randon_d_3;break;     //如果是c,则生成的随机数R+R[2]+R[3]

		case 'D':
		case 'd':goto randon_d_4;break;     //如果是d,则生成的随机数R+R[2]+R[3]+R[4]

		case 'E':
		case 'e':goto randon_d_5;break;     //如果是e,则生成的随机数R+R[2]+R[3]+R[4]+R[5]

		default:exit(0);     //退出程序
	}
/****************随机数生成部分************************/
randon_d_1:

srand((int)time(0));     //将time函数返回值作为随机数生成种子

rand_w=rand();

    return rand_w;
randon_d_2:

for(randon_t_2=0;randon_t_2<2;randon_t_2++)
{
	srand((int)time(0));     //将time函数返回值作为随机数生成种子

	rand_w_2=rand_w_2+rand();
}
	return rand_w_2;
randon_d_3:

for(randon_t_3=0;randon_t_3<3;randon_t_3++)
{
	srand((int)time(0));     //将time函数返回值作为随机数生成种子

	rand_w_3=rand_w_3+rand();
}
	return rand_w_3;
randon_d_4:

for(randon_t_4=0;randon_t_4<4;randon_t_4++)
{
	srand((int)time(0));     //将time函数返回值作为随机数生成种子

	rand_w_4=rand_w_4+rand();
}
	return rand_w_4;
randon_d_5:

for(randon_t_5=0;randon_t_5<5;randon_t_5++)
{
	srand((int)time(0));     //将time函数返回值作为随机数生成种子

	rand_w_5=rand_w_5+rand();
}
	return rand_w_5;
}

#define _LINUX_
#ifndef _LINUX_     //此处判断系统，以便使用正确的清屏.注:默认是Windows!
#define CLSCR system("reset");
#else
#define CLSCR system("cls");
#endif

int main(void){
START:
	printf("********猜数字小游戏********\n");
	printf("*** a.新手模式 b.标准模式***\n");
	printf("*** c.加强模式 d.困难模式***\n");
	printf("*** e.地狱模式 f.退出游戏***\n");
	printf("请选择你需要的难度\n\n");

	rand_cim=getchar();
	
	//printf("Here!");

	rand_w_s=rand_dcm(rand_cim);     //储存随机数

	printf("随机数已生成!\n");

	//printf("随机数是%ld\n",rand_w_s);

play_game:
	CLSCR

	printf("你觉得这个数是什么?\n");

	scanf("%d\n",&rand_w_s_p);

	if(rand_w_s_p<rand_w_s)
	{
		printf("太小了！再试一次吧!\n");

		goto play_game;
	}
	else if(rand_w_s_p>rand_w_s)
	{
		printf("太大了！再试一次吧!\n");

		goto play_game;
	}
	else
	{
		printf("好吧,你猜对了,是否再来一次,或退出游戏?<1/0>\n");
	}

CHOOSE:

		scanf("%d",&re_o_e);

		switch(re_o_e){
			case 1:goto START;break;
			case 2:exit(0);break;
			default:printf("你输入了一个非法字符,请重新输入!\n");goto CHOOSE;
		}
}
