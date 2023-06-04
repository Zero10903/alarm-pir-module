// Directivas para definir los pines a usar
#define PIR_PIN 4
#define PIEZO_PIN 5
#define BTN_PIN 3

// Variables que almacenan el valor de su componente
int pirValue = LOW;
bool btnValue = false;

void setup()
{
  // Definición de los pines
  pinMode(PIR_PIN, INPUT);
  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);

  // Definición de una interrupción para el botón
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), off, RISING);
}

void loop()
{
  // Se lee el pin del módulo PIR en busca de una señal alta o baja
  pirValue = digitalRead(PIR_PIN);
  
  // Si la señal enviada por el PIR es un alto, se activa la alarma
  if(pirValue == HIGH){
  	digitalWrite(PIEZO_PIN, HIGH);
  }

  // Si el botón es pulsado, se desactiva la alarma
  if(btnValue){
  	digitalWrite(PIEZO_PIN, LOW);
    btnValue = false;
  }

  // Delay para que el PIR no envíe señales cada milisegundo
  delay(1000);
}

// Funcuón disparada por la interrupción
void off(){
    // Cambia el valor de la variable que apaga la alarma
	btnValue = true;
}