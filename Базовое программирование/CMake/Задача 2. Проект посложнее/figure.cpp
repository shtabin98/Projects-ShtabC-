#include "figure.h"

figure::figure(std::string figura, int storon,
    int a, int b, int c, int d,
    int A, int B, int C, int D)
    : _figura(figura)
    , _storon(storon)
    , _a(a), _b(b), _c(c), _d(d)
    , _A(A), _B(B), _C(C), _D(D) {
}

figure::figure()
    : _figura("Фигура: ")
    , _storon(0)
    , _a(10), _b(20), _c(30), _d(40)
    , _A(50), _B(60), _C(70), _D(80) {
}

std::string figure::get_figura() const { return _figura; }
int figure::get_storon() const { return _storon; }
int figure::get_a() const { return _a; } int figure::get_b() const { return _b; }
int figure::get_c() const { return _c; } int figure::get_d() const { return _d; }
int figure::get_A() const { return _A; } int figure::get_B() const { return _B; }
int figure::get_C() const { return _C; } int figure::get_D() const { return _D; }

void figure::print_info() const
{
    std::cout << get_figura() << std::endl << "Количество сторон: " << get_storon() << std::endl << std::endl;
}
