#include "triangle.h"
#include "exp.h"

 
triangle::triangle()
    : figure(" ", " ", 3, 10, 20, 30, 40, 50, 60, 70, 80)
{ 
    _figura = "Треугольник";
    _er =  "Ошибка создания фигуры.Причина: \nколичество сторон не равно 3 или сумма углов не равна 180";
    int plus = _A + _B + _C;
    if (plus != 180) throw expection(get_er());
    else if (get_storon() != 3) throw expection(get_er());
}

void triangle::print_info() const
{
    std::cout << get_figura() << "(стороны " << get_a() << " " << get_b()
        << " " << get_c() << "; углы " << get_A() << " " << get_B()
        << " " << get_C() << ") создан" << std::endl;
}