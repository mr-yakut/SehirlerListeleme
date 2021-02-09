#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Sehir.h"

/*
*@Muhammed
*Öðrenci adý: Muhammed Yakut
*Öðrenci kimliði: 170504013
*05.02.2021
*/

class SehirListesi
{
public:
	SehirListesi() {}

	SehirListesi(std::string filePath)
	{
		std::ifstream file(filePath.c_str());

		int id, count;
		std::string name;
		while (file >> id >> name >> count)
		{
			kayitlar.push_back(Sehir(id, name, count));
		}
		file.close();
	}

	void print()
	{

		for (int i = 0; i < kayitlar.size(); i++)
		{
			std::cout << "********************\n";
			std::cout << "Sehir ID'si: " << kayitlar[i].getID() << "\n";
			std::cout << "Sehir ismi: " << kayitlar[i].getIsim() << "\n";
			std::cout << "Sehir miktari: " << kayitlar[i].getMiktar() << "\n";
			std::cout << "********************\n";
		}
	}

	SehirListesi operator+(const SehirListesi& other)
	{
		SehirListesi result;
		for (int i = 0; i < kayitlar.size(); i++)
		{
			for (int j = 0; j < other.kayitlar.size(); j++)
			{
				if (kayitlar[i] == other.kayitlar[j])
					break;

				if (i == 0)
					result.kayitlar.push_back(other.kayitlar[j]);
			}

			result.kayitlar.push_back(kayitlar[i]);
		}
		return result;
	}

	SehirListesi operator-(const SehirListesi& other)
	{
		SehirListesi result;
		for (int i = 0; i < kayitlar.size(); i++)
		{
			bool same = false;
			for (int j = 0; j < other.kayitlar.size(); j++)
			{
				if (kayitlar[i] == other.kayitlar[j])
				{
					same = true;
					break;
				}
			}

			if (!same)
				result.kayitlar.push_back(kayitlar[i]);
		}
		return result;
	}

	SehirListesi operator&(const SehirListesi& other)
	{
		SehirListesi result;
		for (int i = 0; i < kayitlar.size(); i++)
		{
			for (int j = 0; j < other.kayitlar.size(); j++)
			{
				if (kayitlar[i] == other.kayitlar[j])
				{
					result.kayitlar.push_back(kayitlar[i]);
					break;
				}
			}
		}
		return result;
	}

	bool operator==(const SehirListesi& other)
	{
		bool same = false;
		int id_Tutucu;
		for (int i = 0; i < kayitlar.size(); i++)
		{

			for (int j = 0; j < other.kayitlar.size(); j++)
			{

				if (kayitlar[i].getID() == other.kayitlar[j].getID())
				{
					same = true;
					id_Tutucu = i;
					break;
				}
			}

			//	if (!same)
				//	return false;
		}
		//return true;
		std::cout << "********************\n";
		if (same)
			std::cout << kayitlar[id_Tutucu].getID() << "-> Sehir listeleri ayni!\n";
		else
			std::cout << kayitlar[id_Tutucu].getID() << " Sehir listeleri ayni deðil!\n";

	}

private:
	std::vector<Sehir> kayitlar;
};