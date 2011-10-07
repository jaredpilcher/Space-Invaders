#include "text.h"

#define genLetterPixels(a4, a3, a2, a1, a0) (((a4) << 4) | ((a3) << 3) | ((a2) << 2)  | ((a1) << 1) | ((a0)) )
		//LETTERS
		
Xuint16 XTft_Letters[30][5] =
		{
			{ // L
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 1, 1, 1, 0),
			},
			{ // I
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
			},
			{ // V
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 0, 1, 0),
						genLetterPixels( 0, 0, 1, 0, 0),
			},
			{ // E
						genLetterPixels( 1, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 1, 1, 1, 1),
			},			
			{ // S
						genLetterPixels( 0, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 0, 1, 1, 1, 0),
						genLetterPixels( 0, 0, 0, 0, 1),
						genLetterPixels( 1, 1, 1, 1, 0),
			},			
			{ // C
						genLetterPixels( 0, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 0, 1, 1, 1, 1),
			},			
			{ // O
						genLetterPixels( 0, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 0),
			},			
			{ // R
						genLetterPixels( 1, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
			},			
			{ //1
						genLetterPixels( 1, 1, 0, 0, 0),
						genLetterPixels( 0, 1, 0, 0, 0),
						genLetterPixels( 0, 1, 0, 0, 0),
						genLetterPixels( 0, 1, 0, 0, 0),
						genLetterPixels( 0, 1, 0, 0, 0),
			},			
			{ //2
						genLetterPixels( 1, 1, 1, 1, 0),
						genLetterPixels( 0, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 1, 1, 1, 1),
			},			
			{ //3
						genLetterPixels( 1, 1, 1, 1, 0),
						genLetterPixels( 0, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 1),
						genLetterPixels( 0, 0, 0, 0, 1),
						genLetterPixels( 1, 1, 1, 1, 0),
			},			
			{ //4
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 1, 1, 1, 1),
						genLetterPixels( 0, 0, 0, 0, 1),
						genLetterPixels( 0, 0, 0, 0, 1),
			},			
			{ //5
						genLetterPixels( 1, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 1, 1, 1, 1),
						genLetterPixels( 0, 0, 0, 0, 1),
						genLetterPixels( 1, 1, 1, 1, 1),
			},			
			{ //6
						genLetterPixels( 0, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 0),
			},			
			{ //7
						genLetterPixels( 1, 1, 1, 1, 0),
						genLetterPixels( 0, 0, 0, 1, 0),
						genLetterPixels( 0, 0, 0, 1, 0),
						genLetterPixels( 0, 0, 1, 0, 0),
						genLetterPixels( 0, 0, 1, 0, 0),
			},			
			{ //8
						genLetterPixels( 0, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 0),
			},			
			{ //9
						genLetterPixels( 0, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 1),
						genLetterPixels( 0, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 0),
			},
			{ //,
						genLetterPixels( 0, 0, 0, 0, 0),
						genLetterPixels( 0, 0, 0, 0, 0),
						genLetterPixels( 0, 1, 0, 0, 0),
						genLetterPixels( 0, 1, 0, 0, 0),
						genLetterPixels( 1, 0, 0, 0, 0),
			},
			{ // <space>
						genLetterPixels( 0, 0, 0, 0, 0),
						genLetterPixels( 0, 0, 0, 0, 0),
						genLetterPixels( 0, 0, 0, 0, 0),
						genLetterPixels( 0, 0, 0, 0, 0),
						genLetterPixels( 0, 0, 0, 0, 0),
			},
			{ // G
						genLetterPixels( 0, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 0),
						genLetterPixels( 1, 0, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 0, 1, 1, 1, 1),
			},
			{ // A
						genLetterPixels( 0, 1, 1, 1, 0),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 1, 1, 1, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
						genLetterPixels( 1, 0, 0, 0, 1),
			},
			{ // M
						genLetterPixels( 1, 1, 0, 1, 1),
						genLetterPixels( 1, 0, 1, 0, 1),
						genLetterPixels( 1, 0, 1, 0, 1),
						genLetterPixels( 1, 0, 1, 0, 1),
						genLetterPixels( 1, 0, 1, 0, 1),
			},
		};
		


void DrawWord(char * message, int x, int y, int frame, int color){
	DrawScaledWord(message,x,y,frame,color,1);
}
void DrawScaledWord(char * message, int x, int y, int frame, int color, int scale){
	int position = x;
	int i;
	int letter_index;
	for(i=0; message[i]; i++){
		int y_offset = 0;
		int width = 0;
		int next_position = position;
		switch(message[i]){
			case 'L':
				letter_index = 0;
				width = 10;
				break;
			case 'I':
				letter_index = 1;
				width = 4;
				break;
			case 'V':
				letter_index = 2;
				width = 12;
				break;
			case 'E':
				letter_index = 3;
				width = 12;
				break;
			case 'S':
				letter_index = 4;
				width = 12;
				break;
			case 'C':
				letter_index = 5;
				width = 12;
				break;
			case '0':
			case 'O':
				letter_index = 6;
				width = 12;
				break;
			case 'R':
				letter_index = 7;
				width = 12;
				break;
			case '1':
				letter_index = 8;
				width = 6;
				break;
			case '2':
				letter_index = 9;
				width = 12;
				break;
			case '3':
				letter_index = 10;
				width = 12;
				break;
			case '4':
				letter_index = 11;
				width = 12;
				break;
			case '5':
				letter_index = 12;
				width = 12;
				break;
			case '6':
				letter_index = 13;
				width = 12;
				break;
			case '7':
				letter_index = 14;
				width = 10;
				break;
			case '8':
				letter_index = 15;
				width = 12;
				break;
			case '9':
				letter_index = 16;
				width = 12;
				break;
			case ',':
				letter_index = 17;
				width = 6;
				y_offset = 4;
				break;
			case ' ':
				letter_index = 18;
				width = 12;
				break;
			case 'G':
				letter_index = 19;
				width = 12;
				break;
			case 'A':
				letter_index = 20;
				width = 12;
				break;
			case 'M':
				letter_index = 21;
				width = 12;
				break;
			default:
				break;
		}
		switch(color){
			case 1:
				XTft_DrawLetter(frame,letter_index,position, y + y_offset*scale,0x00ffffff,scale);
				break;
			case 0:
				XTft_DrawLetter(frame,letter_index,position, y + y_offset*scale,0x00000000,scale);
				break;
			default:
				XTft_DrawLetter(frame,letter_index,position, y + y_offset*scale, color,scale);
				break;
		}
		position = next_position + width*scale;
		y_offset = 0;
		width = 0;
	}
}	

// better_divide should only be used when the result is less that 10
int better_divide(int amount, int divisor){
	return amount / divisor;
}


void drawScore(int score, int frame){
	Draw_Or_Erase_Score(score, frame, 0x0000FF00);
}


void eraseScore(int score, int frame){
	Draw_Or_Erase_Score(score, frame, 0);
}

void Draw_Or_Erase_Score(int score, int frame, int color){
  char mess[20];
  int millions = better_divide(score,1000000);
  score -= millions*1000000;
  int hundred_thousands = better_divide(score,100000);
  score -= hundred_thousands*100000;
  int ten_thousands = better_divide(score,10000);
  score -= ten_thousands*10000;
  int thousands = better_divide(score,1000);
  score -= thousands*1000;
  int hundreds = better_divide(score,100);
  score -= hundreds*100;
  int tens = better_divide(score,10);
  score -= tens*10;
  int ones = score;
  int i = 0;
  
  if(millions){
	mess[i++]=millions+48;
	mess[i++]=',';
  }
  if(hundred_thousands || i){
	mess[i++]=hundred_thousands+48;
  }
  if(ten_thousands || i){
	mess[i++]=ten_thousands+48;
  }
  if(thousands || i){
	mess[i++]=thousands+48;
	mess[i++]=',';
  }
  if(hundreds || i){
    mess[i++]=hundreds+48;
  }
  if(tens || i){
	mess[i++]=tens+48;
  }
  mess[i++]=ones+48;
  mess[i]=0;
  DrawWord(mess,100,10,frame, color);
}