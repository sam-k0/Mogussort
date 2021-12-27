// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "pch.h"
#include "gms.h"
#include "mogus.h"
#include <Windows.h>
#include <time.h>
#include <ctime>

#pragma warning(disable : 4996)

mogus* Mogus = new mogus();


gmx gmbool mogus_add(gmint n)
{
    Mogus->addElement((int)n);
    return gmtrue;
}

gmx gmbool mogus_sort()
{
    // stop time
    time_t time_1; 
    time_t time_2;

    time(&time_1);
    Mogus->mogussort();
    time(&time_2);

    cout <<" Time taken to sort:" << time_2 - time_1 << " seconds" << endl;

    return gmtrue;
}

gmx gmbool mogus_print()
{
    Mogus->print();
    return gmtrue;
}




BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        srand(time(NULL));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

