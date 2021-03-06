#define _keypad_h_

void Dieukhiencot(int8 cot,int1 trangthai);
void Khoitaophim(void);
int QT();

//Dinh nghia cot
#define C1 pin_b0
#define C2 pin_b1
#define C3 pin_b2
#define C4 pin_b3
//Dinh nghia  hang
#define H1 input(pin_b4)
#define H2 input(pin_b5)
#define H3 input(pin_b6)
#define H4 input(pin_b7)

//Ham dieu khien cot
void Dieukhiencot(int8 cot,int1 trangthai)
{
   switch(cot)
   {
      case 1:
      {
         output_bit(C1,trangthai);
         break;
      }
      case 2:
      {
         output_bit(C2,trangthai);
         break;
      }
      case 3:
      {
         output_bit(C3,trangthai);
         break;
      }
      case 4:
      {
         output_bit(C4,trangthai);
         break;
      }
   }
}
//Ham khoi tao ban phim
void Khoitaophim(void)
{
   for(int8 i=1;i<=4;i++)
   {
      Dieukhiencot(i,1);
   }
}
//Ham quet phim
int QT()
{
   int key=0;
//cot1
   Dieukhiencot(1,0);
   if(!H1)
   {
      while(!H1);
      key=1;
   }
   if(!H2)
   {
      while(!H2);
      key=2;
   }
   if(!H3)
   {
      while(!H3);   
      key=3;
   }
   if(!H4)
   {
      while(!H4);
      key=4;
   }
   Dieukhiencot(1,1);
//cot2
    Dieukhiencot(2,0);
   if(!H1)
   {
      while(!H1);
      key=5;
   }
   if(!H2)
   {
      while(!H2);
      key=6;
   }
   if(!H3)
   {
      while(!H3);
      key=7;
   }
   if(!H4)
   {
      while(!H4);
      key=8;
   }
   Dieukhiencot(2,1);
//cot3
    Dieukhiencot(3,0);
   if(!H1)
   {
      while(!H1); 
      key=9;
   }
   if(!H2)
   {
      while(!H2);
      key=10;
   }
   if(!H3)
   {
      while(!H3); 
      key=11;
   }
   if(!H4)
   {
      while(!H4);
      key=12;
   }
   Dieukhiencot(3,1);
//cot4
   Dieukhiencot(4,0);
   if(!H1)
   {
      while(!H1);
      key=13;
   }
   if(!H2)
   {
      while(!H2); 
      key=14;
   }
   if(!H3)
   {
      while(!H3); 
      key=15;
   }
   if(!H4)
   {
      while(!H4); 
      key=16;
   }
   Dieukhiencot(4,1);
   return key;
}
   
