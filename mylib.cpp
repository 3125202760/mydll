#include <Windows.h>
#pragma comment(lib, "User32.lib")

__declspec(dllexport) void copy_and_paste(const char* str)
{
    // 打开剪贴板
    if (!OpenClipboard(NULL))
        return;

    // 清空剪贴板
    EmptyClipboard();

    // 分配内存
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, strlen(str) + 1);
    if (hMem == NULL)
    {
        CloseClipboard();
        return;
    }

    // 锁定内存
    char* pMem = (char*)GlobalLock(hMem);
    if (pMem == NULL)
    {
        GlobalFree(hMem);
        CloseClipboard();
        return;
    }

    // 复制字符串到内存
    strcpy_s(pMem, strlen(str) + 1, str);

    // 解锁内存
    GlobalUnlock(hMem);

    // 设置剪贴板数据
    SetClipboardData(CF_TEXT, hMem);

    // 关闭剪贴板
    CloseClipboard();

    // 模拟Ctrl+V
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event('V', 0, 0, 0);
    keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

__declspec(dllexport) void press_enter()
{
    // 模拟回车键
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}
