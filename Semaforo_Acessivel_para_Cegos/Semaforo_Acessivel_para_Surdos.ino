               //Programação Semaforo Acessivel


// Semaforo Automotivo 1

int pinoR = 2; //PINO DIGITAL EM QUE O TERMINAL 'R' ESTÁ CONECTADO
int pinoG = 3; //PINO DIGITAL EM QUE O TERMINAL 'G' ESTÁ CONECTADO
int pinoB = 4; //PINO DIGITAL EM QUE O TERMINAL 'B' ESTÁ CONECTADO

// Semaforo Automotivo 2

int pinoR2 = 5; //PINO DIGITAL EM QUE O TERMINAL 'R' ESTÁ CONECTADO
int pinoG2 = 6; //PINO DIGITAL EM QUE O TERMINAL 'G' ESTÁ CONECTADO
int pinoB2 = 7; //PINO DIGITAL EM QUE O TERMINAL 'B' ESTÁ CONECTADO

// Semaforo Pedestre 1

int pinoR3 = 8; //PINO DIGITAL EM QUE O TERMINAL 'R' ESTÁ CONECTADO
int pinoG3 = 9; //PINO DIGITAL EM QUE O TERMINAL 'G' ESTÁ CONECTADO
int pinoB3 = 10; //PINO DIGITAL EM QUE O TERMINAL 'B' ESTÁ CONECTADO
int Buzina1 = 36;

// Semaforo Pedestre 2

int pinoR4 = 11; //PINO DIGITAL EM QUE O TERMINAL 'R' ESTÁ CONECTADO
int pinoG4 = 12; //PINO DIGITAL EM QUE O TERMINAL 'G' ESTÁ CONECTADO
int pinoB4 = 13; //PINO DIGITAL EM QUE O TERMINAL 'B' ESTÁ CONECTADO
int Buzina2 = 37;

int leitura;
char buf;


//COMENTE A LINHA ABAIXO SE O LED RGB QUE ESTÁ UTILIZANDO É CATODO COMUM
#define COMMON_ANODE


void setup() {

// CONTADOR

  pinMode(22, OUTPUT);  
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);

  pinMode(30, OUTPUT);   
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);

  // Pinos Semaforo Automotivo 1

  pinMode(pinoR, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoG, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoB, OUTPUT); //DEFINE O PINO COMO SAÍDA

  // Pinos Semaforo Automotivo 2

  pinMode(pinoR2, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoG2, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoB2, OUTPUT); //DEFINE O PINO COMO SAÍDA

  // Pinos Semaforo Pedestre 1

  pinMode(pinoR3, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoG3, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoB3, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(Buzina1, OUTPUT);

  // Pinos Semaforo Pedestre 2

  pinMode(pinoR4, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoG4, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoB4, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(Buzina2, OUTPUT);

  
  Serial.begin(9600);
  
}

void loop() {

  setColor(0, 0, 0); 
  setColor2(0, 0, 0);

   while(Serial.available() > 0)
  {
    buf = Serial.read();
  }


  if (buf == 'L'){
   
    setColor(255, 255, 0); //PARÂMETROS PARA PRODUZIR A COR AMARELO
    setColor2(255, 255, 0); //PARÂMETROS PARA PRODUZIR A COR AMARELO
    delay(1000);
    setColor(0, 0, 0); //PARÂMETROS PARA APAGAR O RBB
    setColor2(0, 0, 0); //PARÂMETROS PARA APAGAR O RBB
    delay( 1000);
  }

  if (buf == 'D'){
    
    //Luzes Semaforo
    
    setColorP1(0, 255, 0); //PARÂMETROS PARA PRODUZIR A COR VERDE PARA PEDESTRE 1
    setColor(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO
    setColorP2(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 2
    setColor2(0, 255, 0); //PARÂMETROS PARA PRODUZIR A COR VERDE
    
    
    // write digit '20'
    segDisplay(1, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    segDisplay2(0, 0, 0, 0, 0, 0, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY    
    delay(1000);

    // write digit '19'

    segDisplay(0, 1, 1, 0, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    segDisplay2(0, 0, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write digit '18'
    segDisplay2(0, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '17'
    segDisplay2(0, 0, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '16'
    segDisplay2(1, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '15'
    segDisplay2(1, 0, 0, 0, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '14'
    segDisplay2(0, 1, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    // write '13'
    segDisplay2(0, 0, 0, 0, 1, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '12'
    segDisplay2(0, 0, 1, 0, 0, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    // write '11'
    segDisplay2(0, 1, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    // write '10'
    segDisplay2(0, 0, 0, 0, 0, 0, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    
    // CONTAGEM REGRESSIVA

    // write '9'
    segDisplay(1, 1, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    segDisplay2(0, 0, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
 
  // write digit '18'
    segDisplay2(0, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '7'
    segDisplay2(0, 0, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '6'
    segDisplay2(1, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '5'
    segDisplay2(1, 0, 0, 0, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '4'
    segDisplay2(0, 1, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    setColor2(255, 255, 0); //PARÂMETROS PARA PRODUZIR A COR AMARELA
    digitalWrite(Buzina1, HIGH);
    setColorP1(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 1
    
    // write '3'
    segDisplay2(0, 0, 0, 0, 1, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    
    delay(500);
    setColorP1(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 1
    digitalWrite(Buzina1, LOW);

    delay(500);

     // write '2'
    segDisplay2(0, 0, 1, 0, 0, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY

    //ESTADO DO ALARME SONORO
    setColorP1(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 1
    digitalWrite(Buzina1, HIGH);
    delay(500);
    setColorP1(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 1
    digitalWrite(Buzina1, LOW);
    delay(500);

     // write '1'
    segDisplay2(0, 1, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY

     //ESTADO DO ALARME SONORO
    setColorP1(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 1
    digitalWrite(Buzina1, HIGH);
    delay(500);
    setColorP1(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 1
    digitalWrite(Buzina1, LOW);
    delay(500);


     // write '0'
    segDisplay2(0, 0, 0, 0, 0, 0, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY

    
    //ESTADO DO ALARME SONORO
    setColorP1(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 1
    digitalWrite(Buzina1, HIGH);
    delay(500);
    setColorP1(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 1
    digitalWrite(Buzina1, LOW);
    delay(500);
    
    
    setColor(0, 255, 0); //PARÂMETROS PARA PRODUZIR A COR VERDE
    setColorP2(0, 255, 0); //PARÂMETROS PARA PRODUZIR A COR VERDE PARA PEDESTRE 2
    setColor2(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO
    setColorP1(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 1

     // write digit '20'
    segDisplay(1, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    segDisplay2(0, 0, 0, 0, 0, 0, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY    
    delay(1000);

    // write digit '19'

    segDisplay(0, 1, 1, 0, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    segDisplay2(0, 0, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write digit '18'
    segDisplay2(0, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '17'
    segDisplay2(0, 0, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '16'
    segDisplay2(1, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '15'
    segDisplay2(1, 0, 0, 0, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '14'
    segDisplay2(0, 1, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    // write '13'
    segDisplay2(0, 0, 0, 0, 1, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '12'
    segDisplay2(0, 0, 1, 0, 0, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    // write '11'
    segDisplay2(0, 1, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    // write '10'
    segDisplay2(0, 0, 0, 0, 0, 0, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    
    // CONTAGEM REGRESSIVA

    // write '9'
    segDisplay(1, 1, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    segDisplay2(0, 0, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    // write digit '8'
    segDisplay2(0, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '7'
    segDisplay2(0, 0, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    // write '6'
    segDisplay2(1, 0, 0, 0, 0, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '5'
    segDisplay2(1, 0, 0, 0, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);
    
    
    // write '4'
    segDisplay2(0, 1, 0, 1, 1, 0, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(1000);

    
    //ESTADO DO ALARME SONORO
    setColor(255, 255, 0); //PARÂMETROS PARA PRODUZIR A COR AMARELO
    digitalWrite(Buzina2, HIGH);
    setColorP2(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 2


     // write '3'
    segDisplay2(0, 0, 0, 0, 1, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
    delay(500);

    //ESTADO DO ALARME SONORO
    setColorP2(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 2
    digitalWrite(Buzina2, LOW);
    delay(500);
    
    // write '2'
    segDisplay2(0, 0, 1, 0, 0, 1, 0); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY

    //ESTADO DO ALARME SONORO
    setColorP2(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 2
    digitalWrite(Buzina2, HIGH);
    delay(500);
    setColorP2(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 2
    digitalWrite(Buzina2, LOW);
    delay(500);

     // write '1'
     segDisplay2(0, 1, 0, 1, 1, 1, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY

     //ESTADO DO ALARME SONORO
     setColorP2(255, 0, 0); //PARÂMETROS PARA PRODUZIR A COR VERMELHO PARA PEDESTRE 2
     digitalWrite(Buzina2, HIGH);
     delay(500);
     setColorP2(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 2
     digitalWrite(Buzina2, LOW);
     delay(500);
     
     
     
     // write '0'
     segDisplay2(0, 0, 0, 0, 0, 0, 1); //PARÂMETROS PARA ALTERAR OS SEGMENTOS DO  DO DISPLAY
     setColorP1(0, 0, 0); //PARÂMETROS PARA APAGAR A COR VERMELHO PARA PEDESTRE 1
  }

  delay(1000);
}


 //FUNÇÃO QUE PRODUZ O BRILHO DE CADA UM DOS LEDS DE ACORDO COM OS PARÂMETROS INFORMADOS
void setColor(int vermelho, int verde, int azul){
  
  #ifdef COMMON_ANODE //SE O LED RGB FOR DEFINIDO COMO ANODO COMUM, FAZ
    vermelho = 255 - vermelho; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (vermelho) INFORMADO' NA CHAMADA DA FUNÇÃO
    verde = 255 - verde; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (verde) INFORMADO' NA CHAMADA DA FUNÇÃO
    azul = 255 - azul; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (azul) INFORMADO' NA CHAMADA DA FUNÇÃO
    
  #endif
  analogWrite(pinoR, vermelho); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'vermelho'
  analogWrite(pinoG, verde); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'verde'
  analogWrite(pinoB, azul); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'azul'

}


 //FUNÇÃO QUE PRODUZ O BRILHO DE CADA UM DOS LEDS DE ACORDO COM OS PARÂMETROS INFORMADOS
void setColor2(int vermelho2, int verde2, int azul2){
  
  #ifdef COMMON_ANODE //SE O LED RGB FOR DEFINIDO COMO ANODO COMUM, FAZ
    vermelho2 = 255 - vermelho2; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (vermelho) INFORMADO' NA CHAMADA DA FUNÇÃO
    verde2 = 255 - verde2; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (verde) INFORMADO' NA CHAMADA DA FUNÇÃO
    azul2 = 255 - azul2; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (azul) INFORMADO' NA CHAMADA DA FUNÇÃO
    
  #endif
  analogWrite(pinoR2, vermelho2); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'vermelho'
  analogWrite(pinoG2, verde2); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'verde'
  analogWrite(pinoB2, azul2); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'azul'
}

//FUNÇÃO QUE PRODUZ O BRILHO DE CADA UM DOS LEDS DE ACORDO COM OS PARÂMETROS INFORMADOS
void setColorP1(int vermelho3, int verde3, int azul3){
  
  #ifdef COMMON_ANODE //SE O LED RGB FOR DEFINIDO COMO ANODO COMUM, FAZ
    vermelho3 = 255 - vermelho3; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (vermelho) INFORMADO' NA CHAMADA DA FUNÇÃO
    verde3 = 255 - verde3; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (verde) INFORMADO' NA CHAMADA DA FUNÇÃO
    azul3 = 255 - azul3; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (azul) INFORMADO' NA CHAMADA DA FUNÇÃO
    
  #endif
  analogWrite(pinoR3, vermelho3); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'vermelho'
  analogWrite(pinoG3, verde3); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'verde'
  analogWrite(pinoB3, azul3); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'azul'
}

//FUNÇÃO QUE PRODUZ O BRILHO DE CADA UM DOS LEDS DE ACORDO COM OS PARÂMETROS INFORMADOS
void setColorP2(int vermelho4, int verde4, int azul4){
  
  #ifdef COMMON_ANODE //SE O LED RGB FOR DEFINIDO COMO ANODO COMUM, FAZ
    vermelho4 = 255 - vermelho4; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (vermelho) INFORMADO' NA CHAMADA DA FUNÇÃO
    verde4 = 255 - verde4; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (verde) INFORMADO' NA CHAMADA DA FUNÇÃO
    azul4= 255 - azul4; //VARIÁVEL RECEBE O RESULTADO DA OPERAÇÃO '255 MENOS O PARÂMETRO (azul) INFORMADO' NA CHAMADA DA FUNÇÃO
    
  #endif
  analogWrite(pinoR4, vermelho4); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'vermelho'
  analogWrite(pinoG4, verde4); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'verde'
  analogWrite(pinoB4, azul4); //DEFINE O BRILHO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'azul'
}

//FUNÇÃO QUE  ACIONA OS SEGMENTOS DO DIGITO 1 DO DISPLAY, DE ACORDO COM OS PARÂMETROS INFORMADOS
void segDisplay(int digito8, int digito9, int digito10, int digito11, int digito12, int digito13){
  
  #ifdef COMMON_ANODE //SE O LED RGB FOR DEFINIDO COMO ANODO COMUM, FAZ
    digito8  = digito8; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito9  = digito9; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito10 = digito10; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito11 = digito11; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito12 = digito12; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito13 = digito13; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    
  #endif //DEFININDO OS PARAMETROS FINAIS DA CONDIÇÃO 'SE'
  digitalWrite(30, digito8); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(31, digito9); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(32, digito10); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(33, digito11); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(34, digito12); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(35, digito13); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
}



//FUNÇÃO QUE  ACIONA OS SEGMENTOS DO DIGITO 2 DO DISPLAY, DE ACORDO COM OS PARÂMETROS INFORMADOS
void segDisplay2(int digito1, int digito2, int digito3, int digito4, int digito5, int digito6, int digito7){
  
  #ifdef COMMON_ANODE //SE O LED RGB FOR DEFINIDO COMO ANODO COMUM, FAZ
    digito1 = digito1; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito2 = digito2; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito3 = digito3; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito4 = digito4; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito5 = digito5; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito6 = digito6; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    digito7 = digito7; //VARIÁVEL RECEBE O PARÂMETRO (digito) INFORMADO' NA CHAMADA DA FUNÇÃO
    
  #endif //DEFININDO OS PARAMETROS FINAIS DA CONDIÇÃO 'SE'
  digitalWrite(22, digito1); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(23, digito2); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(24, digito3); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(25, digito4); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(26, digito5); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(27, digito6); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
  digitalWrite(28, digito7); //DEFINE O ESTADO DO LED DE ACORDO COM O VALOR INFORMADO PELA VARIÁVEL 'digito'
}
