#include "mouse.h"
#include"DxLib.h"

int Mouse::left_previous;//1フレーム前
int Mouse::left_current;//作業領域
//右クリック用
int Mouse::right_previous;//１フレーム前
int Mouse::right_current;//作業領域

void Mouse::initialize()
{
	left_current = 0;
	left_previous = 0;
	right_current = 0;
	right_previous = 0;
}

void Mouse::update()
{
	left_previous = left_current;
	right_previous = right_current;

	left_current = (GetMouseInput() & MOUSE_INPUT_LEFT);
	right_current = (GetMouseInput() & MOUSE_INPUT_RIGHT);
}

//---------------------------------------------------------------------------
//左クリック
//---------------------------------------------------------------------------
bool Mouse::left_mouse_down()
{
	return left_previous == 0 && left_current != 0;
}

bool Mouse::left_mouse_up()
{
	return left_previous != 0 && left_current == 0;
}

bool Mouse::left_mouse_press()
{
	return left_current != 0 && left_previous != 0;
}

bool Mouse::left_mouse_not_press()
{
	return left_current == 0 && left_previous == 0;
}
//---------------------------------------------------------------------------
//右クリック
//---------------------------------------------------------------------------
bool Mouse::right_mouse_down()
{
	return right_previous == 0 && right_current != 0;
}

bool Mouse::right_mouse_up()
{
	return right_previous != 0 && right_current == 0;
}

bool Mouse::right_mouse_press()
{
	return right_previous != 0 && right_current != 0;
}

bool Mouse::right_mouse_not_press()
{
	return right_previous == 0 && right_current == 0;
}
