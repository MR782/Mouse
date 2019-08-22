#pragma once

class Mouse {
	//左クリック用
	static int left_previus;//1フレーム前
	static int left_current;//作業領域
	//右クリック用
	static int right_previus;//1フレーム前
	static int right_current;//作業領域
public:
	static void initialize();
	static void update();
	//左クリック用
	static bool left_mouse_down();
	static bool left_mouse_up();
	static bool left_mouse_press();
	static bool left_mouse_not_press();
	//右クリック用
	static bool right_mouse_down();
	static bool right_mouse_up();
	static bool right_mouse_press();
	static bool right_mouse_not_press();
};