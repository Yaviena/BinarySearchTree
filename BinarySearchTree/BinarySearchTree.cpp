// Autor: Magda Szafranska, nr indeksu AHNS: 18345
// Informatyka NST, rok 2, sem. 3
// Lecture of algorithms - Binary Search Tree (BST)

#include <iostream>
#include <windows.h>

using namespace std;

int choice;
int* root;
int data_array[16];
bool empty_array[16];

// ----- a procedure to put the cursor in x and y positions -----
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void ShowTree()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    gotoxy(40, 1); if (empty_array[1] == true) cout << "_"; else cout << data_array[1];
    gotoxy(20, 4); if (empty_array[2] == true) cout << "_"; else cout << data_array[2];
    gotoxy(60, 4); if (empty_array[3] == true) cout << "_"; else cout << data_array[3];
    gotoxy(10, 6); if (empty_array[4] == true) cout << "_"; else cout << data_array[4];
    gotoxy(30, 6); if (empty_array[5] == true) cout << "_"; else cout << data_array[5];
    gotoxy(50, 6); if (empty_array[6] == true) cout << "_"; else cout << data_array[6];
    gotoxy(70, 6); if (empty_array[7] == true) cout << "_"; else cout << data_array[7];
    gotoxy(5, 10); if (empty_array[8] == true) cout << "_"; else cout << data_array[8];
    gotoxy(15, 10); if (empty_array[9] == true) cout << "_"; else cout << data_array[9];
    gotoxy(25, 10); if (empty_array[10] == true) cout << "_"; else cout << data_array[10];
    gotoxy(35, 10); if (empty_array[11] == true) cout << "_"; else cout << data_array[11];
    gotoxy(45, 10); if (empty_array[12] == true) cout << "_"; else cout << data_array[12];
    gotoxy(55, 10); if (empty_array[13] == true) cout << "_"; else cout << data_array[13];
    gotoxy(65, 10); if (empty_array[14] == true) cout << "_"; else cout << data_array[14];
    gotoxy(75, 10); if (empty_array[15] == true) cout << "_"; else cout << data_array[15];
    cout << endl << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// ----- adding a number to the tree -----
void add()
{
    int choosen_number;
    cout << "Jaka liczbe dodac do drzewa: ";
    cin >> choosen_number;

    // ----- empty tree -----
    if (empty_array[1] == true)
    {
        root = &data_array[1];
        *root = choosen_number;
        empty_array[1] = false;
    }
    else
    // ----- not empty tree -----
    {
        bool found_place = false;
        int node_nr = 1;

        while (found_place == false)
        {
            if (empty_array[node_nr] == true)
            {
                found_place = true;
                data_array[node_nr] = choosen_number;
                empty_array[node_nr] = false;

            }
            else if (choosen_number < data_array[node_nr])
            {
                // ----- put to the LEFT -----
                node_nr = 2 * node_nr;
            }
            else
            {
                // ----- put to the RIGHT -----
                node_nr = 2 * node_nr + 1;
            }
            if (node_nr > 15)
            {
                cout << "Potrzebne byloby wieksze drzewo!";
                Sleep(3000);
                found_place = true;
            }
        }
    }
}

void find()
{
    int number;
    cout << "Jaka liczbe znalezc w drzewie: ";
    cin >> number;

    bool found = false;
    int node_of_the_number = 1;

    while (found == false)
    {
        if (number == data_array[node_of_the_number])
        {
            cout << "Znaleziono liczbe w wezle nr: " << node_of_the_number;
            Sleep(3000);

            found = true;
        }
        else if (number < data_array[node_of_the_number])
        {
            // ----- go to the LEFT -----
            node_of_the_number = 2 * node_of_the_number;
        }
        else
        {
            // ----- go to the RIGHT -----
            node_of_the_number = 2 * node_of_the_number + 1;
        }
        if (node_of_the_number > 15)
        {
            cout << "Nie znaleziono!";
            Sleep(3000);
            found = true;
        }
    }
}

int main()
{
    for (int i = 1; i <= 15; i++)
    {
        empty_array[i] = true;
    }
    root = NULL;

    do
    {
        ShowTree();

        cout << "----------------------------------" << endl;
        cout << "   EMULATOR DRZEWA BINARNEGO " << endl;
        cout << "----------------------------------" << endl;
        cout << "1. ADD (dodaje element do drzewa)" << endl;
        cout << "2. FIND (szuka elementu w drzewie)" << endl;
        cout << "3. EXIT (zakonczy ten program)" << endl;
        cout << "----------------------------------" << endl;
        cout << "   WYBOR: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1: add(); break;
        case 2: find(); break;
        }

    } while (choice != 3);

    return 0;
}