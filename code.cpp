/* namen: David Britt & Maurits de Groot
   datum: 06 okt 2015
   beschrijving: een programma om boodschappen te maken en te ontcijferen met behulp van je eigen geheimen getal
   compiler: gcc version 5.1.1 20150618 (Red Hat 5.1.1-4) (GCC)
   compile syntax: g++ -Wall -o davidmaurits2 davidmaurits2.cpp  */
#include <iostream> //voor cin en cout etc
#include <fstream>  //voor ifstream en ofstream
#include <cstdlib>  //voor random
#include <ctime>    //voor het initialiseren van random
#include <string>
using namespace std;
/*ifstream invoer ("Programmeermethoden.invoer", ios::in);
ofstream uitvoer ("Programmeermethoden.uitvoer", ios::out);*/
char char_coderen_of_ontcijferen; //variabele voor de optie voor coderen of ontcijferen
int k = 0; //TODO
string invoerfilelocatie, uitvoerfilelocatie;
//testfunctie om dingen te copieren
/*int copy() {
  char letter_char; //variabele voor het lezen en schrijven van een letter
  letter_char = invoer.get ( );
  cout << letter_char;
  while ( ! invoer.eof ( )) {
    if (letter_char != '\n'){
      uitvoer.put (letter_char);
    }
    letter_char = invoer.get ();
    cout << letter_char;
  }

  invoer.close ( );
  uitvoer.close ( );
  return 1;
}*/
//laat het informatieblokje zien
int infoblok(){
  for (int i = 0; i < 56; i++) { cout << "█" ; } cout
   << endl <<     "██                                                    ██"
   << endl <<     "██   ██████╗ ███╗   ███╗     ██████╗ ██████╗ ██████╗  ██"
   << endl <<     "██   ██╔══██╗████╗ ████║    ██╔═══██╗██╔══██╗╚════██╗ ██"
   << endl <<     "██   ██████╔╝██╔████╔██║    ██║   ██║██████╔╝ █████╔╝ ██"
   << endl <<     "██   ██╔═══╝ ██║╚██╔╝██║    ██║   ██║██╔═══╝ ██╔═══╝  ██"
   << endl <<     "██   ██║     ██║ ╚═╝ ██║    ╚██████╔╝██║     ███████╗ ██"
   << endl <<     "██   ╚═╝     ╚═╝     ╚═╝     ╚═════╝ ╚═╝     ╚══════╝ ██"
   << endl <<     "██                                                    ██"
   << endl;//source http://goo.gl/KCWA4N
  for (int i = 0; i < 56; i++) { cout << "█" ; }
  cout << endl << "██ Een programma om geheime boodschappen te maken en  ██"
  << endl <<      "██ te ontcijferen met behulp van je eigen geheimen    ██"
  << endl <<      "██ getal.                                             ██"
  << endl <<      "██                                                    ██"
  << endl <<      "██ gemaakt door:                                      ██"
  << endl <<      "██ David Britt      | s1234567 | I&E | 2015-2016      ██"
  << endl <<      "██ Maurits de Groot | s1676784 | I&E | 2015-2016      ██"
  << endl;
  for (int i = 0; i < 56; i++) { cout << "█" ; }
  return 1;
}
//geeft een willekeurig getal tussen int max en int min
int willekeurig(int min, int max){
  srand (time(NULL)); //de functie rand initialiseren
  int willekeurig_int = rand() % (max + 1 - min) + min;
  return willekeurig_int;
}
//vraagt of je wilt coderen of ontcijferen
void coderen_of_ontcijferen(){
  cout << endl << "Boodschap coderen of ontcijferen?" << endl
       << "typ c voor coderen of o voor ontcijferen" << endl;
  cin  >> char_coderen_of_ontcijferen;
}
//TODO
int coderen(string invoerfilelocatie, string uitvoerfilelocatie){
  ifstream invoer;
  ofstream uitvoer;
  char letter_char; //variabele voor het lezen en schrijven van een letter
  int k = willekeurig(1, 20);
  int counter = 0;
  invoer.open (invoerfilelocatie.c_str(), ios::in);
  uitvoer.open(uitvoerfilelocatie.c_str(), ios::out);
  if (invoer.fail()) {
    cout << invoerfilelocatie << " niet te openen" << endl;
    exit(1);
  }
  letter_char = invoer.get ( );
  while (! invoer.eof()) {
    char willekeurig_char = willekeurig(97, 122);
    uitvoer.put (willekeurig_char);
    counter++;
    if (counter == k){
      uitvoer.put (letter_char);
      counter = 0;
      letter_char = invoer.get ( );
    }
  }
  invoer.close ( );
  uitvoer.close ( );
}
//TODO
int ontcijferen(){
  cout << "ontcijferen" << endl;
}
//main
int main (){
  infoblok();
  coderen_of_ontcijferen();
  if (char_coderen_of_ontcijferen == 'c'){
    cout << "gimmi invoerfilelocatie" << endl;
    cin >> invoerfilelocatie;
    cout << "gimmi uitvoerfilelocatie" << endl;
    cin >> uitvoerfilelocatie;
    coderen(invoerfilelocatie, uitvoerfilelocatie);
  }
  else if (char_coderen_of_ontcijferen == 'o'){
    ontcijferen();
  }
}
