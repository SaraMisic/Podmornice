# 2021_Podmornice

IGRA POTAPANJA PODMORNICA!

Jednostavna igra potapanja podmornica napravljena uz pomoć C++-a i Qt Creator-a.

## Pravila igre : 


Na klik dugmeta "Započni" igra počinje. Imate 60 pokusaja da probate da potopite pet podmornica. Svaka podmornica je različite dužine.
Pobedio je onaj koji je uspeo da potopi sve podmornice za manje od 60 pokušaja. Ukoliko polje zacrveni, to je promašaj, a ukoliko se oboji
u neku nijansu plave, pogodjen je neki deo podmornice (pogledati slike ispod). Podmornice različitih dužina su različito obojene.
Kada pogodite podmornicu, biće vam čekirano polje ispod table na kom će pisati koja je podmornica pogodjena, i takodje će biti ispisano na ekranu.

![promasaj](https://user-images.githubusercontent.com/80061142/118697771-f044e800-b80f-11eb-9f6f-eda00db432b5.jpeg)
![kraj](https://user-images.githubusercontent.com/80061142/118697777-f1761500-b80f-11eb-8e19-266e7ed09d9f.jpeg)




## Instalacija:
  Potrebno je instalirati qmake, qt i g++ kompajler. U prilogu su instalije za Linux(ukucati u terminalu sledece linije):
    g++ :  sudo apt-get install g++ 
    
    qmake : sudo apt-get update -y
            sudo apt-get install -y qt5-qmake
            
    qt : sudo apt-get install qt5-default
    
    
## Kako pokrenuti igru : 
   
   Potrebno je skinuti repozitorijum i ući u terminalu do krajnjeg foldera gde se nalaze samo fajlovi
   (npr na mom sistemu to izgleda ovako : Desktop/projekat/2021_Podmornice/podmorniceGUI_Novo/PodmorniceGUI/).
   Kada se udje u ovaj poslednji direktorijum i ukuca ls, trebalo bi da se vidi fajl PodmorniceGUI.pro.
   Potrebno je ukucati sledeću liniju u terminalu: qmake PodmorniceGUI.pro
   
   Ovo će izenerisati Makefile u tekućem
   direktorijumu. Uz pomoć komande make će se generisati izvršni fajl PodmorniceGUI, koji je potrebno pokrenuti komandom ./PodmorniceGUI
   Ovo će pokrenuti igru. Srećno :)!
  



## Autori:

Sara Mišić 198/2018 \
saram140100@gmail.com

Milena Filipović 273/2018 \
milena.filipovic9909@gmail.com

