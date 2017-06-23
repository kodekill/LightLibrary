void TakeInput() {

    if (irrecv.decode(&results)) {
      Serial.print("got input: ");
      input = (results.value);
      Serial.println(input, HEX);
      delayMicroseconds(500);
    }
    
    else {
       //Serial.println("no input");
       //Note  should this say?
       //input = NULL;
    }
    
      irrecv.resume(); // Receive the next value
      delay(input_rate);
}
