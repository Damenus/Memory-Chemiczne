//POP_2014_12_11_projekt_1_Darczuk_Damian_EiT_2_154824
//Dev-c++ 5.7.1
//TDM-GCC 4.8.1 64-bit Release
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct kafel{
	string nazwachemiczna;	
	int indeks;
	bool czyzgadniety;	
};

struct para{
	int liczba;
	int zbior;
	
};

void piszmenu(int nr);

void pierwszyWiersz(int n)
{
	cout << "XXXX";
	for(int i=0; i<n ;i++)
		{
		cout<< " " << i+1 << " " ;
			for(int j=0; j<11; j++)
				cout << "X";
		}	
		cout << endl;
}

void pustyjedenkafel()
{
		cout << "|";
			for(int j=0; j<11; j++)
				cout << " ";
			cout << "| ";
	
}

void pelnyjedenkafel(int i, int k, kafel** K)
{
	cout << "| ";
			cout << K[i][k].nazwachemiczna; 
			for(int j=0; j<10-K[i][k].nazwachemiczna.length(); j++)
				cout << " ";
			cout << "| ";	 
	
}
/*
void pelnyjedenkafel(int i, int k, kafel** K)
{
	cout << "| ";
			cout << K[i][k].indeks; 
			for(int j=0; j<9; j++)
				cout << " ";
			cout << "| ";	 
	
}
*/
void krawendz(int a, int n, kafel** K)
{
	cout << "X";
	for(int k=0; k<n; k++)
		{
			if (K[a][k].czyzgadniety == false)  
				{	
					for(int j=0; j<14; j++)
						cout << " ";
				}
			else
					{
						cout << "  ";
						for(int j=0; j<11; j++)
							cout << "-";
						cout << " ";
					}
				
		}
	cout << "  X" << endl;	
}

void wnetrze(int a, int n, kafel **K)
{
	cout << "  ";
	for(int k=0; k<n; k++)
		{
			if (K[a][k].czyzgadniety == false)  
			{	
				for(int j=0; j<14; j++)
					cout << " ";
			}
		 else
			pustyjedenkafel();
		}
	cout << endl;
	
}

//pierwszywiersz
//krawedz
//wnetrze
//srodek
//wnetrze
//krawedz
//pierwszywiersz

void rysujWskazaneKafle(int n, int m, int f,int g,int h,int i,kafel** K)
{
	pierwszyWiersz (n);
	
	for (int a=0; a< m; a ++)
	{
		krawendz(a,n,K);
		wnetrze(a,n,K);
		
	
	cout << char (65+a) << " ";
		for(int k=0; k<n; k++)
		{
			if (K[a][k].czyzgadniety == true) 
				if((a==f and k==g)or(a==h and k==i ))	
					pelnyjedenkafel( a, k, K);			 
					else 								
						pustyjedenkafel();				
				 else									
					for(int j=0; j<14; j++)				
						cout << " ";
		}
	cout <<  " " << char (65+a) << endl;
	
		wnetrze(a,n,K);
		krawendz(a,n,K);	
		
	}
	pierwszyWiersz (n);
	
	
}

void rysujWskazaneKaflePelne(int n,int m,kafel** K)
{	
		pierwszyWiersz (n);

	for (int a=0; a< m; a ++)
	{
		krawendz(a,n,K);
		wnetrze(a,n,K);
		
		
		cout << char (65+a) << " ";
			for(int k=0; k<n; k++)
			{
				if (K[a][k].czyzgadniety == true)  
					pelnyjedenkafel( a, k, K);
					 else
						for(int j=0; j<14; j++)
							cout << " ";						
			}
	cout <<  " " << char (65+a) << endl;
	
	

		wnetrze(a,n,K);
		krawendz(a,n,K);
	}
	pierwszyWiersz (n);
	
	
}
void rysujWskazaneKaflePuste(int n, int m, kafel** K)
{
	
		pierwszyWiersz (n);
	for (int a=0; a< m; a ++)
	{
		krawendz(a,n,K);
		wnetrze(a,n,K);
		
		
		cout << char (65+a) << " ";
		
		for(int k=0; k<n; k++)
			{
				if (K[a][k].czyzgadniety == true)  
					pustyjedenkafel(); 
		 			else
						for(int j=0; j<14; j++)
							cout << " ";
						
			}
		
		cout <<  " " << char (65+a) << endl;
	
	
		wnetrze(a,n,K);
		krawendz(a,n,K);		
	}
	pierwszyWiersz (n);
} 

bool czyWylosowana(int i, int liczba, para tab[])
{
	int t = 0;	
	
	if ( i == 0)
		return false;
		
	for (int j=0; j<i; j++)
		{
			if (tab[j].liczba == liczba)
				t++;
			if (t==2)
				return true;
		}			

			return false;
}


void losowanieIndeks(int n, int m, para tab[])
{
	srand( time( 0 ) );
	int liczba;
	int i = 0;
	int j = 0;
	int ilosc;
	
	if(m*n%2==0)
		 ilosc = m*n;
		else
			 ilosc = (m*n)-1;
	
	
	while(i<ilosc)
	{
		
		liczba = 1+ rand() % (ilosc/2);   // lasujê liczbe
		if( czyWylosowana(i, liczba, tab) == false)					//sprawdzam czy liczba wsyt¹pi³a nie wiêcej ni¿ 2 razy
			{
			tab[i].liczba = liczba;
			int zbior =	1+ rand() % (2);
			for (int k=0; k<i; k++)
				if (tab[i].liczba == tab[k].liczba)
					{
						tab[k].zbior = 1+ tab[i].zbior%2;
						break;
					}
					else
					tab[i].zbior = zbior;
		
			i++;
			}
	}
}


void generujPlansze(int n, int m, kafel** K)
{	
	string wzor[]={"H2O","O3","NaI","CH4","C12H22O11","CH3OH","C3H8O3","C2H6O","C6H12O6","CO","NaCL","SiO2","C9H8O4","HgS","CH2"};
	string nazwa[]={"woda","ozon","jodek sodu","metan","cukier","metanol","gliceryna","etanol","glukoza","czad", "sol kuch.","kwarc","aspiryna","cynober","acetylen"};
	


	int p = 0;
	para* tab = new para[ n*m ]; // tablica z lsowymi indeksami
	
	for(int g=0;g<n*m;g++)
		{
			tab[g].liczba=0;
			tab[g].zbior=0;
		}
	losowanieIndeks(n, m, tab);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			{
			if(m*n%2!=0)
				{
				if(i!=n-1 or j!=m-1 )
			{
				K[i][j].czyzgadniety = true;
				K[i][j].indeks = tab[p].liczba;
				if(tab[p].zbior==1)
			 		K[i][j].nazwachemiczna = nazwa[tab[p].liczba];
					else
						K[i][j].nazwachemiczna = wzor[tab[p].liczba];
				p++;
				
			}
				else
					K[i][j].czyzgadniety = false;
				}
				else 
					{
						K[i][j].czyzgadniety = true;
						K[i][j].indeks = tab[p].liczba;
						if(tab[p].zbior==1)
			 			K[i][j].nazwachemiczna = nazwa[tab[p].liczba];
						else
							K[i][j].nazwachemiczna = wzor[tab[p].liczba];
							p++;
					}
			}
	
	delete [] tab;
	tab=NULL;
}

void usunPlansze(int n, int m, kafel** K)
{
	for(int k=0; k<n; k ++)
		{
			delete [] K[k];
			K[k]=NULL;
		}
		
	delete [] K;
	K=NULL;
	
}

int porownanieKafli(int a, int b, int c, int d, int& ilosc_zgad, kafel** K)
{
	if (K[a][b].indeks==K[c][d].indeks)
		{
		K[a][b].czyzgadniety=false;
		K[c][d].czyzgadniety=false;
		cout << "Para!" << endl;
		ilosc_zgad++;
		system( "pause" );
		return 1;
		}	
		
		else 	
		{
		 cout << "Pudlo!" << endl;
		 system( "pause" );
		 	return 0;
		 }
}



int wprowadanalitera (char a)
{
	int f = int(a);
	if (f >= 65 and f <= 90) 
		return f -= 65;
	if (f >= 97 and f <= 122)  
		  return f -= 97;
		  	else
		  		{
		  			cout << "Blendne wejscie!" << endl;
		  				cin.clear();cin.sync();
		  			return -1;
		  		}
	
}

int wprowadzonaliczba (char a)
{
	int f = int(a);
		if (f >= 49 or f <= 57) 
			return f -= 49;
		else
	  		{
		  			cout << "Blendne wejscie!" << endl;
		  				cin.clear();cin.sync();
		  			return -1;
		  		}
}

void pary2(int punkt[], int osoba, int n, int m, int& ilosc_zgad, kafel** K)
{
	
	char a, c, b, d;
	int f, g, h, i;


	system( "cls" );
	rysujWskazaneKaflePelne(n, m, K); 
	cout << "Liczba punktow gracza " << osoba+1 << ": " <<punkt[osoba] << endl;
	
	cout << "Podaj pozycjê  ";
	
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	
//	system( "cls" );
		
	f = wprowadanalitera(a);
	g = wprowadzonaliczba(b); 
	h = wprowadanalitera(c);
	i = wprowadzonaliczba(d);
	cin.clear();cin.sync();
if(f==-1 or g==-1 or h==-1 or d==-1)
	{
	 	cout << "Podano bledne dane-1!" << endl;
	 	system( "pause" );
	 	pary2(punkt, osoba, n, m, ilosc_zgad, K);
	 }

if(f>=0 and f<=m and h>=0 and h<=m and g>=0 and g<=n and i>=0 and i<=n)		
{
	if((f!=h) or (g!=i)) //prawa de morgana
		{
	//	rysujWskazaneKaflePelne(n, m, K); 
		punkt[osoba] += porownanieKafli( f, g, h, i, ilosc_zgad, K);	//dodawanie punktów
		cout << "Liczba punktow gracza " << osoba+1 << ": " <<punkt[osoba] << endl;
		//system( "pause" );
		system( "cls" );
		}
	else
		{	
		cout << "Podano ta sama karte! Wybierz rozne karty!" << endl;
		system( "pause" );
		pary2(punkt, osoba, n, m, ilosc_zgad, K);
		}
}
	else	 {
	 	cout << "Podano bledne dane!" << endl;
	 	//	cin.clear();cin.sync();
	 	system( "pause" );
	 	pary2(punkt, osoba, n, m, ilosc_zgad, K);
	 }
}
void pary1(int punkt[], int osoba, int n, int m, int& ilosc_zgad, kafel** K)
{
	char a, c, b, d;
	int f, g, h, i;

	system( "cls" );
	rysujWskazaneKaflePuste(n, m, K); 
	cout << "Liczba punktow gracza " << osoba+1 << ": " <<punkt[osoba] << endl;
	
	cout << "Podaj pozycje  ";
	
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	
	system( "cls" );
		
	f = wprowadanalitera(a);
	g = wprowadzonaliczba(b); 
	h = wprowadanalitera(c);
	i = wprowadzonaliczba(d);
		cin.clear();cin.sync();
if(f==-1 or g==-1 or h==-1 or d==-1)
	{
	 	cout << "Podano bledne dane-1!" << endl;
	 		system( "pause" );
	 	pary1(punkt, osoba, n, m, ilosc_zgad, K);
	 }

if(f>=0 and f<=m and h>=0 and h<=m and g>=0 and g<=n and i>=0 and i<=n)	
{
	if((f!=h) or (g!=i)) //prawa de morgana
		{
		rysujWskazaneKafle(n, m, f, g, h, i, K);
		punkt[osoba] += porownanieKafli( f, g, h, i, ilosc_zgad, K);	//dodawanie punktów
		cout << "Liczba punktow gracza " << osoba+1 << ": " <<punkt[osoba] << endl;
	//	system( "pause" );
		system( "cls" );
		}
	else
		{	
		cout << "Podano ta sama karte! Wybierz rozne karty!" << endl;
		system( "pause" );
		pary1(punkt, osoba, n, m, ilosc_zgad, K);
		}
}
	else
	 {
	 	cout << "Podano bledne dane!" << endl;
	 	//	cin.clear();cin.sync();
	 	system( "pause" );
	 	pary1(punkt, osoba, n, m, ilosc_zgad, K);
	 }

}

void najlepszygracz(int* punkt, int gracze)
{
	if(gracze!=1)	{
		for (int k=0; k<gracze-1; k++)
		if (punkt[k] > punkt[k+1])
			{
				int buf = punkt[k+1];
				punkt[k+1] = punkt[k];
				punkt[k] = buf;
			}
			if(punkt[gracze-1] != punkt[gracze-2])	
				cout << "Wygral garcz "<< gracze << " i uzyskal " << punkt[gracze-1] << " punkty!" << endl;
				else
					cout << "Remis!" << endl;
	}
	else
		cout << "Uzyskales " << punkt[0] << " punkty!" << endl;

}

void gra(bool czyodkryckarty, int n, int m, int gracze, kafel** K)
{
	int limit;	
	int ilosc_zgad = 0;
	
	if(m*n%2==0)
		limit = m*n/2;
		else
			limit = ((m*n)-1)/2;
	
	int* punkt = new int [gracze];
 	for(int j=0; j<gracze;j++)
	 		punkt[j]=0;

	if (!czyodkryckarty)
		{	
			do
			{
			for (int i=0; i < gracze; i++)
			{
			if (ilosc_zgad<limit)
				pary1(punkt, i, n, m,ilosc_zgad, K);				
			}
			}while(ilosc_zgad<limit);
		}
	else
		{	
			do
			{
			for (int i=0; i < gracze; i++)
			{
			if (ilosc_zgad<limit)
				pary2(punkt, i, n, m,ilosc_zgad, K);	
			}
			}while(ilosc_zgad<limit);
		}
				
	cout << "Znaleziono wszystkie pary!!!" << endl;
	najlepszygracz( punkt, gracze);
	
	delete [] punkt;
		
}

void menugry(int& n, int& m, int& gracze)
{
	system( "cls" );
	piszmenu(2);
	cout << endl;
	cout << "Liczba graczy: ";
	cin >> gracze;
	cout << endl;
	cout << "Liczba kolumn: ";
	cin >> m;
	cout << endl;
	cout << "Liczba wierszy: ";
	cin >> n;
	cout << endl;

}

void wyborgry()
{
	bool czyodkryckarty;
	int tryb, n, m, gracze;
	cout << endl;
	cout << "          Podaj tryb gry: ";
	cin >> tryb;
	
	
	switch (tryb)
		{
		case 1 : 	{
			czyodkryckarty = true;
			piszmenu(2);
			menugry(n ,m, gracze);
			if(m*n>30 or m*n<2 or gracze<1) 
				 {
					cout << "Nieprawidlowe dane! Podales za duza lub za mala plansze." << endl;
					system( "pause" );
					 menugry(n ,m, gracze);
					 break;
				}
				else
				{			
					kafel** K = new kafel* [n];
					for(int i=0; i<n; i++)
					K[i] = new kafel [m];
	
					generujPlansze(n, m, K);
					gra(czyodkryckarty, m, n, gracze, K);
					usunPlansze(n, m, K);
					break;
				}
		}
		case 2 :	{
			czyodkryckarty = false;
			piszmenu(2);
			menugry(n ,m, gracze);	
			if(m*n>30 or m*n<2 or gracze<1) 
				 {
				 	cout << "Nieprawidlowe dane! Podales za duza lub za mala plansze." << endl;
				 	system( "pause" );
					 menugry(n ,m, gracze);
					 break;
				}
				else
				{
					kafel** K = new kafel* [n];
					for(int i=0; i<n; i++)
						K[i] = new kafel [m];
				
					generujPlansze(n, m, K);
					gra(czyodkryckarty, m, n, gracze, K);
					usunPlansze(n, m, K);
					break;
				}
		}
		case 3 :	{
			int n = 3;
			int m = 3;
			czyodkryckarty = true;
			kafel** K = new kafel* [n];
			for(int i=0; i<n; i++)
				K[i] = new kafel [m];
				
			generujPlansze(n, m, K);
			
			gra(czyodkryckarty,m,n,1,K);
			
			usunPlansze(n, m, K);
			break;
			}
				    
		default:    
					cout << endl;
					cout << "Podaj dobry tryb gry!" << endl;
					cin.clear();cin.sync();
 
					wyborgry();	
		}
		
		
	
}

void piszmenu(int nr)
{	
	system( "cls" );
	switch (nr){

	case 1 :	{
		cout << endl;
		cout << "                 Gra MEMO" << endl;
		cout << "                 1 - Tryb 1 z odkrytymi kartami" << endl;
		cout << "                 2 - Tryb 2 z zakrytymi kartami" << endl;
		cout << "                 3 - Szybka gra tryb 1" << endl;	
		break;
	}
	case 2 :	{
		cout << endl;
		cout << "          Wybierz ilosc graczy, kolumn i wierszy! " << endl;
		cout << endl;
		cout << "          Pamietaj, ze liczba kolumn wynosi max. 5!" << endl;
		break;
	}
	}
}
int main()
{
	piszmenu(1);
	wyborgry();	
		
	
	return 0; 
}
