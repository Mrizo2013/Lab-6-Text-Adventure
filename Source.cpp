#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	srand(time(NULL));

	string rooms[4][3];
	int mapWidth = 4;
	int mapHeight = 3;
	int x = 1;
	int y = 1;
	int keyX = rand( ) % mapWidth;
	int keyY = rand () % mapHeight;
	int doorX = rand () % mapWidth;
	int doorY = rand() % mapHeight;
	int monsterX = rand() % mapHeight;
	int monsterY = rand() % mapHeight;
	int monsterChoice = rand() % 2;
	int playerChoice;
	bool fight = true;
	bool hasKey = false;
	bool isDone = false;
	char choice;
	rooms[0][0] = "wall";
	rooms[0][1] = "village enterance";
	rooms[0][2] = "Village Inn \n You could order some tasty pancakes here.";
	rooms[1][0] = "cliff";
	rooms[1][1] = "grassy field";
	rooms[1][2] = "wall";
	rooms[2][0] = "cave entrance";
	rooms[2][1] = "wall";
	rooms[2][2] = "wall";
	rooms[3][0] = "inside cave";
	rooms[3][1] = "deep cave";
	rooms[3][2] = "wall";

	
	while (isDone == false)
	{
		cout << rooms[x][y] << endl;
		//Checks key status
		if (hasKey == true)
			cout << "You are carrying a key" << endl;

		// Checks door status
		if (x == doorX && y == doorY)
		{
			if (hasKey == true)
			{
				cout << "You have unlocked the door!" << endl;
				break;
			}
			else
				cout << "There is a door here, but it is locked." << endl;
		}
		// Picks up Key
		if (x == keyX && y == keyY)
		{
			cout << "There is a key here." << endl;
			cout << "You picked up the key!" << endl;
			hasKey = true;
		}

		// Monster
		// Fight gets stuck
		// Work in progress
		if (x == monsterX && y == monsterY)
		{
			cout << "There is a monster here!!!" << endl;
			cout << "Prepare to fight!!" << endl;
			cout << endl;
			cout << "Pick a number (1, 2, or 3)";
			while (fight == true)
				cin >> playerChoice;
			if (!(playerChoice == 1 || playerChoice == 2 || playerChoice == 3))
			{
				cout << "You have chosen poorly and are dead";
				break;
			}
			playerChoice--;
			if (playerChoice != monsterChoice)

			{
				cout << "You killed the Monster, Good Job!!!";
				fight = false;
			}
			else
			{
				cout << "You have chosen poorly and are dead";
				break;
			}
			break;
		}

		// Gets player choices
		cout << endl;
		cout << "[N]orth, [S]outh, [E]ast, or [W]est? ";
		cin >> choice;
		choice = tolower(choice);

		// Checks player choices
		if (choice == 'n')
			if (y > 0)
				y--;
			else cout << "Invalid choice!" << endl;
			if (choice == 's')
				if (y < mapHeight - 1)
					y++;
				else cout << "Invalid choice!" << endl;
				if (choice == 'e')
					if (x < mapWidth - 1)
						x++;
					else cout << "Invalid choice!" << endl;
					if (choice == 'w')
						if (x > 0)
							x--;
						else cout << "Invalid choice!" << endl;
						if (!(choice == 'n' || choice == 's' || choice == 'e' || choice == 'w'))
							cout << "Invalid choice!" << endl;
	}
		cout << "YOU WIN!!!!";
			return 0;
			
	
	
}
