/* $Id$ */

#include <windows.h>
#include "setup.h"
#include "ircd_signal.h"

#define WM_SIGNAL   (WM_USER + 0)

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
        LPSTR lpCmdLine, int nCmdShow)
{
  HWND wndhandle = FindWindow(PACKAGE_NAME, NULL);

  if (!wndhandle)
  {
    MessageBox(NULL, "ircd-hybrid is not running", NULL, MB_OK | MB_ICONERROR);
    return 1;
  }

  PostMessage(wndhandle, WM_SIGNAL, SIG_REHASH, 0);
}
