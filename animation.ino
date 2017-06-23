void AnimationStep() {
  switch (mode) {
    case BREATHE:
      Serial.println("BREATHE");
      Breathe();
      break;

    case BLINK:
       Serial.println("BLINK");
      Blink();
      break;

    case CYCLE:
      Serial.println("CYCLE");
      Cycle();
      break;
      
    case MIX:
      Serial.println("MIX");
      Mix();
      break;      
      
    case CYCLE_BREATHE:
      Serial.println("CYCLE_BREATHE");
      CycleBreathe();
      break;
      
    case SIRENS:
      Serial.println("SIRENS");
      Sirens();
      break;
      
    case FULL_ON: 
      Full_On();
      break;
  }
}

