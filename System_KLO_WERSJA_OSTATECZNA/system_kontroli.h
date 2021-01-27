
// W pliku naglowkowym zamieszczono glownie makrodefinicje oraz definicje zmiennych globalnych. 
// Umieszczenie wspomnianych czesci kodu w oddzielnym pliku wplywa na zwiekszenie jego przejrzystosci.








// Ze wzgledu na wykorzystanie w projekcie dwoch silnikow krokowych, powinna zachodzic koniecznosc utworzenia lacznie osmiu makrodefinicji pinow sterujacych 
// (po 4 piny sterujace dla kazdego silnika). Jednak zastosowano rozwiazanie polegajace na wykorzystaniu tych pinow portu A, ktore odpowiadaja pinom portu B tzn.
// PTB7 -> PTA7, PTB8 -> PTA8, PTA9 -> PTB9, PTA10 -> PTB10. Dzieki temu nie ma potrzeby wykonywania podwojnej ilosci makrodefinicji (wystarcza tylko 4).
// Wplywa to na zmniejszenie rozmiaru kodu.

#define ULN_WEJ_1 7				 // makrodefinicja pinu PTB8, do ktorego podlaczono wejscie nr 1 ukladu ULN2803
#define ULN_WEJ_2 8        // makrodefinicja pinu PTB9, do ktorego podlaczono wejscie nr 2 ukladu ULN2803
#define ULN_WEJ_3 9				 //         -||-        PTB9           -||-    								 3			-||-  
#define ULN_WEJ_4 10			 //         -||-        PTB10					 -||-   								 4			-||-  






// Ponizej zapisano makrodefinicje czterech kolejnych impulsow podawanych na odpowiednie piny (wejscia) ukladu ULN2803 sterujacego praca silnika krokowego.
// Kiedy jeden z czterech pinow sterujacych mikrokontrolera zostanie ustawiony w stan wysoki, pozostale piny musza byc w stanie niskim (w danej chwili moze byc
// tylko jeden pin w stanie wysokim). Wynika to z faktu, ze kazdy impuls podawany jest na dany tranzystor ukladu ULN2803 a nastepnie trafia do odpowiedniego 
// wyprowadzenia cewki silnika krokowego. Poprzez zastosowanie niewielkiego opoznienia czasowego pomiedzy kolejnymi stanami na 4 tranzystorach oraz dzieki zastosowaniu
// petli while powstaje sekwencja kolejnych czterech impulsow trafiajacych na odpowiednie wyprowadzenia cewek. Sekwencja impulsow musi byc uporzadkowana, 
// tzn. impulsy musza byc przesylane w odpowiedniej kolejnosci aby zapewnic prawidlowa prace silnika krokowego.

// Dla silnika pierwszego (PORT B):

#define IMPULS_1_S1 PTB->PTOR |= (1<<ULN_WEJ_1); PTB->PCOR |= (1<<ULN_WEJ_2|1<<ULN_WEJ_3|1<<ULN_WEJ_4); // impuls 1. generowany na pinie PTB7 trafiajacy do wejscia nr 1
																																																				// ukladu ULN2803, na pozostalych trzech pinach stan niski 
#define IMPULS_2_S1 PTB->PTOR |= (1<<ULN_WEJ_2); PTB->PCOR |= (1<<ULN_WEJ_1|1<<ULN_WEJ_3|1<<ULN_WEJ_4); // impuls 2. generowany na pinie PTB8 trafiajacy do wej nr 2 -||- 
#define IMPULS_3_S1 PTB->PTOR |= (1<<ULN_WEJ_3); PTB->PCOR |= (1<<ULN_WEJ_1|1<<ULN_WEJ_2|1<<ULN_WEJ_4); // impuls 3. generowany na pinie PTB9 trafiajacy do wej nr 3 -||-
#define IMPULS_4_S1 PTB->PTOR |= (1<<ULN_WEJ_4); PTB->PCOR |= (1<<ULN_WEJ_1|1<<ULN_WEJ_2|1<<ULN_WEJ_3); // impuls 4. generowany na pinie PTB10 trafiajacy do wej nr 4 -||-

// Dla silnika drugiego (PORT A):

#define IMPULS_1_S2 PTA->PTOR |= (1<<ULN_WEJ_1); PTA->PCOR |= (1<<ULN_WEJ_2|1<<ULN_WEJ_3|1<<ULN_WEJ_4); // impuls 1. generowany na pinie PTA7 trafiajacy do wejscia nr 5
																																																				// ukladu ULN2803, na pozostalych trzech pinach stan niski 
#define IMPULS_2_S2 PTA->PTOR |= (1<<ULN_WEJ_2); PTA->PCOR |= (1<<ULN_WEJ_1|1<<ULN_WEJ_3|1<<ULN_WEJ_4); // impuls 2. generowany na pinie PTA8 trafiajacy do wej nr 6 -||- 
#define IMPULS_3_S2 PTA->PTOR |= (1<<ULN_WEJ_3); PTA->PCOR |= (1<<ULN_WEJ_1|1<<ULN_WEJ_2|1<<ULN_WEJ_4); // impuls 3. generowany na pinie PTA9 trafiajacy do wej nr 7 -||-
#define IMPULS_4_S2 PTA->PTOR |= (1<<ULN_WEJ_4); PTA->PCOR |= (1<<ULN_WEJ_1|1<<ULN_WEJ_2|1<<ULN_WEJ_3); // impuls 4. generowany na pinie PTA10 trafiajacy do wej nr 8 -||-





#define SPR_CZY_STAN_NISKI_1 1 // makrodefinicja pinu PTB1 wykorzystanego do sprawdzenia czy na jego wejsciu wystepuje stan niski, ktorego pojawienie sie swiadczy 
														   // o przejsciu osoby przez linie zadzialania czujnika pierwszego (osoba wchodzi)

#define SPR_CZY_STAN_NISKI_2 2 // makrodefinicja pinu PTB2 wykorzystanego do sprawdzenia czy na jego wejsciu wystepuje stan niski, ktorego pojawienie sie swiadczy 
														   // o przejsciu osoby przez linie zadzialania czujnika drugiego (osoba wchodzi)
															 

#define SPR_CZY_STAN_NISKI_3 3 // makrodefinicja pinu PTB3 wykorzystanego do sprawdzenia czy na jego wejsciu wystepuje stan niski, ktorego pojawienie sie swiadczy 
															 // o przejsciu osoby przez linie zadzialania czujnika trzeciego (osoba wychodzi)

#define SPR_CZY_STAN_NISKI_4 4 // makrodefinicja pinu PTB4 wykorzystanego do sprawdzenia czy na jego wejsciu wystepuje stan niski, ktorego pojawienie sie swiadczy 
														   // o przejsciu osoby przez linie zadzialania czujnika czwartego (osoba wychodzi)
															 


#define PRZEKROCZENIE_LICZBY_OSOB 11 // makrodefinicja pinu PTB11 wykorzystanego do ustawienia na nim stanu wysokiego gdy liczba osob zostanie przekroczona 





int AKTUALNA_LICZ_OSOB = 0; // definicja zmiennej przechowujacej liczbe osob znajdujacych sie aktualnie w obiekcie. 
														// Zmienna zostaje poczatkowo zainicjalizowana wartoscia 0 

int MAKS_LICZ_OSOB = 10;    // definicja zmiennej przechowujacej najwieksza liczbe osob ktora moze znalezc sie w obiekcie. 
													  // Wstepnie zmienna zostaje zainicjalizowana wartoscia 10.	
											
														

int u = 0;
int i = 0;
int o = 0;
int p = 0;




