#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

struct node{
  int x,y;
};

class tactoe{
    public:
    tactoe();
    void fun();
    bool gameover();
    void playwithpartner();
    void playwithcomputer();
    void printboard();
    void computermake();
    private:
    int board[3][3];
    int num;
    int whoplay;
};

void tactoe::computermake(){
   struct node stack[10];
   int last = 0;
   for(int i = 0;i < 3;i++){
       for(int j = 0;j < 3;j++){
           if(board[i][j]==0){
               stack[++last].x = i;
               stack[last].y = j;
           }
       }
   }

   srand((unsigned)time(NULL));
   int ran =  rand()%last+1;
   struct node temp = stack[ran];
   stack[ran] = stack[last];
   stack[last] = temp;

   int x = stack[last].x;
   int y = stack[last].y;
   board[x][y] = 2;
}

void tactoe::playwithcomputer(){
    printboard();
    while(true){
        int row,col;
        
        cout<<"please enter the row and the col,(1<=row<=3.1<=col<=3)";
        cin>>row>>col;getchar();
        num++;
        board[row-1][col-1] = 1;
        whoplay = 1;
        printboard();
        if(gameover()){
            cout<<"you win!"<<endl;
            break;
        }
      if(num==9) break;
        
        cout<<"enter the space to display the computer's decision";
        getchar();
        computermake();
        printboard();
        whoplay = 2;
        num++;
        if(gameover()){
            cout<<"computer win!"<<endl;
            break;
        }
        if(num==9) break;
    }
}

bool tactoe::gameover(){
    if(num>=5){
        if(board[0][1]==whoplay&&board[0][1]==board[0][2]&&board[0][0]==board[0][1])  return true;
        if(board[0][0]==whoplay&&board[1][1]==board[0][0]&&board[2][2]==board[1][1]) return true;
        if(board[1][0]==whoplay&&board[1][1]==board[1][0]&&board[1][2]==board[1][1]) return true;
        if(board[2][0]==whoplay&&board[2][1]==board[2][0]&&board[2][2]==board[2][0]) return true;
        if(board[0][2]==whoplay&&board[1][1]==board[0][2]&&board[2][0]==board[0][2]) return true;
        if(board[0][0]==whoplay&&board[1][0]==board[0][0]&&board[1][0]==board[2][0]) return true;
        if(board[0][1]==whoplay&&board[1][1]==board[0][1]&&board[2][1]==board[1][1]) return true;
        if(board[0][2]==whoplay&&board[1][2]==board[0][2]&&board[2][2]==board[1][2]) return true;
    }
    return false;
}

void tactoe::playwithpartner(){
    printboard();
    while(true){
        int row;int col;
        
        cout<<"please play1 enter the row and the col,(1<=row<=3,1<=col<=3)";
        cin>>row>>col;getchar();
        whoplay = 1;
        board[row-1][col-1] = 1;
        printboard();
        num++;
        if(num==9) break;
        if(gameover()){
            cout<<"you win!";
            return ;
        }
       
        cout<<"please play2 enter the row and the col,(1<=row<=3,1<=col<=3)";
        cin>>row>>col;getchar();
        whoplay = 2;
        board[row-1][col-1] = 2;
        printboard();
        num++;
        if(gameover()){
            cout<<"you win!";
            return ;
        }
        if(num==9) break;
    }
}

void tactoe::printboard(){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++)
            cout<<board[i][j]<<"\t";
        for(int k = 0;k < 3;k++)
          cout<<endl;
    }
}

tactoe::tactoe(){
    for(int i = 0;i < 3;i++)
       for(int j = 0;j < 3;j++)
          board[i][j] = 0;
    num = 0;
    whoplay = 0;
}

void tactoe::fun(){
    char s;
    cout<<"please make the choice!\n";
    cout<<"play with the computer(enter 'a')\t"<<"play with your patner!(enter 'b')\t"<<":";
    cin>>s;getchar();
    while(s!='a'&&s!='b'){
        cout<<"enter only 'a' or 'b' : ";
        cin>>s;getchar();
    }
    if(s=='a')  playwithcomputer();
    else playwithpartner();
}

int main(){
    tactoe test;
    test.fun();
    cout<<"please enter the space to end";
    getchar();
    cout<<"have fun\n"<<"goodbye";
    return 0;
}
