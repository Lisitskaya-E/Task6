#include <stdio.h>
#include <graphics.h>
#include <math.h>

void fractal(int x1, int y1, int x2, int y2, int l)
{
if (l == 0){
return ;
}
else
{
int m2 = x1+(x1-x2)/4;
int m1 = x1 - (x1-x2)/4;
int n1 = y1 -(y1-y2)/4;
int n2 = y1 + (y1-y2)/4;
int n2_1 = y2 + (y1-y2)/4;
int n2_2 = y2 - (y1-y2)/4;
int m2_1 = x2 - (x1-x2)/4;
int m2_2 = x2 + (x1-x2)/4;

fractal(m1, n1, m2, n2, l-1);
fractal(m1, n2_1, m2, n2_2, l-1);
fractal(m2_1, n1, m2_2, n2, l-1);
fractal(m2_1, n2_1, m2_2, n2_2, l-1);
};
line(x1, y1, x1, y2);
line(x1, (y1+y2)/2, x2, (y1+y2)/2);
line(x2, y2, x2, y1);
}

int main()
{
int gd = DETECT;
int gm;
int n;
scanf("%d", &n);
initgraph(&gd, &gm,"");
setcolor (3);
fractal(100, 100, 400, 400, n);


readkey();
closegraph();
return 0;
}
