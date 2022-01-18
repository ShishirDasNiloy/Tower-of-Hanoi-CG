#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>

#define MAX 12
#define BegPos 125
#define EndPos 325
#define AuxPos 525

int width;

typedef struct disc
{
    char value1[MAX];
    char top, pos;
};

void push(disc *tt,int x);
int pop(disc *tt);
void tower(int,disc *,disc *,disc *);
void draw_stack(disc *beg,disc *,disc *);

int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");

   int i, x=2;
   disc beg, end, aux;
   cout <<"Enter the number of Discs(1-12): ";
   cin >>x;

    width=50/x;

	beg.top=end.top=aux.top=0;
	beg.pos=1;end.pos=3;aux.pos=2;
	for(i=0;i<x;i++)
		push(&beg,(x-i)+1);

	draw_stack(&beg,&end,&aux);
	tower(x,&beg,&end,&aux);

    getch();
    closegraph();
    return 0;
}

void tower(int n, disc *beg, disc *aux, disc *end)
{
    if(n > 0)
    {
        tower(n-1, beg, end, aux);
        push(end, pop(beg));
        draw_stack(beg, end, aux);
        tower(n-1, aux, beg, end);
    }
}

void push(disc *tt, int x)
{
    tt->value1[tt->top] = x;
    tt-> top++;
}

int pop (disc *tt)
{
    int a;
    tt->top--;
    a = tt->value1[tt->top];
    tt->value1[tt->top] = 0;
    return a;
}


void draw_stack(disc *beg, disc *end, disc *aux)
{
    int ypos = 415, i, height = 10, xpos;
    int ver = 0;
    cleardevice();

    settextstyle(10, 0, 5);
    setcolor(11);
    outtextxy(150,50, "Tower of Hanoi");

    settextstyle(10, 0, 3);
    setcolor(9);
    outtextxy(250,90, "-By Shishir");

    setfillstyle(9,7);
    bar(40,420,600,430);
    setfillstyle(4,9);
	bar(120,200,130,420);
	setfillstyle(8,12);
	bar(320,200,330,420);
	setfillstyle(11,10);
	bar(520,200,530,420);

    setcolor(15);
    rectangle(40,420,600,430);
	rectangle(120,200,130,420);
	rectangle(320,200,330,420);
	rectangle(520,200,530,420);

	ypos = 415;
	if(end->pos == 1)
        xpos = BegPos;
    else if(end->pos==2)
        xpos=AuxPos;
	else if(end->pos==3)
		xpos=EndPos;

    for(i=0; i<end->top; i++)
    {
        setfillstyle(1, end->value1[i]);
        bar(xpos-(end->value1[i]*width),ypos,xpos+(end->value1[i]*width),ypos-height);
        rectangle(xpos-(end->value1[i]*width),ypos,xpos+(end->value1[i]*width),ypos-height);
        ypos -= (height+2);
    }
    ver=end->pos;

    if(beg->pos==1)
		xpos=BegPos;
	else if(beg->pos==2)
		xpos=AuxPos;
	else if(beg->pos==3)
		xpos=EndPos;

    ypos = 415;
    for(i=0;i<beg->top;i++)
    {
        setfillstyle(1,beg->value1[i]);
        bar(xpos-(beg->value1[i]*width),ypos,xpos+(beg->value1[i]*width),ypos-height);
        rectangle(xpos-(beg->value1[i]*width),ypos,xpos+(beg->value1[i]*width),ypos-height);
		ypos-=(height+2);
    }

    ver=ver*10+beg->pos;

	if(ver<20)
	{
		if(ver%10==2)
			xpos=EndPos;
		else
			xpos=AuxPos;
	}
	else if(ver<30)
	{
		if(ver%10==1)
			xpos=EndPos;
		else
			xpos=BegPos;
	}
	else if(ver<40)
	{
		if(ver%10==1)
			xpos=AuxPos;
		else
			xpos=BegPos;
	}

	ypos=415;

	for(i=0;i<aux->top;i++)
	{
		setfillstyle(1,aux->value1[i]);
        bar(xpos-(aux->value1[i]*width),ypos,xpos+(aux->value1[i]*width),ypos-height);
        rectangle(xpos-(aux->value1[i]*width),ypos,xpos+(aux->value1[i]*width),ypos-height);
		ypos-=(height+2);
	}
    delay(200);

}

