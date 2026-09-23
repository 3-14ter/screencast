#include <windows.h>

// Forward declaration of the message handler
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// WinMain is the native entry point for Windows graphical applications
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"VirtualDisplayClass";

    // 1. Define the Window properties
    WNDCLASS wc = { };
    wc.lpfnWndProc   = WindowProc; // Handles clicks, closes, etc.
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    // 2. Register the class with the OS
    RegisterClass(&wc);

    // 3. Create the window (800x600)
    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, L"Virtual Display - Native Win32",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    // 4. Display the window
    ShowWindow(hwnd, nCmdShow);

    // 5. Run the message loop
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// 6. Handle OS events
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0); // Exit the application when the X is clicked
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
