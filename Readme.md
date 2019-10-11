# Blokų grandinių technologijos


## Hash generatorius

#Makefile: Guide to using the program
** pavadinimas.exe readFilepav.txt <tipas> readFilepav2.txt <tipas> ... n ** 
	Tipai
1. newhash.cpp - pagrindinė programa, kuri pritaikyta naudoti /dqmis/hashrank
2. Rowread.cpp - programa, kuri nuskaito ir hashuoja po eilutę. (Konstitucijos testui atlikti)
3. Fileread.cpp - programa, kuri hashuoja visą failo content'ą.
4. CollisionTest.cpp - programa, kuri ieško collision'ų lygindama vieną po kito einančius input'us

#Algoritmo idėja
	Šis algoritmas yra 128 bit'ų. Veikimo principas - kiekvieno input'o simbolį pavertus į ascii skaičių manipuliuoti ir vėliau pridėti prie unsigned int reikšmės. Tai daroma su dviem unsigned int, kad gauti 16 simbolių ilgio output'ą.
#Testai
	1. Paveiksle matote rezultatą suhashinus 'a', '4', 128KB failą, tokį patį tik pakeistą vieną simbolį:
		![Pirmas](https://i.imgur.com/W6nXX9l.png)
		![Pirmas2](https://i.imgur.com/ycDvbrW.png)
		![Pirmas3](https://i.imgur.com/LsrBx1L.png)
	2. Konstitucijos testo rezultatai:
		![Antras](https://i.imgur.com/S0mDeVl.png)
	3. Susigeneravau 1mln. string'ų ir lyginau 1 su 2, 3 su 4 ir t.t. Kolizijų neatsirado.
		![Ketvirtas](https://i.imgur.com/fpFXlsN.png)
	4. Pagal /dqmis/hashrank pasikeičia  43.35%
	| andriusjok  | Andriusjok/OriginalHashFunction | 2/1          | 6.7236         | 0.0159 | 4026.8039  | 0.5665 | 0    | 3994.1818  | 0.5665 | 0  |
