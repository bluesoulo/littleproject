#include <stdio.h>
#include <windows.h>
#define U 1 
#define D 2
#define R 3
#define L 4
typedef struct Body{
	int x;
	int y;
	struct Body * next; 
} Snake;

int state = L;   //用来记录蛇当前的状态 
int FOODX = 6,FOODY = 11; //记录时间的位置
int score = 0; 

void pos(int x, int y){  
 
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(hOutput,pos);
}


void initMap(void){
	int i;
	//y:0~25, x:0,2,4, ,50
	for(i = 0; i < 52; i+=2 ){
		pos(i,0);
		printf("■");
		pos(i,25);		
		printf("■");
	}
	for(i = 1; i<=25; i++){
		pos(0,i);
		printf("■");
		pos(50,i);
		printf("■");
	}
}
void printSnake(Snake * t){
	while(t){
		pos(t->x, t->y);
		printf("■");
		t = t->next;
	}
}

Snake* initSnake(void){
	Snake *head= (Snake *)malloc(sizeof(Snake));
	head->x = 24;
	head->y = 11;
	head->next = 0;
	for(int i=1; i<=2; i++){
		int x = 24 - i * 2;
		int y = 11;
		Snake *tem = (Snake *)malloc(sizeof(Snake));
		tem->x = x;
		tem->y = y;
		tem->next = head;
		head = tem;
	}
	printSnake(head);
	return head;
}


int biteSnake(Snake * head){
	int b = 0;
	Snake *t = head->next;
	while(t){
		if (t->x == head->x && t->y == head->y){
			b = 1;
			break;
		}
		t = t->next;
	}
	return b;
}


int endGame(Snake * head){
	int t = 0;
	if (head->x==0||head->x==50||head->y==0||head->y==25)
	 t = 1;
	
	return t;
}

 

Snake * aotoMove(Snake * head){
	//GetAsyncKeyState就是检查在调用该函数时，某一key的状态。
	Snake *q = (Snake *)malloc(sizeof(Snake));
	if (GetAsyncKeyState(VK_DOWN)&&state != U){//按到向下键
		state = D; 
		q->x = head->x;
		q->y = head->y + 1;
	}
	else if(GetAsyncKeyState(VK_UP)&&state != D){//按到向上键 
		state = U; 
		q->x = head->x;
		q->y = head->y - 1;
	}
	else if(GetAsyncKeyState(VK_LEFT)&&state != R){//按到向左键 
		state = L; 
		q->x = head->x - 2;
		q->y = head->y;
	}
	else if(GetAsyncKeyState(VK_RIGHT)&&state != L){//按到向右键
		state = R; 
		q->x = head->x + 2;
		q->y = head->y;
	} 
	else{
		if(state == D){
			q->x = head->x;
			q->y = head->y + 1;		
		}
		else if(state == L){
			q->x = head->x - 2;
			q->y = head->y;		
		}
		else if(state == U){
			q->x = head->x ;
			q->y = head->y - 1;		
		}
		else{
			q->x = head->x + 2;
			q->y = head->y;	
		}
	}
	if (q->x != FOODX || q->y != FOODY){   //没有吃到食物则会在头部插入一个节点，并染出尾部节点，其他节点保持不动 
		Snake * t = head;
		while(t->next->next){
			t = t->next; 
		} 
		Snake * p = t->next;
		t->next = 0;
		free(p);
	}
	else{ //吃到食物会重新随机生成一个新的食物
		score++;
		FOODX = (rand() % 24 + 1) * 2;
		FOODY = rand() % 24 + 1;
	}	
	q->next = head;
	head = q;
	if(endGame(head)||biteSnake(head)){
		return 0;
	}
		
	return head;
}
void controlGame(Snake * head){
	while(1){
	system("cls");
	initMap();
	pos(FOODX,FOODY);
	printf("■");
	printSnake(head);
	Sleep(500);    //注意执行的顺序很重要,应该提前睡眠然后等待按键事件的发生 
	head  = aotoMove(head);
	if(head==0)
		break;	
	}
	
}


int main(void){
//	initMap();
	Snake * head = initSnake();
	controlGame(head);
	pos(0,26);
	printf("Game Over!\n");
	printf("your score is:%d\n\n", score);
	system("pause");
	return 0;
}

