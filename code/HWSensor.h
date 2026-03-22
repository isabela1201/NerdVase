#ifndef HWSENSOR_H
#define HWSENSOR_H

#include <Arduino.h>

class HWSensor {
  private:
    int _pin;
    int _seco;
    int _humido;

  public:
    // Construtor atualizado para aceitar calibração
    HWSensor(int pin, int seco = 3200, int humido = 1200) {
      _pin = pin;
      _seco = seco;
      _humido = humido;
    }

    void begin() {
      pinMode(_pin, INPUT);
    }

    int lerPercentagem() {
      int raw = analogRead(_pin);
      // Mapeia o valor bruto para 0-100%
      int p = map(raw, _seco, _humido, 0, 100);
      return constrain(p, 0, 100);
    }

    // Verifica se a planta precisa de água
    bool precisaRega(int threshold) {
      return (lerPercentagem() < threshold);
    }
};

#endif