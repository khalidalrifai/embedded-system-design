#include <iostream>
#include <cmath>

using namespace std;

class QuadraticEquation
{
private:

    double a, b, c, x1, x2, RealPart, ImaginaryPart, discriminant;

public:

    double DiscriminantCalc()
    {
        discriminant = sqrt(b) - 4 * a * c;
        return discriminant;
    }

    void Solve()
    {
        cout << "Enter coefficient a: ";
        cin >> a;
        cout << "Enter coefficient b: ";
        cin >> b;
        cout << "Enter coefficient c: ";
        cin >> c;

        discriminant = DiscriminantCalc();

        if (discriminant > 0)
        {
            Real(discriminant);
        }

        else if (discriminant == 0)
        {
            Duplicated(discriminant);
        }

        else
        {
            Complex(discriminant);
        }
    }

    void Real (double discriminant)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    void Duplicated (double discriminant)
    {
        cout << "Roots are real and same." << endl;
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    void Complex (double discriminant)
    {
        RealPart = -b / (2 * a);
        ImaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex and different." << endl;
        cout << "x1 = " << RealPart << "+" << ImaginaryPart << "i" << endl;
        cout << "x2 = " << RealPart << "-" << ImaginaryPart << "i" << endl;
    }
};

int main ()
{
    QuadraticEquation solve;

    while (1)
    {
        char choice;
        solve.Solve();

        cout << "Start again? (Y/N): ";
        cin >> choice;

        if (choice != 'N' && choice != 'n')
        {
            continue;
        }

        else
        {
            break;
        }
    }

    return 0;
}