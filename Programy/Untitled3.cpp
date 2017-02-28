#include <iostream>

using namespace std;

bool sprawdz(string haslo)
{
    bool dlitera = false;
    bool mlitera = false;
    bool zspec = false;
    bool cyfra = false;
    char znakispec[7] = {'!', '@', '#', '$', '&', '_'};

    if (haslo.length()>20 || haslo.length()<6)
        return false;

        for (int i = 0; i<haslo.length();i++)
        {
            if ((haslo[i]+haslo[i+1] == haslo[i+2]+haslo[i+3]) || (haslo[i]+haslo[i+1]+haslo[i+2] == haslo[i+3]+haslo[i+4]+haslo[i+5]))
                return false;
            if (isdigit(haslo[i]))
                cyfra = true;
            else if (islower(haslo[i]))
                mlitera = true;
            else if (isupper(haslo[i]))
                dlitera = true;
            for (int h = 0; h<haslo.length();h++)
                if (haslo[i] == znakispec[h])
                    zspec = true;
        }
        if (dlitera && mlitera && zspec && cyfra)
            return true;
}

int main()
{
    int ile;
    string haslo;

    cin>>ile;

    for (; ile > 0; ile--)
    {
        cin>>haslo;
        if (sprawdz(haslo))
            cout << "YES";
        else cout << "NO";
    }


    return 0;
}
