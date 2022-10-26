// Laba1-Hammurabi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int GetRand(int min, int max)
{
	srand(time(nullptr));

	int num = min + rand() % (max - min + 1);

	return num;
}

class City
{
public:
	City(): m_citizens(100), m_wheat(2800), m_acresOfLands(1000) {}
	~City();

	int getCitizen() { return m_citizens; }
	int updateCitizen(int newCitizens) { return m_citizens += newCitizens; }
	int setCitizen(int setcitizen) { return m_citizens = setcitizen; }

	int getWheat() { return m_wheat; }
	int updateWheat(int newWheat) { return m_wheat += newWheat; }
	int setWheat(int setNewWheat) { return m_wheat = setNewWheat; }

	int getAcresOfLands() { return m_acresOfLands;}
	int setAcresOfLands(int setNewAcres) { return m_acresOfLands = setNewAcres; }

	int getDeathFromHunger() { return deathFromHunger; }
	int setDeathFromHunger(int death) { return deathFromHunger = death ;}
	int calculateDeath() {return  deathFromHunger = (m_citizens * wheatForFood - food) / wheatForFood;}

	int calculateAmountOfFoodAfterMeal() { return foodAfterMeal = food - m_citizens * wheatForFood;	}

	int getFoodAfterMeal(){ return foodAfterMeal; }

	int getAcresForPerson() { return acresForPerson; }

	int getwheatForAcres() { return wheatForAcres; }

	int food = -1;////////////////

private:
	int m_citizens;
	int m_wheat;
	int m_acresOfLands;

	int acresForPerson = 10;

	int producedWheat = 0;////////

	int wheatForAcres = 5;///////////////////
	int wheatForFood = 20;
	int foodAfterMeal = 0;

	int deathFromHunger = 0;
};

//City::City()
//{
//}

City::~City()
{
}

int Plague(City city) {
	double calculatePlague;
	int deathFromPlague;

	calculatePlague = GetRand(1, 100) / 85.0;
	if (calculatePlague >= 1) {
		deathFromPlague = city.getCitizen() / 2;
		return deathFromPlague;
	}
	else
	{
		return deathFromPlague = 0;
	}

}

int GetRandFloat(float min, float max)
{
	srand(time(nullptr));

	float num = min + rand() / (max - min + 1);

	return num;
}

class GameRules
{
public:
	GameRules() : m_currentRound(1) { ; }

	int getCurrentRound(){ return m_currentRound; }
	int setCurrentRound(int turn) { return m_currentRound = turn; }
	int updateCurrentRound(int newTurn) { return m_currentRound += newTurn;}
private:

	int m_currentRound = 1;
};

class Player
{
public:
	Player() {;}// возможно вставить Rules сюда и переименовать класс в TheGame

	int setAcresPrice(int price) { return acresPrice = price; }
	int changeAcresPrice() {
		acresPrice = GetRand(17, 26);}

	int buyAcres = -1;
	int sellAcres = -1;
	int acresForCultivation = -1;

private:


	int acresPrice = 0;
};

bool isGameOver(int oldCitizens, int newCitizens) {

	int calculateCitizens = newCitizens * 100 / oldCitizens;

	if (calculateCitizens < 45) {
		cout << "game over";
		return true;
	}
	else
	{
		return false;
	}

}

void SaveGame(City city, Player player, GameRules rules) {
	ofstream saveFile;
	saveFile.open("SaveFile.txt");
	if (saveFile.is_open()) {
		saveFile << city.getCitizen() << " " << city.getWheat() << " " << city.getAcresOfLands() << " "
			<< rules.getCurrentRound() << " " << player.acresForCultivation << " " << city.food<< " ";
	}
	else
	{
		cout << "ошибка в записи файла";
	}

	saveFile.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	City capitalCity;
	Player thegame;
	GameRules rules;

	int wheatFromAcres;
	int collectedNewWeat;

	int newCitizens;

	int plagueisValid;

	float ratRandomEats;
	int ratEats;

	int acresPrice;

	int citizensAtStartRound = 0;

	int tempWheat = 0;
	int tempAcres = 0;

	bool checkGameOver;
	
	int continueGame = 0;
	bool check = false;

	float p = 0;
	float l = 0;

	ifstream loadGame("SaveFile.txt");
	if (loadGame) {
		 check = false;

		cout << "Обнаружено сохранение\n";
		cout << "Хотите продолжить игру с сохранения?\n";
		cout << "Введите цифру 1 для продолжения или введите цифру 2 чтобы начать игру заново\n";
		cin >> continueGame;

		if (continueGame == 1 || continueGame == 2)
			check = true;

		while (check == false)
		{
			cout << "Вы ввели неверное значение!\n";
			cout << "Введите цифру 1 для продолжения или введите цифру 2 чтобы начать игру заново\n";
			cin >> continueGame;

			if (continueGame == 1 || continueGame == 2)
				check = true;
		}

		if (continueGame == 1) {
			int setCitizen, setWheat, setAcresOfLands, setCurrentRound, setAcresForCultivation, setFood;
			loadGame >> setCitizen >> setWheat >> setAcresOfLands >> setCurrentRound >> thegame.acresForCultivation >> setFood;
			capitalCity.setCitizen(setCitizen);
			capitalCity.setWheat(setWheat);
			capitalCity.setAcresOfLands(setAcresOfLands);
			rules.setCurrentRound(setCurrentRound);
			capitalCity.food = setFood;

			cout << "С возвращением, милорд\n";
		}
	}

	while (rules.getCurrentRound() <= 10)
	{
		newCitizens = 0;
		acresPrice = thegame.setAcresPrice(GetRand(17, 26));
		plagueisValid = 0;

	if (rules.getCurrentRound() == 1) {
		cout << "Мой повелитель, соизволь поведать тебе: \n";
		cout << "Текущий раунд - " << rules.getCurrentRound() << "\n";
		cout << "Всего жителей в городе - " << capitalCity.getCitizen() << "\n";
		cout << "Всего в городе " << capitalCity.getWheat() << " бушелей пшеницы " << "\n";;
		cout << "Город занимает - " << capitalCity.getAcresOfLands() << " акров\n";
		cout << "Цена одного акра в этом году - " << acresPrice << "\n";

	}

	if (rules.getCurrentRound() > 1) {
		ratRandomEats = GetRand(0, 7) * 0.01;
		 wheatFromAcres = GetRand(1, 6);
		 collectedNewWeat = thegame.acresForCultivation * wheatFromAcres;
		citizensAtStartRound = capitalCity.getCitizen();

		cout << "Мой повелитель, соизволь поведать тебе: \n";
		cout << "В году " << rules.getCurrentRound() << " твоего высочайшего правления, " << "\n";

		if (capitalCity.calculateAmountOfFoodAfterMeal() >= 0) {
			capitalCity.setDeathFromHunger(0);
		}
		else
		{
			capitalCity.calculateDeath();

			cout << capitalCity.getDeathFromHunger()<< " человек умерли с голода ";
			capitalCity.updateCitizen(-capitalCity.getDeathFromHunger());
		}
		if (capitalCity.getCitizen() <= 0) {
			cout <<"\n" << "game over yeaaaaaaaah";
			return 0;
		}

		checkGameOver = isGameOver(citizensAtStartRound, capitalCity.getCitizen());
		if (checkGameOver == true) {
			return 0;
		}
	
		newCitizens = capitalCity.getDeathFromHunger() / 2 + (5 - wheatFromAcres) * capitalCity.getWheat() / 600 + 1;
		if (newCitizens > 50) {
			newCitizens = 50;
			cout << newCitizens << " человек прибыли в наш великий город" << "\n";
		}
		else if (newCitizens < 0)
		{
				newCitizens = 0;
		}
		else if (newCitizens > 0)
		{
			cout << newCitizens << " человек прибыли в наш великий город" << "\n";
		}

		capitalCity.updateCitizen(newCitizens);

		plagueisValid = Plague(capitalCity);
		if (plagueisValid != 0) {
			capitalCity.updateCitizen(-plagueisValid);
			cout << "Чума уничтожила половину населения" << "\n";

			checkGameOver = isGameOver(citizensAtStartRound, capitalCity.getCitizen());
			if (checkGameOver == true) {
				return 0;
			}
		}

		cout << "Население города сейчас составляет " << capitalCity.getCitizen() << "\n";

		cout << "Мы собрали " << collectedNewWeat << " бушелей пшеницы, " << "по " << wheatFromAcres <<" бушеля с акра " << "\n";
		capitalCity.updateWheat(collectedNewWeat);

		ratEats = ratRandomEats * capitalCity.getWheat();
		cout << "Крысы истребили " << ratEats <<" бушелей пшеницы, оставив "<<capitalCity.getWheat() - ratEats <<" бушеля в амбарах"<< "\n";
		capitalCity.updateWheat(-ratEats);

		cout << "Город сейчас занимает " << capitalCity.getAcresOfLands() << " акров\n";
		cout << "1 акр земли стоит сейчас " << acresPrice<< " бушелей";
		cout << "\n"<< "\n";

		
	;}
	/*
		cout << "Государь, сколько акров земли вы хотите купить ?";
		cin >> thegame.buyAcres;
		if (capitalCity.getWheat() < thegame.buyAcres * acresPrice) {
			cout << "Простите, но у нас недостаточно денег для покупки " << thegame.buyAcres << "-ти акров, укажите другое число";
			cin >> thegame.buyAcres;
		}
		if (thegame.buyAcres < 0) {
			cout << "Введите не отрицательное значение ";
			cin >> thegame.buyAcres;
		}
		capitalCity.getWheat() - thegame.buyAcres;
		capitalCity.getAcresOfLands() + thegame.buyAcres;
			
		cout << "Государь, сколько акров земли вы хотите продать ?";
		cin >> thegame.sellAcres;
		if (thegame.sellAcres > capitalCity.getAcresOfLands())
		{
			cout << "Простие, у вас нет столько акров земли, введите другое число ";
			cin >> thegame.sellAcres;
		}
		if (thegame.sellAcres < 0) {
			cout << "Введите не отрицательное значение ";
			cin >> thegame.sellAcres;
		}

		cout << "Государь, сколько бушелей пшеницы вы хотите использовать в качестве еды ?";
		cin >> capitalCity.food;
		if (capitalCity.food < 0) {
			cout << "Введите не отрицательное значение ";
			cin >> capitalCity.food;
		}
		if (capitalCity.food > capitalCity.getWheat()) {
			cout << "У нас нет столько пшеницы, введите другое число ";
			cin >> capitalCity.food;
		}

		cout << "Государь, какое количество акров земли необходимо зесять пшеницей ?";
		cin >> thegame.acresForCultivation;
		if (thegame.acresForCultivation > capitalCity.getCitizen() * capitalCity.getAcresForPerson()) {
			cout << "Наши жители не могут позволить обработать столько акров, введите другое число ";
			cin >> thegame.acresForCultivation;
		}
		if (thegame.acresForCultivation > capitalCity.getAcresOfLands()) {
			cout << "У нас нет столько акров земли, введите другое число ";
			cin >> thegame.acresForCultivation;
		}
		if (thegame.acresForCultivation < 0) {
			cout << "Введите не отрицательное значение ";
			cin >> thegame.acresForCultivation;
		}
		if (thegame.acresForCultivation * capitalCity.getwheatForAcres() > capitalCity.getWheat()) {
			cout << "у нас не хватает пшеницы ";
			cin >> thegame.acresForCultivation;
		}
		*/

		thegame.sellAcres = -1;
		thegame.buyAcres = -1;
		capitalCity.food = -1;
		thegame.acresForCultivation = -1;

		cout << "Что пожелаешь, повелитель? " << "\n";;

		do
		{
			tempWheat = 0;
			tempAcres = 0;

			cout << "Сколько акров земли повелеваешь купить ? ";
			cin >> thegame.buyAcres;
			tempWheat = capitalCity.getWheat() - thegame.buyAcres * acresPrice;
			tempAcres = capitalCity.getAcresOfLands() + thegame.buyAcres;

			cout << "Сколько акров земли повелеваешь продать? ";
			cin >> thegame.sellAcres;
			tempWheat = tempWheat + thegame.sellAcres * acresPrice;
			tempAcres = tempAcres - thegame.sellAcres;

			cout << "Сколько бушелей пшеницы повелеваешь съесть? ";
			cin >> capitalCity.food;
			tempWheat = tempWheat - capitalCity.food;

			cout << "Сколько акров земли повелеваешь засеять?";
			cin >> thegame.acresForCultivation;
			tempWheat = tempWheat - thegame.acresForCultivation * capitalCity.getwheatForAcres();

			if (capitalCity.getWheat() < thegame.buyAcres * acresPrice || thegame.buyAcres < 0
				|| thegame.sellAcres > capitalCity.getAcresOfLands() + thegame.buyAcres || thegame.sellAcres < 0
				|| capitalCity.food > capitalCity.getWheat() - (thegame.buyAcres * acresPrice) + (thegame.sellAcres * acresPrice)
				|| capitalCity.food < 0
				|| thegame.acresForCultivation > capitalCity.getCitizen() * capitalCity.getAcresForPerson()
				|| thegame.acresForCultivation > capitalCity.getAcresOfLands() + thegame.buyAcres - thegame.sellAcres
				|| thegame.acresForCultivation * capitalCity.getwheatForAcres() > capitalCity.getWheat() - (thegame.buyAcres * acresPrice) + (thegame.sellAcres * acresPrice) - capitalCity.food
				|| thegame.acresForCultivation < 0)
			{
				cout << "О, повелитель, пощади нас! У нас только " << capitalCity.getCitizen()
					<< " человек " << capitalCity.getWheat() << " бушелей пшеницы и " << capitalCity.getAcresOfLands() << " акров земли! " << "\n";;
			}

			cout << "\n";
			cout << "\n";

		} while (capitalCity.getWheat() < thegame.buyAcres * acresPrice || thegame.buyAcres < 0
			|| thegame.sellAcres > capitalCity.getAcresOfLands() + thegame.buyAcres || thegame.sellAcres < 0
			|| capitalCity.food > capitalCity.getWheat() - (thegame.buyAcres * acresPrice) + (thegame.sellAcres * acresPrice)
			|| capitalCity.food < 0
			|| thegame.acresForCultivation > capitalCity.getCitizen() * capitalCity.getAcresForPerson()
			|| thegame.acresForCultivation > capitalCity.getAcresOfLands() + thegame.buyAcres - thegame.sellAcres
			|| thegame.acresForCultivation * capitalCity.getwheatForAcres() > capitalCity.getWheat() - (thegame.buyAcres * acresPrice) + (thegame.sellAcres * acresPrice) - capitalCity.food
			|| thegame.acresForCultivation < 0);

		/*while (capitalCity.getWheat() < thegame.buyAcres * acresPrice || thegame.buyAcres < 0
			|| thegame.sellAcres > capitalCity.getAcresOfLands() || thegame.sellAcres < 0
			|| capitalCity.food > capitalCity.getWheat() || capitalCity.food < 0
			|| thegame.acresForCultivation > capitalCity.getCitizen() * capitalCity.getAcresForPerson()
			|| thegame.acresForCultivation > capitalCity.getAcresOfLands()
			|| thegame.acresForCultivation * capitalCity.getwheatForAcres() > capitalCity.getWheat()
			|| thegame.acresForCultivation < 0);*/

		capitalCity.setAcresOfLands(tempAcres);
		capitalCity.setWheat(tempWheat);

		p += capitalCity.getDeathFromHunger();


		rules.updateCurrentRound(1);

		check = false;

		cout << "Хотите продолжить игру?\n";
		cout << "Введите цифру 1 для продолжения или введите цифру 2 чтобы выйти из игры и сохраниться\n";
		cin >> continueGame;

		if (continueGame == 1 || continueGame == 2)
			check = true;

		while (check == false)
		{
			cout << "Вы ввели неверное значение!\n";
			cout << "Введите цифру 1 для продолжения или введите цифру 2 чтобы выйти из игры и сохраниться\n";
			cin >> continueGame;

			if (continueGame == 1 || continueGame == 2)
				check = true;
		}

		if (continueGame == 2) {
			SaveGame(capitalCity, thegame, rules);
			return 0;
		}

		; }

	 p = capitalCity.getDeathFromHunger() / 10.0;
	 l = capitalCity.getAcresOfLands() / capitalCity.getCitizen();

	if (rules.getCurrentRound() == 12) {
		cout << "В этот год из-за голода умерло слишком много людей, после чего "
			"в вашу спальню был подослан убийца одного из соседних царств. "
			"Воспользовавшись вашей смертью и неразберихой, оно полностью захватило "
			"все земли после вашей смерти..." << endl;
	}
	else if (rules.getCurrentRound() == 11 && p > 33 && l < 7) {
		cout << "Из-за вашей некомпетентности в управлении, народ устроил бунт, "
			"и изгнал вас их города. "
			"Теперь вы вынуждены влачить жалкое существование в изгнании..." << endl;
	}
	else if (rules.getCurrentRound() == 11 && p > 10 && l < 9) {
		cout << "Вы правили железной рукой, подобно Нерону и Ивану Грозному. "
			"Народ вздохнул с облегчением, "
			"и никто больше не желает видеть вас правителем..." << endl;
	}
	else if (rules.getCurrentRound() == 11 && p > 3 && l < 10) {
		cout << "Вы справились вполне неплохо, у вас, "
			"конечно, есть недоброжелатели, но многие хотели бы увидеть вас во "
			"главе города снова" << endl;
	}
	else if (rules.getCurrentRound() == 11) {
		cout << "Фантастика! Карл Великий, "
			"Дизраэли и Джефферсон вместе не справились бы лучше" << endl;
	}
	else return 0;

} 

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
