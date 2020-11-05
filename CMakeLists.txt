cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME Lab_MultiSteck) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(StackLib StackLib) #Переменная с именем библиотеки
set(MultiStack MultiStack)
set(main main)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib
${CMAKE_CURRENT_SOURCE_DIR}/MultiStack) 
# ${CMAKE_CURRENT_SOURCE_DIR}/gtest) 
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории

 #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(StackLib)
add_subdirectory(MultiStack)
add_subdirectory(main)

add_subdirectory(gtest)
add_subdirectory(test)