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
		imyeet::checkbox("imyeet", c);

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

