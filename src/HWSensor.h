#ifndef HWSENSOR_H
#define HWSENSOR_H

#include <Arduino.h>

class HWSensor {
  private:
    uint16_t _pin;
    uint16_t _seco;
    uint16_t _humido;

  public:
    // Construtor atualizado para aceitar calibração
    HWSensor(uint16_t pin, uint16_t seco = 3200, uint16_t humido = 1200) {
      _pin = pin;
      _seco = seco;
      _humido = humido;
    }

    void begin() {
      pinMode(_pin, INPUT);
    }

    uint16_t lerPercentagem() {
      uint16_t raw = analogRead(_pin);
      // Mapeia o valor bruto para 0-100%
      uint16_t p = map(raw, _seco, _humido, 0, 100);
      return constrain(p, 0, 100);
    }

    // Verifica se a planta precisa de água
    bool precisaRega(uint16_t threshold) {
      return (lerPercentagem() < threshold);
    }
};

#endif