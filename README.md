# objprog2

APRAŠYMAS:
---
Ši programa analizuoja studentų duomenų failus su skirtingais įrašų dydžiai, juos surūšiuoja, vėliau juos išskirsto pagal jų galutinį balą į dvi grupes: kietekų(galutinis balas >=5.0 ) ir vargšų(galutinis balas < 5.0). Šioje versijoje naudojama klasė ir rule of five įtriaukianti:
1. default konstuktorių
2. kopijavimo konstruktorių
3. kopijavimo priskyrimo operatorių
4. perkelimo konstruktorių
5. perkelimo priskyrimo operatorių
6. destruktorių

Taip pat perdengti >> ir << operatoriai:
1. kad palaikytų įvestį iš vartotojo (cin), iš stringo, iš failo
2. kad palaikytų išvestį į ekraną ir į failą

Testavimą atlieka funkcija testuotiStudentoMetodus().

-------------------------------------------------------------------------------------------------------
Programos paleidimas:
---
1. Sukurkite darbo katalogą, kur norite atsisiųsti projektą: 

mkdir mano-projektas
cd mano-projektas

2. Klonuoti Repozitoriją:    

 git clone https://github.com/Vancyy5/objprog2.git


3. Užtikrinkite, kad turite įdiegtą C++17 suderinamą kompiliatorių.

4. Kompiliuoti su makefile:

 make

5. Paleiskite:

 ./main

6. Išvalykite:

 make clean


Makefile apima:
---
Kompiliatoriaus nustatymai su C++17 standartu ir optimizavimo vėliavomis

Kompiliacijos taisyklės visiems šaltinio failams

Specialus elgesys su šablonais pagrįstu kodu funkcijos.cpp faile

Švaros funkcija, skirta pašalinti objektų failus ir vykdomąjį failą ir papildomus failus

-------------------------------------------------------------------------------------------------------
TESTAVIMO SISTEMOS PARAMETRAI:
---
CPU: Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz, 1190 Mhz, 4 Core(s), 8 Logical Processors

RAM: 8GB DDR4-2666 

DISK: SKHynix_HFM512GDHTNI-87A0B (476,9 GB)

OS: Microsoft Windows 11 Home

GPU: Intel(R) UHD Graphics (1920x1080x32b)

G++ versija 14.2.0

------------------------------------------------------------------------------------------------------
Perdengti metodai:
---
------
Duomenų įvestis:
---
| Tipas  | Aprašymas |
| ------------- | ------------- |
| Rankinis  | Vartotojas įveda vardą, pavardę, pažymius ir egzaminą naudodamas cin |
| Automatinis  | Įvestis testavimo metu per istringstream |
| Iš failo  | Įvestis iš failo per ifstream |

Duomenų išvestis:
---
|  Tipas   | Aprašymas |
| ------------- | ------------- |
| Į ekraną  | Naudojamas cout <<  |
| Į failą | Studentai išvedami į rezultataiT.txt failą  |
-----------------------------------------------------------------------------------------------------
Testas:
----
Funkcija testuotiStudentoMetodus() tikrina:

1. default konstuktorių
2. kopijavimo konstruktorių
3. kopijavimo priskyrimo operatorių
4. perkelimo konstruktorių
5. perkelimo priskyrimo operatorių
6.  6.1  įvesties operatorių (is istringstream)

    6.2  įvestį is cin (>>)

    6.3  įvestį is failo

7. išvedimą į stringstream (<<)
8. failo nuskaitymą su nuskaitymasFile()
9. išvedimą į ekraną ir į faila
10. destruktorių

Rule of five: 
----
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.2/nuotraukos/Screenshot%202025-04-24%20193143.png)

Įvesties testavimas:
---
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.2/nuotraukos/Screenshot%202025-04-24%20193158.png)

Išvedimo testavimas:
---
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.2/nuotraukos/Screenshot%202025-04-24%20193207.png)

Destruktorius:
---
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.2/nuotraukos/Screenshot%202025-04-24%20193213.png)


------------------------------------------------------------------------------------------------------------
Papildomi failai testavimui:
---
failinis.txt - 6.3 testas (įvestis su operatorium >> iš failo)

studentai.txt - 8 testas (failo nuskaitymas)

rezultataiT.txt - 9 testas (išvedimo rezultato failas)


Jos išsitrina kartu su vykdomuoju failu parašius terminale make clean.