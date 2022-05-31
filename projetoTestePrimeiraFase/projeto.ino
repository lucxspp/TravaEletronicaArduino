
const int pinoGreen= 2;
const int pinoRed = 3;
const int pinoSensor = 8; //PINO DIGITAL UTILIZADO PELO SENSOR
const int pinoBuzzer = 4 ;//PINO DIGITAL UTILIZADO PELO LED
const int pinoTrava = 7 ;//PINO DIGITAL UTILIZADO PELO RELE
int initialArray[6] = {};
int validPassword[6] = {};
int teste = 0;

void abrir(boolean validacao){
  if (validacao){
    digitalWrite(pinoTrava, HIGH);
    digitalWrite(pinoGreen, HIGH);    
    delay(4000);
    digitalWrite(pinoTrava, LOW);
    digitalWrite(pinoGreen, LOW);    
  }else{
    digitalWrite(pinoRed, HIGH);    
    delay(8000);
    digitalWrite(pinoRed, LOW);}
  
}

boolean comparar(int senhaValida[], int senhaTentada[]){
  for(int i =0; i<6; i++){
    if(senhaTentada[i] > (senhaValida[i]+150) or senhaTentada[i] < (senhaValida[i]-150) ){
        return false;
      }    
  }
  return true;  
}

int *gravar(int arr[]){
  int aux = 0;
  int aux2=0; 
  int sequenceSize = 0;
  int sequencia[6] = {};
  tone(pinoBuzzer,490);   
  while(aux < 2000){
      if (digitalRead(pinoSensor)== HIGH){
        if (aux > 100 and sequenceSize < 6){
          sequencia[sequenceSize]=aux;
          sequenceSize ++;   
        }  
        while (aux2 < 50){
          if (digitalRead(pinoSensor)== LOW){
            aux2++;
          }else {
            aux2=0;
          }
        } 
        aux=0;
      }
      aux ++;
      delay(1);
    }
    noTone(pinoBuzzer);
    for (int i = 0; i <6; i++) {
      arr[i] = sequencia[i];  
    }
    return arr;   
}

void gravarSenha(){
  if(digitalRead(pinoSensor) == HIGH){
    int *temp = gravar(initialArray); 
    for(int i=0; i<6; i++){
      validPassword[i] = temp[i];        
    }
  }
}


void setup() {
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoGreen, OUTPUT);
  pinMode(pinoRed, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoTrava, OUTPUT);
  digitalWrite(pinoTrava, LOW); //LED INICIA DESLIGADO
  
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(pinoSensor) == HIGH  and teste==0){
    gravarSenha();
    teste++;
  }
  if(digitalRead(pinoSensor) == HIGH and teste >0 ){
    int *password = gravar(initialArray);
    boolean valido= comparar(validPassword,password);
    abrir(valido);   
  }

    
    

}
