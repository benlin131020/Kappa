#ifndef BT_H
#define BT_H

class  bt
{
	int bt_x,bt_y;
	int speed;
	int random,rx,right;
public:
	bt(int x,int y,int r){
		bt_x = x;
		bt_y = y;
		speed = 5;
		random = r;
		right = rand() % 2;
		rx = rand() % speed + 1;
	}

	int getx(){ return bt_x; };
	int gety(){ return bt_y; };
	void move(){ 
		bt_y -= speed;
		if (random == 1){
			if (right == 0) bt_x -= rx;
			else bt_x += rx;
		}
	};
	void draw(CDC *dc);
};
#endif