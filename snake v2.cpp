#include <conio.h>
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;
const int ancho = 20;
const int alto = 20;

int x, y;
int frutaX, frutaY;
int puntaje;
int colaX[100], colaY[100];
int largocola;
enum direccion { STOP = 0, LEFT, RIGHT, UP, DOWN };
direccion sDir;

bool fin;

void Inicio()
{
	void init();
    fin = false;
    sDir = STOP;
    x = ancho / 2;
    y = alto / 2;
    frutaX = rand() % ancho;
    frutaY = rand() % alto;
    puntaje = 0;
}

void GuardarPuntaje(int puntaje) {
  fstream archivo("puntaje.txt",ios::out);
  archivo << puntaje;
  archivo.close();}

void Cargarjuego(string nombre)
{
	void init();
    system("cls");
    for (int i = 0; i < ancho + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j <= ancho; j++) {
            if (j == 0 || j == ancho)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == frutaY && j == frutaX)
                cout << "$";
            else {
                bool pcola = false;
                for (int k = 0; k < largocola; k++) {
                    if (colaX[k] == j
                        && colaY[k] == i) {
                        cout << "o";
                        pcola = true;
                    }
                }
                if (!pcola)
                    cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < ancho + 2; i++)
        cout << "#";
    cout << endl;
    cout <<" Puntaje de "<< nombre <<" : "<<  puntaje << endl;
    GuardarPuntaje(puntaje);

}

void Actualizar()
{
    int prevX = colaX[0];
    int prevY = colaY[0];
    int prev2X, prev2Y;
    colaX[0] = x;
    colaY[0] = y;

    for (int i = 1; i < largocola; i++) {
        prev2X = colaX[i];
        prev2Y = colaY[i];
        colaX[i] = prevX;
        colaY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
}
    switch (sDir) {

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
    }

    if (x >= ancho || x < 0 || y >= alto || y < 0)
        fin = true;
    for (int i = 0; i < largocola; i++) {
        if (colaX[i] == x && colaY[i] == y)
            fin = true;
    }
    if (x == frutaX && y == frutaY) {
        puntaje += 10;
        frutaX = rand() % ancho;
        frutaY = rand() % alto;
        largocola++;
    }
}

int Ajustardificultad()
{
    int dificultad, eleccion;
    cout << "\nSELECCIONE DIFICULTAD\n1: Facil\n2: Medio\n3: Dificil "<<endl;
    cout<<"Caso default: Medio"<<endl;
    cin >> eleccion;
    switch (eleccion) {
case '1':
        dificultad = 50;
        break;

    case '2':
        dificultad = 100;
        break;

    case '3':
        dificultad = 150;
        break;

    default:
        dificultad = 100;
    }
    return dificultad;
}


void Entrada_usuario()
{
    if (_kbhit()) {
        switch (_getch()) {

        case 'a':
            sDir = LEFT;
            break;

        case 'd':
            sDir = RIGHT;
            break;

        case 'w':
            sDir = UP;
            break;

        case 's':
            sDir = DOWN;
            break;

        case 'x':
            fin = true;
            break;
        }

    }
}

void creditos() {
    int opcion;
    do{system("cls");
    cout<<"**"<<endl;
    cout<<"Desarrolladores"<<endl;
    cout<<"Rommel Rivera"<<endl;
    cout<<"Nayeli Preciado"<<endl;
    cout<<"**"<<endl;
    cout<<"Presione 4, para volver al menu"<<endl;
    cin>>opcion;

    }while(opcion!=4);

}
void jugar()
{
    string nombre;
    cout << " Ingrese su nombre: ";
    cin >> nombre;
    int dificultad = Ajustardificultad();
    Inicio();
  void init();
    while (!fin) {
    	void init();
        Cargarjuego(nombre);
        Entrada_usuario();
        Actualizar();
        Sleep(dificultad);

}
}

struct Puntaje {
    string nombre;
    int puntaje;
};


int LeerPuntaje() {
  ifstream archivo("puntaje.txt");
  int puntaje;
  if (archivo.is_open()) {
    archivo >> puntaje;
    archivo.close();
  } else {
    puntaje = 0;
  }
  return puntaje;
}


int main()
{
     int opcion;
    Puntaje puntaje;

    do {

     system("cls");
    cout << "SNAKE" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Puntajes" << endl;
    cout << "3. Creditos" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch(opcion) {
            case 1:
            	void init();
                jugar();
                break;
            case 2:
                 cout<<LeerPuntaje();
                 Sleep(3000);

                break;
            case 3:
                creditos();
                break;
            case 4:
                break;
    }
    }while(opcion != 4);
    return 0;
}
