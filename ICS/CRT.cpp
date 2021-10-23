#include <iostream>
using namespace std;

class CRT
{

public:
    int total_product;
    int N;
    int Ni[100];
    int yi[100];
    int n[100];
    int b[100];
    void getData();
    void evaluate();
    bool isRelativePrime();
    static int GCD(int a, int b);

    CRT()
    {
        total_product = 1;
    }
};

void CRT::getData()
{

    cout << "\nEnter no. of inputs : ";
    cin >> N;

    cout << "\nEnter values of divisor (n) : ";

    for (int i = 0; i < N; i++)
    {
        cin >> n[i];
    }

    cout << "\nEnter values of remainder (b) : ";

    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }
}

int CRT::GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

bool CRT::isRelativePrime()
{

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (GCD(n[i], n[j]) != 1)
                return false;
        }
    }

    return true;
}

void CRT::evaluate()
{
    int ans = 0;

    // Calculating total product of divisors
    for (int i = 0; i < N; i++)
    {
        total_product = total_product * n[i];
    }

    cout << "\nTotal product of divisors (n) is : " << total_product << "\n";

    for (int i = 0; i < N; i++)
    {
        Ni[i] = total_product / n[i];
    }

    cout << "\n";

    for (int i = 0; i < N; i++)
    {
        yi[i] = 1;
    }

    cout << "\n";

    for (int i = 0; i < N; i++)
    {
        // Loop for finding out modular multiplicative inverse
        for (int j = 1; j < n[i]; j++)
        {
            if ((Ni[i] * j) % n[i] == 1)
                yi[i] = j;
        }
    }

    for (int i = 0; i < N; i++)
    {
        ans += b[i] * Ni[i] * yi[i];
    }

    ans = ans % total_product;

    cout << "\nbi\tNi\tyi";

    for (int i = 0; i < N; i++)
    {
        cout << "\n\n"
             << b[i] << "\t" << Ni[i] << "\t" << yi[i];
    }

    cout << "\n\nRemainder is " << ans;
}

int main()
{
    CRT c;
    c.getData();

    if (c.isRelativePrime())
    {
        c.evaluate();
    }
    else
    {
        cout << "Divisors (n) are not relative prime.\n";
    }
}