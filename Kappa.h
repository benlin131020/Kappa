#ifndef KAPPA_H
#define KAPPA_H

class kappa
{
	int kappa_x,kappa_y;
	int speed;
public:
	kappa(int x = 0,int y=0){
		kappa_x = x;
		kappa_y = y;
		speed = 5;
	}
	void setpos(int x, int y){ kappa_x = x; kappa_y = y; };
	int getx(){ return kappa_x; };
	int gety(){ return kappa_y; };
	void up(){ kappa_y -= speed; };
	void down(){ kappa_y += speed; };
	void left(){ kappa_x -= speed; };
	void right(){ kappa_x += speed; };
	void speedup(){ speed+=1; };
	void initialize(){ speed = 5; kappa_x = 360; kappa_y = 600; };
	void draw(CDC *dc);
};

#endif