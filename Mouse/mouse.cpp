#include "mouse.h"
#include"DxLib.h"

int Mouse::left_previus;//1�t���[���O
int Mouse::left_current;//��Ɨ̈�
//�E�N���b�N�p
int Mouse::right_previus;//�P�t���[���O
int Mouse::right_current;//��Ɨ̈�

void Mouse::initialize()
{
	left_current = 0;
	left_previus = 0;
	right_current = 0;
	right_previus = 0;
}

void Mouse::update()
{
	left_previus = left_current;
	right_previus = right_current;

	left_current = (GetMouseInput() & MOUSE_INPUT_LEFT);
	right_current = (GetMouseInput() & MOUSE_INPUT_RIGHT);
}

bool Mouse::left_mouse_down()
{
	return left_previus == 0 && left_current == 1;
}

bool Mouse::left_mouse_up()
{
	return left_previus == 1 && left_current == 0;
}

bool Mouse::left_mouse_press()
{
	return left_current == 1 && left_previus == 1;
}

bool Mouse::left_mouse_not_press()
{
	return left_current == 0 && left_previus == 0;
}

//�E�N���b�N-----------------------------------------------------------------

bool Mouse::right_mouse_down()
{
	return right_previus == 0 && right_current == 1;
}

bool Mouse::right_mouse_up()
{
	return right_previus == 1 && right_current == 0;
}

bool Mouse::right_mouse_press()
{
	return right_previus == 1 && right_current == 1;
}

bool Mouse::right_mouse_not_press()
{
	return right_previus == 0 && right_current == 0;
}
