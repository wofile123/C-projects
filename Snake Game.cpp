#include<bits/stdc++.h>
#include <conio.h>
#include <windows.h>

#define MAX_lENGTH 1000

using namespace std;

const char UP ='U';
const char DOWN ='D';
const char LEFT ='L';
const char RIGHT ='R';

int C_width,C_height; 

const string RESET = "\033[0m";
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string B_BLACK = "\033[90m";
const string B_RED = "\033[91m";
const string B_GREEN = "\033[92m";
const string B_YELLOW = "\033[93m";
const string B_BLUE = "\033[94m";
const string B_MAGENTA = "\033[95m";
const string B_CYAN = "\033[96m";
const string B_WHITE = "\033[97m";


struct point{
    int xc,yc;  //coordinates
    point(){

    }
    point(int x,int y){
        xc=x;
        yc=y;
    }
};

class Snake{
    int length;
    char direction;
public:
point body[MAX_lENGTH];
    Snake(int x,int y){
        length =1;
        body[0]=point(x,y);
        direction=RIGHT;
    }

int getlength(){
    return length;
}
void change_dir(char new_d){
    if(new_d==UP &&  direction!=DOWN){
        direction=new_d;
    }
    else if(new_d==DOWN &&  direction!=UP){
        direction=new_d;
    }
    else if(new_d==LEFT && direction!=RIGHT){
        direction=new_d;
    }
    else if(new_d==RIGHT &&  direction!=LEFT){
        direction=new_d;
    }
}
bool move(point food){
    for(int i=length-1;i>0;i--){             //length=4
        body[i] = body[i-1];
    }
    switch(direction){
        int value;
        case UP:
        {
            value=body[0].yc;
            body[0].yc=value-1;
            break;
        }
        case DOWN:
        {
            value=body[0].yc;
            body[0].yc=value+1;
            break;
        }
        case LEFT:
        {
            value=body[0].xc;
            body[0].xc=value-1;
            break;
        }
        case RIGHT:
        {
            value=body[0].xc;
            body[0].xc=value+1;
            break;
        }
    }
    // if snake bites itself
    for(int i=1;i<length;i++){
        if(body[0].xc == body[i].xc && body[0].yc == body[i].yc ){
            return false;
        }
    }

    // if snakes eats fruit
    if(body[0].xc == food.xc && body[0].yc == food.yc){
        body[length] = point(body[length-1].xc ,body[length-1].yc);
        length++;
        // length=length+5;
    }
        return true;
}
};

class Board{
    Snake *snake;
    const char snake_ki_body = '|';
    point food;
    const char fruit = 'o';
    int score;
public:
    Board(){
        spawnFood();
        snake = new Snake(10,10);
        score = 0;
    }
    ~Board(){
        delete snake;
    }
int get_score(){
    return score;
}
void spawnFood(){
    int x=rand() % C_width;
    int y=rand() % C_height;
    food = point(x,y);
}
void display_score(){
    gotoxy(C_width/2,0);
    cout <<B_RED<< "Score: "<<RESET <<B_YELLOW<< score << endl<<RESET;
}
void gotoxy(int x,int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void draw(){
    system("cls");
    for(int i=0;i<snake->getlength();i++){
        gotoxy(snake->body[i].xc,snake->body[i].yc);
        cout<<B_GREEN<<snake_ki_body<<RESET;
    }
    gotoxy(food.xc,food.yc);
    cout<<B_RED<<fruit<<RESET;

    display_score();
}
bool update(){
    bool isAlive = snake->move(food);
    if(isAlive==false){
        return false;
    }
    if(snake->body[0].xc == food.xc && snake->body[0].yc == food.yc){
        
        score++;
        spawnFood();
    }
    return true;
}
void getinput(){
    if(kbhit()){
        int key =getch();
        if (key == 'w' || key == 'W'){
            snake->change_dir(UP);
        }
        else if (key == 'a' || key == 'A'){
            snake->change_dir(LEFT);
            
        }
        else if (key == 's' || key == 'S'){
            snake->change_dir(DOWN);
            
        }
        else if (key == 'd' || key == 'D'){
            snake->change_dir(RIGHT);
            
        }
    }
}
};



void screen(){
    HANDLE console =GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console,&csbi);
    C_height=csbi.srWindow.Bottom - csbi.srWindow.Top +1;
    C_width=csbi.srWindow.Right - csbi.srWindow.Left +1;

}

void front(){
    system("cls");
     cout<<B_GREEN<<"=============================================================="<<endl; 
        cout<<"[|]                                                        [|]"<<endl;
        cout<<"[|]                \033[93mWelcome To The Snake Game\033[0m\033[92m               [|]"<<endl;
        cout<<"[|]                                                        [|]"<<endl;
        cout<<"=============================================================="<<RESET<<"\n\n"; 
    cout<<B_BLUE<<"Controller Keys:\n----------------\n"<<RESET;
    cout<<B_GREEN<<"W or w:"<<RESET; cout<<B_YELLOW<<" Move Up\n"<<RESET;
    cout<<B_GREEN<<"A or a:"<<RESET; cout<<B_YELLOW<<" Move Left\n"<<RESET;
    cout<<B_GREEN<<"S or s:"<<RESET; cout<<B_YELLOW<<" Move Down\n"<<RESET;
    cout<<B_GREEN<<"D or d:"<<RESET; cout<<B_YELLOW<<" Move Right\n\n"<<RESET;
    cout<<B_RED<<"ALERT!! Don't cross the window's boundaries/corners\n"<<RESET;
    cout<<B_RED<<"We hope you read the instructions carefully!!"<<RESET;
    cout<<B_MAGENTA<<"\n\nPress any key to continue....."<<RESET; getchar(); 

}

int main()
{
screen();
front();


Board *board =new Board();

char ch;
int var;
system("cls");
level:
cout<<B_MAGENTA<<"Enter Level: \n"<<RESET;
cout<<B_YELLOW<<"[1]"<<RESET;  cout<<B_GREEN<<" Easy\n"<<RESET;
cout<<B_YELLOW<<"[2]"<<RESET;  cout<<B_GREEN<<" Medium\n"<<RESET;
cout<<B_YELLOW<<"[3]"<<RESET;  cout<<B_GREEN<<" Hard\n"<<RESET;
cout<<B_GREEN<<">>>"<<RESET; cin>>ch;
if(ch=='1'){
   var= 70;
    
}
else if(ch=='2'){
    var= 50;
}
else if(ch=='3'){
    var= 30;
}
else {
    system("cls");
    cout<<B_RED<<"Invalid Input\n"<<RESET;
    goto level;
}

while(board->update()){
    board->getinput();
    board->draw();
    Sleep(var);
}

system("cls");
cout<<B_RED<<"GAME IS OVER"<<endl<<RESET;
cout<<B_GREEN<<"Total Score: "<<RESET<<B_YELLOW<<board->get_score()<<RESET<<endl;
system("PAUSE");
 return 0;
}
