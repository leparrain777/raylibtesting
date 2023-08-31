#include <cmath>
#include "raylib.h"


int main()
{
	InitWindow(800,600,"Game Window!");
	//SetWindowState(FLAG_VSYNC_HINT);

	struct Physicsob
	{
		float xpos, ypos, xvel, yvel, xaccel, yaccel, rad, cor;

		void Draw()
		{
			DrawCircle((int)xpos, (int) ypos, rad, WHITE);
		}
		void DoPhysics()
		{
			xaccel = -1 *std::copysign(xaccel,xvel);
			xvel += xaccel * GetFrameTime();
			yvel += yaccel * GetFrameTime();
			xpos += xvel * GetFrameTime();
			ypos += yvel * GetFrameTime();
			if (xpos < 0)
			{
				xpos = 0;
				xvel = cor * xvel;
			}
			if (xpos > GetScreenWidth())
			{
				xpos = GetScreenWidth();
				xvel = cor * xvel;
			}
			if (ypos < 0)
			{
				ypos = 0;
				yvel = cor * yvel;
			}
			if (ypos > GetScreenHeight())
			{
				ypos = GetScreenHeight();
				yvel = cor * yvel;
			}

		}
	};

	Physicsob ball;
	ball.xpos = GetScreenWidth() / 2.0f;
	ball.ypos = GetScreenHeight() / 2.0f;
	ball.xvel = 80;
	ball.yvel = -50;
	ball.xaccel = .5;
	ball.yaccel = 60;
	ball.rad = 5;
	ball.cor = -.9;

	while(!WindowShouldClose())
	{
		ball.DoPhysics();

		BeginDrawing();
		ClearBackground(BLACK);
		ball.Draw();
		

		DrawFPS(10, 10);
		EndDrawing();

	}

	CloseWindow();
	return 0;
}