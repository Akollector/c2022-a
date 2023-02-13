#include "title.h"

IMAGE backImg;	 //����ͼƬ����������


void drawPiece(int x, int y, int color) //��������
{
	if (color == 1)
	{
		setfillcolor(WHITE); 
	}
	else if (color == 2)
	{
		setfillcolor(BLACK); 
	}
	fillcircle(x * piece_size + offsetx, y * piece_size + offsety, piece_size / 2);   //�����xӦ���Ǵ�����������x
	
}

void drawBoard()
{
	initgraph(520, 520); 
	setbkcolor(WHITE);
	cleardevice();
	setbkmode(TRANSPARENT);  

	settextstyle(55, 0, L"����");   
	settextcolor(RGB(70, 70, 70)); 
	outtextxy(270, 130, L"��Ҷ�ս");   
	outtextxy(320, 200, L"AI��ս");
	outtextxy(320, 270, L"AIVSAI");
	
}

void clear(int x,int y)
{
	//�����С�����εķ�ʽ���Բ����ֹ���±��ߣ�ȱ���ǻ��ȥ�������ӵ�һС����...
		clearrectangle(x * piece_size + offsetx - (piece_size / 2), y * piece_size + offsety - (piece_size / 2), x * piece_size + offsetx + (piece_size / 2), y * piece_size + offsety + (piece_size / 2));   //��������
		if ((x == 0) || (y == 0) || (x == 14) || (y == 14))    //��Ե����
		{
			line(x * piece_size + offsetx - (piece_size / 2), offsety + y * piece_size, x * piece_size + offsetx + (piece_size / 2), offsety + y * piece_size);
			line(offsetx + x * piece_size, y * piece_size + offsety - (piece_size / 2), offsetx + x * piece_size, y * piece_size + offsety + (piece_size / 2));
			clearrectangle(offsetx-piece_size/2,offsety,offsetx,offsety + 14 * piece_size);        //����ಹ����
			clearrectangle(offsetx,offsety+14*piece_size,offsetx+14*piece_size,offsety+14*piece_size+piece_size/2);
			clearrectangle(offsetx + 14 * piece_size, offsety, offsetx + 14 * piece_size+piece_size/2, offsety+14*piece_size);
			clearrectangle(offsetx,offsety,offsetx+14*piece_size,offsety-piece_size / 2);
			line(offsetx, offsety, offsetx, offsety + 14 * piece_size);               //�����Ե����
			line(offsetx, offsety + 14 * piece_size, offsetx+14*piece_size, offsety + 14 * piece_size);
			line(offsetx + 14 * piece_size, offsety , offsetx + 14 * piece_size, offsety + 14 * piece_size);
			line(offsetx, offsety, offsetx + 14 * piece_size, offsety);


		}
		else               //�������
		{
			line(x * piece_size + offsetx - (piece_size / 2), offsety + y * piece_size, x * piece_size + offsetx + (piece_size / 2), offsety + y * piece_size);
			line(offsetx + x * piece_size, y * piece_size + offsety - (piece_size / 2), offsetx + x * piece_size, y * piece_size + offsety + (piece_size / 2));
		}
		
		map[x][y] = 0;        //����λ����Ϣ
		Piece += changePiece;
		changePiece *= -1;         //�ı�������ɫ
	
}

void regret(void)
{
	if (num != 0)
	{
		for (int i = 0; i <= 14; i++)
		{
			for (int j = 0; j <= 14; j++)
			{
				if (order[i][j] == num)
				{
					clear(i, j);
					order[i][j] = 0;
					num = num - 1;
					jump = 1;        //����ֹͣѭ�����ôε���»������
					break;
				}
			}
			if (jump == 1)
			{
				jump = 0;
				break;
			}
		}
	}
}

