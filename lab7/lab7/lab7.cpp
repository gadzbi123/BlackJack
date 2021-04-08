#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <fstream>

static std::mutex mtx;
std::condition_variable cv;

void funkcjaKopiujWektor(const std::vector<int> & a, std::vector<int> & b) {
	for (auto i : a)
	{
		std::unique_lock<std::mutex>blokada(mtx);
		std::cout << std::this_thread::get_id() << std::endl;
		b.push_back(i);
	}
}

class CopyVector
{
public:
	void operator()(const std::vector<int>& a, std::vector<int>& b) {
		for (auto i : a)
		{
			std::lock_guard<std::mutex>blokada(mtx);
			std::cout << std::this_thread::get_id() << std::endl;
			b.push_back(i);
		}
	}
};

class ZapiszDoPliku
{
private:
 	std::string sciezkaDoPliku;
	std::vector<std::string>slowa;

public:
	ZapiszDoPliku(const std::string& sciezkaDoPliku) : sciezkaDoPliku(sciezkaDoPliku) {}
	void Wypelnij()
	{
		for (int i = 0; i < 5; i++)
		{
			std::string temp;
			std::cin >> temp;
			slowa.push_back(std::move(temp));
			cv.notify_all();
		}
	}
	void Zapisz()
	{
		std::ofstream plik(sciezkaDoPliku);
		for (int i = 0; i < 5; i++)
		{
			std::unique_lock < std::mutex> lck(mtx);
			cv.wait(lck, [=] {return i + 1 <= slowa.size(); });
			plik << slowa[i] << '\n';
		}
		plik.close();
	}
	
};

int main()
{
	//Zad1
	std::cout << std::thread::hardware_concurrency() << std::endl;

	//Zad 2
	std::vector<int> wek1 = { 3,13,44,22,66,88,25,11 };
	std::vector<int> wek2 = { 113,183,244,522,766,888,925,111 };
	std::vector<int> wek3;

	

	CopyVector objekt;
	std::thread t1(funkcjaKopiujWektor, std::cref(wek1), ref(wek3));
	std::thread t2(std::ref(objekt), cref(wek2), ref(wek3));
	
	t1.join();
	t2.join();
	
	for (auto i : wek3)
	{
		std::cout << (i) << " ";
	}
	std::cout << std::endl;

	//Zad3
	ZapiszDoPliku plik("zadanie.txt");
	std::thread t3(&ZapiszDoPliku::Wypelnij, &plik);
	std::thread t4(&ZapiszDoPliku::Zapisz, &plik);

	std::cout << "Podaj 5 slow" << std::endl;
	t3.join();
	t4.join();
}
