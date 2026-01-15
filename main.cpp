#include <iostream>
#include <cmath>
using namespace std;

// Расширенный алгоритм Евклида
long long gcd_ext(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main() {
    long long a, b, c, x0, y0, d;
    
    cout << "Введите a, b: ";
    cin >> a >> b;
    
    int m;
    cout << "Введите n (диапазон от -m до m): ";
    cin >> m;
    
    for(int n = 4; n <= m; n++)
    {
        c = n;
        cout << "=======================================================" << endl;
        if (a >= 0 && b >= 0)
        {
            cout << a << " * x + " << b << " * y = " << c << "\tОбщие решения: " << endl;
        }
        else
        {
            cout << a << " * x " << b << " * y = " << c << "\tОбщие решения: " << endl;
        }
        
        // Найдём НОД(a, b) и коэффициенты Безу x0, y0
        d = gcd_ext(a, b, x0, y0);
        // Проверяем, делится ли c на НОД(a, b)
        if (c % d != 0) {
            cout << "-1" << endl;
            return 0;
        }
        // Нормализуем коэффициенты
        long long factor = c / d;
        x0 *= factor;
        y0 *= factor;
        // Общие решения будут зависеть от параметра k
        long long step_x = b / d;
        long long step_y = a / d;
        cout << "Частное решение: x0 = " << x0 << ", y0 = " << y0 << endl;
        
        for (int i = 4; i <= n; i=i+2) {
            cout << "Неотрицательные целочисленные решения:" << endl;
            bool found = false;
            for (int k = -n; k <= n; ++k) {
                long long x = x0 + k * step_x;
                long long y = y0 - k * step_y;
                if (x >=0  && y >= 0) { // неотрицательные решения
                    cout << "k = " << k << ": x = " << x << ", y = " << y << endl;
                    found = true;
                }
            }
            if (!found) {
                if (n > 0)
                {
                    cout << "Нет положительных решений в указанном диапазоне: (-" << n << ", " << n << ")" << endl;
                }
                else
                {
                    cout << "Нет положительных решений в указанном диапазоне: (" << n << ", " << -n << ")" << endl;
                }
            }
        }
    }
    
    
    return 0;
}
