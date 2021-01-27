
#include "MKL05Z4.h"           // dolaczenie pliku naglowkowego
#include "system_kontroli.h"   // 						-||-
#include "frdm_bsp.h"
#include "lcd1602.h"






void delay_ms( int n) {
volatile int i;
volatile int j;
for( i = 0 ; i < n; i++)
for(j = 0; j < 3500; j++) {}
}







int main()
{

SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK; // wlaczenie zegara systemowego dla GPIO A
SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK; // wlaczenie zegara systemowego dla GPIO B




PORTA->PCR[ULN_WEJ_1] |= PORT_PCR_MUX(1); // ustawienie pinu 7 portu A jako GPIO 
PORTA->PCR[ULN_WEJ_2] |= PORT_PCR_MUX(1); // ustawienie pinu 8 portu A jako GPIO 
PORTA->PCR[ULN_WEJ_3] |= PORT_PCR_MUX(1); // ustawienie pinu 9 portu A jako GPIO 
PORTA->PCR[ULN_WEJ_4] |= PORT_PCR_MUX(1); // ustawienie pinu 10 portu A jako GPIO 

	
PORTB->PCR[ULN_WEJ_1] |= PORT_PCR_MUX(1); // ustawienie pinu 7 portu B jako GPIO 
PORTB->PCR[ULN_WEJ_2] |= PORT_PCR_MUX(1); // ustawienie pinu 8 portu B jako GPIO 
PORTB->PCR[ULN_WEJ_3] |= PORT_PCR_MUX(1); // ustawienie pinu 9 portu B jako GPIO 
PORTB->PCR[ULN_WEJ_4] |= PORT_PCR_MUX(1); // ustawienie pinu 10 portu B jako GPIO 
	
	
PORTB->PCR[SPR_CZY_STAN_NISKI_1] |= PORT_PCR_MUX(1); // ustawienie pinu 1 portu B jako GPIO 
PORTB->PCR[SPR_CZY_STAN_NISKI_2] |= PORT_PCR_MUX(1); // ustawienie pinu 2 portu B jako GPIO 
PORTB->PCR[SPR_CZY_STAN_NISKI_3] |= PORT_PCR_MUX(1); // ustawienie pinu 3 portu B jako GPIO 
PORTB->PCR[SPR_CZY_STAN_NISKI_4] |= PORT_PCR_MUX(1); // ustawienie pinu 4 portu B jako GPIO 
PORTB->PCR[PRZEKROCZENIE_LICZBY_OSOB] |= PORT_PCR_MUX(1); // ustawienie pinu 11 portu B jako GPIO 





PTA->PDDR |= (1<<ULN_WEJ_1); // Ustawienie pinu PTB7 (ULN_WEJ_1) jako wyjscie (rejestr kierunku)
PTA->PSOR |= (1<<ULN_WEJ_1); // Ustawienie stanu wysokiego na powyzszym pinie 

PTA->PDDR |= (1<<ULN_WEJ_2); // Ustawienie pinu PTB8 (ULN_WEJ_2) jako wyjscie
PTA->PSOR |= (1<<ULN_WEJ_2); //   -||-

PTA->PDDR |= (1<<ULN_WEJ_3); // Ustawienie pinu PTB9 (ULN_WEJ_3) jako wyjscie
PTA->PSOR |= (1<<ULN_WEJ_3); //   -||-

PTA->PDDR |= (1<<ULN_WEJ_4); // Ustawienie pinu PTB10 (ULN_WEJ_4) jako wyjscie
PTA->PSOR |= (1<<ULN_WEJ_4); //   -||-



PTB->PDDR |= (1<<ULN_WEJ_1); // Ustawienie pinu PTB7 (ULN_WEJ_1) jako wyjscie (rejestr kierunku)
PTB->PSOR |= (1<<ULN_WEJ_1); // Ustawienie stanu wysokiego na powyzszym pinie 

PTB->PDDR |= (1<<ULN_WEJ_2); // Ustawienie pinu PTB8 (ULN_WEJ_2) jako wyjscie
PTB->PSOR |= (1<<ULN_WEJ_2); //   -||-

PTB->PDDR |= (1<<ULN_WEJ_3); // Ustawienie pinu PTB9 (ULN_WEJ_3) jako wyjscie
PTB->PSOR |= (1<<ULN_WEJ_3); //   -||-

PTB->PDDR |= (1<<ULN_WEJ_4); // Ustawienie pinu PTB10 (ULN_WEJ_4) jako wyjscie
PTB->PSOR |= (1<<ULN_WEJ_4); //   -||-




PTB->PDDR |= (1<<PRZEKROCZENIE_LICZBY_OSOB); // Ustawienie pinu PTB11 jako wyjscie (rejestr kierunku)
PTB->PSOR |= (1<<PRZEKROCZENIE_LICZBY_OSOB); // Ustawienie stanu wysokiego na powyzszym pinie. W sytuacji gdy w obiekcie znajdzie sie maksymalnie dopuszczalna 
																						 // liczba osob, nastapi ustawienie stanu wysokiego na pinie PTB11 i tym samym zablokowanie pracy silnika krokowego
																						 // sterujacego wejsciem. Silnik krokowy sterujacy wyjsciem pozostanie aktywny. Gdy co najmniej jedna osoba opusci obiekt,
																						 // zostanie dopuszczone wznowienie pracy silnika krokowego sterujacego wejsciem.

 


LCD1602_Init(); 														 // inicjalizacja wyswietlacza LCD
LCD1602_Backlight(TRUE);									


if(AKTUALNA_LICZ_OSOB <= MAKS_LICZ_OSOB){						 // wyswietlacz LCD 
	
	

						// wyswietlenie napisu na LCD

																				
		LCD1602_ClearAll();															 // skasowanie napisow  							
		LCD1602_SetCursor(0,0);													 // ustawienie kursora wyswietlacza na wybranej pozycji (kolumna, wiersz)		
		LCD1602_Print("PROSIMY ZACHOWAC");							 // wyswietlenie napisu
		LCD1602_SetCursor(3,1);													 // ustawienie kursora
		LCD1602_Print("BEZPIECZNA");										 // wyswietlenie napisu
		DELAY(5000)																			 // opoznienie czasowe 5[s]
		LCD1602_ClearAll();															 //          .	
		LCD1602_SetCursor(3,0);													 //          .
		LCD1602_Print("ODLEGLOSC!");										 //          .
		DELAY(3000)
		LCD1602_ClearAll();	
	  LCD1602_SetCursor(3,0);													 	
		LCD1602_Print("ZAPRASZAMY!");		
	
}	
	







while(1)          // nieskonczona petla while
	{
		
		
	if(AKTUALNA_LICZ_OSOB <= MAKS_LICZ_OSOB){          // instrukcja warunkowa if. W wyr. warunkowym sprawdzenie czy liczba osob nie przekracza maksymalnie dopuszczalnej.
	
		PTB->PCOR |= (1<<PRZEKROCZENIE_LICZBY_OSOB);     // wyzerowanie pinu PTB11 (ustawienie stanu niskiego). Warunek petli if jest spelniony.  Oznacza to ze nie wystepuje 
																										 // przekroczenie maksymalnej liczby osob w obiekcie. Zatem pin PTB11 musi znajdowac sie w stanie niskim.
	}																						 			 
	else	
	
	PTB->PTOR |= (1<<PRZEKROCZENIE_LICZBY_OSOB); 		   // kiedy wyrazenie warunkowe instrukcji if nie jest spelnione (liczba osob w obiekcie przekracza maksymalnie 
																										 //	mozliwa) na pinie PTB13 zostaje ustawiony stan wysoki. 
																								
		
	

	
///////////////////////////////////////////////  SYTUACJA GDY OSOBA WCHODZI DO OBIEKTU I PRZECHODZI PRZEZ LINIE ZADZIALANIA CZUJNIKA 1
		
		
	
	
				if( ( PTB->PDIR & (1<<SPR_CZY_STAN_NISKI_1) ) ==0 ){    // sprawdzenie czy na pinie PTB1 ustawionym jako wejscie wystepuje stan niski pochodzacy od czujnika 
																																// pierwszego. PDIR pozwala na sprawdzenie danych wejsciowych
				
						if(AKTUALNA_LICZ_OSOB <= MAKS_LICZ_OSOB){						// zabezpieczenie przed przekroczeniem dopuszczalnej liczby osob. Gdy liczba osob jest maksymalna,
																																// zostaje zablokowana praca silnika pierwszego (bramka nie podnosi sie). Nie ma tym samym mozliwosci 
																																// wejscia do obiektu.
					
								if(u<1){																				// instrukcja warunkowa if zostala dodana w celu zabezpieczenia przed nieskonczonym obracaniem sie 
																																// wirnika silnika krokowego. Gdyby nie zastosowano niniejszego zabezpieczenia, w sytuacji podania stanu 
								i = 0; 																					// niskiego na pin PTB1 ustawiony jako wejscie, wyrazenie warunkowe instrukcji if sprawdzajacej stan 
								o = 0;																					// niski na pinie PTB1 byloby spelnione dla kazdego obiegu nieskonczonej petli while oraz jednoczesnie
								p = 0;																					// powodowaloby ciagle generowanie impulsow sterujacych silnikiem w sytuacji wystepowania stanu niskiego
																																// na pinie PTB1 (ze wzgledu na nieskonczona petle while). Na potrzeby projektu wymagany jest jednak 
																																// obrot wirnika o 90 stopni. Wprowadzenie niniejszego zabezpieczenia umozliwia podanie na silnik 
																																// okreslonej liczby impulsow ktora gwarantuje oczekiwany kat obrotu wirnika. Zatem ustawiona ilosc 
																																// sekwencji impulsow zostanie zrealizowana tylko raz dla jednego obiegu nieskonczonej petli while.
					
											

									double CZTERY_IMPULSY = 0;   									// zmienna lokalna typu double. Zostanie wykorzystana w wyrazeniu warunkowym kolejnej petli while. 
																																// Wstepnie zainicjalizowana wartoscia zero. 

																		
										while(CZTERY_IMPULSY<14.35){								// w wyrazeniu warunowym petli while nastepuje porownanie aktualnej wartosci zmiennej 4 impulsy 
																																// (tj. 1 krok) z ustalona optymalna liczba krokow odpowiadajca wykonaniu obrotu wirnika o kat 90 stopni
																																// optymalna liczba krokow odpowiadajca wykonaniu obrotu wirnika o kat 90 stopni 
																																// (otworzenie lub zamkniecie szlabanu). Wartosc 14.35 zostala wyznaczona doswiadczalnie poprzez										
																																// obserwacje zachowania silnika dla roznych wartosci krokow.
	


											// Obroty w prawo (w gore), podnoszenie szlabanu o 90 stopni						
	
											IMPULS_1_S1
											delay_ms(5);	// czas 5 [ms] przyjety jako optymalny pomiedzy kolejnymi impulsami 
		
											IMPULS_2_S1
											delay_ms(5);
	
											IMPULS_3_S1	
											delay_ms(5);
	
											IMPULS_4_S1	
											delay_ms(5);
										
											CZTERY_IMPULSY++;
									}

									u++;
	
							}
					}		
			}
					

	
		
/////////////////////////////////////////////// SYTUACJA GDY OSOBA WCHODZI DO OBIEKTU I PRZECHODZI PRZEZ LINIE ZADZIALANIA CZUJNIKA 2 
		
		

							
				if( ( PTB->PDIR & (1<<SPR_CZY_STAN_NISKI_2) ) ==0 ) {   // sprawdzenie czy na pinie PTB2 ustawionym jako wejscie wystepuje stan niski pochodzacy 
																																// od czujnika drugiego. 
																																
	
						if(AKTUALNA_LICZ_OSOB <= MAKS_LICZ_OSOB){						// dodatkowe (opcjonalne) zabezpieczenie przed przekroczeniem dopuszczalnej liczby osob.
																															
		
		
								if(i<1){																				// zabezpieczenie pelniace funkcje indentyczna jak opisane w poprzedniej sytuacji

												u = 0;
												o = 0;
												p = 0;
		
	
									for(double e =1; e<14.35; e++){			// petla for, nastepuje porownanie aktualnej wartosci zmiennej e (4 impulsy, czyli 1 krok) z ustalona optymalna 
																											// liczba krokow odpowiadajca wykonaniu obrotu wirnika o kat 90 stopni (otworzenie lub zamkniecie szlabanu).
																											// Wartosc 14.35 zostala wyznaczona doswiadczalnie poprzez obserwacje zachowania silnika dla roznych wartosci krokow.
							
												// obroty w lewo (w dol), opadanie szlabanu (kat 90 stopni)
												// Podanie sekwencji impulsow w odwrotnej kolejnosci powoduje ruch silnika w przeciwna strone								
	
												IMPULS_4_S1	
												delay_ms(5);    // czas 5 [ms] przyjety jako optymalny pomiedzy kolejnymi impulsami 
		
												IMPULS_3_S1	
												delay_ms(5);

												IMPULS_2_S1
												delay_ms(5);
		
												IMPULS_1_S1
												delay_ms(5);	
	
									}
										i++;

						AKTUALNA_LICZ_OSOB++; // dzieki umieszczeniu zwiekszania wartosci zmiennej w tym miejscu dokonano zabezpieczenia przed sytuacja w ktorej osoba po przejsciu
																	// przez linie zadzialania czujnika pierwszego nie przeszla z jakiegos powodu przez linie zadzialania czujnika drugiego, a wiec
																	// nie weszla do obiektu. Dzieki umieszczeniu zmiennej w tym miejscu, osoba zostanie doliczona do aktualnej liczby osob dopiero
																	// po zamknieciu szlabanu wejscia, a wiec gdy osoba znajdzie sie w obiekcie (zadzialanie czujnika drugiego).
								
						}
					}
				}
	
							
				
	
/////////////////////////////////////////////// SYTUACJA GDY OSOBA WYCHODZI Z OBIEKTU I PRZECHODZI PRZEZ LINIE ZADZIALANIA CZUJNIKA 3
	
	

		
	
				if( ( PTB->PDIR & (1<<SPR_CZY_STAN_NISKI_3) ) ==0 ){    // sprawdzenie czy na pinie PTB3 ustawionym jako wejscie wystepuje stan niski pochodzacy od czujnika 
																																// trzeciego. 
							
													// w tym miejscu w przeciwienstwie do poprzednich sytuacji nie wystapi sprawdzenie liczby osob.
													// Wyjscie powinno byc nieprzerwanie aktywne (poniewaz nie zwieksza sie liczba osob).
					
					if(o<1){																							// zabezpieczenie pelniace funkcje jak opisane poprzednio
	
									u = 0;
									i = 0;
									p = 0;
						
		
							double CZTERY_IMPULSY = 0;    // zmienna lokalna typu double. Zostanie wykorzystana w wyrazeniu warunkowym kolejnej petli while. 
																						// Wstepnie zainicjalizowana wartoscia zero. 

																		
								while(CZTERY_IMPULSY<7.15) {   	// w wyrazeniu warunowym petli while nastepuje porownanie aktualnej wartosci zmiennej 4 impulsy (tj. 1 krok) z ustalona 
																								// optymalna liczba krokow odpowiadajca wykonaniu obrotu wirnika o kat 90 stopni (otworzenie lub zamkniecie szlabanu).
																								// Ze wzgledu na zastosowanie innego rodzaju silnika krokowego (jako silnik 2) liczba krokow powodujaca ruch obrotowy
																								// wirnika o 90 stopni ulegla zmianie. Tym razem rowniez poprzez obserwacje pracy silnika dla roznej ilosci krokow
																								// wyznaczono optymalna wartosc rowna okolo 7.15.
	
											// Obroty w lewo (w gore), podnoszenie szlabanu o 90 stopni	(silnik nr 2 odwrotnie ustawiony wzgledem pierwszego)					
							
											IMPULS_1_S2
											delay_ms(5);	// czas 5 [ms] przyjety jako optymalny pomiedzy kolejnymi impulsami 
	
											IMPULS_2_S2
											delay_ms(5);
	
											IMPULS_3_S2	
											delay_ms(5);
	
											IMPULS_4_S2	
											delay_ms(5);
		

											CZTERY_IMPULSY++;
	
									}
									o++;
					
						
							}	
				}
			

	
	

///////////////////////////////////////////////  SYTUACJA GDY OSOBA WYCHODZI Z OBIEKTU I PRZECHODZI PRZEZ LINIE ZADZIALANIA CZUJNIKA 4
	

							
							
			if( ( PTB->PDIR & (1<<SPR_CZY_STAN_NISKI_4) ) ==0 ) {   // sprawdzenie czy na pinie PTB4 ustawionym jako wejscie wystepuje stan niski pochodzacy 
																															// od czujnika drugiego. 
	
					if(p<1){																						// -||- 
			
							u = 0;
							o = 0;
							i = 0;
			

							double CZTERY_IMPULSY = 0;     // zmienna lokalna (dlatego wymagana ponowna definicja)
	

		
								while(CZTERY_IMPULSY<7.15){    	// w wyrazeniu warunowym petli while nastepuje porownanie aktualnej wartosci zmiennej 4 impulsy (tj. 1 krok) z ustalona 
																								// optymalna liczba krokow odpowiadajca wykonaniu obrotu wirnika o kat 90 stopni (otworzenie lub zamkniecie szlabanu).
																								// Ze wzgledu na zastosowanie innego rodzaju silnika krokowego (jako silnik 2) liczba krokow powodujaca ruch obrotowy
																								// wirnika o 90 stopni ulegla zmianie. Tym razem rowniez poprzez obserwacje pracy silnika dla roznej ilosci krokow
																								// wyznaczono optymalna wartosc rowna okolo 7.15.
							
										
										// obroty w lewo (w dol), opadanie szlabanu (kat 90 stopni)
										// Podanie sekwencji impulsow w odwrotnej kolejnosci powoduje ruch silnika w przeciwna strone								
	
										IMPULS_4_S2	
										delay_ms(5);    // czas 5 [ms] przyjety jako optymalny pomiedzy kolejnymi impulsami 
		
										IMPULS_3_S2	
										delay_ms(5);

										IMPULS_2_S2
										delay_ms(5);
		
										IMPULS_1_S2
										delay_ms(5);	
	
																	
										CZTERY_IMPULSY++;
	
										}
										p++;	

										
	AKTUALNA_LICZ_OSOB--; // dzieki umieszczeniu w tym miejscu zmniejszania wartosci zmiennej dokonano zabezpieczenia przed sytuacja w ktorej osoba po przejsciu
												// przez linie zadzialania czujnika trzeciego nie przeszla z jakiegos powodu przez linie zadzialania czujnika czwartego, a wiec
												// nie wyszla z obiektu. Dzieki umieszczeniu procedury zmniejszania zmiennej w tym miejscu, osoba zostanie odjeta od 
												// aktualnej liczby osob dopiero po zamknieciu szlabanu wyjscia (a wiec gdy osoba znajdzie sie poza obiektem) - zadzialanie czujnika drugiego.
		
								
						
			}

		} 
	
	}	
	
}
	

	
