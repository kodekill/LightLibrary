
void Interpret(){
  switch (input) { 
      case RED:
        color.R = 5,color.G = color.B = 0;
        break;

      case GREEN:
        color.R = color.B = 0, color.G = 5;
        break;

      case BLUE:
        color.R = color.G = 0, color.B = 5;
        break;
        
      case WHT:
        color.R = color.G = color.B = 3;
        break;
        
      case DARKORANGE:
        color.R = 5, color.G = 3, color.B = 0;
        break;

      case TURQUOISE:
        color.R = 0, color.G = 10, color.B = 5;
        break;       
         
      case DARKBLUE:
        color.R = 0, color.G = 0, color.B = 5;
        break;
        
      case ORANGE:
        color.R = 10, color.G = 5, color.B = 0;
        break;
       
      case CYAN:
        color.R = 0, color.G = color.B = 5;
        break;

      case PURPLE:
        color.R = 3, color.G = 0, color.B = 5;
        break;
        
      case YELLOWORANGE:
        color.R = 10, color.G = 7, color.B = 5;
        break;
        
      case LIGHTBLUE:
        color.R = 0, color.G = 5, color.B = 10;
        break;

      case LIGHTPURPLE:
        color.R = 5, color.G = 0, color.B = 10;
        break;

      case YELLOW:
        color.R = 4, color.G = 6, color.B = 0;
        break;

      case SKYBLUE:
        color.R = 0, color.G = 0, color.B = 5;
        break;

      case PINK:
        color.R = 10, color.G = 0, color.B = 5;
        break;

      case UP:
        increaseIntensity();
        break;

      case DOWN:
        decreaseIntensity();
        break;

      case OFF:
        color.R = color.G = color.B = 0;
        break;
        
      case ON:
        mode = FULL_ON;
        break; 

      case FLASH:
        mode = SIRENS;
        //mode = BLINK;      
        break; 
               
      case STROBE:
        mode = CYCLE;
        break; 
        
      case FADE:
        mode = CYCLE_BREATHE;
        break;   
                     
      case SMOOTH:
        mode = MIX;
        break;

      case SIRENS:
        mode = SIRENS;
        break;

      case SOMEBUTTON:   //made up place holder for this option
        mode = BREATHE;
        break;
    }
    input = 0;
}

