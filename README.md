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

1 STRATEGIJA
---
1 strategijoje reikėjo kopijuoti studentu grupes narius i kietiakų ir vargšų konteinerius.

Taip pačiai padaryta pradiniame tyrime ir visi rezultatai sukelti faile "Pradinis testavimias.txt" albume "nuotraukos_ir_tyrimai"

Kadangi duomenys yra kopijuojami yra be reikalo užimima vieta kompiuterio atmintyje. 

Pateikta kiek vietos užema vykdoma programa.

![alt text](https://github.com/Vancyy5/objprog/blob/v1.0/nuotraukos_ir_tyrimai/Screenshot%202025-03-21%20155630.png)


------------------------------------------------------------------------------------------------------------
2 STRATEGIJA
---
2-oje strategijoje reikėjo išmesti kietiaku konteinerį ir surikiuoti juos tiktais naudojant pradinį grupes konteinerį ir naują vargšų.

Buvo išmatuotas laikas, per kurį nuskaitomi failai, surūšiuojami studentai ir išskirstomi į du atskirus(vienas senas, kitas naujas) konteinerius pagal atitinkamus įrašų dydžius ir naudojamą konteinerį.

Rezultatai sukelti faile "2strategija.txt" albume "nuotraukos_ir_tyrimai"

Su kiekvienu failu ir konteineriu tyrimas buvo pakartotas 5 kartus, rezultatai surašyti į lentelę ir apskaičiuotas vidurkis sekundėmis.

![alt text](https://github.com/Vancyy5/objprog/blob/v1.0/nuotraukos_ir_tyrimai/image2.png)

Pateikta kiek atminties užema vykdoma programa.

![alt text](https://github.com/Vancyy5/objprog/blob/v1.0/nuotraukos_ir_tyrimai/Screenshot%202025-03-21%20162909.png)

--------------------------------------------------------------------------------------------------------------
Tyrimo pastebėjimai: 
---
Vector yra greičiausias pasirinkimas failo nuskaitymui ir rūšiavimui

List ir deque konteineriai yra žymiai letėsni failo nuskaityme ir rūšiavime.

List yra greičiausias išskirstant į du konteinerius.

-------------------------------------------------------------------------------------------------------------
Išvada:
---
Geriausia naudoti vector konteinerį failo nuskaitymui ir duomenų rūšiavimui, bet list yra palankesnis išskirstyme.

Antra strategija efektyvesnė atminties atžvilgiu, tačiau dažni trynimai (ypač su tam tikrais konteineriais) gali turėti neigiamą poveikį veikimo greičiui.

--------------------------------------------------------------------------------------------------------------
 3 STRATEGIJA
---
 Kadangi vector pagal 1 strategiją vector buvo greitesnis negu 2-oje,  3 strategijoje ir naudosime 1 strategijos principą (sukurti 2 naujus konteinerius).

 Iš duotų pasirinktų STL algoritmų panaudojau:
 
  std::partition atskirti studentus pagal jų galutinį pažymį,
  
  std::copy kopijuoti kopijuoti elementus į kietiakų ir vargšų konteinerius,

  std::transform suskaičiuoti galutinį pažymį, išmetant loopus. Tai leidžia pritaikyti skaičiavimą visiems elementams atliekant vieną operaciją.


Buvo išmatuotas laikas, per kurį nuskaitomi failai, surūšiuojami studentai ir išskirstomi į du atskirus konteinerius pagal atitinkamus įrašų dydžius.

Visur buvo naudojamas vector konteineris.

Rezultatai sukelti faile "3strategija.txt" albume "nuotraukos_ir_tyrimai"

Su kiekvienu failu tyrimas buvo pakartotas 5 kartus, rezultatai surašyti į lentelę ir apskaičiuotas vidurkis sekundėmis.

![alt text](https://github.com/Vancyy5/objprog/blob/v1.0/nuotraukos_ir_tyrimai/Screenshot%202025-03-21%20191536.png)

---------------------------------------------------------------------------
Tyrimo pastebėjimai:
---
Rūšiavimas išlieka efektyvus nepriklausant nuo failo dydžio.

Skirstymas į du konteinerius tampa truputį lėtesnis didėjant įrašų skaičiui.

Failo nuskaitymo laikas auga beveik linijiškai, tačiau 10 milijonų įrašų failas užtrunka žymiai ilgiau.

----------------------------------------------------------------------------
Išvada:
---
3-ioji strategija, naudojanti optimizuotus algoritmus su VECTOR konteineriu yra greita ir efektyvi, ypač esant dideliems studentų kiekiams. Ši strategija suteikia žymiai greitesnį skirstymą į grupes palyginti su kitais konteineriais ir medotais.

----------------------------------------------------------------------------
Konteinerių palyginimas:
---
![alt text](https://github.com/Vancyy5/objprog/blob/v1.0/nuotraukos_ir_tyrimai/Screenshot%202025-03-21%20200201.png)

GALUTINĖ IŠVADA:
---
Naudokite vector yra geriausias pasirinkimas bendrai, ypač jeigu pagrindinis prioritetas yra rūšiavimas ir skirstymas į grupes.
Naudokite list, jei dažnai reikia įterpti arba šalinti elementus.
Venkite naudoti deque, kadangi jis yra lėčiausias rūšiavime.

