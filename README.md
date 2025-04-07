# objprog

APRAŠYMAS:
---
Ši programa analizuoja studentų duomenų failus su skirtingais įrašų dydžiai, juos surūšiuoja,vėliau juos išskirsto pagal jų galutinį balą į dvi grupes: kietekų(galutinis balas >=5.0 ) ir vargšų(galutinis balas < 5.0). Testavimai buvo atlikti su  dviejais atsitiktinias studentų sąrašų failais, sudarytų iš 1 00 000 ir 1 000 000 įrašų. Šioje versijoje naudojama klasės. 

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

Švaros funkcija, skirta pašalinti objektų failus ir vykdomąjį failą

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
Tyrimas tarp struktūros ir klasės.
---
Buvo išmatuotas laikas, per kurį nuskaitomi failai, surūšiuojami studentai ir išskirstomi į du atskirus vector konteinerius pagal atitinkamus įrašų dydžius (100000 ir 1000000) ir naudojamą tipą (klasę ar struktūrą). 

Struktūrą tyrinėti paimta versijos v1.0 3 strategija.

Abiem tipams buvo naudojamas O3 optimizavimo lygis.

Su kiekvienu failu ir tipu tyrimas buvo pakartotas 5 kartus, rezultatai surašyti į lentelę ir apskaičiuotas vidurkis sekundėmis.

![alt text](https://github.com/Vancyy5/objprog2/blob/v1.1/nuotraukos/Screenshot%202025-04-06%20234457.png)

--------------------------------------------------------------------------------------------------------------
Tyrimo pastebėjimai: 
---
Klasė yra greitesnė negu struktūra (ypač išskirstant grupes į dvi atskiras).

-------------------------------------------------------------------------------------------------------------
Išvada:
---
Geriau naudoti klasę.
 
----------------------------------------------------------------------------------------------------------- 

Programos spartos analizė su O1, O2, O3 flag'ais
---
Šiame dokumente pateikiama programos spartos analizė, lyginant "Struktūros" ir "Klasės" variantus su skirtingais optimizavimo flagais. (O1, O2, O3).

Buvo išmatuotas laikas, per kurį nuskaitomi failai, surūšiuojami studentai ir išskirstomi į du atskirus vector konteinerius pagal atitinkamus įrašų dydžius (100000 ir 1000000) ir naudojamą tipą (klasę ar struktūrą). 

Executable failų dydis priklausomai nuo tipo ir optimizavimo lygio pavaizduoti nuotraukoje:

![alt text](https://github.com/Vancyy5/objprog2/blob/v1.1/nuotraukos/Screenshot%202025-04-06%20235325.png)


Su kiekvienu failu, tipu ir optimizavimo lygiu tyrimas buvo pakartotas 5 kartus, rezultatai surašyti į lentelę ir apskaičiuotas vidurkis sekundėmis.

![alt text](https://github.com/Vancyy5/objprog2/blob/v1.1/nuotraukos/Screenshot%202025-04-07%20000511.png)

![alt text](https://github.com/Vancyy5/objprog2/blob/v1.1/nuotraukos/Screenshot%202025-04-07%20000522.png)

------------------------------------------------------------------------------------------------------------
Tyrimo pastebėjimai: 
---
.exe failų dydžiai yra didžiausi naudojant O1 optimizavimo flag'ą, o mažiausi - O2.

Optimizavimo flag'ai labiausiai veikia failo nuskaitymą ir studentų skistymą.

Su struktūra geriausi rezultatai pasiekiami naudojant O1 optimizavimo lygį.

Su klase geriausi rezultatai pasiekti naudoant O2 optimizavimo lygį.

-------------------------------------------------------------------------------------------------------------
Išvados:
---
Optimizavimo flagai (O1, O2, O3) reikšmingai pagerina programos veikimo laiką, ypač didesniems duomenų rinkiniams.

Failo nuskaitymo ir studentų skaidymo į grupes operacijos labiausiai pasinaudoja optimizavimo flagais.

Studentų rūšiavimo operacija yra palyginti greita ir mažai priklauso nuo optimizavimo flagų.

Rekomenduojama naudoti didesnius optimizavimo flagus (O2 ar O3) didesniems duomenų rinkiniams, kad programa veiktų greičiau.

