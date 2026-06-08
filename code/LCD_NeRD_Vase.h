/*Para ligar ao ESP32 Dev Module : GND -> GND
                                   VCC -> 3V3
                                   SDA -> D21
                                   SCL -> D22
*/

#ifndef _LCDNERDVASE_H
#define _LCDNERDVASE_H 


#include <LiquidCrystal_I2C.h> //Inclui a biblioteca necessária para utilizar o LCD
LiquidCrystal_I2C lcd(0x27,20,4); //Configura o LCD para 16x2

byte smile[] = { //Informação para um novo caracter de uma cara a sorrir
  B00000,
  B01010,
  B01010,
  B00000,
  B11111,
  B10001,
  B01110,
  B00000
};

byte frown[] = { //Informação para um novo caracter de uma cara triste
  B00000,
  B00000,
  B01010,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000
};

void setup() {
lcd.init(); //Inicializar o LCD
lcd.backlight(); //Luz de fundo (Não remover)

lcd.createChar(0, smile);  //Cria um novo caracter de uma cara a sorrir
lcd.createChar(1, frown);  //Cria um novo caracter de uma cara triste

lcd.setCursor(6,0); //Identificação
lcd.print("NeRD");
lcd.setCursor(6,1);
lcd.print("Vase");
delay(2000);
lcd.clear();
}

void printvar(String nome, float valor){ //Esta função permite imprimir a variavel e a sua identificação para o LCD
  String id = nome + ":";
  lcd.setCursor(0,0);
  lcd.print(id);
  lcd.setCursor(0,1);
  lcd.print(valor);
}



void checkstate(float max, float min, float valor){ //Esta função coloca uma cara feliz se o valor estiver entre o máximo e o minimo e uma cara triste caso contrario
lcd.setCursor(15,1);
if (valor >= min && valor <= max){                 //Se não houver máximo ou minimo recomendo colocar o valor da variavel "valor" no lugar da variavel "max" ou "min"
lcd.write(byte(0));
} else {
lcd.write(byte(1));
}

}


void intervalClear(){ //Esta função serve para colocar a tela em branco após um certo intervalo para que deste modo possamos passar ao proximo valor
  delay(4000);
  lcd.clear();
}



#endif //_LCDNERDVASE_H