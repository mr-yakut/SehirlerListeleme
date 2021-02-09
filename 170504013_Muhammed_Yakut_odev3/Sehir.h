#pragma once
#include <string>

/*
*@Muhammed
*Öğrenci adı: Muhammed Yakut
*Öğrenci kimliği: 170504013
*05.02.2021
*/

class Sehir
{
public:
	Sehir() {}
	Sehir(int id, const std::string& name, int count) : ID(id), isim(name), miktar(count) {}

	bool operator==(const Sehir& other) const
	{
		return other.ID == ID && other.isim == isim && other.miktar == miktar;
	}

	bool operator!=(const Sehir& other) const
	{
		return !((*this) == other);
	}

	inline int getID() const { return ID; }
	inline const std::string& getIsim() const { return isim; }
	inline int getMiktar() const { return miktar; }

private:
	int ID;
	std::string isim;
	int miktar;
};