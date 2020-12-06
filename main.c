#include <stdio.h>
#include "bmpDrawing.h"

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
    drawLine(x1, y1, x1, y2,2,RED);
    drawLine(x1, (y1+y2)/2, x2, (y1+y2)/2, 2, RED);
    drawLine(x2, y2, x2, y1, 2, RED );
}

int main() {
    int n;
    scanf("%d", &n);
    create("frac.bmp", 800, 800);
    fractal(300, 300, 500, 500, n);
    writeFile();
    return 0;
}
