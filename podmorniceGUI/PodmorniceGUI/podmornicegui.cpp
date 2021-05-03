#include "podmornicegui.h"
#include "ui_podmornicegui.h"


int matrica[10][10];

Podmornica::Podmornica(char d, int lgth, QVector<int> r, QVector<int> c, int hit, QString nme)
{
    pravac=d;
    duzina=lgth;
    vrsta_podm=r;
    kolona_podm=c;
    pogodak=hit;
    ime=nme;
}


Podmornica::Podmornica(){};



    //pogodili polje u podmornici, uvecavamo brojac
    void Podmornica::setPogodak()
    {
        pogodak++;
    }

    int Podmornica::proveriPotop(int duzinaPodm)
    {
        //ako imamo pogodaka koliko je podmornica dugacka mi smo je potopili
        if(pogodak>=duzinaPodm)
        {
            return 9;
        }
        else
        {
            return 0;
        }
    }

        //hocemo da vidimo koja je podmornica na datoj koordinati
    QString Podmornica::getPodmornica(int v, int k)
    {
        for(int i=0; i<duzina; i++)
        {
            if((vrsta_podm[i]==v) && (kolona_podm[i]==k))
            {
                return ime;
            }
        }
            return "";
     }



    void postaviTablu(int matrica[][10]){
        for (int vrsta=0;vrsta<10;vrsta++)
            for(int kolona=0;kolona<10;kolona++)
                matrica[vrsta][kolona]=0;

    }



    bool postaviPodmornicu(int matrica[][10],int duzinaBroda,int ime,QVector<Podmornica> &listaBrodova)
    {
        srand(time(0)); // utice na fju rand tako sto je pravi jos vise random
        int vrsta=0;
        int kolona = 0;
        char smer ='v';
        bool neuspesnoPostavljeno=true;
        int cs=0;
        smer = uzmiPravac(rand()%10);
        izaberiVrsteiKolone(kolona,vrsta,duzinaBroda,smer);


        while(neuspesnoPostavljeno)
        {
            if (smer=='h')
            {
                cs = proveriPreklapanje(matrica,kolona,vrsta,duzinaBroda,smer);
                // proveravamo da vidimo da li se vec neka podmornica nalazi na ovom mestu

                if (cs==1)   //imamo vec neko polje ovde ne mozemo da postavimo podmornicu gde smo hteli
                            // genrisemo opet random kolonu vrstu i smer i ajmo opet

                {
                    smer = uzmiPravac(rand()%10);
                    izaberiVrsteiKolone(kolona,vrsta,duzinaBroda,smer);
                    cs=0;
                    continue;
                }
                izmeniTablu(matrica,kolona,vrsta,duzinaBroda,smer);
                //stavlja pormornicu na tablu

                izmeniPodmornicu(matrica,kolona,vrsta,smer,listaBrodova,ime);
                // kreira objekat Podmornica

                return 0;//nis spec samo znamo da smo uspeli da postavimo podmornicu na tablu

            }else if (smer=='v')
            {
                cs = proveriPreklapanje(matrica,kolona,vrsta,duzinaBroda,smer);
                // proveravamo da vidimo da li se vec neka podmornica nalazi na ovom mestu

                if (cs==1)   //imamo vec neko polje ovde ne mozemo da postavimo podmornicu gde smo hteli
                            // genrisemo opet random kolonu vrstu i smer i ajmo opet

                {
                    smer = uzmiPravac(rand()%10);
                    izaberiVrsteiKolone(kolona,vrsta,duzinaBroda,smer);
                    cs=0;
                    continue;
                }
                izmeniTablu(matrica,kolona,vrsta,duzinaBroda,smer);
                //stavlja pormornicu na tablu

                izmeniPodmornicu(matrica,kolona,vrsta,smer,listaBrodova,ime);
                // kreira objekat Podmornica

                return 0;//nis spec samo znamo da smo uspeli da postavimo podmornicu na tablu

            }

        }

    }




    int proveriPreklapanje(int matrica[][10],int kolona,int vrsta,int s,char smer)
    {
        int provera = 0;
        // proveravamo po vrsti
        if(smer=='h')
        {
            for (int i=kolona;i<kolona+s;i++)
            {
                provera=matrica[vrsta][i];
                    if(provera!=0)
                    {
                        return 1;//ima vec nesto na polju pa vracamo jedan
                    }
            }

            return 0; // fiksirana vrsta, prolazimo po kolonama da vidimo ima li necega
        }else
        {
            //fiksiramo kolonu, prolazimo po kolonama gledamo ima li necega
            for(int i=vrsta;i<vrsta+s;i++)
            {
                provera=matrica[i][kolona];
                if(provera!=0)
                   /* condition */ {
                        return 1;

                    }
            }
            return 0;

        }
    }



    char uzmiPravac(int p)
    {
        if(p>4)
        {
            return 'h'; //rendom izabrali u kom ce nam pravcu ici podmornica
        }else
        {
            return 'v';
        }
    }



    void izaberiVrsteiKolone(int& kolona,int& vrsta,int duzinaBroda,char smer)
    {
        // ovde je bitno da vodimo racuna o tome koja podmornica moze da uzme koja polja a da jos uvek postoji
        // na primer, za horizontalnu podmornicu duzine 2 znamo da moze da uzmemo bilo koju kolonu za pocetak,
        // ali moramo da vodimo racuna o tome da ne uzima indeks veci od 7 jer kad bi pocela na osmom indeksu prelsa
        // bi preko nase tabele

        //vratice referencu na vrste i kolone koje su nam potrebne

        switch(duzinaBroda)
        {
        case Br1p:
        if(smer=='h')
            {
                kolona = rand()%10;
                vrsta = rand()%10;
            }else
            {
                kolona = rand()%10;
                vrsta = rand()%10;
            }
            break;
        case Br2p:
            if(smer=='h')
            {
                kolona = rand()%8;
                vrsta = rand()%10;
            }else
            {
                kolona = rand()%10;
                vrsta = rand()%8;
            }
            break;
        case Br3p:
        if(smer=='h')
            {
                kolona = rand()%7;
                vrsta = rand()%10;
            }else
            {
                kolona = rand()%7;
                vrsta = rand()%10;
            }
            break;
        case Br4p:
            if(smer=='h')
            {
                kolona = rand()%6;
                vrsta = rand()%10;
            }else
            {
                kolona = rand()%6;
                vrsta = rand()%10;
            }
            break;

        case Br5p:
        if(smer=='h')
            {
                kolona = rand()%5;
                vrsta = rand()%10;
            }else
            {
                kolona = rand()%5;
                vrsta = rand()%10;
            }
            break;
        }
    }




    void izmeniTablu(int matrica[][10],int kolona,int vrsta,int duzinaPodmornice,int smer)
    {
        if(smer=='h'){
            for(int i=0;i<duzinaPodmornice;i++)
            {
                matrica[vrsta][kolona] = duzinaPodmornice;
                kolona++;
            }
        }
        else if(smer=='v')
        {
            for(int i=0;i<duzinaPodmornice;i++)
            {
                matrica[vrsta][kolona] = duzinaPodmornice;
                vrsta++;
            }

        }else
        {
          // ovde napravi za gresku kako nije prosledjen pravac
        }


    }



    int izmeniPodmornicu(int matrica[][10],int kolona,int vrsta,int smer,QVector<Podmornica> &listaPodmornica,int ime)
    {
        switch (ime)
        {
            case Br5p:
                if(smer =='h')
                {
                    QVector<int> r1 (5);
                    QVector<int> c1(5);
                    for(int i=0;i<(int)r1.size();i++)
                            r1[i]=vrsta;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)c1.size();i++){
                        c1[i] = kolona;
                        kolona++;
                    }
                      // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno

                Podmornica podmornica5('h',5,r1,c1,0,"Podmornica duzine 5");
                listaPodmornica.push_back(podmornica5);

                }else if(smer=='v')
                {
                    QVector<int> r1 (5);
                    QVector<int> c1 (5);

                    for(int i=0;i<(int)c1.size();i++)
                            c1[i]=kolona;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)r1.size();i++){
                        r1[i] = vrsta;
                        vrsta++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica5('v',5,r1,c1,0,"Podmornica duzine 5");
                listaPodmornica.push_back(podmornica5);

                }
                break;

            case Br4p:
                if(smer =='h')
                {
                    QVector<int> r1 (4);
                    QVector<int> c1(4);
                    for(int i=0;i<(int)r1.size();i++)
                            r1[i]=vrsta;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)c1.size();i++){
                        c1[i] = kolona;
                        kolona++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica4('h',4,r1,c1,0,"Podmornica duzine 4");
                listaPodmornica.push_back(podmornica4);
                }else if(smer=='v')
                {
                    QVector<int> r1 (4);
                    QVector<int> c1 (4);

                    for(int i=0;i<(int)c1.size();i++)
                            c1[i]=kolona;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)r1.size();i++){
                        r1[i] = vrsta;
                        vrsta++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica4('v',4,r1,c1,0,"Podmornica duzine 4");
                listaPodmornica.push_back(podmornica4);
                }
                break;

            case Br3p:
                if(smer =='h')
                {
                    QVector<int> r1 (3);
                    QVector<int> c1(3);
                    for(int i=0;i<(int)r1.size();i++)
                            r1[i]=vrsta;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)c1.size();i++){
                        c1[i] = kolona;
                        kolona++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica3('h',3,r1,c1,0,"Podmornica duzine 3");
                listaPodmornica.push_back(podmornica3);

                }else if(smer=='v')
                {
                    QVector<int> r1 (3);
                    QVector<int> c1 (3);

                    for(int i=0;i<(int)c1.size();i++)
                            c1[i]=kolona;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)r1.size();i++){
                        r1[i] = vrsta;
                        vrsta++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica3('v',3,r1,c1,0,"Podmornica duzine 3");
                listaPodmornica.push_back(podmornica3);
                }
                break;

            case Br2p:
                if(smer =='h')
                {
                    QVector<int> r1 (2);
                    QVector<int> c1 (2);
                    for(int i=0;i<(int)r1.size();i++)
                            r1[i]=vrsta;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)c1.size();i++){
                        c1[i] = kolona;
                        kolona++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica2('h',2,r1,c1,0,"Podmornica duzine 2");
                listaPodmornica.push_back(podmornica2);

                }else if(smer=='v')
                {
                    QVector<int> r1 (2);
                    QVector<int> c1 (2);

                    for(int i=0;i<(int)c1.size();i++)
                            c1[i]=kolona;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)r1.size();i++){
                        r1[i] = vrsta;
                        vrsta++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica2('v',2,r1,c1,0,"Podmornica duzine 2");
                listaPodmornica.push_back(podmornica2);
                }
                break;

            case Br1p:
                if(smer =='h')
                {
                    QVector<int> r1 (1);
                    QVector<int> c1(1);
                    for(int i=0;i<(int)r1.size();i++)
                            r1[i]=vrsta;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)c1.size();i++){
                        c1[i] = kolona;
                        kolona++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica1('h',1,r1,c1,0,"Podmornica duzine 1");
                listaPodmornica.push_back(podmornica1);

                }else if(smer=='v')
                {
                    QVector<int> r1 (1);
                    QVector<int> c1 (1);

                    for(int i=0;i<(int)c1.size();i++)
                            c1[i]=kolona;//stavili smo koordinate vrste,posto je
                                            //podmornica horizontalna svuda je ista koordinata vrste
                    for(int i=0;i<(int)r1.size();i++){
                        r1[i] = vrsta;
                        vrsta++;   // za kolone u ovom slucaju uvecavamo jer je podmornica postavljena horizontalno
                    }
                Podmornica podmornica1('v',1,r1,c1,0,"Podmornica duzine 1");
                listaPodmornica.push_back(podmornica1);
                }
                break;

        }

        return 1;
    }







PodmorniceGUI::PodmorniceGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PodmorniceGUI)
{
    ui->setupUi(this);
    QPushButton *dugmici[100][100];
    for(int i=0;i<100;i++)
        for(int j=0;j<100; j++){
                  QString s="p" + QString::number(i)+QString::number(j);
                  dugmici[i][j]=PodmorniceGUI::findChild<QPushButton *> (s);
                  connect(dugmici[i][j], SIGNAL(clicked()),this, SLOT(oboj()));
         }

}

PodmorniceGUI::~PodmorniceGUI()
{
    delete ui;
}

void PodmorniceGUI::oboj(){
    QPushButton * dugme =  (QPushButton *)sender();
    dugme->setStyleSheet("background-color: yellow");
    //ui->p11->setStyleSheet("background-color: yellow");
}

void PodmorniceGUI::on_postavi_clicked()
{
    postaviTablu(matrica);

    ui->lineEdit->setText(QString::number(matrica[5][0]));
}
