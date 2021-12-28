Program dokáže komprimovať a dekomprimovať textové či binárne súbory. TXT -> BIN  , TXT <- BIN

-Vstupným argumentom funkcii je názov vstupného a výstupného súboru.

Textová Komprimácia funguje na základe prechádzania súboru a porovnávania znaku s nasledujúcim znakom , kedy v prípade zhody premenná count zväčší o 1 a v prípade, že znak je v súbore zapísaný viac ako 9 krát 
za sebou sa premenná count zapíše do súboru spolu s daným znakom. Vo funkcii prechádzame súbor po jednom znaku konkrétne po jednom bajte pomocou funkcie fread. 
Vo funkcii je použitá funkcia sprintf kvôli zápisu počtu opakovania ako číslice v ASCII tvare.
Na konci sa otestuje či bol celý súbor prečítaný v prípade ak nie program končí s chybovou hláškou exit(1). Táto funkcia sa nachádza v každej ďalšej funkcii kedy pracujeme so súborom.


Textová Dekomprimácia funguje na základe prechádzania súboru kedy prvá hodnota určuje počet koľko krát sa má daná hodnota zapísať do súboru , túto hodnotu neskôr použijeme ako podmienku cyklu no premenná musí byť zmenšená o 48 kvôli tomu že je v ASCII tvare. 
Ďalšia načítaná hodnota ja samotný znak ktorý sa má zapísať do súboru.
Rovnako je použitá funkcia fread a čítame súbor po bajte,  zápis zabezpečuje funkcia fputc.



Binárna Komprimácia funguje na základe prechádzania textového súboru ktorý následne číta pomocou funkcie fread po jednom bajte a zapisuje v binárnom móde kedy funguje skoro rovnako ako funkcia Textovej Komprimácie.
Dáta sú zapísané do súboru v spôsobe kedy prvý bajt určuje počet výskytov daného znaku a ďalší bajt je hodnota znaku v ASCII tabuľke. V tomto prípade sa znak môže opakovať maximálne 255 krát
následne bude zapísaný  do súboru a bude sa počítať od znova. Zápis zabezpečuje funkcia fwrite.


Binárna Dekomprimácia funguje na základe prechádzania súboru v binárnom móde prvá hodnota určuje koľko krát sa má znak zapísať do súboru v tomto prípade už netreba odrátavať od danej hodnoty 48 pretože hodnota priamo reprezentuje počet výskytov znaku.
Pri čítaní je použitá funkcia fread a na zápis slúži funkcia fputc. 

Print je funkcia ktorá vypisuje obsah súboru podľa toho či sa jedná o textovy alebo binárny súbor slúži na výpis iba vstupného súboru, výstupný súbor sa bude vypisovať postupne pri zvolenej funkcii (Compress - Decompress).

Compare je na mieru pre každú funkciu komprimovania. Prejde celý súbor od začiatku po koniec a zisti veľkosť vstupného a výstupného súboru , následne tieto hodnoty porovná.

Main - hlavná funkcia programu obsahuje kontrolu vstupných argumentov (počet , vstup ) ktoré následne vyhodnotí pomocou funckie strcmp. v prípade kedy chýba vstupný alebo výstupný súbor sa program ukončí, ak sú vstupne parametre odlišne od požadovaných parametrov tak v tom prípade sú ignorované .
ďalej nasleduje Vyhodnotenie vstupných argumentov a spustenie funkcií pre výpis , komprimáciu alebo dekomprimáciu  a porovnanie veľkostí  ušetrených či premrhaných  dát. 


-Dodatočné sú hlavičkové súbory Library a  Headers. Library obsahuje použité knižnice a Headers obsahuje hlavičkové súbory obsahujúce funkcie pre beh programu.



-----------------------------------------------------------------------------------------------------------------------------------------------------------

												Spustenie:


Pre spustenie programu je nutné dostať sa do adresára build , a spustiť program napríklad príkazom  ./zipper -i text.txt -o text2.txt , ./zipper -o text.txt -i text2.txt -d , ./zipper -i text.txt -o text2.zip -b , ./zipper -d -i text.zip -b -o text2.txt

-Na poradí argumentov nezáleží, okrem argumetu " -i " za ktorým má nasledovať vstupný súbor ktorý však nesmie byť prázdny inak sa program ukončí a argumentu " -o "  za ktorým následuje výstupný súbor (data vo výstupnom súbore v prípade že je v ňom niečo zapísané
budú vymazané prípadne prepísané) , vstupných argumentov musí byť maximálne 7  vrátane " ./zipper " , neplatné argumenty budú ignorované ... 
