#pragma once
class WezelDrzewaBST
{
public:
	WezelDrzewaBST* wskaznikNaOjca;
	WezelDrzewaBST* wskaznikNaSynaLewego;
	WezelDrzewaBST* wskaznikNaSynaPrawego;
	
	int wartoscWezla;

	WezelDrzewaBST()
	{
		wskaznikNaOjca = nullptr;
		wskaznikNaSynaLewego = nullptr;
		wskaznikNaSynaPrawego = nullptr;

		wartoscWezla = 0;
	}
	~WezelDrzewaBST();
};

