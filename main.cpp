
//  888888 888888    db     dP""b8 88  88 888888 88""Yb     888888  dP"Yb   dP"Yb  88     
//    88   88__     dPYb   dP   `" 88  88 88__   88__dP       88   dP   Yb dP   Yb 88     
//    88   88""    dP__Yb  Yb      888888 88""   88"Yb        88   Yb   dP Yb   dP 88  .o 
//    88   888888 dP""""Yb  YboodP 88  88 888888 88  Yb       88    YbodP   YbodP  88ood8 
// outil fait par nicolas prigge

#include <windows.h>
#include <string>
#include <iostream>
#include "src/login.cpp"
#include "src/home.cpp"

using namespace std;

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch(msg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        
        case WM_COMMAND:
            if (LOWORD(wparam) == 4) // 2 is the ID of the button
            {
                char buffer[256];
                char buffer2[256];
                char buffer3[256] = "\n";
                bool loginvar = false;
                HWND hEdit1 = GetDlgItem(hwnd, 1); // Get the handle of the edit control
                HWND hEdit2 = GetDlgItem(hwnd, 2); // Get the handle of the edit control
                GetWindowTextA(hEdit1, buffer, 256); // Get text from the edit control
                GetWindowTextA(hEdit2, buffer2, 256); // Get text from the edit control
                loginvar = login(string(buffer), string(buffer2)); // call login function

                if (loginvar == true){
                    // concatenate strings
                    string final_string = string(buffer) + string(buffer3) + string(buffer2);

                    MessageBoxA(NULL, final_string.c_str(), "Input", MB_OK); // Display the text in a message box
                }
                else{
                    MessageBoxA(NULL, "Login failed!", "Input", MB_OK); // Display the text in a message box
                }
            }
            break;
        default:
            return DefWindowProcA(hwnd, msg, wparam, lparam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClass(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    HWND hwnd = CreateWindow(CLASS_NAME, "outils prof", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, NULL, NULL, hInst, NULL);

    // Create an edit control (text input field)

    //text 
    HWND hText1 = CreateWindow("STATIC", "User Name", WS_CHILD | WS_VISIBLE,
                        50, 30, 200, 20, hwnd, (HMENU)3, NULL, NULL);
    //input
    HWND hEdit1 = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
                            50, 50, 200, 20, hwnd, (HMENU)1, NULL, NULL);
    //text 
    HWND hText2 = CreateWindow("STATIC", "Password", WS_CHILD | WS_VISIBLE,
                          50, 90, 200, 20, hwnd, (HMENU)3, NULL, NULL);
    //input
    HWND hEdit2 = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
                            50, 110, 200, 20, hwnd, (HMENU)2, NULL, NULL);


    // Create a button
    HWND hButton = CreateWindow("BUTTON", "Submit", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                                50, 150, 100, 20, hwnd, (HMENU)4, NULL, NULL);
    if (hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // deuxieme fenetre pour register



    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    createWindow();
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
