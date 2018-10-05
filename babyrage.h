#ifndef BABYRAGE_H
#define BABYRAGE_H

class  babyrage
{
	int baby_x, baby_y;
	int vx,vy;
	int half;
	int three;
public:
	babyrage(int width=1, int height=1,int speed=0){
		three = rand() % 3;
		if (three == 0){
			baby_x = rand() % width;
			baby_y = 0;
			half = rand() % 2;
			if (half == 0){
				vx = rand() % 2;
			}
			else{
				vx = -rand() % 2;
			}
			vy = rand() % 5 + speed;
		}
		else if (three == 1){
			baby_x = 0;
			baby_y = rand() % height;
			half = rand() % 2;
			if (half == 0){
				vy = rand() % 2;
			}
			else{
				vy = -rand() % 2;
			}
			vx = rand() % 5 + 1;
		}
		else{
			baby_x = width;
			baby_y = rand() % height;
			half = rand() % 2;
			if (half == 0){
				vy = rand() % 2;
			}
			else{
				vy = -rand() % 2;
			}
			vx =-(rand() % 5 + 1);
		}
	}

	void setxy(int x, int y){ baby_x = x; baby_y = y; };
	int getx(){ return baby_x; };
	int gety(){ return baby_y; };
	void move(){ baby_x += vx; baby_y += vy; };
	void draw(CDC *dc);
};
#endif