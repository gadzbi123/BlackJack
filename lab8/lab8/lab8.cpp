#include <iostream>
#include <regex>
#include <string>

bool podwojne_a_search(std::string str)
{
	std::regex dwaA("(a){2}");
	bool jestAA=false;
	jestAA=std::regex_search(str, dwaA);
	if (jestAA)
		std::cout << str << " /|\\ ";
	return jestAA;
}

bool podwojne_a_match(std::string str)
{
	std::regex dwaA(".*(a){2}.*");
	bool jestAA = false;
	jestAA = std::regex_match(str, dwaA);
	if (jestAA)
		std::cout << str << " /|\\ ";

	return jestAA;
}

void wpisz_godzine()
{
	bool poprawna_godzina = false;
	std::string insert;
	std::regex godzina("^(0{2}|[1-9]|1[0-9]|2[0-3]):([0-5][0-9])$");
	while (poprawna_godzina == false)
	{
		std::cout << "Wpisz godzine XX:XX\n";
		std::cin >> insert;
		if (std::regex_match(insert, godzina))
		{
			std::cout << "Wpisano pomyslnie\n";
			poprawna_godzina = true;
		}
	}
}

void wpisz_email()
{
	bool poprawny_email = false;
	std::string insert;
	std::regex email("^[a-zA-Z0-9]{5,}@(gmail.com|onet.pl|wp.pl|o2.com)$");
	std::smatch koncowka;

	while (poprawny_email == false)
	{
		std::cout << "Wpisz email\n";
		std::cin >> insert;
		if (std::regex_match(insert, koncowka,email))
		{
			std::cout << "Wpisano pomyslnie z koncowka: " << koncowka[1].str() << std::endl;
			poprawny_email = true;
		}
	}
}

int main()
{
	std::vector<std::string> vec = { "aaaa","aa","bab","aba","abababbbbbaaaababbbbaaaa" };

	//Zad 1
	std::cout << "search: \n";
	for (int i = 0; i < vec.size(); i++)
		podwojne_a_search(vec[i]);
	std::cout << std::endl;

	std::cout << "match: \n";
	for (int i = 0; i < vec.size(); i++)
		podwojne_a_match(vec[i]);
	std::cout << std::endl;

	//Zad 2
	//wpisz_godzine();

	//Zad 3
	//wpisz_email();

	//Zad 4
	std::string numery_tel = { "023 456 789, 223 - 111 - 555, 666 666 666, 999-999-999" };
	std::regex reg("[1-9]{3}(-|\\s)\\d{3}(-|\\s)\\d{3}");
	std::cout << numery_tel << std::endl;
	std::string x = std::regex_replace(numery_tel, reg, "numery_telefonu");
	std::cout << x << std::endl;

	//Zad 5
	std::string bog("Bog zas pokoju zetrze wkrutce szatana pod waszymi stopami.Laska Pana naszego Jezusa Chrystusa niech bedzie z wami !");
	std::regex dwie_sam("[\\w^aeiouy]*([aeiouy][\\w^aeiouy]*){2}[\\w]*", std::regex::icase);

	auto words_begin = std::sregex_iterator(bog.begin(), bog.end(), dwie_sam);
	auto words_end = std::sregex_iterator(); //pusty iterator - odpowiednik metody end dla kontenera

	std::cout << "Znaleziono " << std::distance(words_begin, words_end) << " slow:\n";

	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{
		std::smatch dopasuj = *i;
		std::cout << dopasuj.str() << '\n';
	}
}
