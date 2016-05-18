#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main()
{
     char SERVER_IP [32], E3DC_USER [32], E3DC_PASS [32], AES_PASS  [32];
     char HM_IP [32], ISE_POWER_PV [6], ISE_POWER_BAT [6], ISE_POWER_HOME [6], ISE_POWER_NET_IN [6], ISE_POWER_NET_OUT [6], ISE_POWER_GRID [6], ISE_POWER_ADD [6], ISE_BAT_SOC [6], ISE_Time [6], SleepTime [4];
     char answer;

     S10_Eingabe:
     cout << "\n" << "Parametereingabe des E3DC S10\n";
     cout << "\n" << "Bitte die IP-Adresse des S10 eingeben: ";
     cin.getline(SERVER_IP, 32);
     cout << "\n" << "Bitte den E3DC Benutzernamen eingeben: ";
     cin.getline(E3DC_USER, 32);
     cout << "\n" << "Bitte das E3DC Passwort eingeben: ";
     cin.getline(E3DC_PASS, 32);
     cout << "\n" << "Bitte den RSCP Schlüssel eingeben: ";
     cin.getline(AES_PASS, 32);
     cout << "\n";

     std::printf("SERVER_IP:\t%-10s\n",SERVER_IP);
     std::printf("E3DC_USER:\t%-10s\n", E3DC_USER);
     std::printf("E3DC_PASSWORD:\t%-10s\n", E3DC_PASS);
     std::printf("AES_PASSWORD:\t%-10s\n", AES_PASS);
     cout << "Ist Ihre Eingabe korrekt? J/N: ";
     S10_Answer:
     cin >> answer;
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     if ( answer == 'N' || answer == 'n' ) {
       goto S10_Eingabe;
     }
     else if ( answer == 'J' || answer == 'j' ) {
       goto HM_Eingabe;
     }
     else {
       cout << "Ihre Eingabe war nicht Ja oder Nein!\n" << "Ist Ihre Eingabe der S10 Parameter korrekt? J/N: ";
       goto S10_Answer;
     }
     HM_Eingabe:
     cout << "\n" << "Parametereingabe der Homematic CCU1/CCU2/Webmatic\n";
     cout << "\n" << "Bitte die IP-Adresse der Homematic eingeben: ";
     cin.getline(HM_IP, 32);
     cout << "\n" << "Bitte die ISE_ID der Systemvariablen für die PV-Leistung eingeben: ";
     cin.getline(ISE_POWER_PV, 6);
     cout << "\n" << "Bitte die ISE_ID der Systemvariablen für die Batterie-Leistung eingeben: ";
     cin.getline(ISE_POWER_BAT, 6);
     cout << "\n" << "Bitte die ISE_ID der Systemvariablen für den Hausverbrauch eingeben: ";
     cin.getline(ISE_POWER_HOME, 6);
     cout << "\n" << "Bitte die ISE_ID der Systemvariablen für die Netzeinspeisung eingeben: ";
     cin.getline(ISE_POWER_NET_IN, 6);
     cout << "\n" << "Bitte die ISE_ID der Systemvariablen für den Netzbezug eingeben: ";
     cin.getline(ISE_POWER_NET_OUT, 6);
     cout << "\n" << "Bitte die ISE_ID der Systemvariablen für die Netz-Leistung eingeben: ";
     cin.getline(ISE_POWER_GRID, 6);
     cout << "\n" << "Ist eine Leistungsmessung für eine externe Quelle vorhanden? J/N: ";
     cin >> answer;
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     cout << "\n";
     if ( answer == 'J' || answer == 'j' ) {
       cout << "Bitte die ISE_ID der Systemvariablen für die externe Quelle eingeben: ";
       cin.getline(ISE_POWER_ADD, 6);
       cout << "\n";
     }
     else {
       int ISE_POWER_ADD_0 = 0;
       snprintf (ISE_POWER_ADD, (size_t)6, "%d", ISE_POWER_ADD_0);
     }
     cout << "Bitte die ISE_ID der Systemvariablen für den Batterie-SOC eingeben: ";
     cin.getline(ISE_BAT_SOC, 6);
     cout << "\n" << "Bitte die ISE_ID der Systemvariablen für den Sende-Zeitstempel eingeben: ";
     cin.getline(ISE_Time, 6);
     cout << "\n";
     std::printf("Bitte die Intervallzeit in Sekunden für die Übertragung zur CCU eingeben.\n ");
     std::printf("Die Intervallzeit sollte nicht zu klein gewählt werden damit die CCU nicht überlastet.\n ");
     std::printf("Die Empfohlene Zeit ist 30 Sekunden.\n ");
     cout << "Eingabe: ";
     cin.getline(SleepTime, 3);

     std::printf("\n");
     std::printf("HOMEMATIC_IP:\t%-10s\n", HM_IP);
     std::printf("ISE_POWER_PV:\t%-10s\n", ISE_POWER_PV);
     std::printf("ISE_POWER_BAT:\t%-10s\n", ISE_POWER_BAT);
     std::printf("ISE_POWER_HOME:\t%-10s\n", ISE_POWER_HOME);
     std::printf("ISE_POWER_NET_IN:\t%-10s\n", ISE_POWER_NET_IN);
     std::printf("ISE_POWER_NET_OUT:\t%-10s\n", ISE_POWER_NET_OUT);
     std::printf("ISE_POWER_GRID:\t%-10s\n", ISE_POWER_GRID);
     if ( answer == 'J' || answer == 'j' ) {
       std::printf("ISE_POWER_ADD:\t%-10s\n", ISE_POWER_ADD);
     }
     std::printf("ISE_BAT_SOC:\t%-10s\n", ISE_BAT_SOC);
     std::printf("ISE_Time:\t%-10s\n", ISE_Time);
     std::printf("SleepTime:\t%-10s\n", SleepTime);
     std::printf("\n");
     cout << "Ist Ihre Eingabe korrekt? J/N: ";
     HM_Answer:
     cin >> answer;
     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     if ( answer == 'N' || answer == 'n' ) {
       goto HM_Eingabe;
     }
     else if ( answer == 'J' || answer == 'j' ) {
       goto Ende;
     }
     else {
       cout << "Ihre Eingabe war nicht Ja oder Nein!\n" << "Ist Ihre Eingabe der S10 Parameter korrekt? J/N: ";
       goto HM_Answer;
     }
     Ende:
     ofstream fout("parameters.txt");
     if (fout.is_open()) {
       fout << SERVER_IP << ";" << E3DC_USER << ";" << E3DC_PASS << ";" << AES_PASS << ";" << HM_IP << ";" << ISE_POWER_PV << ";" << ISE_POWER_BAT << ";" << ISE_POWER_HOME << ";" << ISE_POWER_NET_IN << ";" << ISE_POWER_NET_OUT << ";" << ISE_POWER_GRID << ";" << ISE_POWER_ADD << ";" << ISE_BAT_SOC << ";" << ISE_Time << ";" << SleepTime << ";\n";
       fout.close();
       cout << "Ihre Eingaben wurden gespeichert.\n";
       cout << "\n";
     }
 else {
   cerr << "Konnte Datei nicht erstellen!";
 }
    return 0;
}
