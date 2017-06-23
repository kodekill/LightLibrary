void SetPixels() {
  //Serial.println("colorPrime.intensity");
 // Serial.println(colorPrime.intensity);
  
  int rr = colorPrime.R * colorPrime.intensity;
  int gg = colorPrime.G * colorPrime.intensity;
  int bb = colorPrime.B * colorPrime.intensity;
  
  rr = Clamp(rr);
  gg = Clamp(gg);
  bb = Clamp(bb);
  
  SetLED(strip.Color(rr, gg, bb), 0);
//  Serial.println();
//  Serial.print("Red = ");
//  Serial.println(rr);
//  
//  
//  Serial.print("Green = ");
//  Serial.println(gg);
//  
//  Serial.print("Blue = ");
//  Serial.println(bb);
}


void SetLED(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
}
