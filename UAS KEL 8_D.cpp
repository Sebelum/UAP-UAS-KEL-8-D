/* 		Kelompok 8 Kelas D
	Muhammad Fadhilah Ramdhani	(2157051006)
	Myshel Wihasna Prastika		(2117051061)
	Nindi Restu Pembayun		(2117051021)
*/

#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

using namespace std;


const int panjang = 30;
const int lebar = 20;
int x, y, foodX, foodY, score, nEkor,warna;
string nama;
char back;
int ekorX[1000], ekorY[1000];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
bool GameOver;


void gotoxy(int x, int y){
	COORD coord ;
	coord.X = x ;
	coord.Y = y ;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Loading(){
	
	
	for(int i=0;i<=100;i++){
		system("cls");
		gotoxy(35,12); cout<<"\t\t Loading..."<<i<<"%"<<endl;
		
	
	gotoxy(35,13);
	for(int j=1;j<=i;j++){
		if (j%2==0){
			cout<<"|";
		}
	}cout<<endl;
	usleep(10);
	}getch;
	system("cls");

}

void Warning(){
	
	cout << "PERATURAN PERMAINAN!\n\n";
	cout << "\t\tJika ekor sudah melebihi 2 dan Anda menekan tombol\n\t\tyang berlawanan, misalkan ular bergerak ke atas\n\t\tlalu Anda menekan tombol bawah,\n\t\tmaka permainan akan selesai\n\n";
	cout << "\t\tJika Anda menabrak ekor sendiri maka permainan akan selesai\n\n";
	cout << " Tekan apapun lalu Enter untuk melanjutkan ";
	int a;
	cin>>a;
	getch();
}

void Setup(){
    GameOver = false;
    dir = STOP;
    x = panjang / 2;
    y = lebar / 2;
    foodX = rand() % panjang;
    foodY = rand() % lebar;
    score = 0;
}

void Arena(){
	
    system("cls");
    for (int i = 0; i < panjang+2; i++)
        cout << "$";
    cout << endl;
 	
    for (int i = 0; i < lebar; i++)
    {
        for (int j = 0; j < panjang; j++)
        {
            if (j == 0)
                cout << "$";
            if (i == y && j == x)
                cout << "\1";
            else if (i == foodY && j == foodX)
                cout << "\2";
            else
            {
                bool print = false;
                for (int k = 0; k < nEkor; k++)
                {
                    if (ekorX[k] == j && ekorY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == panjang - 1)
                cout << "$";
        }
        cout << endl;
    }
 
    for (int i = 0; i < panjang+2; i++)
        cout << "$";
    cout << endl;
    cout << "Score : " << score << endl;
}

void Movement(){
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }
}

void Body(){
    int tambahX = ekorX[0];
    int tambahY = ekorY[0];
    int tambah2X, tambah2Y;
    ekorX[0] = x;
    ekorY[0] = y;
    for (int i = 1; i < nEkor; i++)
    {
        tambah2X = ekorX[i];
        tambah2Y = ekorY[i];
        ekorX[i] = tambahX;
        ekorY[i] = tambahY;
        tambahX = tambah2X;
        tambahY = tambah2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    
    if (x >= panjang) x = 0; else if (x < 0) x = panjang - 1;
    if (y >= lebar) y = 0; else if (y < 0) y = lebar - 1;
 
    for (int i = 0; i < nEkor; i++)
        if (ekorX[i] == x && ekorY[i] == y)
            GameOver = true;
         	cout << "Gunakan W,A,S,D untuk bergerak" << endl << endl;
 			
    if (x == foodX && y == foodY)
    {
        score += 10;
        foodX = rand() % panjang;
        foodY = rand() % lebar;
        nEkor++;
    }
}

void Color(){

	
	switch (warna){
		case 1:
		 	system("color 71");
			break;
		case 2:
		 	system("color 70");	
			break;
		case 3:
			system("color 72");	
			break;
		default:
			system("color 75");
			break;
	}
}

void Change(){
	gotoxy(60,4);
	cout<<"Pilahan warna : "<<endl;
	gotoxy(60,6);cout<<"   kode 1 = Merah";
		gotoxy(60,8);
	cout<<"   kode 2 = Hitam";
			gotoxy(60,10);
	cout<<"   kode 3 = Hijau"<<endl;
			
}

int main(){
	

	Loading();
	
	system("color 75");
	
	gotoxy(2,3);cout << " LOGIN : ";
	
	gotoxy(2,7);cout << " Masukan Nama Pemain : "; 
	cin >> nama; 

	gotoxy(2,9);cout<< " Pilih warna ular : ";
	
	Change();
	
	gotoxy(22,9);cin >> warna;
	system("cls");
	
	gotoxy(2,3);Warning();
	Color();
    Setup();
    while (!GameOver)
    {
        Arena();
        Movement();
        Body();
        Sleep(20);
    }
  	cout << "Permainan selesai!" << endl;
	cout << "  Score " <<nama<< " adalah : " << score;


    
    return 0;
}
