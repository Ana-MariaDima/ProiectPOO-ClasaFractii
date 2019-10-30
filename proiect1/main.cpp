#include <iostream>
#include<string>

using namespace std;

    class fractie{
        private:
            int numarator;
            int numitor;

    //constructori
        public:
            int n;
            fractie();
            fractie(int);
            fractie(int, int);

    //copiere
            fractie(const fractie&);

    //destructor
            ~fractie();
    //metode
            void citire();
            void simplificare();
            void afisare();

    //functii prietene pt citire si afisare+supraincarcare op
            friend istream& operator >>(istream&, fractie&);
            friend ostream& operator <<(ostream&, fractie&);
            friend fractie operator +(fractie, fractie);
            friend fractie operator -(fractie, fractie);
            friend fractie operator *(fractie, fractie);
            friend fractie operator *(fractie, int);
            friend fractie operator /(fractie, fractie);

        //sistem
            int sistem(fractie,fractie,fractie,fractie, fractie,fractie);


};

//simplificare frcatie
    int cmmdc(int x,int y)
{
        int z;
        if (x==0 || y==1) return 1;
        if (x<0) x=-x;
        if (y<0) y=-y;
        while (x!=0)
            {
                if (y>x)
                {
                    z=x;
                    x=y;
                    y=z;
                }
                x%=y;
            }
        return y;
}

    void fractie::simplificare()
{
        int divizor_com;
        if (numarator<0)
            {
                numarator=-numarator;
                numitor=-numitor;
            }
             /*if (numitor<0)
            {
                numarator=-numarator;
                numitor=-numitor;
            }*/
        if (numitor>1)
            {
                divizor_com=cmmdc(numarator,numitor);
                if (divizor_com>1)
                {
                    numarator/=divizor_com;
                    numitor/=divizor_com;
                }
            }
                    if (numitor<0)
            {
                divizor_com=cmmdc(-numarator,numitor);
                if (divizor_com>1)
                {
                    numarator/=divizor_com;
                    numitor/=divizor_com;
                }
            }
}
//initializare
 fractie::fractie()
{
        numarator=0;
        numitor=1;
}

fractie::fractie(int x)
{
        numarator=x;
        numitor=1;
}

    fractie::fractie(int x,int y)
{
        numarator=x;
        numitor=y;
        simplificare();
}

    //copirere
    fractie::fractie(const fractie &f)
{
        numitor=f.numitor;
        numarator=f.numarator;
        cout<<"c"<<endl;
}

    //destructor
   fractie::~fractie()
{
        cout<<"D"<<endl;
       numarator=0;
        numitor=1;
}

    //functie afisare
    void fractie::citire()
{
        cout <<"introduceti numitorul: ";
        cin>>numitor;
         cout <<"introduceti numaratorul: ";
        cin>>numarator;
}

         void fractie::afisare()
    {
        simplificare();
        if (numitor==1)
            cout<< numarator<<endl;
        else if (numitor==-1)
            cout<< -numarator<<endl;

         else
            cout << numarator << "/" << numitor << endl;
    }


    //supraincarcare citire
   istream& operator >>(istream& in, fractie& ob)
{
        in>>ob.numarator>>ob.numitor;
        return in;
}

    //supraincarcare afisare
    ostream& operator <<(ostream& out, fractie& ob)
{
        out<<ob.numarator<<"/"<<ob.numitor<<endl;
        return out;

}
//supraincarcare operatori de +.-.*,/
    fractie operator +(fractie f1, fractie f2)
{

    fractie f;
    f.numarator=f1.numarator*f2.numitor+f2.numarator*f1.numitor;
    f.numitor=f1.numitor*f2.numitor;
    void simplificare();
    return f;

}
    fractie operator -(fractie f1, fractie f2)
{

    fractie f;
    f.numarator=f1.numarator*f2.numitor-f2.numarator*f1.numitor;
    f.numitor=f1.numitor*f2.numitor;
    void simplificare();
    return f;

}

    fractie operator *(fractie f1, fractie f2)
{

    fractie f;
    f.numarator=f1.numarator*f2.numarator;
    f.numitor=f1.numitor*f2.numitor;
    void simplificare();
    return f;

}

    fractie operator *(fractie f1, int x)
{

    fractie f;
    f.numarator=f1.numarator*x;
    f.numitor=f1.numitor;
    void simplificare();
    return f;

}

    fractie operator /(fractie f1, fractie f2)
{

    fractie f;
    f.numarator=f1.numarator*f2.numitor;
    f.numitor=f1.numitor*f2.numarator;
    void simplificare();
    return f;

}

    int sistem(fractie x1,fractie x2,fractie y1,fractie y2, fractie rez1, fractie rez2)
{
    //solutiile ecuatiei
    fractie x;
    fractie y;
    //determinantii sistemului
    fractie det;
    fractie detx;
    fractie dety;

    det=x1*y2-y1*x2;
    detx=rez1*y2-y1*rez2;
    dety=x1*rez2-rez1*x2;

    x=detx/det;
    x.simplificare();
    y=dety/det;
    y.simplificare( );

    cout<<"x= ";
    x.afisare();
    cout<<endl;

    cout<<"y= ";
    y.afisare();
    cout<<endl;

    return 0;

}

//clasa pentru citirea a n obiecte de tip fractie

class nr_fractie{
    int n;
    fractie *fr;
 public:
     void citire();
     void afisare();
};
//functie de citire a n obiecte

    void nr_fractie::citire()
{
        cout<<"introduceti nr de obiecte pe care doriti sa le cititi n=";
        cin >>n;
        fr=new fractie [n];
        for(int i=0; i<n; i++)
        {
            if(i==0){cout<<"introduce numitorul si numaratorul pentru prima fractie:"<<endl;
                        cin >>fr[i];}
            else if (i==1) {cout<<"introduce numitorul si numaratorul pentru a doua fractie:"<<endl;
                                cin >>fr[i];}
            else {cout<<"introduce numitorul si numaratorul pentru a "<<i<<"-a fractie:"<<endl;
                                cin >>fr[i];}

        }

        cout<<endl<<endl;

}
//afisarea a n fractii citite anterior
    void nr_fractie::afisare()
{
    for(int i=0; i<n; i++ )
    fr[i].afisare();
}

int main()
{
    /*
    nr_fractie fr;
    fr.citire();
    fr.afisare();
    */

   // fractie f;
    //cout<<fractie f(4,5);
    //in>>f;
  //  fractie f(3);
    //f.afisare();
/*int x=3;
    fractie f(2,3);
    fractie f1=f*x;
    f1.afisare();*/
    //apelare sistem
    /*fractie x1(2);
    fractie x2(1);
    fractie y1(-3);
    fractie y2(1);
    fractie rez1(5);
   fractie rez2(10);
    fractie f(2,3);
    fractie q;
    fractie g(7,3);
    q=f+g;
    q.afisare();
    q=q+f*g;
    q.afisare();*/

   // sistem(x1, x2, y1,y2,rez1,rez2);

    //sistem(2,1,-3,1, 5, 10);

/*    fractie f;
    fractie f1(2,-3);
    fractie f2(-3,4);
    f=f1+f2;
    f.afisare();
    f=f1-f2;
    f.afisare();
    f=f1*f2;
    f.afisare();
    f=f1/f2;
    f.afisare();
    int x=3;
    f=f1*x;
    f.afisare();
*/
    fractie f(-6,3);
    f.afisare();

    return 0;
}
