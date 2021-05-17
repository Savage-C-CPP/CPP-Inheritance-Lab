#include <iostream>
#include <CIdentfierString.h>
#include <OctString.h>

#include "Dialog/MainMenu/ShowMainMenu.h"

using std::cin;
using std::cout;

int main(int, char **)
{
    /* CIdentifierString is; is = CIdentifierString("_testIdentifierString1"); CIdentifierString is2(MyString("this_will_be_in_new_identifier")); CIdentifierString is3("This string wont be in new identifier"); CIdentifierString is4("ButThisIsValid11__cppIdentifier"); MyString ms("Lol"); is = is + (is2 + is3) + is4 + ms; is.println(); int ixOfN = is.findFirst('n'); std::cout << "First 'n' is on index " << ixOfN << "\n"; char at15 = is[15]; std::cout << "At index 15 we have " << at15 << '\n'; OctString os1("77"); OctString os2("14"); OctString os3("334"); OctString os4("10"); OctString os5("1"); OctString os6("5"); OctString os7("465"); OctString res = os1 + os2 + os3 + os4 + os5 + os6; OctString os8("2000000000000000000000"); os8.ConvertableToUnsignedLong(); res.println(); */ // TODO: DIalog....  /* Режим диалога должен обеспечиваться с помощью иерархического меню. Основные пункты: 1. «Инициализация». Подпункты: 1.1. «Число элементов». Задает число элементов в массиве указателей на базовый класс. По­сле ввода числа элементов пользоваться этим пунктом меню запрещается.  1.2. «Начальное значение». С помощью этого пункта меню можно задать номер элемента, его тип и начальное значение. Задавать начальные значения и работать с другими пунктами меню запрещается до тех пор, пока не будет задано число элементов. Допускается задать новое началь­ное значение несколько раз.  2. «Тестирование». Подпункты: 2.1. «Строка».  2.2. «Строка-идентификатор».  2.3. Класс, соответствующий варианту задания.  2.4. «Задать операнды».  После выбора одного из этих пунктов меню предлагается выбрать один из методов из списка всех обязательных методов (кроме конструкторов и деструкторов), связанных с выбранным под­пунктом.  3. Выход.  */

    ShowMainMenu();

    return EXIT_SUCCESS;
}
