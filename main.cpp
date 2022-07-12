#include <windows.h>
#include <fstream>
#include <iostream>

using namespace std;

int con_app_mcpp_h_create()
{
    HANDLE SCARED = GetStdHandle(STD_OUTPUT_HANDLE);
    const char *cons_c = "#include <iostream>\n\nusing namespace std;\n\nint main()\n{\n\t/* Start of code */\n\treturn 0;\n}";
    ofstream con_app_fi("main.cpp");
    con_app_fi << cons_c;
    con_app_fi.close();
    if (strcmp(__argv[2], "--y-mh") == 0)
    {
        ofstream con_m_h("main.h");
        con_m_h << "/* Define Constants here or write some code (insert it using snippets)*/";
        con_m_h.close();
        SetConsoleTextAttribute(SCARED, 23);
        cout << "\"main.h\" successfully created!"
             << "\n";
        SetConsoleTextAttribute(SCARED, 15);
    }
    else if (strcmp(__argv[2], "--n-mh") == 0)
    {
        cout << "main.cpp created!"
             << "\n";
        cout << "No additional files created!"
             << "\n";
    }
    else
    {
        cout << "No parameters specified!"
             << "\n";
        SetConsoleTextAttribute(SCARED, 32);
        cout << "Looks like I have to teach you a lesson..."
             << "\n";
        SetConsoleTextAttribute(SCARED, 15);
        cout << "Just kidding, I meant that no file \"main.h\" will be created :D "
             << "\n";
        exit(-1);
    }

    return 0;
}

int win32_app_mcpp_create()
{
    const char *win32_app_c = "#include <windows.h>\nLRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);\nLPCTSTR WindowClassName = TEXT(\"WindowClassName\");\nint WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszArgument, int nCmdShow)\n{\n\tHWND hwnd;\n\tMSG messages;\n\tWNDCLASSEX wincl;\n\twincl.hInstance = hInst;\n\twincl.lpszClassName = WindowClassName;\n\twincl.lpfnWndProc = WindowProcedure;\n\twincl.style = CS_DBLCLKS; /* Catch double-clicks */\n\twincl.cbSize = sizeof(WNDCLASSEX);\n\twincl.hIcon = NULL;\n\twincl.hIconSm = NULL;\n\twincl.hCursor = LoadCursor(NULL, IDC_ARROW);\n\twincl.lpszMenuName = NULL;\n\twincl.cbClsExtra = 0;\n\twincl.cbWndExtra = 0;\n\twincl.hbrBackground = (HBRUSH)COLOR_WINDOW;\n\tif (!RegisterClassEx(&wincl))\n\t\treturn 0;\n\thwnd = CreateWindowEx(0,\n\t\t\t\t\t\tWindowClassName,\n\t\t\t\t\t\tTEXT(\"App title\"),\n\t\t\t\t\t\tWS_OVERLAPPEDWINDOW,\n\t\t\t\t\t\tCW_USEDEFAULT,\n\t\t\t\t\t\tCW_USEDEFAULT,\n\t\t\t\t\t\t544,\n\t\t\t\t\t\t375,\n\t\t\t\t\t\tHWND_DESKTOP,\n\t\t\t\t\t\tNULL,\n\t\t\t\t\t\thInst,\n\t\t\t\t\t\tNULL);\n\tShowWindow(hwnd, nCmdShow);\n\twhile (GetMessage(&messages, NULL, 0, 0))\n\t{\n\t\tTranslateMessage(&messages);\n\t\tDispatchMessage(&messages);\n\t}\n\treturn messages.wParam;\n}\nLRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)\n{\n\tswitch (message)\n\t{\n\tcase WM_CREATE:\n\t\tbreak;\n\tcase WM_DESTROY:\n\t\tPostQuitMessage(0);\n\t\tbreak;\n\tdefault:\n\t\treturn DefWindowProc(hwnd, message, wParam, lParam);\n\t}\n\treturn 0;\n}";
    ofstream win32_app_fi("main.cpp");
    win32_app_fi << win32_app_c;
    win32_app_fi.close();
    return 0;
}
void display_help()
{
    HANDLE help_col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(help_col, 49);
    cout << "C++ Project Generator";
    SetConsoleTextAttribute(help_col, 7);
    cout << "\n"
         << "\n";
    ifstream help_file("help.txt");
    if (help_file.is_open())
    {
        char mychar;
        while (help_file)
        {
            mychar = help_file.get();
            cout << mychar;
        }
    }
    help_file.close();
}
int command_line_handler()
{
    if (strcmp(__argv[1], "-help") == 0)
    {
        display_help();
    }
    else if (strcmp(__argv[1], "-win32") == 0)
    {
        win32_app_mcpp_create();
    }
    else if (strcmp(__argv[1], "-con") == 0)
    {
        con_app_mcpp_h_create();
    }
    else
    {
        cout << "Your computer is being destroyed since you gave invalid arguments!"
             << "\n";
        while (true)
        {
            int *news = new int;
        }
    }

    return 0;
}
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        HANDLE console_color;
        console_color = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console_color, 12);
        cout << "Please give some command arguments to the program or"
             << "\n";
        cout << "Im gonna put some dirt in your eye"
             << "\n";
        SetConsoleTextAttribute(console_color, 7);
        exit(-1);
    }
    else if (argc > 1)
    {
        command_line_handler();
    }

    return 0;
}