#include <graphics.h>
#include <conio.h>
#include <time.h>

#define WIDTH_GRAPH 1200
#define HEIGHT_GRAPH 600
#define PI 3.14159

int CreatGraph(int width, int height) {
	initgraph(width, height);
	setbkcolor(RGB(128, 128, 128));
	cleardevice();
	return 1;
}

int CreatPicture(int x, int y, int radius) {
	double totalset = 0.0;		//不同半径之间的角度偏移量
	double offset = 0.0;		//相同半径之间的角度偏移量
	while (radius > 0) {
		int left_x = x - radius;
		int left_y = y - radius;
		int right_x = x + radius;
		int right_y = y + radius;
		float h = rand() % 180;
		COLORREF color1 = HSVtoRGB(h, 0.9, 0.8);
		COLORREF color2 = HSVtoRGB(h + 180, 0.9, 0.8);
		for (int i = 0; i < 20; i++) {
			offset = i * (PI / 10) + totalset;

			setfillcolor(color1);
			solidpie(left_x, left_y, right_x, right_y, offset, PI / 30 + offset);

			setfillcolor(RGB(255, 255, 255));
			solidpie(left_x, left_y, right_x, right_y, PI / 30 + offset, PI / 20 + offset);

			setfillcolor(color2);
			solidpie(left_x, left_y, right_x, right_y, PI / 20 + offset, PI / 12 + offset);

			setfillcolor(RGB(0, 0, 0));
			solidpie(left_x, left_y, right_x, right_y, PI / 12 + offset, PI / 10 + offset);
		}
		totalset += PI / 20;
		radius -= 50;
	}
	return 1;
}

int main(void) {
	CreatGraph(WIDTH_GRAPH, HEIGHT_GRAPH);
	srand(time(0));
	while (1) {
		cleardevice();
		for (int x = WIDTH_GRAPH / 8; x <= WIDTH_GRAPH; x += WIDTH_GRAPH / 4) {
			for (int y = HEIGHT_GRAPH / 4; y <= HEIGHT_GRAPH; y += HEIGHT_GRAPH / 2) {
				CreatPicture(x, y, 150);
			}
		}
		_getch();
	}
	return 0;
}