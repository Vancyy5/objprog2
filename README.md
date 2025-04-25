# objprog2

APRAŠYMAS:
---
Ši programa analizuoja studentų duomenų failus su skirtingais įrašų dydžiai, juos surūšiuoja, vėliau juos išskirsto pagal jų galutinį balą į dvi grupes: kietekų(galutinis balas >=5.0 ) ir vargšų(galutinis balas < 5.0). Šioje versijoje naudojama bazinė klasė Žmogus ir išvestinė klasė Studentas. Programoje yra rule of five įtriaukianti:
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
Naudoja g++ kompiliatorių su C++17 standartu ir optimizavimu

Apima klaidų tikrinimo vėliavėles

Sukompiliuokite visus šaltinio failus į objektų failus

Susieja juos kartu, kad sukurtų vykdomąjį failą

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