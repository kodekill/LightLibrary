void Blink() {
  static int brightness = color.intensity;
  static enum {
    on,
    off,
    middle
  } type = on;

  if (type == on) {
    delay(200 * rate); //500
    brightness = color.intensity;
    type = middle;
  }

  else if (type == middle) {
    type = off;
  }

  else {
    delay(200 * rate);
    brightness = 0;
    type = on;
  }

  colorPrime = color;
  colorPrime.intensity = brightness;
}


void Breathe() {

  static enum {
    inhale,
    exhale
  } respiration = exhale;
  
  static int brightness = 255;

  if (brightness > color.intensity) {
    brightness = color.intensity;
    respiration = exhale;
  }

  if (respiration == exhale) {
    if (brightness == 0) {
      respiration = inhale;
      brightness++;
    }
    else
      brightness--;
  }

  else {
    if (brightness == color.intensity) {
      respiration = exhale;
      brightness--;
    }
    else brightness++;
  }

  // use the value of colorPrime for output
  colorPrime = color;
  colorPrime.intensity = brightness;
  
  Serial.print("brightness = ");
  Serial.println(brightness);

  //Serial.print("color.intensity = ");
 // Serial.println(color.intensity);
  
  //rate = .07; 
}


int ColorChange(){
   static enum{
    red,
    green,
    blue,
    yellow,
    purple,
    cyan,
    white
  }interval = yellow;
  
    if (interval == red)
    {
      Serial.println("red");
      input = RED;
      interval = green;
    }
  
      else if (interval == green)
    {
      Serial.println("green");
      input = GREEN;
      interval = blue;
    }
  
      else if (interval == blue)
    {
      Serial.println("blue");
      input = BLUE;
      interval = yellow;
    }
  
      else if (interval == yellow)
    {
      Serial.println("yellow");
      input = YELLOW;
      interval = purple;
    }
  
      else if (interval == purple)
    {
      Serial.println("purple");
      input = PURPLE;
      interval = cyan;
    }
  
      else if (interval == cyan)
    {
      Serial.println("cyan");
      input = CYAN;
      interval = white;
    }
  
      else if (interval == white)
    {
      Serial.println("white");
      input = WHT;
      interval = red;
    }
  return interval;
 }

void Cycle(){
  ColorChange();
  colorPrime = color;
  delay(50*rate); //100
}


void CycleBreathe(){ //NEed to work on this code, as of now resperatio = inhale doesn't do anything. 

  static enum {
   inhale,
   exhale 
  }respiration = exhale;
  
  static int brightness = 25;
 //Serial.println(color.intensity);
  //Serial.println(brightness);


if (brightness > color.intensity){
    brightness = color.intensity;
    respiration = exhale;
}

if (respiration == exhale){
  if (brightness == 0){
    respiration = inhale;
        
    Serial.print("Change Color = ");
    ColorChange();
    brightness++;
  }
  
  else 
    brightness--;
}

else{
  if (brightness == color.intensity){
    respiration = exhale;
    brightness--;
  }
  else brightness++;
}
 
  colorPrime = color;
  colorPrime.intensity = brightness;
  delayMicroseconds(50);
    //Serial.print("brightness = ");
    //Serial.println(brightness);
    
  //Serial.println(brightness);
  //delay(10*rate); //100
  
}


void Full_On() {
  colorPrime = color;
}



void Mix(){
 
  static enum {
  count_down
} RGB_value = count_down;

int Max_count = 768;
static int brightness = Max_count;

if (RGB_value == count_down) {
    if (brightness == 0) {
      brightness = Max_count;
    }
    else
      brightness--;
  }

if (brightness <= (Max_count/3))                         // <256    // Red to Yellow
  {
    color.R = ((Max_count/3) - brightness);                         // red goes from on to off
    color.G = brightness;                                           // green goes from off to on
    color.B = 0;                                                    // blue is always off
  }

else if (brightness <= ((Max_count/3)*2))                // <512    // Green to Blue
  {
    color.R = 0;                                                    // red is always off
    color.G = ((Max_count/3) - (brightness - (Max_count/3)));       // green on to off
    color.B = (brightness - (Max_count/3));                         // blue off to on
  }

else if (brightness >= ((Max_count/3)*2))                // <768    // Purple to Red
  {
    color.R = (brightness - ((Max_count/3)*2));                     // red off to on
    color.G = 0;                                                    // green is always off
    color.B = 255 - (brightness - ((Max_count/3)*2));               // blue on to off
  }
  
  Serial.print("brightness = ");
  Serial.println(brightness);
  
  colorPrime = color;
  colorPrime.intensity = 1;
  input_rate = 1;
  delay(20);
}


void Sirens(){
 
int siren_time = 100;

  for(int i = 0; i <= 2; i++){
    color.R = 5,color.G = color.B = 0;
    colorPrime = color;
    SetPixels();
    delay(siren_time);

    
    color.R = color.G = color.B = 0;
    colorPrime = color;
    SetPixels();
    delay(siren_time);
  }

  for(int i = 0; i <= 2; i++){
    color.R = color.G = 0, color.B = 5;
    colorPrime = color;
    SetPixels();
    delay(siren_time);
    
    color.R = color.G = color.B = 0;
    colorPrime = color;
    SetPixels();
    delay(siren_time);
  }
}
