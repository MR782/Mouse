#pragma once

class Mouse {
	//���N���b�N�p
	static int left_previus;//1�t���[���O
	static int left_current;//��Ɨ̈�
	//�E�N���b�N�p
	static int right_previus;//1�t���[���O
	static int right_current;//��Ɨ̈�
public:
	static void initialize();
	static void update();
	//���N���b�N�p
	static bool left_mouse_down();
	static bool left_mouse_up();
	static bool left_mouse_press();
	static bool left_mouse_not_press();
	//�E�N���b�N�p
	static bool right_mouse_down();
	static bool right_mouse_up();
	static bool right_mouse_press();
	static bool right_mouse_not_press();
};