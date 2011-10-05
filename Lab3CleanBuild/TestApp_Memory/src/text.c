#include "text.h"

#define genLetterPixels(a4, a3, a2, a1, a0) (((a4) << 4) | ((a3) << 3) | ((a2) << 2)  | ((a1) << 1) | ((a0)) )
		//LETTERS
		
Xuint16 XTft_Letters[20][5] =
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
		};
		
		
void DrawWord(char * message, int x, int y, int frame, int color){
	int position = x;
	int i;
	int letter_index;
	for(i=0; message[i]; i++){
		int y_offset = 0;
		int next_position = position;
		switch(message[i]){
			case 'L':
				letter_index = 0;
				next_position += 10;
				break;
			case 'I':
				letter_index = 1;
				next_position +=4;
				break;
			case 'V':
				letter_index = 2;
				next_position += 12;
				break;
			case 'E':
				letter_index = 3;
				next_position += 12;
				break;
			case 'S':
				letter_index = 4;
				next_position += 12;
				break;
			case 'C':
				letter_index = 5;
				next_position += 12;
				break;
			case '0':
			case 'O':
				letter_index = 6;
				next_position += 12;
				break;
			case 'R':
				letter_index = 7;
				next_position += 12;
				break;
			case '1':
				letter_index = 8;
				next_position += 6;
				break;
			case '2':
				letter_index = 9;
				next_position += 12;
				break;
			case '3':
				letter_index = 10;
				next_position += 12;
				break;
			case '4':
				letter_index = 11;
				next_position += 12;
				break;
			case '5':
				letter_index = 12;
				next_position += 12;
				break;
			case '6':
				letter_index = 13;
				next_position += 12;
				break;
			case '7':
				letter_index = 14;
				next_position += 10;
				break;
			case '8':
				letter_index = 15;
				next_position += 12;
				break;
			case '9':
				letter_index = 16;
				next_position += 12;
				break;
			default:
				break;
		}
		switch(color){
			case 1:
				XTft_DrawLetter(frame,letter_index,position, y + y_offset,0x00ffffff);
				break;
			case 0:
				XTft_DrawLetter(frame,letter_index,position, y + y_offset,0x00000000);
				break;
			default:
				break;
		}
		position = next_position;
		y_offset = 0;
	}
}	