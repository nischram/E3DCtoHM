## E3DC to HomeMatic

#### Wichtig
Bitte meine neue Repository __E3dcGui__ beachten!  
[https://github.com/nischram/E3dcGui.git](https://github.com/nischram/E3dcGui.git)  
Diese Repository wird nicht weitergeführt!

Stand: 30.11.2016

Hier beschreibe ich wie du dein S10 Hauskraftwerk von E3DC an eine HomeMatic Hausautomation von eQ-3 anbinden kannst.

Als Schnittstelle zwischen S10 und HomeMatic dient ein Raspberry Pi. Die Applikation stelle ich hier zur Verfügung. Diese habe ich auf Basis einer Beispielapplikation, die E3DC im Downloadbereich hat, erstellt.

Ich nutze diese Applikation auf einem Raspberry Pi 2 Model B. Meine HomeMatic hat die Firmware 2.17.16 (zuvor auch 2.17.15 getestet) installiert. Das S10-E hatte zuvor die Version 2015-082 und jetzt die 2016-02. Soweit ich weiß solle diese Applikation auch für S10-Mini und für S10-SP40 funktionieren. Mit meiner sehr geringen Erfahrung in der Programmierung sind die Änderungen in der Applikation eventuell unprofessionell ausgefallen, aber die Funktionalität wird erfüllt.

Mit der Applikation, also dem RSCP-Protokoll von E3DC (Remote-Storage-Control-Protokoll), fragt man Leistungswerte und Batteriefüllstand vom S10 ab und sendet diese per CURL-Befehl an die XML-API Schnittstelle der HomeMatic.

Ich beschreibe im Folgenden auch für etwas unerfahrene Anwender die Schritte, die für die Einrichtung nötig sind.

__LOXONE__

Da es mit wenign Änderungen in meiner Applikation möglich ist eine Loxone Zentrale mit Werte zu verorgen, habe ich am Ende ein Kapitel _RSCP to Loxone_ erstellt.

## Vorbereitung der HomeMatic CCU /CCU2
### Systemvariablen einrichten
In der WebUI der HomeMatic Zentrale müssen diverse Systemvariablen eingerichtet werden.
Benötigt werden folgende Systemvariablen:

<img src="http://s20.postimg.org/6enhgxc9p/TAB_001.jpg" alt="TAB_001">

<img src="http://s20.postimg.org/jcd18h9ul/HM_IMG_001.png" alt="HM_IMG_001">

Weil die HomeMatic in Programmen keine negativen Werte auswerten kann, werden die Variablen „NET_IN“ und „NET_OUT“ benötigt. Weiter ist es zum Beispiel bei einem Anzeige-Display sinnvoller, mit einem einzelnen Parameter zu arbeiten. Hierfür wird die Variable „GRID“ benötigt.
Die Variable für die externe Quelle „ADD“ wird natürlich nur benötigt wenn ein Leistungsmesser für die externe Quelle eingesetzt ist.
Auch die Variable für die Wallbox „WB_ALL“ wird natürlich nur bei verwendeter Wallbox benötigt.
Die Variable „Time“ nutzte ich, um die Aktualität der letzten Übertragung zu prüfen.
Die Namen der Systemvariablen müssen nicht eindeutig sein, es können auch eigene Namen vergeben werden.
Die Systemvariablen werden vom Raspberry Pi über die eindeutige Variable „ise_id“ angesteuert oder geändert. Auch nach einer Namensänderung der Systemvariablen bleiben die „ise_id“ immer identisch.
Es ist wichtig, dass alle Variable mit dem Variablentyp „Zahl“ erstellt werden. Alle Variablen benötigen die Standardvorgabe mit einem Maximalwert von „65000“. Nur die Variable „Time“ benötigt einen Maximalwert von „2147483647“

In der RSCP-Applikation besteht die Möglichkeit noch weitere Werte des S10 abzufragen, z.B. Autarky oder Eigenstrom. Hierfür muss die "RscpHomeMatic.cpp" angepasst werden. In der paralellen Anleitung E3DC-Gui habe ich die Autarky, den Eigensterom und die Seriennummer mit aufgenommen. Die ISE_ID wird natürlich auch benötigt und muss ich der "RscpHomeMatic.cpp" eingebaut werden.

### XML-API einrichten
Damit der Raspberry Pi die Werte des S10 zur HomeMatic senden kann, benötigt die HomeMatic die Zusatz-Software „XML-API“.
Aller technischen Informationen entnehmen Sie bitte der Anleitung des Anbieters.
Den Download und eine Installationsanleitung finden Sie unter dem folgenden Link:
[http://www.homematic-inside.de/software/xml-api]( http://www.homematic-inside.de/software/xml-api)
Ich gehe hier nicht näher auf die Installation der XML-API ein.

### „ise_id“ auslesen
Damit über die „XML-API“ die Werte in die HomeMatic übertragen werden können, muss die „ise_id“ der zuvor erstellten Systemvariablen abgefragt werden. Die Abfrage kann z. B. über den Webbrowser mit diesem Befehl erfolgen:
`http://IP-HomeMatic/config/xmlapi/sysvarlist.cgi `
„IP-HomeMatic“ steht für die IP-Adresse der HomeMatic. Ich setzen voraus, dass dir die tatsächliche IP-Adresse bekannt ist. I.d.R. steht sie in der Adresszeile des Webbrowsers, wenn man mit der WebUi auf der HomeMatic eingeloggt ist.
In der Browserausgabe auf den zuvor eingegebenen Befehl sind alle konfigurierten Systemvariablen alphabetisch sortiert zu finden. Die „ise-id“ zu den zuvor konfigurierten Variablen werden später benötigt.

## Vorbereitung am S10
Hauptmenü > Einstellungen
Am S10 muss ein RSCP-Passwort vergeben werden. Im „Hauptmenü“ unter „Einstellungen“ kann ein RSCP-Passwort gesetzt werden. Das gesetzte Passwort wird später in der Installation des Raspberry benötigt.
Im selben Menüfenster ist weiter oben die IP-Adresse des S10 zu finden

## Raspberry Pi
Ich erkläre hier nicht die Erstinstallation eines Raspberry Pi beschrieben. Diese Anleitung setzt einen lokalen Zugriff oder SSH-Zugriff auf den Raspberry voraus.

### Netzwerk
Es ist Wichtig darauf zu achten, dass der Raspberry Pi im selben Netzwerk wie das S10 installiert ist. Der IP-Adressbereich muss gleich sein, zum Beispiel so: 192.168.178.xxx

Auch darf die Verbindung zwischen S10 und Raspberry Pi nicht über eine VPN Verbindung hergestellt werden.


### Applikation auf den Raspberry kopieren
Es werden auf dem Raspberry die Dateien „InstallParameter“ und „e3dc-rscp“ benötigt.
Jetzt wird der lokale oder der SSH-Zugang zum Raspberry benötigt. Ich mache dies mit dem per SSH mit „Terminal“ für MAC.
Download bei Git:
```shell
git clone git://github.com/nischram/E3DCtoHM.git ~/e3dc-rscp
```

### Applikation ausführbar machen
Folgende Eingaben sind zu machen:
```shell
pi@raspberrypi:~ $  cd e3dc-rscp
```
- wechseln in den Unterordner
```shell
pi@raspberrypi ~/e3dc-rscp $  ls
```
- Ordnerinhalt zur Kontrolle anzeigen
```shell
pi@raspberrypi ~/e3dc-rscp $  chmod +x InstallParameter
```
- die Datei InstallParameter ausführbar machen
```shell
pi@raspberrypi ~/e3dc-rscp $  chmod +x e3dc-rscp
```
- die Datei e3dc-rscp ausführbar machen

Wenn der Watchdog genutzt werden soll, muss auch dieser Ausführbar gemacht werden.
```shell
pi@raspberrypi ~/e3dc-rscp $  chmod +x watchdogHM
```
Für den Watchdog bitte das Kapitel zum Watchdog beachten.

<img src="http://s20.postimg.org/cdoq78v31/PI_IMG_001.png" alt="PI_IMG_001">
(one Watchdog)

### Parameter installieren
Jetzt wird die Installationsdatei ausgeführt mit:
```shell
pi@raspberrypi ~/e3dc-rscp $ ./InstallParameter
```
- Installationsdatei Ausführen

Folge nun den Anweisungen in der Ausgabe und geben deine IP-Adresse des S10, den Benutzernamen für das Portal, das Passwort für das Portal und das
RSCP-Passwort ein.
Es werden deine Eingaben für eine Kontrolle ausgegeben, dies kannst du mit „J“ bestätigen oder erneut eingeben nach der Bestätigung mit „N“.

<img src="http://s20.postimg.org/y425i9oil/PI_IMG_002.png" alt="PI_IMG_002">

Jetzt folgt die Abfrage der HomeMatic IP-Adresse und der diversen „ise-id“ zu den verschiedenen Variablen.

<img src="http://s20.postimg.org/4gha2b0pp/PI_IMG_004.png" alt="PI_IMG_004">

Es erfolgen Abfragen, ob ein Leistungsmesser für externe Quellen verbaut ist, oder ob eine Wallbox verbaut ist. Wenn diese Fragen mit „J“ beantwortet werden, benötigen Sie die „ise-id“ für die „ADD“ und „WB_ALL“.
In der letzten Abfrage kannst du eine Zeit in Sekunden einstellen, die beim Verwenden der Applikation das Intervall darstellt, mit dem Daten vom S10 abgeholt und zur HomeMatic übertragen werden. Um die HomeMatic nicht zu überlasten, empfehle ich hier einen Wert zwischen 30 und 60 Sekunden.

<img src="http://s20.postimg.org/g2j0kguhp/PI_IMG_003.png" alt="PI_IMG_003">

Wieder werden alle eingegebenen Werte dargestellt, und du musst diese bestätigen. Nach dem Bestätigen mit “J“ ist die Installation abgeschlossen.
Es wurde nun auf dem Raspberry eine neue Datei „parameters.txt“ erstellt. In dieser Datei sind Ihre Eingaben unverschlüsselt enthalten. Bitte behandle diese Datei sorgsam. Wenn sich das Passwort für das Kundenportal ändert, kann dies einfach die Text-Datei bearbeitet werden.

Die Abfrage der Parameter muss bei jeder Programmändrung neu durchgeführt werden.

### Applikation starten
Jetzt kann die Applikation für Tests gestartet werden.
```shell
pi@raspberrypi ~/e3dc-rscp $  ./e3dc-rscp
```
- Starten der RSCP-Applikation

In der Ausgabe sieht man einmalig die zuvor eingegebenen Parameter, die das Programm aus der „parameters.txt“ ausliest. Als Nächstes erfolgt die Authentifizierung am S10 und nach der Sleepzeit (Intervall) werden die ersten Daten geholt und zur HomeMatic übertragen.

<img src="https://s20.postimg.org/i9oiwt8m5/PI_IMG_006.png" alt="PI_IMG_006">

Dieses Programm vorerst im Hintergrund laufen lassen.

### Systemvariable prüfen
In der HomeMatic WebUi kannst du nun im Bereich „Status und Bedienung“ die Systemvariable einsehen. Hier sollten nun Zahlen mit einem aktuellen Zeitstempel stehen. Diese Werte aktualisieren sich im Intervallrhythmus.

<img src="http://s20.postimg.org/wj2h805jx/HM_IMG_002.png" alt="HM_IMG_002">

### Autostart der Applikation (durch Crontab-Job)
Damit das Programm und die Variablen nun dauerhaft genutzt werden können, muss die Applikation auf dem Raspberry in den Autostart gebracht werden. Diese geschieht bei einem Raspberry Pi in dem ein Crontab-Job erstellt wird.
Zuvor muss auf dem Raspberry die Applikation gestoppt werden. Dies geschieht mit der Tastenkombination:
„ctrl“ + „c“

Die Crontab ruft man auf mit:
```shell
pi@raspberrypi ~/e3dc-rscp $  crontab -e
```
- Crontab für die Bearbeitung öffnen

In der geöffneten Crontab wird eine neue Zeile mit diesem Inhalt eingefügt:
```shell
@reboot /home/pi/e3dc-rscp/e3dc-rscp
```
Die Änderung wird mit „ctrl“ + „o“ gespeichert und die Crontab beendet mit
„ctrl“ + „x“.
Weitere Informationen zur Crontab entnehmen Sie bitte aus Quellen wie z. B. dieser:
[https://raspberry.tips/raspberrypi-einsteiger/cronjob-auf-dem-raspberry-pi-einrichten](https://raspberry.tips/raspberrypi-einsteiger/cronjob-auf-dem-raspberry-pi-einrichten)

### Alternative: Autostart der Applikation (mit /etc/rc.local)
Mit freundlicher Unterstützung im Homematic-Forum, wurde mir von Elmar eine Alternative aufgezeigt.

Link zum Forum:
[http://homematic-forum.de/forum/viewtopic.php?f=19&t=30095&sid=d0e5f32ac87776b98b340cdce545131b&start=10#p286737](http://homematic-forum.de/forum/viewtopic.php?f=19&t=30095&sid=d0e5f32ac87776b98b340cdce545131b&start=10#p286737)

Hier der Beitrag von Elmar:

Hallo zusammen,

mit Hilfe von Linux-Wissenden Kollegen läuft das ganze jetzt bei mir wie gewünscht automatisch.
Zunächst habe ich noch ein Startskript "e3dc.sh" im selben Ordner erstellt und ausführbar gemacht mit folgendem Inhalt: (Datei ist im Ordner enthalten)
```shell
#!/bin/bash
cd /home/pi/e3dc-rscp
./e3dc-rscp
```

Grund: Die Anwendung muss im Ordner ausgeführt werden um die parameters.txt zu finden.
Anschl. wurde das Startskript in /etc/rc.local aufgenommen:
```shell
sudo nano /etc/rc.local
```

folgende Zeile vor exit 0 einfügen:
```shell
/home/pi/e3dc-rscp/e3dc.sh
```
Viele Grüße

Elmar

__Fehler im Quellcode geändert__

Leider habe ich das Programm bei mir ohne die "parameters.txt" im täglichen Einsatz, somit war mir der Fehler nicht aufgefallen. Ich habe den Pfad jetzt für den Rasperry Pi angepasst. Er sieht jetzt wie Folgt aus:
```shell
/home/pi/e3dc-rscp/parameters.txt
```
Sollte meine Applikation nicht auf einen Raspberry Pi installiert werden, muss ggf. der Pfad angepasst werden. Er ist in der Datei "SourceCode/RscpHomeMatic.cpp" auf der Zeile 448 zu finden:
```shell
fstream datei("/home/pi/e3dc-rscp/parameters.txt",ios::in);
```
Nach der Änderung muss der "make" Befehl genutzt werden und ggf. die neue Datei "e3dc-rscp" in den übergeordneten Ordner verschoben werden.

### Raspberry Pi neu starten
Damit die Applikation nun erneut gestartet wird, kann der Raspberry neu gestartet werden mit:
```shell
pi@raspberrypi ~/e3dc-rscp $  sudo reboot
```
- Reboot Befehl mit Administrator-Rechten
Der Raspberry Pi startet neu und die Applikation wird im Hintergrund ohne Bildschirmausgaben ausgeführt. Nach ca. 1 Minute werden die Werte der Systemvariablen der HomeMatic wieder aktualisiert.

## Umschaltung Sommer-/ Winterzeit
Die Einstellung der Sommer oder Winterzeit muss von Hand vorgenommen werden, dafür muss in der Datei "Timezone.txt" entweder "Wintertime" oder "Summertime" eingetragen werden.

## Werte in der HomeMatic nutzen
Nun können diverse Programme, Funktionen und Anzeigen mit den Werten in der HomeMatic realisiert werden. In dieser Anleitung gehen wir nur auf Möglichkeiten ein, die mit vorhandenen Mitteln getestet wurden und im täglichen Praxiseinsatz sind. Die folgenden Vorschläge sind als Hilfestellung gedacht und können jederzeit abgeändert werden.

###	HM Display nutzen
Im Ordner „HM-Scripte“ befindet sich ein Script, mit dem das Display „HM-Dis-WM55“ angesteuert werden kann. Auf das Anlernen des Displays wird hier nicht näher eingegangen. Damit das Display genutzt werden kann, muss im Bereich „Programme und Verknüpfungen“ > „Programme“ ein neues Programm angelegt werden.

<img src="http://s20.postimg.org/8w1ijw07x/HM_IMG_003.png" alt="HM_IMG_003">

Als „Bedingung: „Wenn...“ wird als Gerät das Display mit „Tastendruck kurz“ eingebunden. Die Bezeichnung des Display ist im obigen Bild „EG Display“ mit „:1“ wird der Tastendruck unten ausgewählt.
Als „Aktivität: Dann...“ wird als „Script“ der Inhalt der im Ordner "HM-Scripte" befindlichen Datei „Display-S10.hm“ eingefügt. Es wird nicht die Datei benötigt. Die Auslösung muss für ein Display „sofort“ erfolgen.

__Wichtig:__
Wenn die Systemvariablen mit einem anderen Namen angelegt wurden, muss im Script die Definition der Variable angepasst werden. Im Folgenden ein Ausschnitt aus dem Script-Editor „Atom“ für Mac. In grüner Schriftfarbe werden die Namen der Systemvariablen dargestellt, die ggf. angepasst werden müssen:
```shell
var S10EPP = dom.GetObject("S10_EMS_POWER_PV").State();
var S10EPB = dom.GetObject("S10_EMS_POWER_BAT").State();
var S10EPG = dom.GetObject("S10_EMS_POWER_GRID").State();
var S10EPH = dom.GetObject("S10_EMS_POWER_HOME").State();
var S10SOC = dom.GetObject("S10_BAT_SOC").State();
time RSCPTime = dom.GetObject("S10_RSCP_Time").ToTime();
```
Hier ein Bild vom Display mit der Anzeige der S10-Werte. Die Werte werden je nach Bedingung in unterschiedlichen Farben dargestellt.

<img src="http://s20.postimg.org/pvyuh3tul/IMG_001.png" alt="IMG_001">

Durch einen kurzen Tastendruck an der Unterkante des Displays löst man das Programm aus, und die Werte des S10 werden angezeigt.

Fehleranfälligkeit in diesem Programm:
Derzeit besteht ein bei der HomeMatic-Software ein Problem mit der maximalen Anzahl von Variablen in Scripten. Hier im Forum diskutiert:
[http://homematic-forum.de/forum/viewtopic.php?f=26&t=27907&start=100](http://homematic-forum.de/forum/viewtopic.php?f=26&t=27907&start=100)
In dem oben verwendetem Scrip ist diese Variable z. B. „S10EPP“. Aus eigener Erfahrung kann es bei der HomeMatic zu Problemen führen, wenn in diversen Scripten die maximale Anzahl von ca. 200 Variablen überschritten wird. In dem angegebenen Forum werden Lösungsansätze besprochen. In eigenen Scripten werden seit Bekanntwerden dieses Problem nur noch allgemeine Variablen verwendet (siehe „Display-S10-ohneVariable.hm“).

### Spülmaschinen per Aktor steuern
Im Folgenden wird beschrieben, wie man per Aktor eine Spülmaschine leistungsabhängig einschaltet.

__Spülmaschine prüfen__

Bevor diese Funktion umgesetzt wird, ist zu klären, ob die Spülmaschine diese Möglichkeit unterstützt.
Man muss nach dem Starten der Spülmaschine den Stecker der Spülmaschine ziehen und kurz drauf wieder einstecken. Wenn die Spülmaschine anschließend das Programm an der gleichen Stelle weiter führt, kann die Steuerung der Spülmaschine per HomeMatic genutzt werden.

__Aktor einbinden__

Für diese Anwendung wird der Zwischensteck-Schaltaktor mit Leistungsmessung „HM-ES-PMSw1-Pl“ benötigt.
Dieser Aktor muss in der Zuleitung der Spülmaschine gesteckt und bei der HomeMatic angemeldet sein.
Der Anschluss und das Anlernen des Aktors wird hier nicht näher beschrieben.

__Programm anlegen__

Im Bereich „Programme und Verknüpfungen“ > „Programme“ wird ein neues Programm erstellt.
Dieses Programm überprüft die momentane Leistung der Spülmaschine. Im Standby benötigen viele Maschinen nur wenig Leistung (Watt). Die von mir verwendete Spülmaschine zieht beim Programmieren maximal 3 – 6 Watt. Wenn die Spülmaschine gestartet wird, erhöht sich die Leistungsaufnahme. Diesen Umstand nutze ich, um den Aktor auszuschalten. Nach dem Ausschalten wartet das Programm auf die Einschaltbedingung und schaltet den Aktor zu. Weiter wird die Bedienung des Aktor gesperrt, damit die Spülmaschine für die Programmlaufzeit nicht abgeschaltet wird. Die Sperre wird nach Ablauf der Zeit aufgehoben.
Im folgenden Bild ist das gesamte Programm zu sehen, hier mit einer Startbedingung auf den Überschuss mit 2500 Watt. Somit startet die Spülmaschine erst bei einer Überschussleistung von 2500 Watt, was oft erst nach vollständig geladenen Batterien eintritt.

<img src="http://s20.postimg.org/p8bk9mejh/HM_IMG_004.png" alt="HM_IMG_004">

Im nächsten Bild ist zu sehen, wie die Spülmaschine bei einer PV-Produktion von 2500 Watt mit definierten Bedingungen startet.
Meine PV-Anlage ist kleiner und ich erreiche somit selten Überschuss. Somit schlte ich die Spülmaschine schon bei einer PV Produktion von 2500 Watt ein. Wie zuvor beschrieben, kann ein HomeMatic-Programm keine negativen Werte auswerten. Somit kommt hier der Wert „NET-IN“ zum Einsatz.

<img src="http://s20.postimg.org/cms93v3fh/HM_IMG_005.png" alt="HM_IMG_005">

In beiden Beispielen ist eine zusätzliche Zeitbedingung (hier 15:00 Uhr) enthalten, damit die Spülmaschine am Starttag oder am Folgetag nach dem Start auch durchläuft.

Weiter habe ich über einen Taster (z. B. „HM-PB-6-WM55“) ein Sonderstart ohne ein Berücksichtigung der Leistungsbedingung eingabaut.

### Heizstab mit Programm ansteuern
Im Folgenden beschreibe ich ein Programm zum Ansteuern eines Heizstab. (Nur zur Präsentation bei mir nicht getestet)
Es können diverse Aktoren für diese Anwendung genutzt werden. Daher geben ich keine genauere Bezeichnung für einen Aktor an.
Es wird wieder ein Programm erstellt. Dieses Programm (Abbildung unten) wertet die Überschussleistung „NET-IN“ aus. Im Beispiel wird bei 510 Watt eingeschaltet und bei einem Bezug „NET-OUT“ von 10 Watt wieder ausgeschaltet.

<img src="http://s20.postimg.org/5kubhnztp/HM_IMG_006.png" alt="HM_IMG_006">

### Werte des S10 auf der Startseite der WebUI anzeigen
Im Beriech „Einstellungen“ > „Benutzerverwaltung“ > „Bearbeiten“ kann man über „Systemvariable hinzufügen“ entsprechend Systemvariablen zur Startseite hinzufügen.

<img src="http://s20.postimg.org/5yvnh9jx9/HM_IMG_007.png" alt="HM_IMG_007">

### Diverse Anwendungen für S10-Werte

__Zeitstempel umrechnen__

Ein Programm, um den Zeitstempel „S10_RSCP_Time“ von UnixTime auf Uhrzeit und Datum für eine neue Systemvariable umzurechnen, sieht wie folgt aus:

<img src="http://s20.postimg.org/l8viogffh/HM_IMG_008.png" alt="HM_IMG_008">

Der Inhalt des Scripts sieht wie folgendermaßen aus:
```shell
var v105 = dom.GetObject("S10_Zeitstempel");
time v106 = dom.GetObject("S10_RSCP_Time").ToTime();
string v107 = v106.ToTime();
string v108 = v107.Format("%d.%m.%Y %H:%M:%S");
v105.State(v108);
```

__Tagesmaximalwert der PV-Leistung als Variable anlegen__

Speichern der Maximalwerte von PV-Leistung in eine Systemvariable. Diese Variable muss als Variablentyp „Zahl“ angelegt werden.
Folgendes Programm ist nötig:

<img src="http://s20.postimg.org/4mijt4bvh/HM_IMG_009.png" alt="HM_IMG_009">

Das Script sieht so aus:
```shell
var source = dom.GetObject("$src$");
var v101 = dom.GetObject("S10_PV-MAX");
if (source)
{
if (source.Value() > v101.Variable())
{
v101.Variable(source.Value());
}
}
else
{
var v102 = dom.GetObject("S10_EMS_POWER_PV");
v101.Variable(v102.Value());
}
```
Damit der Wert „S10-PV-MAX“ täglich auf „0“ gesetzt wird, kommt ein weiteres Programm zum Einsatz. Dieses wird täglich ausgelöst, z. B. um 0:00 Uhr. Im Script muss folgendes stehen:
```shell
var v001= dom.GetObject("S10_PV-MAX");
v001.Variable("0");
```

__Minimal- und Maximal-Werte SOC__

Ich Speicher mir die Minimal- und Maximal-Werte des SOC (State Of Charge) auch.
Passend dazu ist das Skript „S10-min-maxSOC.hm“ (_Datei Fehlt noch_) ist im Ordner „HM-Scripte“ zu finden. Das Skript „DATA-PV.hm“ gehört dazu und ersetzt hierbei das Script aus der täglichen Auslösung von PV_Max. Es trägt die Werte in eine zusätzliche Systemvariable für „Yesterday“ ein und speichert alle Werte in einer Datei. Zum Speichern der Datei wird die „CUxD“ verwendet. In dieser Anleitung gehen ich aber auf diese Funktion nicht weiter ein.

## Watchdog

Teilweise bleibt die RSCP-Applikation hängen und die Automatische re-connection in der Applikation funktioniert leider nicht immer. So wird ein Neustart der RSCP-Applikation nötig.

Für dieses Problem habe ich einen einfachen WatchDog geschrieben. Damit der WatchDog den Betrieb der Applikation überwachen kann, lasse ich mit einem kleinen Teil in der e3dc-rscp (RscpHomeMatic.cpp), eine Datei im RAMDisk erstellen. In der Datei ist die Unixtime des S10, diese widerum liest der WatchDog ein und vergleicht diese mit einer definierten Differenz mit der aktuellen Ziet.  

In der RscpHomeMatic.cpp sind die Zeilen 93 bis 100 neu:
```shell
int WD_Aktivint = atoi(WD_Aktiv);
if (WD_Aktivint == 1){
  ofstream fout("/mnt/RAMDisk/UnixtimeHM.txt");
  if (fout.is_open()) {
    fout << TAG_EMS_OUT_UNIXTIME << endl;
    fout.close();
  }
  else cerr << "Konnte UnixtimeHM.txt nicht erstellen! (RAMDisk aktiviert?)";
```
In der neuen Watchdog.cpp kann noch verschiedenes definiert werden: (Kompelieren nötig! (make))
```shell
//Zeitdifferenz zur aktuellen Zeit bis zur Watchdog aktivierung, in Sekunden
#define diff            300
//Zeitinterval für die Abfragen des Watchdog, in Sekunden
#define sleepTime       120
//Anzahl Programm Neustarts bis zum Reboot
#define rebootCounter   4
//Nach dieser Zeit wird der rebootCounter zurückgesetzt wenn die Daten aktuell sind, in Minuten
#define resetMin        60
```
Wenn der Watchdog zuschlägt, erstellt er eine Datei "Watchdog.csv" im e3dc-rscp Ordner. Somit ist eine kotrolle der aktivität möglich. Es wird je aktivität eine Zeile erstellt, entweder mit reboot eintrag oder mit pkill wenn die Applikation neu gestartet wurde.

Für den automatischen Start muss du den watchdogHM wie zuvor für die Applikation e3dc-rscp auch in die Crontab mit folgender Zeile eintragen:
```shell
@reboot /home/pi/e3dc-rscp/watchdogHM
```

__Wichtig!__

Damit der WatchDog die Daten überprüfen kann, lasse ich von der "e3dc-rscp" eine Datei in dem RAMDisk erstellen. Wenn ihr den Watchdog nutzen wollt müsst ihr in der InstallParamerter die Frage ob der WatchDog aktiviert werden soll mit "J" beantworten und vorm nutzen der Applikation den RAMDisk am Raspberry Pi aktivieren (nächstes Kapitel). Wenn ihr den WatchDog nicht nutzen wollt muss das RAMDisk nicht erstellt werden.

ToDo: Ein Fehler ist aktuell noch zu beheben -- mehrfacher Reboot des PI --. Also solltet ihr das S10 vom Netzwek trennen oder eine längere sonstige Störung bestehen, würde alle 8 Minuten der Raspberry Pi mit einem Reboot neu gestartet. Um dies zu stoppen musst du folgendes in der Komandozeile eingeben:
```shell
pi@raspberrypi:~ $ pkill watchdogHM
```

## RAMDisk

RAMDisk am Raspberry erstellen:
Zuerst wird ein Mountpoint für die RAM-Disk erzeugt:
```
sudo mkdir /mnt/RAMDisk
```
Für die RAM-Disk muß die Filesystem Table angepasst werden:
```
sudo nano /etc/fstab
```
Einfügen dieser Zeile am Ende der Datei:
```
tmpfs /mnt/RAMDisk tmpfs nodev,nosuid,size=4M 0 0
```
Die Größe wird über den Parameter "4M" auf 4 MB festgelegt. Jetzt montiert man alle Filesysteme über:
```
sudo mount -a
```
Der Erfolg lässt sich mit Diskfree überprüfen:
```
df
```
Es sollte dann ein Eintrag mit der RAM-Disk zu finden sein:
```
Filesystem 1K-blocks Used Available Use% Mounted on
rootfs 15071704 2734624 11674436 19% /
/dev/root 15071704 2734624 11674436 19% /
devtmpfs 218620 0 218620 0% /dev
tmpfs 44580 236 44344 1% /run
tmpfs 5120 0 5120 0% /run/lock
tmpfs 89140 0 89140 0% /run/shm
/dev/mmcblk0p1 57288 19712 37576 35% /boot
tmpfs 4096 0 4096 0% /mnt/RAMDisk
```

Diesen Teil zum RAMDisk habe ich von hier Kopiert:
[http://www.kriwanek.de/raspberry-pi/486-ram-disk-auf-raspberry-pi-einrichten.html](http://www.kriwanek.de/raspberry-pi/486-ram-disk-auf-raspberry-pi-einrichten.html)

## RSCP to Loxone

Durch ein Forum bin ich auf die Möglichkeit aufmerksam gemacht worden, dass mit wenign Änderungen auch eine Loxone Zentrale mit Daten versorgt werden kann.

Da ich keine Loxone besitze gehe ich nicht näher auf das einrichten der Variablen ein.

Im SourceCode der RscpHomeMatic.cpp sind ein paar Änderungen nötig.
Die Installation kann mit der InstallParameter kann ohne Anpassungen erfolgen. Da die Variablen bei Loxone nicht nur aus Zahlen bestehen, habe ich in der Applikation die "printsend()" Funktion schon von "int" auf "char" geändert (funktioniert für HM auch). In der RscpHomeMatic.cpp muss du nun die CURL-Adresse zur Loxone anpassen.
Die Zeile 64 sieht für HomeMatic so aus:
```
snprintf(batch, sizeof(batch), "curl \"http://%s/config/xmlapi/statechange.cgi?ise_id=%s&new_value=%i\" > /dev/null 2>&1",HM_IP , id, value);

```
Für Loxone müsste es etwa so aussehen:
```
snprintf(batch, sizeof(batch), "curl \"http://user:passwort@%s/​dev/sps/​io/%s/%i" > /dev/null 2>&1",HM_IP , id, value);
```
Für HM_IP hast du zuvor in der InstallParameter einfach deine Loxone IP eingetragen. Den "user" und "passwort" für Loxone musst du in der Ziele anpassen.
Natürlich könnte man die "InstallParameter" und die Abfrage der "parameters.txt" in der "RscpHomeMatic.cpp" auch umschreiben und den "user" und das "passwort" abfragen. Dann müsste die Zeile oben etwa so aussehen:
```
snprintf(batch, sizeof(batch), "curl \"http://%s:%s@%s/​dev/sps/​io/%s/%i" > /dev/null 2>&1", loxuser, lospassword, HM_IP , id, value);
```
Nach den Anpassungen muss die Applikation neu gebaut (kompeliert) werden. Folgendes eintippen:
```
pi@raspberrypi ~/e3dc-rscp $  cd SourceCode
pi@raspberrypi ~/e3dc-rscp/SourceCode $  make
```
Jetzt sollte mit der "e3dc-rscp" deine Loxone Zentrale erreicht werden. Da ich keine Loxone sondern die HomeMatic besitze und habe ich es natürlich nicht getestet, bin also auf Rückmeldungen bei Problemen angewiesen.

## Rohdaten
Im Ordner "SourceCode" ist der C++ Quellcode, die Hauptdatei ist die "RscpHomeMatic.ccp"

Meine Quelle:

Downloadbereich E3DC Kundenportal [https://s10.e3dc.com](https://s10.e3dc.com)

"Zusätzliche Optionen" > " RSCP-Beispielapplikation_2016-04-25.pdf"

[Link](https://s10.e3dc.com/s10/module/download/get.php?dl=3408) (Benutzerdaten erforderlich)
