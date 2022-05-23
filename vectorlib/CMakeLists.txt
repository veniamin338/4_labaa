

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .cpp

#include_directories(lib1)
#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
add_library(${vectorlib} STATIC ${srcs} ${hdrs}) #Сщздаем статическую библиотеку с именет из переменной vector объявленной в родительстком CVake файле (локальные переменные переносятся в наследники)в нее добавляются файлы из переменных srcs and hdrs

 #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}