unsigned int temp;
float mV, actualTemp;
unsigned short text[10];

// LCD module connections
sbit LCD_RS at RB1_bit;
sbit LCD_EN at RB0_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;
sbit LCD_RS_Direction at TRISB1_bit;
sbit LCD_EN_Direction at TRISB0_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;
// End LCD module connections


void main(){
  
  Lcd_Init();                          // Initialize Lcd
  Lcd_Cmd(_LCD_CLEAR);                 // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);            // Cursor off
  Lcd_Out(1, 1, "Temperature : ");
  Lcd_Chr(2, 14, 39);
  Lcd_Out(2, 15, "C");
  
  PWM1_Init(5000);                    // Initialize PWM1 module at 5KHz

  PWM1_Start();                       // start PWM1

  while(1){
    temp = ADC_Read(0);
    mV = (temp*5000.0)/1024.0;
    actualTemp = mV/10.0;
    FloattoStr(actualTemp,text);
    Lcd_Out(2, 6, text);
    
    if(actualTemp > 50.0){
        PWM1_Set_Duty(255);                  // Set current duty for PWM1
    }else if(actualTemp > 45.0){
        PWM1_Set_Duty(224);                  // Set current duty for PWM1
    }else if(actualTemp > 40.0){
        PWM1_Set_Duty(192);                  // Set current duty for PWM1
    }else if(actualTemp > 35.0){
        PWM1_Set_Duty(160);                  // Set current duty for PWM1
    }else if(actualTemp > 30.0){
        PWM1_Set_Duty(128);                  // Set current duty for PWM1
    }else if(actualTemp > 25.0){
        PWM1_Set_Duty(96);                  // Set current duty for PWM1
    }else if(actualTemp > 20.0){
        PWM1_Set_Duty(64);                  // Set current duty for PWM1
    }else if(actualTemp > 15.0){
        PWM1_Set_Duty(32);                  // Set current duty for PWM1
    }else if(actualTemp > 10.0){
        PWM1_Set_Duty(0);                  // Set current duty for PWM1
    }
    
    Delay_ms(1000);
    
  }
  
}