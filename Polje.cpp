#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

    class Polje
    {

            int _x;
            int _y;
        public:
        Polje(int x,int y)
        {
            _x=x;
            _y=y;
        }

        int getX()
        {
            return _x;
        }
        
        int getY()
        {
            return _y;
        }


        void ispisPolja()
        {
            std::cout<<"("<<_x<<", "<<_y<<")"<<std::endl;
        }

    };



    class Podmornica
    {   
        
    public:
        int duzina;
        std::vector<Polje> podmornica;
        Podmornica(std::vector<Polje>);
        int proveraPogotka(Polje polje);

    };    

    Podmornica::Podmornica(std::vector<Polje> polja)
    {
            podmornica=polja;
            duzina=podmornica.size();
    }
    

    int Podmornica::proveraPogotka(Polje p1)
    {
        if(std::binary_search(Podmornica::podmornica.begin(),Podmornica::podmornica.end(),p1))
            return 1;
        else 
            return 0;

        // vraca 1 ako je u podmornici polje koje je protivnik gadjao, nula ako nije
    }


    class PodmornicaSaNizom{
            public:
                std::pair<Podmornica,std::vector<int>> podmornicaSaNizom;
                PodmornicaSaNizom(Podmornica);
                void oznaciPogodjenoPolje(Polje polje);
                void potopiPodmornicu(Podmornica podmornica);

    
        PodmornicaSaNizom(Podmornica podmornica)
        {
            std::vector<int> pomocni(podmornica.duzina,0);
            podmornicaSaNizom=std::make_pair(podmornica,pomocni);
        }

        void oznaciPogodjenoPolje(Polje polje)
        {

        }
    
    };



int main()
{
    Polje polje(2,3);
    polje.ispisPolja();

    return 0;

}