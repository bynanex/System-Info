#include <iostream>
#include <Windows.h>
#include <intrin.h>
#include <conio.h>





static const char* cpuId(void)
{
	/* credits to sourceforge -0-0-, needed help with this one*/
	unsigned long s1 = 0;
	unsigned long s2 = 0;
	unsigned long s3 = 0;
	unsigned long s4 = 0;
	__asm
	{
		mov eax, 00h
		xor edx, edx
		cpuid
		mov s1, edx
		mov s2, eax
	}
	__asm
	{
		mov eax, 01h
		xor ecx, ecx
		xor edx, edx
		cpuid
		mov s3, edx
		mov s4, ecx
	}

	static char buf[100];
	sprintf_s(buf, "%08X%08X%08X%08X ", s1, s2, s3, s4);
	return buf;
}

int main()
{

	

	
	SetConsoleTitle(TEXT("System Info"));
	system("cls");
	
	std::cout << "					===============================" << std::endl;
	std::cout << "			  		       > system info < " << std::endl;
	std::cout << "			 	        ===============================" << std::endl;
	std::cout << "\n";
	std::cout << "CPU Name" << std::endl;
	system("echo %PROCESSOR_IDENTIFIER% ");
	std::cout << "\n";
	system("wmic path win32_VideoController get name");
	/* was lazy so just used system */
	std::cout << "\n";
    system("wmic diskdrive get serialnumber");
    std::cout << "\n";
    system("WMIC BIOS GET SERIALNUMBER");
    std::cout << "\n";
    system("getmac");
    std::cout << "\n";
    system("wmic csproduct get uuid");
	std::cout << "\n";
	system("wmic cpu get processorid");
	std::cout << "CPUID \n" << "{" << cpuId << "}" << std::endl;
	
	
	std::cout << "\n";
    std::cin.get();
}


