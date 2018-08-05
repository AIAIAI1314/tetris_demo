#include <IRremote.h>
#include <U8glib.h>

U8GLIB_SSD1306_128X64 u8g(10, 9, 12, 11, 13); //SCK = 10, MOSI = 9 , CS = 12, A0 = 11, RES = 13
int dot[20][10]={
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0
};
int level=0;
int score=0;
int px=36;
int py=34;
int draw_state=0;
int k,knext;
int firsttrick,nexttrick;  
int irReceivePin=2;
IRrecv irrecv(irReceivePin);
decode_results results;

void checkright(int rightx,int righty,int rightcase)
{
  switch(rightcase)
  {
    case 1:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;    
    case 2:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-14)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;  
    case 3:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-22)/4]==1||dot[(rightx/4-10)][(righty-18)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;  
     case 4:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;  
    case 5:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-22)/4]==1||dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;  
    case 6:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
     case 7:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-18)/4]==1||dot[(rightx/4-10)][(righty-18)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;  
    case 8:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-14)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
    case 9:
    if(py<=14)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-18)/4]==1||dot[(rightx/4-10)][(righty-18)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
    case 10:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-18)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
    case 11:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-18)/4]==1||dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;     
    case 12:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
    case 13:
    if(py<=14)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-18)/4]==1||dot[(rightx/4-10)][(righty-18)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;  
    case 14:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-18)/4]==1||dot[(rightx/4-9)][(righty-22)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;    
     case 15:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-22)/4]==1||dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break;  
    case 16:
    if(py<=18)
    {
      py=py;
    }
    else if(dot[(rightx/4-10)][(righty-22)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
     case 17:
    if(py<=14)
    {
      py=py;
    }
    else if(dot[(rightx/4-11)][(righty-14)/4]==1||dot[(rightx/4-10)][(righty-18)/4]==1||dot[(rightx/4-9)][(righty-18)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
     case 18:
    if(py<=22)
    {
      py=py;
    }
    else if(dot[(rightx/4-9)][(righty-26)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
     case 19:
    if(py<=14)
    {
      py=py;
    }
    else if(dot[(rightx/4-12)][(righty-14)/4]==1||dot[(rightx/4-11)][(righty-14)/4]==1||dot[(rightx/4-10)][(righty-14)/4]==1||dot[(rightx/4-9)][(righty-14)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py-4;
    };
    break; 
  }
}

void checkleft(int leftx,int lefty,int leftcase)
{  
  switch(leftcase)
  {
    case 1:   
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-10)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 2:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-6)/4)]==1||dot[(leftx/4-9)][((lefty-6)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 3:
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][((lefty-10)/4)]==1||dot[(leftx/4-10)][((lefty-10)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
     case 4:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-6)/4)]==1||dot[(leftx/4-9)][((lefty-14)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 5:
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][((lefty-14)/4)]==1||dot[(leftx/4-10)][((lefty-14)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
     py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 6:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-14)/4)]==1||dot[(leftx/4-9)][((lefty-14)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 7:
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][((lefty-10)/4)]==1||dot[((leftx/4-10))][((lefty-10)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 8:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-6)/4)]==1||dot[(leftx/4-9)][((lefty-6)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 9:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][(lefty-6)/4]==1||dot[(leftx/4-10)][((lefty-10)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 10:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-10)/4)]==1||dot[(leftx/4-9)][((lefty-6)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 11:
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][((lefty-10)/4)]==1||dot[(leftx/4-10)][((lefty-10)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 12:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-6)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 13:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][(lefty-10)/4]==1||dot[(leftx/4-10)][((lefty-6)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
     case 14:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-6)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
     case 15:
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][(lefty-14)/4]==1||dot[(leftx/4-10)][(lefty-10)/4]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 16:
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-10)][((lefty-10)/4)]==1||dot[(leftx/4-9)][((lefty-6)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
     case 17:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-11)][((lefty-6)/4)]==1||dot[(leftx/4-10)][((lefty-6)/4)]==1||dot[(leftx/4-9)][((lefty-10)/4)]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 18:
    if(py>=46)
    {
      py=py;
    }
    else if(dot[(leftx/4-9)][(lefty-6)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;
    case 19:
    if(py>=50)
    {
      py=py;
    }
    else if(dot[(leftx/4-12)][(lefty-10)/4]==1||dot[(leftx/4-11)][(lefty-10)/4]==1||dot[(leftx/4-10)][(lefty-10)/4]==1||dot[(leftx/4-9)][(lefty-10)/4]==1)
    {
      py=py;
    }
    else
    {
      py=py+4;
    };
    break;    
  }
}


void checkdown(int downx,int downy,int downcase)
{ 
  switch(downcase)
  {
    case 1:
    downx=downx-8;   
    if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+3][(downy-22)/4+2]==1)
    {       
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 2:
    downx=downx-8;
     if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+3][(downy-22)/4+2]==1||dot[(downx-36)/4+3][(downy-22)/4+3]==1)
    {            
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 3:
    downx=downx-12;
     if(dot[(downx-36)/4+2][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {           
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 4:
    downx=downx-12;
     if(dot[(downx-36)/4+3][(downy-22)/4+2]==1||dot[(downx-36)/4+3][(downy-22)/4+3]==1||dot[(downx-36)/4+4][(downy-22)/4+1]==1)
    {           
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 5:
    downx=downx-12;
     if(dot[(downx-36)/4+4][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {           
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
     case 6:
     downx=downx-8;    
     if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+3][(downy-22)/4+2]==1||dot[(downx-36)/4+3][(downy-22)/4+3]==1)
    {        
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
     case 7:
     downx=downx-12;
     if(dot[(downx-36)/4+4][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {         
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
     case 8:
     downx=downx-8;  
     if(dot[(downx-36)/4+2][(downy-22)/4+1]==1||dot[(downx-36)/4+2][(downy-22)/4+2]==1||dot[(downx-36)/4+3][(downy-22)/4+3]==1)
    {    
      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 9:
    downx=downx-12;
     if(dot[(downx-36)/4+2][(downy-22)/4+3]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {      

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 10:
    downx=downx-8;
     if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+3][(downy-22)/4+2]==1||dot[(downx-36)/4+3][(downy-22)/4+3]==1)
    {     

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 11:
    downx=downx-12;
     if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {   

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 12:
    downx=downx-12;
     if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+3][(downy-22)/4+3]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {      

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 13:
     downx=downx-12;
     if(dot[(downx-36)/4+3][(downy-22)/4+3]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {      

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 14:
      downx=downx-12;  
     if(dot[(downx-36)/4+3][(downy-22)/4+3]==1||dot[(downx-36)/4+4][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {   

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 15:
    downx=downx-12;
     if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {      

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 16:
    downx=downx-12;
     if(dot[(downx-36)/4+3][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1||dot[(downx-36)/4+4][(downy-22)/4+3]==1)
    {      

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 17:
    downx=downx-12;
     if(dot[(downx-36)/4+3][(downy-22)/4+3]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 18:
    downx=downx-12;
     if(dot[(downx-36)/4+4][(downy-22)/4+1]==1||dot[(downx-36)/4+4][(downy-22)/4+2]==1||dot[(downx-36)/4+4][(downy-22)/4+3]==1||dot[(downx-36)/4+4][(downy-22)/4]==1)
    {

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;
    case 19:
    downx=downx-12;
     if(dot[(downx-36)/4+4][(downy-22)/4+2]==1)
    {

      reachgraph(downx,downy,downcase);
      px=36;
    }
    else
    {
      px=px+4;
    };
    break;    
  }  
}

void reachgraph(int reachx,int reachy,int graphyk)
{
  switch(graphyk)
  {
    case 1:
    dot[(px-44+4)/4][(py-22+4)/4]=1;
    dot[(px-44+8)/4][(py-22+4)/4]=1;
    dot[(px-44+8)/4][(py-22+8)/4]=1;
    dot[(px-44+4)/4][(py-22+8)/4]=1;
    break;
    case 2:
     dot[(px-44+4)/4][(py-22+12)/4]=1;
    dot[(px-44+8)/4][(py-22+4)/4]=1;
    dot[(px-44+8)/4][(py-22+8)/4]=1;
    dot[(px-44+8)/4][(py-22+12)/4]=1;
    break;    
    case 3:
    dot[(px-48+4)/4][(py-22+4)/4]=1;
    dot[(px-48+4)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    break;    
    case 4:
    dot[(px-48+12)/4][(py-22+4)/4]=1;
    dot[(px-48+8)/4][(py-22+4)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+12)/4]=1;
    break;    
    case 5:
     dot[(px-48+12)/4][(py-22+8)/4]=1;
    dot[(px-48+4)/4][(py-22+4)/4]=1;
    dot[(px-48+8)/4][(py-22+4)/4]=1;
    dot[(px-48+12)/4][(py-22+4)/4]=1;
    break;    
    case 6:
    dot[(px-44+4)/4][(py-22+4)/4]=1;
    dot[(px-44+8)/4][(py-22+4)/4]=1;
    dot[(px-44+8)/4][(py-22+8)/4]=1;
    dot[(px-44+8)/4][(py-22+12)/4]=1;
    break;    
    case 7:
    dot[(px-48+12)/4][(py-22+4)/4]=1;
    dot[(px-48+4)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    break;    
     case 8:
     dot[(px-44+8)/4][(py-22+12)/4]=1;
    dot[(px-44+4)/4][(py-22+4)/4]=1;
    dot[(px-44+4)/4][(py-22+8)/4]=1;
    dot[(px-44+4)/4][(py-22+12)/4]=1;
    break;    
     case 9:
     dot[(px-48+4)/4][(py-22+12)/4]=1;
    dot[(px-48+4)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    break;    
     case 10:
     dot[(px-44+4)/4][(py-22+8)/4]=1;
    dot[(px-44+8)/4][(py-22+4)/4]=1;
    dot[(px-44+8)/4][(py-22+8)/4]=1;
    dot[(px-44+8)/4][(py-22+12)/4]=1;
    break;    
     case 11:
     dot[(px-48+8)/4][(py-22+4)/4]=1;
    dot[(px-48+4)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    break;    
     case 12:
     dot[(px-48+12)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+4)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+12)/4]=1;
    break;    
     case 13:
     dot[(px-48+8)/4][(py-22+12)/4]=1;
    dot[(px-48+4)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    break;    
     case 14:
     dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+12)/4]=1;
    dot[(px-48+12)/4][(py-22+4)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    break;    
     case 15:
     dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+4)/4]=1;
    dot[(px-48+4)/4][(py-22+4)/4]=1;
    break;    
     case 16:
     dot[(px-48+8)/4][(py-22+4)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+12)/4]=1;
    break;    
     case 17:
     dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    dot[(px-48+4)/4][(py-22+12)/4]=1;
    dot[(px-48+8)/4][(py-22+12)/4]=1;
    break;    
     case 18:
     dot[(px-44+8)/4][(py-22)/4]=1;
    dot[(px-44+8)/4][(py-22+4)/4]=1;
    dot[(px-44+8)/4][(py-22+8)/4]=1;
    dot[(px-44+8)/4][(py-22+12)/4]=1;
    break;    
     case 19:
     dot[(px-48)/4][(py-22+8)/4]=1;
    dot[(px-48+4)/4][(py-22+8)/4]=1;
    dot[(px-48+8)/4][(py-22+8)/4]=1;
    dot[(px-48+12)/4][(py-22+8)/4]=1;
    break;    
  }

}


void firstTrick(int x,int y,int firsttrick)
{
  if(firsttrick==1||firsttrick==2||firsttrick==6||firsttrick==8||firsttrick==10||firsttrick==18)
  {
    shape(px-8,py,firsttrick);    
  }
  else
  {
    shape(px-12,py,firsttrick);
  }
}


void profile(int level,int score)
{
  u8g.drawLine(34,63,34,20);//boarline
  u8g.drawLine(35,63,35,20);
  u8g.drawLine(36,63,115,63);
  u8g.drawLine(36,62,115,62);
  u8g.drawLine(116,63,116,20);
  u8g.drawLine(117,63,117,20);
  u8g.drawLine(36,21,115,21);
  u8g.drawLine(36,20,115,20);

  u8g.setFont(u8g_font_micro);//next
  u8g.drawStr270(40,18,"NEXT:");  
  u8g.drawStr270(70,18,"LEVEL");
  u8g.setFont(u8g_font_6x13_67_75);
  switch(level)
  {
    case 1:
    u8g.drawBox(80,14,2,2);
    break;
    case 2:
    u8g.drawBox(80,14,2,2);
    u8g.drawBox(78,11,4,2);
    break;
    case 3:
    u8g.drawBox(80,14,2,2);
    u8g.drawBox(78,11,4,2);
    u8g.drawBox(76,8,6,2);
    break;
    case 4:
    u8g.drawBox(80,14,2,2);
    u8g.drawBox(78,11,4,2);
    u8g.drawBox(76,8,6,2);
    u8g.drawBox(74,5,8,2);
    break;
    case 5:
    u8g.drawBox(80,14,3,2);
    u8g.drawBox(78,11,5,2);
    u8g.drawBox(76,8,7,2);
    u8g.drawBox(74,5,9,2);
    u8g.drawBox(72,2,11,2);
    break;
    default:
    break;   
  }

  u8g.setFont(u8g_font_5x7);//score
  u8g.drawStr270(15,62,"SCORE:");
  int scorege=score%10;
  writeScore(15,5,scorege);
  int scoreshi=(score%100-scorege)/10;
  writeScore(15,11,scoreshi);
  int scorebai=(score%1000-scoreshi*10-scorege)/100;
  writeScore(15,17,scorebai);
  int scoreqian=(score%10000-scorebai*100-scoreshi*10-scorege)/1000;
  writeScore(15,23,scoreqian);
  int scorewan=(score%100000-scoreqian*1000-scorebai*100-scoreshi*10-scorege)/10000;
  writeScore(15,29,scorewan);  
}

void writeScore(int x,int y,int score)
{
  switch(score)
  {
    case 0:
    u8g.drawStr270(x,y,"0");
    break;
    case 1:
    u8g.drawStr270(x,y,"1");
    break;
    case 2:
    u8g.drawStr270(x,y,"2");
    break;
    case 3:
    u8g.drawStr270(x,y,"3");
    break;
    case 4:
    u8g.drawStr270(x,y,"4");
    break;
    case 5:
    u8g.drawStr270(x,y,"5");
    break;
    case 6:
    u8g.drawStr270(x,y,"6");
    break;
    case 7:
    u8g.drawStr270(x,y,"7");
    break;
    case 8:
    u8g.drawStr270(x,y,"8");
    break;
    case 9:
    u8g.drawStr270(x,y,"9");
    break;    
  }
}

void switchrotate(int rotate)
{
  if(rotate==1)
  {
    rotate=rotate;
  }
  else if(rotate==5||rotate==9||rotate==13||rotate==15||rotate==17||rotate==19)
  {
    rotate=rotate-1;
  }
  else
  {
    rotate=rotate+1;
  };
}

void shape(int x,int y,int k)
{
  switch(k)
  {
    case 1:  
    if((x+4)>=36&&(x+4)<=115&&(y+4)>=22&&(y+4)<=61)
    {
    base(x+4,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    {
    base(x+8,y+4);    
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    {
    base(x+8,y+8);     
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);     
    };
    break;
    case 2:
    if((x+4)>=36&&(x+4)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+4,y+12);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    break;
    case 3:
    if((x+4)>=36&&(x+4)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+4,y+4);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    break;
    case 4:
    if((x+12)>=36&&(x+12)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+12,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    break;
    case 5:
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+4,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+12,y+4);
    };
    break;
    case 6:
    if((x+4)>=36&&(x+4)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+4,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    break;
    case 7:
    if((x+12)>=36&&(x+12)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+12,y+4);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    break;
    case 8:
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+4,y+4);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+4,y+12);
    };
    break;
    case 9:
    if((x+4)>=36&&(x+4)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+4,y+12);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8); 
    };
    break;  
    case 10:
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    break;
    case 11:
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    break;
    case 12:
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    break;
    case 13:
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    break;
    case 14:
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+12,y+4);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    break;
    case 15:
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+4,y+4);
    };
    break;
    case 16:
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+12,y+12);
    };
    break;
    case 17:
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+4,y+12);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    break;
    case 18:
    if((x+8)>=36&&(x+8)<=115&&y>=22&&y<=61)
    { 
    base(x+8,y);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+4)>=22&&(y+4)<=61)
    { 
    base(x+8,y+4);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+12)>=22&&(y+12)<=61)
    { 
    base(x+8,y+12);
    };
    break;
    case 19:
    if(x>=36&&x<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x,y+8);
    };
    if((x+4)>=36&&(x+4)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+4,y+8);
    };
    if((x+8)>=36&&(x+8)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+8,y+8);
    };
    if((x+12)>=36&&(x+12)<=115&&(y+8)>=22&&(y+8)<=61)
    { 
    base(x+12,y+8);
    };
    break;   
    default:
    break; 
  }
}

void shapenext(int x,int y,int k)
{
  switch(k)
  {
    case 1:      
    base(x+4,y+4);    
    base(x+8,y+4);       
    base(x+8,y+8);       
    base(x+4,y+8);       
    break;
    case 2:  
    base(x+4,y+12);    
    base(x+8,y+4);   
    base(x+8,y+8);       
    base(x+8,y+12);   
    break;
    case 3:   
    base(x+4,y+4);
    base(x+4,y+8);    
    base(x+8,y+8);   
    base(x+12,y+8);   
    break;
    case 4:    
    base(x+12,y+4);    
    base(x+8,y+4);    
    base(x+8,y+8);    
    base(x+8,y+12);    
    break;
    case 5:    
    base(x+12,y+8);   
    base(x+4,y+4);    
    base(x+8,y+4);   
    base(x+12,y+4);   
    break;
    case 6:    
    base(x+4,y+4);   
    base(x+8,y+4);    
    base(x+8,y+8);   
    base(x+8,y+12);    
    break;
    case 7:    
    base(x+12,y+4);    
    base(x+4,y+8);   
    base(x+8,y+8);   
    base(x+12,y+8);  
    break;
    case 8:    
    base(x+8,y+12);   
    base(x+4,y+4);    
    base(x+4,y+8);   
    base(x+4,y+12);   
    break;
    case 9:   
    base(x+4,y+12);    
    base(x+4,y+8);    
    base(x+8,y+8);   
    base(x+12,y+8);   
    break;  
    case 10:   
    base(x+4,y+8);   
    base(x+8,y+4);
    base(x+8,y+8);    
    base(x+8,y+12);    
    break;
    case 11:    
    base(x+8,y+4);   
    base(x+4,y+8);    
    base(x+8,y+8);   
    base(x+12,y+8);   
    break;
    case 12:    
    base(x+12,y+8);    
    base(x+8,y+4);   
    base(x+8,y+8);   
    base(x+8,y+12);   
    break;
    case 13:    
    base(x+8,y+12);   
    base(x+4,y+8);    
    base(x+8,y+8);        
    base(x+12,y+8);    
    break;
    case 14:   
    base(x+8,y+8);   
    base(x+8,y+12);    
    base(x+12,y+4);    
    base(x+12,y+8);   
    break;
    case 15:    
    base(x+8,y+8);   
    base(x+12,y+8);    
    base(x+8,y+4); 
    base(x+4,y+4);
    break;
    case 16:    
    base(x+8,y+4);
    base(x+8,y+8);    
    base(x+12,y+8);   
    base(x+12,y+12);    
    break;
    case 17:   
    base(x+8,y+8);    
    base(x+12,y+8);   
    base(x+4,y+12);   
    base(x+8,y+12);   
    break;
    case 18:   
    base(x+8,y);
    base(x+8,y+4);   
    base(x+8,y+8);   
    base(x+8,y+12);   
    break;
    case 19:   
    base(x,y+8);    
    base(x+4,y+8);    
    base(x+8,y+8);    
    base(x+12,y+8);    
    break;   
    default:
    break; 
  }
}

void base(int x,int y)
{
  u8g.drawLine(x,y,x+3,y);
  u8g.drawLine(x,y+1,x,y+3);
  u8g.drawLine(x+2,y+3,x+1,y+3);
  u8g.drawLine(x+3,y+1,x+3,y+3);
  u8g.drawPixel(x+1,y+1);
  u8g.drawPixel(x+2,y+2); 
}


void draw()
{
  switch(draw_state)
  {
    case 1:
    profile(level,score);   

    firstTrick(px,py-12,firsttrick);
    shapenext(41,0,knext);    
    break;
    case 2:
     for(int ix=0;ix<20;ix++)
   {
    for(int iy=0;iy<10;iy++)
    {
      if(dot[ix][iy]==1)
      {
        base((4*ix+36),(4*iy+22));
      }
     }
    };


    profile(level,score);      
    shapenext(41,0,knext);

    firstTrick(px,py-12,nexttrick);   
    break;    
  }
}

void setup()
{  
  // flip screen, if required
  u8g.setRot180();
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) 
    u8g.setColorIndex(255);     // white
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
    u8g.setColorIndex(3);         // max intensity
  else if ( u8g.getMode() == U8G_MODE_BW )
    u8g.setColorIndex(1);         // pixel on  
  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH); 
  randomSeed(analogRead(A0));
  irrecv.enableIRIn();
  //Serial.begin(9600);
}


void loop()
{
  if(px==36)
  {
    k=random(1,20);        
    firsttrick=random(1,20);
    nexttrick=knext;
    py=34; 



    knext=k;
     if(draw_state<2)
    {
      draw_state++;
    }
    else
    {
      draw_state=draw_state;
    };
  }
  else
  {
    knext=knext;
  };



  u8g.firstPage();
  do{    
    draw();
  }
  while(u8g.nextPage());




  if(irrecv.decode(&results))
  {
    long remotesignal=results.value;
  // Serial.println(results.value);
    if(remotesignal==16769055)              //zuo
    {
      if(draw_state==1)
      {
        checkleft(px,py,firsttrick);
      }
      else
      {
        checkleft(px,py,nexttrick);
      };

      if(draw_state==1)
      {
        checkdown(px,py,firsttrick);
      }
      else
      {
        checkdown(px,py,nexttrick);
      };
    }
    else if(remotesignal==16754775)           //you
    {
       if(draw_state==1)
      {
        checkright(px,py,firsttrick);
      }
      else
      {
        checkright(px,py,nexttrick);
      };

     if(draw_state==1)
      {
        checkdown(px,py,firsttrick);
      }
      else
      {
        checkdown(px,py,nexttrick);
      };
    }
    else if(remotesignal==16748655)           //xuanzhuan
    { 

      if(firsttrick==1)
      {
        firsttrick=firsttrick;
      }
        else if(firsttrick==5||firsttrick==9||firsttrick==13)
      {
        firsttrick=firsttrick-3;
      }
      else if(firsttrick==15||firsttrick==17||firsttrick==19)
      {
        firsttrick=firsttrick-1;
      }
      else
      {
        firsttrick=firsttrick+1;
      }; 

      if(nexttrick==1)
      {
        nexttrick=nexttrick;
      }
        else if(nexttrick==5||nexttrick==9||nexttrick==13)
      {
        nexttrick=nexttrick-3;
      }
      else if(nexttrick==15||nexttrick==17||nexttrick==19)
      {
        nexttrick=nexttrick-1;
      }
      else
      {
        nexttrick=nexttrick+1;
      };  

      if(draw_state==1)
      {
        checkdown(px,py,firsttrick);
      }
      else
      {
        checkdown(px,py,nexttrick);
      };
    }
    else if(remotesignal==16625743)               //xia
    {
   if(draw_state==1)
      {
        checkdown(px,py,firsttrick);
      }
      else
      {
        checkdown(px,py,nexttrick);
      };
      if(draw_state==1)
      {
        checkdown(px,py,firsttrick);
      }
      else
      {
        checkdown(px,py,nexttrick);
      };
    };
    if(px==112)
    {
      if(draw_state==1)
      {
      reachgraph(px,py,firsttrick);
      }
      else if(draw_state==2)
      {
      reachgraph(px,py,nexttrick);
      };
      px=36;      
      py=34;
    };
    irrecv.resume();
  }
  else
  {
    if(px==112)
    {
      if(draw_state==1)
      {
      reachgraph(px,py,firsttrick);
      }
      else if(draw_state==2)
      {
      reachgraph(px,py,nexttrick);
      };
      px=36;      
      py=34;
    }
    else
    {
    if(draw_state==1)
      {
        checkdown(px,py,firsttrick);
      }
      else
      {
        checkdown(px,py,nexttrick);
      };
    }
  };



  for(int xiaox=19;xiaox>=0;xiaox--)
  {
    int scoretimes=0;
    if(dot[xiaox][0]==1&&dot[xiaox][1]==1&&dot[xiaox][2]==1&&dot[xiaox][3]==1&&dot[xiaox][4]==1&&dot[xiaox][5]==1&&dot[xiaox][6]==1&&dot[xiaox][7]==1&&dot[xiaox][8]==1&&dot[xiaox][9]==1)
    {
      for(int updatex=xiaox;updatex>=0;updatex--)
      {
        for(int updatey=0;updatey<10;updatey++)
        {
          dot[updatex][updatey]=dot[updatex-1][updatey];
        };
      };
      scoretimes=scoretimes+1;
    }
    if(scoretimes==4)
    {
      score=score+50;
    }
    else
    {
      score=score+10*scoretimes;
    }
  };



  if(score<200)
  {
    level=1;
  }
  else if(score>=200&&score<500)
  {
    level=2;
  }
  else if(score>=500&&score<800)
  {
    level=3;
  }
  else if(score>=800&&score<1000)
  {
    level=4;
  }
  else if(score>=1000)
  {
    level=5;
  };


  int unittime=1000-level*100;
  delay(unittime);
//delay(50);
}


