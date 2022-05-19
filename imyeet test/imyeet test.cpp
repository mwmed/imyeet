#include "base_window.h"
#include <imyeet_widgets.h>

int  main(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	base_window* window = new base_window(hInstance, "YeetDelta", "Yeet_Window");

	if (!window->create()) {
		spdlog::error("failed to create window");
		system("pause");
		return -1;
	}

	D3DCOLOR clear_color = D3DCOLOR_RGBA(255, 255, 255, 125);

	auto device = window->get_d3dbase()->get_device();
	imyeet::on_create(window->get_window(), device);

	bool c = true;
	bool c2 = false;
	bool done = false;

	while (!done) {
		MSG msg;
		while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				done = true;
		}
		if (done)
			break;
		imyeet::on_frame_begin();

		imyeet::begin("ImYeet Test", true, IM_COL32(15,15,15,255), ImVec2(500,500));

		imyeet::begin_child(ImVec2(350, 250));

		if (imyeet::button("button in child", ImVec2(15, 120), false))
			std::cout << "clicked button in child" << std::endl;

		if (imyeet::button("button in child2", ImVec2(15, 120), false))
			std::cout << "clicked button in child" << std::endl;

		imyeet::end_child();
		imyeet::checkbox("imyeet", c);
		if (imyeet::button("imbutton", ImVec2(17, 65)))
			std::cout << "clicked" << std::endl;
		imyeet::checkbox("imyeet2", c2);

	
	
		imyeet::end();
		//drawings
		device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_color, 1.0f, 0);
		if (device->BeginScene() >= 0) {
			imyeet::on_frame_end();
			device->EndScene();
		}
		HRESULT result = device->Present(NULL, NULL, NULL, NULL);

	}
}

