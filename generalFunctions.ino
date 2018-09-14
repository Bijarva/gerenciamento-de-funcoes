
/***************************************************
* Botão de Espera para ser pressionado em um tempo definido em segundos
****************************************************/
void waitButtonPress (int waitTime)
{
  long startTiming = millis();
 while (debounce(SENSORS_READ_BUTTON)) 
 { 
   if ((millis()-startTiming) > (waitTime*1000)) break;
}
}
/***************************************************
* Temprorizadores
****************************************************/
void startTimers(void)
{
   timer.setInterval(READ_BUTTONS_TM*1000, readLocalCmd);
   timer.setInterval(READ_SOIL_TEMP_TM*1000, getSoilTempData);
   timer.setInterval(READ_AIR_DATA_TM*1000, getDhtData);
   timer.setInterval(READ_SOIL_HUM_TM*1000, getSoilMoisterData);
   timer.setInterval(AUTO_CTRL_TM*1000, autoControlPlantation);
 
}

/***************************************************
* Condição  de  leitura dos botões para corrigir possiveis erros.
****************************************************/
boolean debounce(int pin)
{
  boolean state;
  boolean previousState;
  const int debounceDelay = 30;
  
  previousState = digitalRead(pin);
  for(int counter=0; counter< debounceDelay; counter++)
  {
    delay(1);
    state = digitalRead(pin);
    if(state != previousState)
    {
      counter = 0;
      previousState = state;
    } 
  }
  return state;
}
