#include "title.h"




int AIVSAI()
{
	initgraph((map_width - 1) * piece_size + offsetx * 2, (map_height - 1) * piece_size + offsety * 2);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	for (int i = 0; i < map_width; i++)//����
	{
		line(i * piece_size + offsetx, offsety, i * piece_size + offsetx, offsety + (map_height - 1) * piece_size);
	}
	for (int i = 0; i < map_height; i++)//����
	{
		line(offsetx, offsety + i * piece_size, (map_width - 1) * piece_size + offsetx, offsety + i * piece_size);
	}




	AI2x = 7, AI2y = 7;
	map[AI2x][AI2y] = 2;
	drawPiece(AI2x, AI2y, 2);
	while (1)
	{

		//����
				AI(AI2x, AI2y);
				drawPiece(AIx, AIy, 1);
				map[AIx][AIy] = 1;
				judge(AIx, AIy);
				if (check == 1)
				{
					MessageBox(GetHWnd(), L"��AIʤ����", L"��Ϸ������", MB_OKCANCEL);
					break;
				}


		//����
				AI2(AIx,AIy);
				drawPiece(AI2x,AI2y,2);
				map[AI2x][AI2y] = 2;
				judge(AI2x, AI2y);
				if (check == 2)
				{
					MessageBox(GetHWnd(), L"��AIʤ����", L"��Ϸ������", MB_OKCANCEL);
					break;
				}

				if (check == 3)
				{
					MessageBox(GetHWnd(), L"ƽ��", L"��Ϸ������", MB_OKCANCEL);
					break;
				}
				
	}
	mciSendString(L"stop m", NULL, 0, NULL);
	return 0;
}
