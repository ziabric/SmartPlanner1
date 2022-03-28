cmake_minimum_required(VERSION 3.5)

project(source VERSION 0.1 LANGUAGES CXX)


# Пишем кудой компилируем проект курсача (для дебага, релиза и тд)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Иконка приложения 
#set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/icon.rc")

set(CMAKE_INCLUDE_CURRENT_DIR ON) # Хз что это такое
set(CMAKE_AUTOUIC ON) # Автоматически устанавливаем компиляцию ui
set(CMAKE_AUTOMOC ON) # То же, но для мета данных
set(CMAKE_AUTORCC ON) # То же, но для ресурсов

if (WIN32)
    set(CMAKE_PREFIX_PATH C:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
    set(QT_DIR C:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
endif()



# Ищем библеотеки QT
find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# Говорим, что переменная PROJECT_SOURCES хранит в себе файлы(как я понял, хранит именно строку с названиями)
set(PROJECT_SOURCES main.cpp mainwindow.cpp mainwindow.h mainwindow.ui newwindow.h newwindow.cpp newwindow.ui data.h data.cpp)

# Добавляем бинарник
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${APP_ICON_RESOURCE_WINDOWS})

# Линкуем библеотеку к бинарнику
target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

#Усли оська винда, то перемещаем зависимости из папки исходников к бинарнику
if(WIN32)
    install(FILES "dependences/win/Qt5Cored.dll" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    install(FILES "dependences/win/Qt5Guid.dll" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    install(FILES "dependences/win/Qt5Widgetsd.dll" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    install (DIRECTORY "dependences/win/platforms" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})  
endif()

#if(UNIX)
#    install(FILES "dependences/osx/Qt5Cored.dll" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#    install(FILES "dependences/osx/Qt5Guid.dll" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#    install(FILES "dependences/osx/Qt5Widgetsd.dll" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#    install (DIRECTORY "dependences/win/platforms" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#endif()
