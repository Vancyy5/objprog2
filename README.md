# objprog2

APRAŠYMAS:
---
Ši programa analizuoja studentų duomenų failus su skirtingais įrašų dydžiai, juos surūšiuoja,vėliau juos išskirsto pagal jų galutinį balą į dvi grupes: kietekų(galutinis balas >=5.0 ) ir vargšų(galutinis balas < 5.0). Testavimai buvo atlikti su  dviejais atsitiktinias studentų sąrašų failais, sudarytų iš 1 00 000 ir 1 000 000 įrašų. Šioje versijoje naudojama klasės. 

1. V1.1 versijoje turiami skirtumai taip struktūros ir klasės, ir programos spartos analizė su O1, O2, O3 flag'ais.
2. V1.2 versijoje pritaikyta Rule of Five ir perdengti įvesties ir išvesties metodai.
3. V1.5 versijoje testuojamos bazinės ir išvesties klasės ir perdengti įvesties ir išvesties operatoriai.
4. V2.0 versijoje įkelta dokumentacija ir padaryti 8 Unit testai

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

5.1 Paleiskite:

 ./main

5.2 Jeigu norit atlikti unit testus:
  
  make test 

6. Išvalykite:

 make clean


Makefile apima:
---
Naudoja g++ kompiliatorių su C++17 standartu ir optimizavimu

Apima klaidų tikrinimo vėliavėles

Sukompiliuokite visus šaltinio failus į objektų failus

Susieja juos kartu, kad sukurtų vykdomąjį failą

Atskirai susieja Unit testam skirtus failus

Pateikiamas švarus tikslas pašalinti objekto failus, vykdomąjį failą ir testavimui reikalingus failus
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
# V1.1
---
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



# V1.2
---
Aprašymas:
---
Šioje versijoje naudojama klasė ir rule of five įtriaukianti:
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


# V1.5 
--- 
APRAŠYMAS:
---
 Šioje versijoje naudojama bazinė klasė Žmogus ir išvestinė klasė Studentas. Programoje yra rule of five įtriaukianti:
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

------------------------------------------------------------------------------------------------------

# Bazinė ir išvestinė klasės

---

## Zmogus (abstrakti bazinė klasė)

---

### Atributai

| Atributas  | Tipas         | Aprašymas         |
|------------|---------------|-------------------|
| vardas_    | std::string   | asmens vardas     |
| pavarde_   | std::string   | asmens pavardė    |

### Konstruktoriai

- `Zmogus()` – numatytasis konstruktorius  
- `Zmogus(const std::string& vardas, const std::string& pavarde)` – konstruktorius su parametrais  
- `Zmogus(const Zmogus& other)` – kopijavimo konstruktorius

### Rule of Five

- `Zmogus(const Zmogus& other)` – kopijavimo konstruktorius  
- `Zmogus& operator=(const Zmogus& other)` – kopijavimo priskyrimo operatorius  
- `Zmogus(Zmogus&& other) noexcept` – perkelimo konstruktorius  
- `Zmogus& operator=(Zmogus&& other) noexcept` – perkelimo priskyrimo operatorius  
- `virtual ~Zmogus() = 0` – virtualus destruktorius (pure virtual, kad klasė būtų abstrakti)

### Grynai virtualios funkcijos

- `virtual void print(std::ostream& os) const = 0` – išvedimui  
- `virtual void read(std::istream& is) = 0` – įvedimui

### Getteriai ir setteriai

- `std::string vardas() const` – grąžina vardą  
- `std::string pavarde() const` – grąžina pavardę  
- `void setVardas(const std::string& vardas)` – nustato vardą  
- `void setPavarde(const std::string& pavarde)` – nustato pavardę

### Globalūs operatoriai

- `std::ostream& operator<<(std::ostream& os, const Zmogus& zmogus)` – išvedimo operatorius  
- `std::istream& operator>>(std::istream& is, Zmogus& zmogus)` – įvedimo operatorius

---

### Testavimas

Testuojant atkomentuoja `testuotiZmogausKlase()` dalis su `Zmogus z`, tada programa nesikompiliuoja, nes `Zmogus` yra abstrakti klasė.

---

## Studentas : public Zmogus (išvestinė klasė)

---

### Papildomi atributai

| Papildomas atributas | Tipas             | Aprašymas              |
|----------------------|-------------------|------------------------|
| nd_                  | std::vector<int>  | namų darbų pažymiai    |
| egzaminas_           | int               | egzamino rezultatas    |
| galutinis_           | double            | galutinis balas        |

### Statiniai atributai

- `static int destruktoriuSk` – destruktoriaus iškvietimų skaičius (testavimui)

### Konstruktoriai

- `Studentas()` – numatytasis konstruktorius  
- `Studentas(std::istream& is)` – konstruktorius su įvesties srautu  
- `Studentas(const std::string& vardas, const std::string& pavarde)` – konstruktorius su vardu ir pavarde

### Rule of Five

- `Studentas(const Studentas& other)` – kopijavimo konstruktorius  
- `Studentas& operator=(const Studentas& other)` – kopijavimo priskyrimo operatorius  
- `Studentas(Studentas&& other) noexcept` – perkelimo konstruktorius  
- `Studentas& operator=(Studentas&& other) noexcept` – perkelimo priskyrimo operatorius  
- `~Studentas() override` – destruktorius

### Virtualių funkcijų realizacijos

- `void print(std::ostream& os) const override` – išvedimo funkcija  
- `void read(std::istream& is) override` – įvedimo funkcija

### Getteriai

- `std::vector<int> nd() const` – grąžina namų darbų masyvą  
- `int egzaminas() const` – grąžina egzamino balą  
- `double galutinis() const` – grąžina galutinį balą

### Setteriai

- `void setEgzaminas(int egzaminas)` – nustato egzamino balą  
- `void setGalutinis(double galutinis)` – nustato galutinį balą
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
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.5/nuotraukos/Screenshot%202025-04-25%20170802.png)

Įvesties testavimas:
---
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.5/nuotraukos/Screenshot%202025-04-25%20170815.png)

Išvedimo testavimas:
---
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.5/nuotraukos/Screenshot%202025-04-25%20170829.png)

Destruktorius:
---
![alt text](https://github.com/Vancyy5/objprog2/blob/v1.5/nuotraukos/Screenshot%202025-04-25%20170836.png)


------------------------------------------------------------------------------------------------------------
Papildomi failai testavimui:
---
failinis.txt - 6.3 testas (įvestis su operatorium >> iš failo)

studentai.txt - 8 testas (failo nuskaitymas)

rezultataiT.txt - 9 testas (išvedimo rezultato failas)


Jos išsitrina kartu su vykdomuoju failu parašius terminale make clean.

# V2.0 
---
# Dokumentacija ir unit testai
---
Aprašymas:
---
Šioje versijoje įkeliama dokumentaciją, kuri aprašo klases ir į kodą įtraukiami Unit testai kurie apima:

1. Rule of five
2. Destruktoriaus skaičiavimą
3. Skaičiavimus (pažymių vidurkius ir galutinį studento pažymį)
4. Įvesties ir išvesties operatorius

## Dokumentacija

Kataloge docs yra programos dokumentacija  (doxygen HTML ir LaTeX ir jame sukompiliuotas PDF)

Kad savo terminale sukūrtumėte dokumentaciją reikia įrašyti:
   doxygen 

Dokumentacijoje aprašytos klasės Laikas, Žmogus ir Studentai. Tai įtraukia jų atributų, funkcijų, metodų ir paveldimumo aprašymą. 

Kadangi mano operacinė sistema yra Windows, tai ji neatlieka funkcijų vizualizacijos.

objprog.pdf sudaro 44 puslapiai.

## Unit Testai

Naudotas Google Test frameworka's Unit testavimui. 

Unit testai apima:

1. Rule of five
2. Destruktoriaus skaičiavimą
3. Skaičiavimus (pažymių vidurkius ir galutinį studento pažymį)
4. Įvesties ir išvesties operatorius

Unit Testai rodo ar teisingai pereinami testai ir rodo kiekvieno testo atlikimo, bandomajo paleidomo ir viso bandomojo paleidimo laiką milisekundėmis.


Viso bandomojo paleidime įeina;

1. Bandomojo atvejo vykdymas (52 ms)

2. Visuotinis nustatymas ir išardymas

3. Bet kokia bandymo aplinka (įkėlimas, išvesties formatavimas ir kt.)

Lentelėje parodoma kiek vidutiniškai laiko užtruko atliekant tikruosius bandomuosius atvejus StudentasTest testų rinkinyje ir viso bandomoji paleidimą. Vidurkis gaunamas iš 5 testų laikų.

| Kas skaičiuojama?          | Laikas (s)        |
|----------------------------|-------------------|
| Bandomasis paleidimas      |       64          | 
| Visas bandomasis paleidimas|       89          | 

Parodyta, kad visi testai pavyko

![alt text](https://github.com/Vancyy5/objprog2/blob/v2.0/nuotraukos/Screenshot%202025-05-08%20211935.png)




