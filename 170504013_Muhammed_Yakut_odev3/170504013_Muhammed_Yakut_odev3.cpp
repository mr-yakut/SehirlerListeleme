#include "SehirListesi.h"

/*
*@Muhammed
*Öðrenci adý: Muhammed Yakut
*Öðrenci kimliði: 170504013
*05.02.2021
*/

int main()
{
	SehirListesi S1("sehirler1.txt"), S2("sehirler2.txt");
	SehirListesi L1, L2, L3, L4;

	S1 == S2;
	L1 = S1 + S2;
	L2 = S1 & S2;
	L3 = S1 - S2;
	L4 = S2 - S1;

	std::cout << "L1:\n";
	L1.print();
	std::cout << "L2:\n";
	L2.print();
	std::cout << "L3:\n";
	L3.print();
	std::cout << "L4:\n";
	L4.print();
}