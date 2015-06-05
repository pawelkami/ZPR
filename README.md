# Projekt zespołowy na przedmiot Zaawansowane Programowanie w C++ 
## Gra w kółko i krzyżyk w architekturze klient-server
##### Autorzy: Paweł Kamiński, Carlos Zaldivar Batista, Jan Muczyński
##### Prowadzący przedmiot: dr inż. Robert Nowak
##### Uczelnia: Politechnika Warszawska
##### Wydział: EiTI
##### ******************************************************************
###### Projekt wykorzystuje:
###### HTML + CSS + JavaScript(jQuery) jako interfejs graficzny klienta
###### web2py + Python jako kontroler po stronie serwera
###### boost::python + C++ jako logika aplikacji
###### ******************************************************************
###### Wymagania:
###### boost, web2py, scons, python 
###### ******************************************************************
###### Kompilacja:
###### scons
###### ******************************************************************
###### Uruchamianie testów:
###### cd calculations
###### bash runcovertest.sh
######
###### Aby wyczyścić katalog po testach należy użyć:
###### bash runcovertest.sh clean
###### Wyniki testu zapisują się w pliku testresult.txt
###### ******************************************************************
###### Uruchamianie servera:
###### Należy pobrać web2py i umieścić gdziekolwiek na dysku.
###### Katalog z githuba nazwij game i wrzuć go do katalogu applications w
###### miejscu gdzie masz rozpakowane web2py.
###### Skompiluj grę:
###### $ scons
###### Przejdź do głównego katalogu web2py.
###### Wpisz komende:
###### $ python web2py.py
###### W okienku proszę wpisać jakiekolwiek hasło i nacisnąć Start server.
###### Po uruchomieniu serwera gra pojawia się w przeglądarce pod adresem http://127.0.0.1:8000
