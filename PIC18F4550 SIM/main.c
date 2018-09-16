
#include <main.h>
#define LCD_ENABLE_PIN PIN_E2
#define LCD_RS_PIN PIN_E0
#define LCD_RW_PIN PIN_E1
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
#include <lcd.c>
#include <keypad.h>
#include <string.h>
#include <stdio.h>

//Ban Phim
char Banphim[16]= {'1','4','7','*',
                   '2','5','8','0',
                   '3','6','9','#',
                   'a','b','c','d'};

int1 kt;
int8 key,mksai=0;
int8 NewSms=0,NewCall=0;
char Inpass[5],Newpass[5];
char Password[5];
char rcv=0,b1=0,b2=0,b3=0,b4=0,b5=0;
char Buffer[150];
int  o=0;
char SDT0[]="01683173311",SDT84[]="841683173311";
char PassUnlock[]="Lock";
char PassWarning[]="Seen";
int  counter=0,Servo=4;
//Ham kiem tra pass
int1 Ktmk(int1 b)
{
   Switch(b)
   {
      case 0: //Inpass vs Password
      {
         int8 a=0;
         for(int8 i=0;i<=4;i++)
         {
            if(Inpass[i]==Password[i])
            {
               a++;
            }
         }
         if(a==5) return 1;
         else return 0;
         break;
      }
      case 1: //Inpass vs Newpass
      {
         int8 a=0;
         for(int8 i=0;i<=4;i++)
         {
            if(Inpass[i]==Newpass[i])
            {
               a++;
            }
         }
         if(a==5) return 1;
         else return 0;
         break;
      }
   }
}
#int_RDA
void RDA_isr(void)
{
   rcv=getc();
   if(rcv=='+') b1=rcv;
   if(rcv=='C') b2=rcv;
   if(rcv=='M') b3=rcv;
   if(rcv=='T') b4=rcv;
   if(rcv=='I') b5=rcv;
   if(b1=='+' && b2=='C' && b3=='M' && b4=='T' && b5=='I')
   {
      NewSms=1;
   }
   //goi
   if(rcv=='+') b1=rcv;
   if(rcv=='C') b2=rcv;
   if(rcv=='L') b3=rcv;
   if(rcv=='I') b4=rcv;
   if(rcv=='P') b5=rcv;
   if(b1=='+' && b2=='C' && b3=='L' && b4=='I' && b5=='P')
   {
      NewCall=1;
   }
   //SMS,CALL
   if((NewSms==1 || NewCall==1) && rcv != '\0')
   {
      Buffer[o++]=rcv;
   }
   if(o>=150)
   {
      o=0;
   }
}
//Ngat timer
#INT_TIMER2
void  TIMER2_isr(void) 
{
   counter+=1;
   if(counter<=Servo)
   {
      set_pwm1_duty((int16)1021);
   }
   else if(counter>Servo && counter<=39)
   {
      set_pwm1_duty((int16)0);
   }
   else counter=0;
   
}
//Reset Buffer
void reset()
{
   NewSms=NewCall=0;
   b1=b2=b3=b4=b5=0;
   o=0;
   for(int i=0;i<=150;i++)
   {
      Buffer[i]='\0';
   }
   printf("AT+CMGDA=\"DEL ALL\"\r\n");
   delay_ms(500); 
}
void main()
{ 
   lcd_init();
   setup_timer_2(T2_DIV_BY_16,130,1);      //Cai dat timer
   setup_ccp1(CCP_PWM);                    //Cai dat CCP PWM
   set_pwm1_duty((int16)1021);
   enable_interrupts(INT_TIMER2);          //Ngat timer
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RDA); //cho phep ngat uart - ngat nhan du lieu tu sim800
   enable_interrupts(GLOBAL);
   for(int i=0;i<=4;i++)
   {
      Password[i]= read_eeprom(i);
      delay_ms(20);
   }
   Khoitaophim();
   Servo=4;
   counter=0;
   lcd_putc("Loading.....");
   delay_ms(12000);
   printf("AT+CNMI=2,1\r\n"); delay_ms(500);
   printf("AT+CSAS\r\n"); delay_ms(500);
   printf("AT+CMGS=\"01683173311\"\r\n");
   delay_ms(500);
   printf("Hello Bayby!");
   putc(26);
   delay_ms(500);
   lcd_putc("\f");
   lcd_gotoxy(4,1);
   lcd_putc("Welcome!!!");
   delay_ms(1000);
   int khoa=1;
GOTO4: lcd_putc("\f");
   lcd_gotoxy(5,1);
   lcd_putc("Locked!");
   while(true)
   {
      //Quen Mat Khau
      if(NewCall==1)                                //Neu co nguoi goi den
      {
         output_high(pin_a2);
         delay_ms(250);
         output_low(pin_a2);
         delay_ms(2000);
         printf("ATH\r\n"); delay_ms(500);
         if(strstr(Buffer,SDT0)!='\0'|| strstr(Buffer,SDT84)!='\0')
         {
            printf("AT+CMGS=\"%s\"\r\n",SDT0);
            delay_ms(500);
            printf("Mat khau: ");
            for(int i=0;i<=4;i++)
            {
               printf("%c",Password[i]);
            }
            putc(26);
            delay_ms(500);
         }
         reset();
      }
//Mo bang tin nhan
      if(NewSms==1)
      {
         output_high(pin_a2);
         delay_ms(250);
         output_low(pin_a2);
         printf("AT+CMGR=1\r\n"); 
         delay_ms(2000);
         if(strstr(Buffer,PassUnlock)!='\0')
         {
            khoa=0;
            mksai=0;
            output_high(pin_a0);
            reset();
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            delay_ms(150);
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            Servo=2;
            delay_ms(500);
            goto GOTO3;
         }
         reset();
      }
      
      
      key = QT();
      if(key==13&&khoa==1)                                            //Nhap MK
      {
GOTO5:   int8 index=6;
         int8 i=0;
         lcd_putc("\f");
         lcd_putc("Nhap Mat Khau:");
         lcd_gotoxy(6,2);
         lcd_putc("_____");
         while(i<=4)
         {
            key = QT();
            if(key==16)
            {
               goto GOTO4;
            }
            if((key>=1&&key<=3)||(key>=5&&key<=11))
            {
               Inpass[i]=Banphim[key-1];
               lcd_gotoxy(index,2);
               index++;
               printf(lcd_putc,"*");
               i++;
            }  
            delay_ms(50); 
         }
         delay_ms(250);
         kt=Ktmk(0);
         if(kt==1)
         {
            khoa=0;
            mksai=0;
            lcd_putc("\f");
            lcd_putc("Mat khau Dung!");
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            delay_ms(150);
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            output_high(pin_a0);
            Servo=2;
            delay_ms(500);
    GOTO3:  lcd_putc("\f");
            lcd_gotoxy(5,1);
            lcd_putc("Unlocked!");
          }
          else if(kt==0)                        //Mat khau sai
          {
             mksai++;
             
             lcd_putc("\f");
             lcd_putc("Mat khau Sai!");
             output_high(pin_a2);
             delay_ms(500);
             output_low(pin_a2);
             if(mksai==3)
             {
                int ChinhChu=0;
                output_high(pin_a2);
                printf("AT+CMGS=\"%s\"\r\n",SDT0);
                delay_ms(500);
                printf("Canh Bao: Thiet bi da bi vo hieu hoa!");
                putc(26);
                delay_ms(500);
                printf(lcd_putc,"\f");
                lcd_gotoxy(4,1);
                printf(lcd_putc,"Warning!!!");
                output_high(pin_a1);
                while(ChinhChu==0)
                {
                  if(NewCall==1)
                  {
                     output_high(pin_a2);
                     delay_ms(250);
                     output_low(pin_a2);
                     delay_ms(1000);
                     printf("ATH\r\n"); delay_ms(500);
                     reset();
                  }
                  if(NewSms==1)
                  {
                     output_high(pin_a2);
                     delay_ms(250);
                     output_low(pin_a2);
                     printf("AT+CMGR=1\r\n"); 
                     delay_ms(2000);
                     if(strstr(Buffer,PassWarning)!='\0')
                     {
                        ChinhChu=1;
                     }
                     reset();
                  } 
                }
                mksai=0;
                output_low(pin_a2);
                output_low(pin_a1);
             }
             delay_ms(750);
             lcd_putc("\f");
             lcd_putc("Moi Nhap Lai");
             delay_ms(750);
             goto GOTO5;
          }
      }
            
      if(key==14&&khoa==0)                                              // Khoa
      {
         khoa=1;
         output_high(pin_a2);
         delay_ms(500);
         output_low(pin_a2);
         output_low(pin_a0);
         Servo=4;
         delay_ms(500);
         lcd_putc("\f");
         lcd_gotoxy(5,1);
         lcd_putc("Locked!");
      }
      if(key==15&&khoa==0)                                            //Doi  mk
      {
    GOTO1: int8 index=6;                             //Nhap MK cu
           int8 i=0;
           lcd_putc("\f");                                  
           lcd_putc("Nhap MK cu:");
           lcd_gotoxy(6,2);
           lcd_putc("_____");
           while(i<=4)
           {
               key = QT();
               if(key==16)
               {
                  goto GOTO3;
               }
               if((key>=1&&key<=3)||(key>=5&&key<=11))
               {
                  Inpass[i]=Banphim[key-1];
                  lcd_gotoxy(index,2);
                  index++;
                  printf(lcd_putc,"*");
                  i++;
               }  
               delay_ms(50);
           }
           delay_ms(250);
           kt=ktmk(0);
           if(kt==1)
           {
              output_high(pin_a2);
              delay_ms(250);
              output_low(pin_a2);
              delay_ms(150);
              output_high(pin_a2);
              delay_ms(250);
              output_low(pin_a2);
     GOTO2:   lcd_putc("\f");                        //Nhap MK moi
              lcd_putc("Nhap MK moi:");
              lcd_gotoxy(6,2);
              lcd_putc("_____");
              int8 index=6;
              int8 i=0;
              while(i<=4)
              {
                 key = QT();
                 if(key==16)
                 {
                    goto GOTO3;
                 }
                 if((key>=1&&key<=3)||(key>=5&&key<=11))
                 {
                    Newpass[i]=Banphim[key-1];
                    lcd_gotoxy(index,2);
                    index++;
                    printf(lcd_putc,"*");
                    i++;
                 }
                 delay_ms(50);
              }
              delay_ms(250);
              lcd_putc("\f");                        //Kiem tra Mk moi
              lcd_putc("Xac nhan MK moi:");
              lcd_gotoxy(6,2);
              lcd_putc("_____");
              index=6;
              i=0;
              while(i<=4)
              {
                 key = QT();
                 if(key==16)
                 {
                    goto GOTO3;
                 }
                 if((key>=1&&key<=3)||(key>=5&&key<=11))
                 {
                     Inpass[i]=Banphim[key-1];
                     lcd_gotoxy(index,2);
                     index++;
                     printf(lcd_putc,"*");
                     i++;
                 }
                 delay_ms(50);
               }
               delay_ms(250);
               kt=Ktmk(1);
               if(kt==1)
               {
                   output_high(pin_a2);
                   delay_ms(250);
                   output_low(pin_a2);
                   delay_ms(150);
                   output_high(pin_a2);
                   delay_ms(250);
                   output_low(pin_a2);
                   lcd_putc("\f");
                   lcd_putc("Da doi mat khau!");
                   for(int8 i=0;i<=4;i++)
                   {
                       Password[i]=Newpass[i];
                       write_eeprom(i,Password[i]);
                       delay_ms(20);
                   }
                   delay_ms(750);
                   goto GOTO3;
                }
                else if(kt==0)
                {
                   output_high(pin_a2);
                   delay_ms(500);
                   output_low(pin_a2);
                   lcd_putc("\f");
                   lcd_putc("MK khong khop!");
                   delay_ms(750);
                   goto GOTO2;
                }   
           }
           else if(kt==0)
           {
               output_high(pin_a2);
               delay_ms(500);
               output_low(pin_a2);
               lcd_putc("\f");
               lcd_putc("Mat Khau Sai!");
               delay_ms(750);
               goto GOTO1;
           }
      }
      delay_ms(50);
   }
}

   
   

