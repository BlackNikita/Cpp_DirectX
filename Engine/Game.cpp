/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	xs = 500;
	ys = 400;
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (bInhibitUp) 
		{
		}
		else
		{
			vy -= 1;
			bInhibitUp = true;
		}
	} else {
		bInhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (bInhibitDown)
		{
		}
		else {
			vy += 1;
			bInhibitDown = true;
		}
	}
	else {
		bInhibitDown = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (bInhibitLeft) {

		}
		else {
			vx -= 1;
			bInhibitLeft = true;
		}
	}
	else {
		bInhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (bInhibitRight) {

		}
		else {
			vx += 1;
			bInhibitRight = true;
		}
	}
	else {
		bInhibitRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		vy = 0;
		vx = 0;
	}

	x = x + vx;
	y = y + vy;

	if (x + 5 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 6;
		vx = 0;
	}
	if (x - 5 < 0) {
		x = 5;
		vx = 0;
	}
	if (y + 5 >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 6;
		vy = 0;
	}
	if (y - 5 < 0) {
		y = 5;
		vy = 0;
	}
	
	

		bIsColorChanged = false;
		if ((x >= xs - 5 && x < xs + 5) || (y > ys - 5 && y < ys + 5)) {
			bIsColorChanged = true;
		}
		else {
			bIsColorChanged = wnd.kbd.KeyIsPressed(VK_CONTROL);
		}
		if (bIsColorChanged) {
			r = 0;
		}

		else {
			r = 255;
		}
	bIsShapeChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
	
	
	
}

void Game::ComposeFrame()
{
	
	
	if (bIsShapeChanged) {
		gfx.PutPixel(x - 3, y, r, 255, r);
		gfx.PutPixel(x - 2, y, r, 255, r);
		gfx.PutPixel(x - 1, y, r, 255, r);
		gfx.PutPixel(x + 1, y, r, 255, r);
		gfx.PutPixel(x + 2, y, r, 255, r);
		gfx.PutPixel(x + 3, y, r, 255, r);
		gfx.PutPixel(x, y - 3, r, 255, r);
		gfx.PutPixel(x, y - 2, r, 255, r);
		gfx.PutPixel(x, y - 1, r, 255, r);
		gfx.PutPixel(x, y + 1, r, 255, r);
		gfx.PutPixel(x, y + 2, r, 255, r);
		gfx.PutPixel(x, y + 3, r, 255, r);
	}
	else {
		gfx.PutPixel(x - 5, y, r, 255, r);
		gfx.PutPixel(x - 4, y, r, 255, r);
		gfx.PutPixel(x - 3, y, r, 255, r);
		gfx.PutPixel(x + 3, y, r, 255, r);
		gfx.PutPixel(x + 4, y, r, 255, r);
		gfx.PutPixel(x + 5, y, r, 255, r);
		gfx.PutPixel(x, y - 5, r, 255, r);
		gfx.PutPixel(x, y - 4, r, 255, r);
		gfx.PutPixel(x, y - 3, r, 255, r);
		gfx.PutPixel(x, y + 3, r, 255, r);
		gfx.PutPixel(x, y + 4, r, 255, r);
		gfx.PutPixel(x, y + 5, r, 255, r);
	}

	gfx.PutPixel(xs - 5, ys, 255, 50, 0);
	gfx.PutPixel(xs - 4, ys, 255, 50, 0);
	gfx.PutPixel(xs - 3, ys, 255, 50, 0);
	gfx.PutPixel(xs + 3, ys, 255, 50, 0);
	gfx.PutPixel(xs + 4, ys, 255, 50, 0);
	gfx.PutPixel(xs + 5, ys, 255, 50, 0);
	gfx.PutPixel(xs, ys - 5, 255, 50, 0);
	gfx.PutPixel(xs, ys - 4, 255, 50, 0);
	gfx.PutPixel(xs, ys - 3, 255, 50, 0);
	gfx.PutPixel(xs, ys + 3, 255, 50, 0);
	gfx.PutPixel(xs, ys + 4, 255, 50, 0);
	gfx.PutPixel(xs, ys + 5, 255, 50, 0);
	
		
	
}
