#include<iostream>
#include<conio.h>
#include<windows.h> 
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y;//variables for head position:
int fruitX,fruitY,score;//variables FOR FRUIT  position.
//we have to track the direction of snake as we press the key:
enum eDirection{ STOP=0,LEFT,RIGHT,UP,DOWN};

//logics for tail:
//we will have two arrays 1)x-co ordinate of the tail,2) y-co ordinate of the tail.
int tailX[100],tailY[100];
int nTail;//for length of the tail:


eDirection dir;
void Setup()
{
    gameOver=false;
    dir =STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score = 0;

}

void Draw()
{
system("cls");//to n clear the console window:
for(int i=0;i<width+2;i++)
cout<<"#";
cout<<endl;

for(int i=0;i<height;i++)
{

    for(int j=0;j<width;j++)
    {
        if(j==0)
        cout<<"#";

        if(i==y && j==x)
        cout<<"O";
        else if(i==fruitY && j==fruitX)
        cout<<"F";
        else
        {
             bool print =false;
            for(int k=0;k<nTail;k++)
            {
                // bool print =false;
                if(tailX[k]==j && tailY[k]==i)
                {
                    cout<<"o";
                    print=true;
                }
                //  if(print==false)
                //  cout<<" ";
            }
            if(print==false)//fruit nahi khaya hai isiliye khali space print hoga:
            cout<<" ";
        }
        

        if(j==width-1)
        cout<<"#";

    }
    cout<<endl;
}
for(int i=0;i<width+2;i++)
cout<<"#";
cout<<endl;
cout<<"score: "<<score<<endl;

}
// w
// as
// z
void Input()
{
if(_kbhit())
{
switch(_getch())//to handlle the controlls:
{
case 'a':
dir=LEFT;
break;

case 's':
dir=RIGHT;
break;

case 'w':
dir=UP;
break;

case 'z':
dir=DOWN;
break;
case 'x':
gameOver =true;
break;

}
}

}
void Logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    //we need to set the first element to follow the head:
    tailX[0]=x;
    tailY[0]=y;
    //now movement of the tail:
    for(int i=1;i<nTail;i++)
    {
        prev2X=tailX[i];//prev2X 1 par hai
        prev2Y=tailY[i];//prev2Y 1 par hai

        tailX[i]=prevX;//ab jo 1 wala hai uspe aa jayega 0 wala:
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }
switch(dir)
{
    case LEFT:
    x--;
    break;
    case RIGHT:
    x++;
    break;
    case UP:
    y--;
    break;
    case DOWN:
    y++;
    break;

    default:
    break;
}
// if(x > width || x < 0 || y > height || y<0)
// gameOver=true;
if(x>=width)
x=0;
else if(x<0)
x=width-1;

if(y>=height)
y=0;
else if(y<0)
y=height-1;



for(int i=0;i<nTail;i++)//if it hit his head with any tail segment then terminate the game:
{
    if(tailX[i]==x && tailY[i]==y)
    {
        gameOver=true;
    }
}
if(x==fruitX && y==fruitY)
{
    score=score+10;
     fruitX=rand()%width;
     fruitY=rand()%height;
     nTail++;
}
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(200);
        // it slows our game a little bit:

    }
    return 0;
}