// Programação extintor_teste_0001

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int pinoSensor = 0;
const int Botao1 = 6;                      //Botao para acionamento do estintor
const int Botao2 = 7;                      //Botao para cancelamento de acionamento
const int ledPin1 = 8;                     //Led de status de bom funcionamento
const int ledPin2 = 9;                     //Led de alerta de Incêndio
const int Buzzer = 10;                     //Buzzer para alarme de Incendio
const int Solenoide = 13;                  //solenoide de controle do extintor

int EstadoBotao1 = 0;                      //Botao inicia desligado
int EstadoBotao2 = 0;                      //Botao inicia desligado
int valorSensor = 0;                       //Sensor de Temperatura inicia com valor "0"

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);                      //Informa to tamanho do display
  pinMode(Botao1, INPUT);                  //Indica pno 6 como entrada
  pinMode(Botao2, INPUT);                  //Indica pno 7 como entrada
  pinMode(ledPin1, OUTPUT);                //Indica pino 8 como saida
  pinMode(ledPin2, OUTPUT);                //Indica pino 9 como saida
  pinMode(Buzzer, OUTPUT);                 //Indica pino 10 como saida
  pinMode(Solenoide, OUTPUT);              //Indica o pino 13 como saida
}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("extintor");                 //Indica o que será escrito na linha 0
  lcd.setCursor(0,1);
  lcd.print("Automovivo");               //Indica o que será escrito na linha 1
  
  delay(5000);
  
  lcd.setCursor(0,0);
  lcd.print("Carregando");
  lcd.setCursor(0,1);
  lcd.print("Configuracoes");
  
  delay(3000);
  
  lcd.setCursor(0,0);
  lcd.print("carregamento");
  lcd.setCursor(0,1);
  lcd.print("concluido");
  
  delay(2000);
  
  lcd.setCursor(0,0);
  lcd.print("Protecao");
  lcd.setCursor(0,1);
  lcd.print("Ativada");
  
  delay(5000);
  
  lcd.setCursor(0,0);
  lcd.print("status");
  lcd.setCursor(0,1);
  lcd.print("valorSensor = ");
  
  //Condição inicial caso a temperatura esteja acima de "0"
  if (valorSensor > 0){
    digitalWrite(ledPin1, HIGH);
  }
  
  //Condição inicial caso a temperatura nao esteja acima de "0"
  else{
    digitalWrite(ledPin1, LOW);
  }
  
  //Condição inicial caso a temperatura esteja acima de "800"
  if (valorSensor > 800){
    digitalWrite(ledPin1, LOW);
    delay(2000);
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin1, LOW);
    delay(1000);
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin1, LOW);
    delay(500);
    digitalWrite(ledPin1,HIGH);
  }
  
  //Condição inicial caso a temperatura esteja acima de "935"
  if (valorSensor > 935){
    digitalWrite(ledPin1, LOW);
    lcd.setCursor(0,0);
    lcd.print("Alerta, Incendio");
    lcd.setCursor(0,1);
    lcd.print("valorSensor = ");
    digitalWrite(Solenoide,HIGH);
    digitalWrite(Buzzer, HIGH);
  }
  
  else{
    digitalWrite(ledPin1, HIGH);
    lcd.setCursor(0,0);
    lcd.print("status");
    lcd.setCursor(0,1);
    lcd.print("valorSensor = ");
  }
  
  if (Buzzer == HIGH){
    digitalWrite(ledPin2, HIGH);
    delay(1000);
    digitalWrite(ledPin2, LOW);
    delay(1000);
    digitalWrite(ledPin2, HIGH);
  }
  
  else{
    digitalWrite(ledPin2, LOW);
  }
  
  if (EstadoBotao1 = HIGH){
    digitalWrite(Solenoide, HIGH);
    lcd.setCursor(0,0);
    lcd.print("status");
    lcd.setCursor(0,1);
    lcd.print("Extintor ON");
  }
  
  if (EstadoBotao2 == HIGH){
    digitalWrite(Solenoide, LOW);
    digitalWrite(Buzzer, LOW);
    digitalWrite(ledPin2, LOW);
    lcd.setCursor(0,0);
    lcd.print("status");
    lcd.setCursor(0,1);
    lcd.print("Alerta Cancelado");
  }
}
