#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

typedef unsigned long long int LL;
LL a, b, c, ans;

LL mult(LL a, LL b,LL c)
{
    LL res = 0;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            b--;
            res = (res + a) % c;

        }
        a = (a + a) % c;
        b /= 2;

    }
    return res;

}

int gcd(unsigned long long  int a, unsigned long long int b, unsigned long long int & x, unsigned long long int & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    unsigned long long int x1, y1;
    unsigned long long int l = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return l;
}


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned long long int shifr_ost,shifr,otvet,litera,ostatok, E=0, N, N1, y, x=0, p1 = 982451653, p2 = 961748941,ToGetE=0  ,d, p,s_msg;
    N = p1 * p2;
    N1 = (p1 - 1) * (p2 - 1);
    string to_decrypt;
    int exit = -1;

    int i,k=4,r=20;

    int choice = 0;
    while (ToGetE == 0)
    {
        E++;
        ToGetE = N1 % E;
    }
  
    int g = gcd(E, N1, d, p); //d - обратный элемент для E по модулю N1

    while (exit != 2)
    {
        system("cls");
        cout << "Введите ваше сообщение, и на конце поставте точку: \n";
        char* msg = new char[256];
        cin.getline(msg, 256, '.');
        int length_of_msg = strlen(msg) - 1;
        int counter = 0;
        x = 0;

        while (counter <= length_of_msg)
        {
            counter = k;

            x = 0;
            for (i = 0; i < 4; i++)
            {
                if ((int)msg[k - i - 1] == 0 || (int)msg[k - i - 1] < 0)
                    counter = length_of_msg + 1;
                else
                {
                    x = x + (int)msg[k - i - 1] * pow(256, i);
                    //cout << "ASCII " << msg[k - i-1 ] << " = " << (int)msg[k - i-1 ] <<endl;
                    //cout << "x= " << x << endl;
                }

            }
            k += 4;
            //cin >> a >> b >> c;
            a = x, b = E, c = N;
            ans = 1;
            while (b > 0)
            {
                if (b % 2 == 1)
                {
                    b--;
                    ans = mult(ans, a, c);

                }
                b /= 2;
                a = mult(a, a, c);

            }
            //cout << ans;
            y = ans;
            to_decrypt = to_decrypt + to_string(y) + " ";
            shifr = y;
            shifr_ost = shifr;
            for (int j = -1; r > j; r--)
            {

                litera = shifr_ost / (unsigned long long int)(pow(256, r));
                shifr_ost = shifr_ost % (unsigned long long int) pow(256, r);
                if (litera != 0)
                {
                    cout << "Буква после ШИФРОВКИ:" << (char)litera << " ASCII= " << litera << endl;
                }
            }

        }
        delete msg;

        cout << "---------------------------ENCRYPTED---------------------------\n\n";
        //----------------------------------------------------------------зашифровал
        int spaces = count(to_decrypt.begin(), to_decrypt.end(), ' ');
        char decrypted_msg[250] = "";
        int numb = 0;
        while (spaces != 0)
        {
            spaces = spaces - 1;
            LL decrypted = 0;

            string line = to_decrypt.substr(0, to_decrypt.find(' '));
            to_decrypt = to_decrypt.substr(to_decrypt.find(' ') + 1, to_decrypt.size());
            for (int z = 0; z < line.length(); z++) {
                decrypted = decrypted * 10 + line[z] - 0x30;
            }
            r = 20;
            y = decrypted;
            //cin >> a >> b >> c;
            a = y, b = d, c = N;
            ans = 1;
            while (b > 0)
            {
                if (b % 2 == 1)
                {
                    b--;
                    ans = mult(ans, a, c);

                }
                b /= 2;
                a = mult(a, a, c);

            }
            //cout << ans;
            otvet = ans;
            ostatok = otvet;
            for (int j = -1; r > j; r--)
            {

                litera = ostatok / (unsigned long long int)(pow(256, r));
                ostatok = ostatok % (unsigned long long int) pow(256, r);
                if (litera != 0)
                {
                    cout << "Буква после РАСШИФРОВКИ:" << (char)litera << " ASCII= " << litera << endl;
                    decrypted_msg[numb] = (char)litera;
                    numb++;
                }
            }

            r = 20;
        }
        cout << "MESSAGE : " << decrypted_msg << endl;
        cout << "\nКонец.\n\n1. Ещё раз!\n2. Выход\n";
        cin >> exit;
    }
}