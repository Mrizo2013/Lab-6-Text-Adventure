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
	int x = 0;
	int y = 0;
	int playerX = 1;
	int playerY = 1;
	int keyX = rand( ) % mapWidth;
	int keyY = rand () % mapHeight;
	int doorX = rand () % mapWidth;
	int doorY = rand() % mapHeight;
	bool hasKey = false;
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

	cout << "Enter a X and Y index" << endl;
	cout << "X = ";
	cin >> x;
	cout << "Y = ";
	cin >> y;

	bool isDone = false;
	char choice;
	while (isDone == false)
	{
		cout << rooms[x][y] << endl;
		if (hasKey == true)
			cout << "You are carrying a key" << endl;
			
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

		if (x == keyX && y == keyY)
		{
			cout << "There is a key here." << endl;
			cout << "You picked up the key!" << endl;
			hasKey = true;
		}
		cout << endl;
		cout << "[N]orth, [S]outh, [E]ast, or [W]est? ";
		cin >> choice;
		choice = tolower(choice);

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
		
		cout << "YOU WIN!!!!";
			return 0;
			
	}
	
	

	//int randomNumber = rand() % n;

}
