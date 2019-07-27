#include <cstdio>
#include <cstdlib>
#include "resource.h"

static void Fail(const char* msg)
{
    std::printf("FAIL %s\n", msg);
    std::exit(1);
}

int main()
{
    if (IDD_ABOUTBOX != 100)
        Fail("about");
    if (IDS_ABOUTBOX != 101)
        Fail("aboutstr");
    if (IDD_GETMACADDRESS_BY_MICHAEL_HAEPHRATI_DIALOG != 102)
        Fail("dialog");
    if (IDC_MACID != 1000)
        Fail("macid");
    std::printf("OK MacIdTests\n");
    return 0;
}
