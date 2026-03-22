# NerdVase - Vaso Inteligente (Hortelã)

O **NerdVase** é um projeto do núcleo de robótica diversificada da Universidade de Aveiro de vaso inteligente desenvolvido para sustentar plantas específicas, como a **Hortelã**, com o mínimo de intervenção humana. Este sistema monitoriza as necessidades críticas da planta e atua para garantir o seu crescimento saudável no clima de Aveiro.

## Visão Geral
A hortelã é uma planta herbácea que necessita de solo fértil, rico em matéria orgânica e com boa drenagem. O NerdVase foca-se em satisfazer as suas necessidades principais:
**Humidade do Solo:** Monitorização prioritária (1-4 vezes por dia) devido à alta necessidade hídrica da planta.
**Luminosidade:** Alta (exposição solar ou luz artificial Grow Light).
**Temperatura:** Regulação ideal para evitar extremos térmicos.

## Hardware Implementado
**Microcontrolador:** ESP32-WROVER-IE.
**Sensor de Solo:** Capacitivo HW-390 (resistente à corrosão).
**Ligação:** Pino **IO34** (entrada analógica ADC1_CH6).
**VCC:** 3.3V.

## Estrutura Modular
O código foi desenhado para ser modular, permitindo que diferentes membros da equipa trabalhem em componentes específicos:

* `main.ino`: ficheiro principal com as leituras e a lógica de decisão.
* `HWSensor.h`: módulo responsável pela leitura, filtragem de ruído e calibração da humidade do solo.

## Configuração da IDE
Para compilar este projeto na Arduino IDE:
1. Adiciona o suporte para ESP32 nas Preferências.
2. Instala o pacote **esp32 by Espressif Systems**.
3. Seleciona a placa **ESP32 Wrover Module**.
4. Define o Baud Rate do Monitor Serial para **115200**.

## RoadMap / Próximos Passos

- [ ] **Módulo Atuador:** Implementar MOSFET para controlar a Bomba de 12V.
- [ ] **Módulo de Luz:** Integrar sensor BH1750 e LED Grow Light.
- [ ] **Nutrientes e pH:** Adicionar sensores de pH e EC via conversor ADS1115.
- [ ] **Interface:** Implementar display OLED ou envio de dados para smartphone.
