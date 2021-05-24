/*
    Библиотека для распознавания хлопков в микрофон (рекомендуется совместно с VolAnalyzer)
    Документация: 
    GitHub: https://github.com/GyverLibs/Clap
    Возможности:
    - Неблокирующий опрос
    - Считает количество хлопков
    
    AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License

    Версии:
    v1.0 - релиз
*/

#ifndef Clap_h
#define Clap_h
#include <Arduino.h>

class Clap {
public:
    // вызывать в луп, передавать текущую громкость
    void tick(int val) {
        if (millis() - _tmr >= 10) {
            _tmr = millis();
            int der = val - _prevVal;
            _prevVal = val;
            int signal = 0;
            int front = 0;
            if (der > _trsh) signal = 1;
            if (der < -_trsh) signal = -1;
            if (_prevSignal == 0 && signal == 1) front = 1;
            if (_prevSignal == 0 && signal == -1) front = -1;
            _prevSignal = signal;

            uint32_t deb = millis() - _tmr2;

            if (front == 1 && _state == 0) {
                _state = 1;
                if (!_startClap) {
                    _claps = 0;
                    _ready = 0;
                }
                _startClap = 1;
                _clap = 0;
                _tmr2 = millis();
            } else if (front == -1 && _state == 1 && deb <= 200) {
                _state = 2;
                _tmr2 = millis();
            } else if (front == 0 && _state == 2 && deb <= 200) {
                _state = 0;
                _claps++;
                _clap = 1;
                _tmr2 = millis();
            } else if (_startClap && deb > _tout) {
                _state = 0;
                _startClap = 0;
                if (_claps != 0) _ready = 1;
            }
        }
    }
    
    // установить порог громкости
    void setTrsh(int trsh) {
        _trsh = trsh;
    }
    
    // установить таймаут последнего хлопка
    void setTimeout(int tout) {
        _tout = tout;
    }
    
    // проверка на хлопок
    bool isClap() {
        if (_clap) {
            _clap = 0;
            return 1;
        }
        return 0;
    }
    
    // есть указанное количество хлопков
    bool hasClaps(uint8_t claps) {
        if (_ready && _claps == claps) {
            _ready = 0;
            _claps = 0;
            return 1;
        }
        return 0;
    }
    
    // есть несколько хлопков
    bool hasClaps() {
        return _ready;
    }
    
    // получить количество хлопков
    uint8_t getClaps() {
        if (_ready) {
            _ready = 0;
            uint8_t buf = _claps;
            _claps = 0;
            return buf;
        } return 0;
    }

private:
    uint32_t _tmr = 0, _tmr2 = 0;
    int _prevVal = 0;
    int _trsh = 150;
    uint8_t _state = 0;
    int8_t _prevSignal = 0;
    int _tout = 700;
    uint8_t _claps = 0;
    bool _ready = 0;
    bool _clap = 0;
    bool _startClap = 0;
};
#endif