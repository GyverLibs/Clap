![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![author](https://img.shields.io/badge/author-AlexGyver-informational.svg)
# Clap
Библиотека для распознавания хлопков в микрофон (рекомендуется совместно с VolAnalyzer.h)
- Неблокирующий опрос
- Считает количество хлопков

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **Clap** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/Clap/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
```cpp
Clap clap;
```

<a id="usage"></a>
## Использование
```cpp
void tick(int val);             // вызывать в луп, передавать текущую громкость
void setTrsh(int trsh);         // установить порог громкости
void setTimeout(int tout);      // установить таймаут последнего хлопка
bool isClap();                  // проверка на хлопок
bool hasClaps(uint8_t claps);   // есть указанное количество хлопков
bool hasClaps();                // есть несколько хлопков
uint8_t getClaps();             // получить количество хлопков
```

<a id="example"></a>
## Пример
```cpp
// распознавание количества хлопков

#include <VolAnalyzer.h>
#include <Clap.h>

VolAnalyzer vol(A0);	// микрофон на А0
Clap clap;

void setup() {
  Serial.begin(115200);
}

void loop() {
  vol.tick();
  clap.tick(vol.getRawMax());
  if (clap.isClap()) Serial.println("clap");
  if (clap.hasClaps(1)) Serial.println("1 clap");
  if (clap.hasClaps(2)) Serial.println("2 clap");
  if (clap.hasClaps(3)) Serial.println("3 clap");
}
```

<a id="versions"></a>
## Версии
- v1.0

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!