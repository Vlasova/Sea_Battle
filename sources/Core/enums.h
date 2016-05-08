#ifndef ENUMS_H
#define ENUMS_H

//Читаемость кода лучше и структура понятнее, когда enum'ы находятся в классах, где используются.
//TODO раскидать enum'ы по классам.
//В c++11 появились перечисления с областью видимости (см. "Современный и эффективный c++ 11/14" С. Мейерс.)
//TODO попробовать сделать перечисления с областью видимости
enum cellStatus{whole=0, stricken, blank, tried};
enum shipStatus{safe=0, smitten, destroyed};
enum shipLine{vertical=0, horizontal};



#endif // ENUMS_H

