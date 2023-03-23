// Console.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "framework.h"
#include "Console.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {

        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            wprintf(L"심각한 오류: MFC 초기화 실패\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            
            _tsetlocale(LC_ALL, _T(""));

            CString str, strMSG, strFOR, strTMP;
            CString name("Gaeul Kim");

            str.LoadString(IDS_APP_TITLE);
            strMSG.LoadString(IDS_MESSAGE);
            strFOR.LoadString(IDS_FORMAT);

            _tprintf(_T("Hello from %s!\n"), (LPCTSTR)str);
            _tprintf(_T("%s\n"), (LPCTSTR)strMSG);
            strTMP.Format(strFOR, name, 20);
            _tprintf(_T("%s\n"), (LPCTSTR)strTMP);

        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
