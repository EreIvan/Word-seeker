#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main(){


    size_t position_string1, position_string2 = 0;     // позиции, куда вставим >>> и <<< в случае переноса слова

    size_t capacity = 0;                               // переменная, где хранится число строк во входном тексте

    std::string temp;                                  // шаблон - последовательность букв, которую ищем в тексте

    std::string word;                                  // переменная, где хранятся кандидаты на сравнение (compare) с шаблоном (template)

    std::string stroka;                                // переменная, в которую считаем каждую строку входного текста, перед тем, как записать её в вектор строк

    std::vector<std::string> text;                     // вектор строк, в котором хранится весь текст



   std::getline(std::cin, temp, '\n');                 // считали шаблон



   for(size_t j = 0; j != temp.length(); ++j){         // проверяем шаблон на корректность и приводим все его буквы к нижнему регистру


        if(!std::isalpha(temp[j])){

            throw std::runtime_error ("Incorrect input\n");

        }else{

            temp[j] = std::tolower(temp[j]);

        }

    }



    while(std::getline(std::cin, stroka, '\n')){        // считываем текст построчно и записываем его в вектор

        text.push_back(stroka);

        capacity++;

    }



    int* stringout = new int [capacity] {};             // создали строку флагов (для вывода нужных строк текста)


    for(size_t j = 0; j != capacity; ++j){              // все буквы текста переводим в нижний регистр

            for(size_t i = 0; i != text[j].length(); ++i){

                if(std::isalpha(text[j][i])){text[j][i] = std::tolower(text[j][i]);}

            }
    }





for(size_t j = 0; j != capacity; ++j){                              // идем по всем строчкам, и по всем символам, кроме последнего

        for(size_t i = 0; i != text[j].length() - 1; ++i){



                if(std::isalpha(text[j][i])){ word.push_back(text[j][i]); }



                if(text[j][i] == ' '){                              // между соседними словами всегда есть пробел, так что если нашли его, то проводим сравнение

                     if(temp.compare(word) == 0){

                            text[j].insert(i, "<<<");

                            text[j].insert(i - temp.length(), ">>>");

                            stringout[j] = 1;                       // если нашли совпадение, выставили флаг в массиве флагов, чтобы потом вывести эту строку

                     }

                     word.erase();

                }



        }

}



    word.erase();                                               // стираем содержимое т.к. рассмотрение первого случая закончено


for(size_t j = 0; j != capacity - 1; ++j){                      // случай переноса слова

                                                                // смотрим последние символы всех строк, если нашли тире, формируем word
        if(text[j][text[j].length() - 1] == '-'){



                for(int k = 1; text[j][text[j].length() - 1 - k] != ' '; ++k){

                        word.push_back(text[j][text[j].length() - 1 - k]);

                        position_string1 = k;

                }



                std::reverse(std::begin(word), std::end(word));  // меняем порядок символов в word на противоположный, т.к. записывали туда справа-налево



                int pos = 0;

                while((text[j + 1][pos]) == ' '){++pos;}

                for(int k = pos; (text[j + 1][k] != ' ')&&(text[j + 1][k] != '.'); ++k){

                        word.push_back(text[j + 1][k]);

                        position_string2 = k + 1;

                }




                if(temp.compare(word) == 0){

                    text[j].insert(text[j].length() - 1 - position_string1, ">>>");

                    text[j + 1].insert(position_string2, "<<<");

                    stringout[j] = 1;

                    stringout[j+1] = 1;

                }


                word.erase();

        }

}





if(std::isalpha(text[0][0])){text[0][0] = std::toupper(text[0][0]);}                    // все операции сравнения проводили в нижнем регистре, теперь

                                                                                        // некоторые буквы приводим обратно к верхнему регистру


for(size_t j = 0; j != capacity; ++j){

        for(size_t i = 0; i != text[j].length(); ++i){



                if((text[j][text[j].length() - 1] == '.')&&(j!= capacity - 1)){

                        if(std::isalpha(text[j+1][0])){text[j+1][0] = std::toupper(text[j][0]);}

                }


                if(text[j][i] == '.'){

                        size_t i2 = i;

                        while((!std::isalpha(text[j][i2]))&&(i2 != text[j].length())){

                                i2++;

                        }


                        if(std::isalpha(text[j][i2])){text[j][i2] = std::toupper(text[j][i2]);}

               }



        }
}




    for(size_t j = 0; j != capacity; ++j){                              // выводим нужные строки текста

         if(stringout[j] == 1){std::cout << text[j] << '\n';}

    }


     delete[] stringout;

     return 0;
}




