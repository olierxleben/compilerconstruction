
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "guiCSS.h"

void printNode(int x, int y, int r, char* name) {
	move(x,y);
	attrset(COLOR_PAIR(3));
	printw(name);
}

void printGUI(css_RuleList list) {
	int ch;
	WINDOW *myWin;
	int currX = 2, currY = 2;
	int currNode = 1;
	int selsPos = 0, decsPos = 0;
	
	// start ncurses
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);	

	bkgd(COLOR_PAIR(1));

	printw("CSS Source-Tree\n");
	
	attrset(COLOR_PAIR(3));
	printNode(currY, currX, 0, "root");
	
	currY += 3;
	
	do {		
		while(list) {
			// print rule
			if(list->rule) {
				char prStr[10] = "rule ";
				char buffer[3];
				sprintf(buffer, "%d", currNode);
				printNode(currY, currX, 0, strcat(prStr, buffer));
			}
			else {
			    break;
			}
			
			// print selector and declaration list
			printNode(currY+3, currX, 0, "sels");
			printNode(currY+3, currX+20, 0, "decs");
						
			// print selectors
			css_SelectorList sels = list->rule->selectorList; 	
			selsPos = 0;					
			while(sels) {
				if(sels->selector)
					printNode(currY+6+selsPos, currX, 0, sels->selector->name);
				selsPos++;
				sels = sels->next;
			}
			
			// print declarations
			css_DeclarationList decs = list->rule->declarationList; 	
 			decsPos = 0;					
 			while(decs) {
 				if(decs->declaration) {
 					printNode(currY+6+decsPos, currX+20, 0, decs->declaration->dec_key);				
 				}
 				decsPos++;
 				decs = decs->next;
 			}
			
			currX += 40;
			currNode++;
			list = list->next;
		}
			
			
		
		refresh();
		ch = getch();		
	} while(ch != KEY_UP);
	
	endwin();	
	
}
