//
//  main.c
//  2048 C
//
//  Created by 马大椽 on 16/10/24.
//  Copyright © 2016年 马大椽. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define LINE 4
#define DIFFICULTY 5

void func_build(void);
void func_random(void);
void func_print(void);
void func_up(void);
void func_down(void);
void func_left(void);
void func_right(void);
void func_gameover(void);
void func_upadd(void);
void func_downadd(void);
void func_leftadd(void);
void func_rightadd(void);
bool gameover_judge(void);

int square[LINE][LINE];


int main(void)
{
    int a,b;
    char direction;
    int overcount = 0;
    func_build();
    func_random();
    func_print();
    printf("Your move:(Use WASD to move!)\n");
    for(;;)
    {
        scanf("%c", &direction);
        if (direction != '\n' && direction != ' ')
        {
            switch (direction)
            {
                case 'w':case 'W':  func_up();
                    func_upadd();
                    func_up();
                    break;
                case 's':case 'S':  func_down();
                    func_downadd();
                    func_down();
                    break;
                case 'a':case 'A':  func_left();
                    func_leftadd();
                    func_left();
                    break;
                case 'd':case 'D':  func_right();
                    func_rightadd();
                    func_right();
                    break;
            }
            func_random();
            
            func_print();
            overcount = 0;
            for(a=0;a<LINE;a++)
            {
                for(b=0;b<LINE;b++)
                {
                    if(square[a][b] != 0)
                    {
                        overcount = overcount + 1;
                    }
                }
            }
            if (overcount == LINE*LINE && gameover_judge() == true)
            {
                func_gameover();
            }
            
        }
    }
    return 0;
}




void func_build(void)
{
    int i,j;
    for (i=0;i<LINE;i++)
    {
        for(j=0;j<LINE;j++)
        {
            square[i][j] = 0;
        }
    }
}

void func_print(void)
{
    int i,j;
    for (i=0;i<LINE;i++)
    {
        for(j=0;j<LINE;j++)
        {
            printf("%5d ",square[i][j]);
        }
        printf("\n");
    }
}

void func_random(void)
{
    int i,j,two_or_four, random_number;
    srand((unsigned) time(NULL));
    do{ i = rand() % LINE;
        j = rand() % LINE;
        two_or_four = rand() % DIFFICULTY;}
    while(square[i][j] != 0);
    if(two_or_four == 1)
    {
        random_number = 4;
    }
    else
    {
        random_number = 2;
    }
    square [i][j] = random_number;
}

void func_gameover(void)
{
    char restart;
    printf("GAME OVER!\nTry again?(Y/N)\n");
    scanf(" %c",&restart);
    if (restart == 'y' || restart == 'Y' )
    {
        func_build();
        func_random();
        func_print();
        printf("Your move:(Use WASD to move!)\n");
    }
    else if (restart == 'n' || restart == 'N' )
    {
        exit(EXIT_SUCCESS);
    }
}




void func_up(void)
{
    int i,j = 0;
    int k = 0;
    int temp;
    for(j=0;j<LINE;j++)
    {
        for(i=0;i<LINE;i++)
        {
            if (square[i][j] != 0)
            {
                temp = square[i][j];
                square[i][j] = square [k][j];
                square[k][j] = temp;
                k++;
            }
        }
        k=0;
        
    }
}

void func_down(void)
{
    int i,j = 0;
    int k = LINE - 1;
    int temp;
    for(j=0;j<LINE;j++)
    {
        for(i=LINE-1;i>=0;i--)
        {
            if (square[i][j] != 0)
            {
                temp = square[i][j];
                square[i][j] = square [k][j];
                square[k][j] = temp;
                k--;
            }
        }
        k=LINE - 1 ;
        
    }
}

void func_left(void)
{
    int i,j = 0;
    int k = 0;
    int temp;
    for(i=0;i<LINE;i++)
    {
        for(j=0;j<LINE;j++)
        {
            if (square[i][j] != 0)
            {
                temp = square[i][j];
                square[i][j] = square [i][k];
                square[i][k] = temp;
                k++;
            }
        }
        k=0;
        
    }
}

void func_right(void)
{
    int i,j = 0;
    int k = LINE-1;
    int temp;
    for(i=0;i<LINE;i++)
    {
        for(j=LINE-1;j>=0;j--)
        {
            if (square[i][j] != 0)
            {
                temp = square[i][j];
                square[i][j] = square [i][k];
                square[i][k] = temp;
                k--;
            }
        }
        k=LINE-1;
        
    }
}

void func_upadd(void)
{
    int i,j=0;
    for(j=0;j<LINE;j++)
    {
        for(i=0;i<LINE;i++)
        {
            if(square[i][j] == square[i+1][j])
            {
                square[i][j] = 2 * square[i+1][j];
                square[i+1][j] = 0;
            }
        }
        
    }
    
}

void func_downadd(void)
{
    int i,j;
    
    for(j=0;j<LINE;j++)
    {
        for(i=LINE-1;i>=0;i--)
        {
            if (square[i][j] == square[i-1][j])
            {
                square[i][j] = 2*square[i-1][j];
                square[i-1][j] = 0;
            }
        }
        
    }
}

void func_leftadd(void)
{
    int i,j;
    
    for(i=0;i<LINE;i++)
    {
        for(j=0;j<LINE;j++)
        {
            if (square[i][j] == square[i][j+1])
            {
                square[i][j] = 2 * square [i][j+1];
                square[i][j+1] = 0;
                
            }
        }
        
    }
}

void func_rightadd(void)
{
    int i,j;
    
    for(i=0;i<LINE;i++)
    {
        for(j=LINE-1;j>=0;j--)
        {
            if (square[i][j] == square[i][j-1])
            {
                square[i][j] = 2*square[i][j-1];
                square[i][j-1] = 0;
                
            }
        }
        
    }
}

bool gameover_judge(void)
{
    int i,j;
    int count;
    for (i=0;i<LINE;i++)
    {
        for(j=0;j<LINE;j++)
        {
            if (square[i+1][j] != square[i][j] && square[i][j+1] != square[i][j] && square[i-1][j] != square[i][j] && square[i][j-1] != square[i][j])
            {
                count++;
            }
        }
    }
    if (count == LINE*LINE)
    {
        return true;
    }
    else{
        return false;
    }
    
}
