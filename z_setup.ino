void setup() {
  color = {0, 0, 0, default_intensity}; //initialize pixels to off with a pre-set intensity
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);
  //setup_mode();
}


void setup_mode(){
//color.R = color.B = 0, color.G = 5;
//color.R=30, color.G=50, color.B=0;

default_intensity = .5;

  mode = SIRENS;
//mode = CYCLEBREATHE;
//mode = FULL_ON;
}

