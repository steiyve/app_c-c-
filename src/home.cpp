
#include <Windows.h>

void createWindow() {
    // Définition des paramètres de la fenêtre
    LPCSTR className = "Homme";
    LPCSTR windowTitle = "Homme";
    DWORD windowStyle = WS_OVERLAPPEDWINDOW;
    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
    int width = CW_USEDEFAULT;
    int height = CW_USEDEFAULT;
    HWND parentWindow = NULL;
    HMENU menu = NULL;
    HINSTANCE instance = GetModuleHandle(NULL);
    LPVOID param = NULL;

    // Création de la fenêtre
    HWND window = CreateWindowEx(
        0,
        className,
        windowTitle,
        windowStyle,
        x, y, width, height,
        parentWindow,
        menu,
        instance,
        param
    );

    // Affichage de la fenêtre
    ShowWindow(window, SW_SHOWDEFAULT);
    UpdateWindow(window);
}
