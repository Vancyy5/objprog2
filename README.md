# objprog

APRAŠYMAS:

Ši programa analizuoja studentų duomenų failus su skirtingais įrašų dydžiai, juos surūšiuoja,vėliau juos išskirsto pagal jų galutinį balą į dvi grupes: kietekų(galutinis balas >=5.0 ) ir vargšų(galutinis balas < 5.0). Testavimai buvo atlikti su  penkiais atsitiktinias studentų sąrašų failais, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Programoje vartotojas pasirenka, kurį konteinerį nori naudoti iš (vector/list/deque).

TESTAVIMO SISTEMOS PARAMETRAI: 
CPU         Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz, 1190 Mhz, 4 Core(s), 8 Logical Processor(s)
RAM         8GB DDR4-2666 
DISK        SKHynix_HFM512GDHTNI-87A0B (476,9 GB)
OS        	Microsoft Windows 11 Home
GPU         Intel(R) UHD Graphics (1920x1080x32b)
G++ versija 14.2.0

PRADINIS TYRIMAS

Buvo išmatuotas laikas, per kurį nuskaitomi failai, surūšiuojami studentai ir išskirstomi į du atskirus konteinerius pagal atitinkamus įrašų dydžius ir naudojamą konteinerį.

Su kiekvienu failu ir konteineriu tyrimas buvo pakartotas 5 kartus, rezultatai surašyti į lentelę ir apskaičiuotas vidurkis sekundėmis.

![alt text](image.png)

Tyrimo pastebėjimai: 
Visi konteineriai panašiai nuskaito failo.
Vector yra greičiausias pasirinkimas visais etapais.
List failo skirstymas į dvi grupes užtrunka net apie 43 kartus ilgiau nei Vector.
Deque visiškai neefektyvus, ypač skirstymo etape (apie 97 kartus lėčiau nei Vector).

Išvada:
Geriausia naudoti vector konteinerį.
