#include <unistd.h>
#include <ctime>
#include <iostream>
#include <conio.h>
#include <cstdlib>
int dotCount = 0; // Counter for dots eaten
int level=1;
int ghostRow = 2;
const int height = 30;
const int width = 30;
int gx,gy;
using namespace std;
void ghost(char arr[][width], int inix, int iniy) {
    // Calculate the direction towards the player
    int dx = inix - gx;
    int dy = iniy - gy;

    // Determine whether to move horizontally or vertically based on distance
    if (abs(dx) > abs(dy)) {
        // Move horizontally
        if (dx > 0 && gx < height - 1 && arr[gx + 1][gy] != '*') {
            arr[gx][gy] = ' '; // Clear the current position
            gx++; // Move towards the player
        } else if (gx > 0 && arr[gx - 1][gy] != '*') {
            arr[gx][gy] = ' '; // Clear the current position
            gx--; // Move towards the player
        }
    } else {
        // Move vertically
        if (dy > 0 && gy < width - 1 && arr[gx][gy + 1] != '*') {
            arr[gx][gy] = ' '; // Clear the current position
            gy++; // Move towards the player
        } else if (gy > 0 && arr[gx][gy - 1] != '*') {
            arr[gx][gy] = ' '; // Clear the current position
            gy--; // Move towards the player
        }
    }

    // Place the ghost at the new position
    arr[gx][gy] = 'G';
}
void exit()
{   system("clear");
    cout<<"This is made by Asad Shayan";
    sleep(10);
}
void displaypacman(){
    //cout<<"\033[33m"<<level<<"\033[0m"<<endl;
    cout << "\033[33m";
    cout << "__________  _____  _________              _____      _____    _______   \n";
    cout << "\\______   \\/  _  \\ \\_   ___ \\            /     \\    /  _  \\   \\      \\  \n";
    cout << " |     ___/  /_\\  \\/    \\  \\/   ______  /  \\ /  \\  /  /_\\  \\  /   |   \\ \n"<<"\t\t\tLevel :"<<level<<" \033[34m Dots eaten :"<<dotCount<<endl;
    cout << " |    |  /    |    \\     \\____ /_____/ /    Y    \\/    |    \\/    |    \\\n";
    cout << " |____|  \\____|__  /\\______  /         \\____|__  /\\____|__  /\\____|__  /\n";
    cout << "                 \\/        \\/                  \\/         \\/         \\/ \n";  
    cout<<"\033[0m";
}
void about(){       //if you press the about button in the menu this will be printed on the terminal.
    system("clear");
    cout<<"\033[34mSon, Once you have entered the game there is no way back.\nYou have to complete the levels and eat those Dots, remember beware of those\n(*) they are your worst enemies .\033[0m";
}
void menu(){
    int op;
    int op1;
    int enter=0;
    int j=0;
    system("clear");
    displaypacman();
    string names[3]={"\033[33mStart\033[0m\nAbout\nExit","Start\n\033[33mAbout\033[0m\nExit","Start\nAbout\n\033[33mExit\033[0m"};
    cout<<names[j];
    while (true)
    {
    if(_kbhit())
        {
            op=getch();
            if(op==115)
            {
                if(j<=2){
                op1=getch();
                system("clear");
                displaypacman();
                j++;
                //printf("%c",7);
                cout<<names[j];
                }
                if(op1==10)
                {
                    if(j==1)
                    {
                        about();
                    }
                    if(j==2)
                    {
                        system("clear");
                        cout<<"Bye Bye";
                    }

                
                    
                }
            }
            if(op==119)
            {
                if(j>=0){
                system("clear");
                displaypacman();
                j--;
                cout<<names[j];
                op1=getch();
                }
                if(op1==10)
                {
                    system("clear");
                    if(j==0)
                    {
                        break;
                    }
                    if(j==1)
                    {
                        about();
                    }
                }
            }
        }        
    }
}
void setCursorPosition(int x, int y) {
    cout<< "\033[" << y << ";" << x << "H";
}
void assigner(char arr[][width],int num) {
    for(int i=0;i<30;i++)
    { for(int j=0;j<30;j++)
        {
            arr[i][j]=' ';
        }cout<<endl;
    }
    for(int i=0;i<30;i++)
    {
        arr[i][0]='|';
        arr[i][29]='|';
    }
    arr[0][14]='|';
    arr[0][16]='|';
    arr[1][14]='|';
    arr[1][16]='|';
    arr[2][14]='\\';
    arr[2][15]='_';
    arr[2][16]='/';//for the nose
    arr[2][3]='|';
    arr[2][5]='|';
    arr[2][4]='-';//for 1st box
    arr[2][7]='|';
    arr[2][8]='-';
    arr[2][9]='|';//for 2nd box
    arr[2][26]='|';
    arr[2][25]='-';
    arr[2][24]='|';
    arr[2][22]='|';
    arr[2][21]='-';
    arr[2][20]='|';
    arr[13][13]='_';
    arr[13][14]='_';
    arr[13][15]=' ';
    arr[13][16]='_';
    arr[13][17]='_';
    arr[14][13]='|';
    arr[15][13]='|';// the main central box
    arr[14][17]='|';
    arr[15][17]='|';
    arr[16][13]='|';
    arr[16][17]='|';
    arr[16][14]='_';
    arr[16][15]=' ';
    arr[16][16]='_';
    arr[15][0]=' ';//two side wholes (left one)
    arr[15][29]=' ';//two side wholes
    arr[29][14]='|';
    arr[29][16]='|';
    arr[28][14]='|';
    arr[28][16]='|';
    arr[27][14]='/';
    arr[27][15]='-';
    arr[27][16]='\\';//for the nose
    arr[11][3]='|';
    arr[12][3]='|';
    arr[13][3]='|';
    arr[14][3]='|';
    arr[15][3]='|';
    arr[16][3]='|';
    arr[17][3]='|';
    arr[18][3]='|';
    arr[19][3]='|';
    arr[11][5]='|';
    arr[12][5]='|';
    arr[13][5]='|';
    arr[14][5]='|';
    arr[15][5]='|';
    arr[16][5]='|';
    arr[17][5]='|';
    arr[18][5]='|';
    arr[19][5]='|';
    arr[11][26]='|';
    arr[12][26]='|';
    arr[13][26]='|';
    arr[14][26]='|';
    arr[15][26]='|';
    arr[16][26]='|';
    arr[17][26]='|';
    arr[18][26]='|';
    arr[19][26]='|';
    arr[11][24]='|';
    arr[12][24]='|';
    arr[13][24]='|';
    arr[14][24]='|';
    arr[15][24]='|';
    arr[16][24]='|';
    arr[17][24]='|';
    arr[18][24]='|';
    arr[19][24]='|';
    arr[4][10]='_';
    arr[4][11]='_';
    arr[4][12]='_';
    arr[4][13]='_';
    arr[4][14]='_';
    arr[4][15]='_';
    arr[4][16]='_';
    arr[4][17]='_';
    arr[4][18]='_';
    arr[4][19]='_';
    arr[4][20]='_';
    arr[6][10]='_';
    arr[6][11]='_';
    arr[6][12]='_';
    arr[6][13]='_';
    arr[6][14]='_';
    arr[6][15]='_';
    arr[6][16]='_';
    arr[6][17]='_';
    arr[6][18]='_';
    arr[6][19]='_';
    arr[6][20]='_';
    arr[24][10]='_';
    arr[24][11]='_';
    arr[24][12]='_';
    arr[24][13]='_';
    arr[24][14]='_';
    arr[24][15]='_';
    arr[24][16]='_';
    arr[24][17]='_';
    arr[24][18]='_';
    arr[24][19]='_';
    arr[24][20]='_';
    arr[22][10]='_';
    arr[22][11]='_';
    arr[22][12]='_';
    arr[22][13]='_';
    arr[22][14]='_';
    arr[22][15]='_';
    arr[22][16]='_';
    arr[22][17]='_';
    arr[22][18]='_';
    arr[22][19]='_';
    arr[22][20]='_';
    // Create rooms and obstacles (customize this part based on your game design)
    for (int i = 2; i < height - 2; i++) {
        for (int j = 2; j < width - 2; j++) {
            if (rand() % num == 0 && arr[i][j]!='_'&& arr[i][j]!='|') 
                arr[i][j] = '*';
        }
    }
}
void generateRandomDots(char arr[][width],int numOfDots) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < numOfDots; i++) {
        int randX = rand() % height;
        int randY = rand() % width;
        arr[randX][randY] = '.';
    }
}
void display(char arr[][width], int inix, int iniy) {
    setCursorPosition(0, 0);
    system("clear");// Clear screen
    displaypacman();
    ghost(arr,inix,iniy);
    cout << " __________________________________________________________" << endl;
    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < width; j++) {
            if (i == inix && j == iniy) {
                cout << "\033[1;33mC\033[0m "; // Print 'C' in yellow
            }
            else if(arr[i][j]=='*'){
                cout << "\033[1;31m*\033[0m ";//prints asterisk in red color.
            }
            else {
                cout << arr[i][j] << " ";
            }
        }
        cout<< endl;
    }
    cout << "| ________________________________________________________|" << endl;
}
void gameover(){
        while(true){
        system("clear");
    cout << "\033[1;31m";//red color    
    cout<<"________________________________________YOU ARE A NERD________________________________________\n"<<endl;
    cout << " ________    _____      _____  ___________         ____________   _________________________\n";
    cout << "/  _____/   /  _  \\    /     \\ \\_   _____/         \\_____  \\   \\ /   /\\_   _____/\\______   \\\n";
    cout << "/   \\  ___  /  /_\\  \\  /  \\ /  \\ |    __)_   ______  /   |   \\   Y   /  |    __)_  |       _/\n";
    cout << "\\    \\_\\  \\/    |    \\/    Y    \\|        \\ /_____/ /    |    \\     /   |        \\ |    |   \\\n";
    cout << " \\______  /\\____|__  /\\____|__  /_______  /         \\_______  /\\___/   /_______  / |____|_  /\n";
    cout << "        \\/         \\/         \\/        \\/                  \\/                 \\/         \\/\n";
    cout<<"\033[0m";
        usleep(5000);
        }
}
void checkmove(char move, int& inix, int& iniy, char arr[][width], int& count);
void checkLevelCompletion(char arr[][width]);
void checkmove(char move, int& inix, int& iniy, char arr[][width], int& count) {  // a function to check the move......................................................................................................
    while (true) {
        if (kbhit()) {
            move = getch();
            switch (move) {
                case 'w':
                    if (inix > 0) {
                        if (arr[inix - 1][iniy] == '.') {
                            count++;
                        }
                        if(arr[inix-1][iniy]=='|'||arr[inix-1][iniy]=='_')
                        {
                            break;
                        }
                        if(arr[inix-1][iniy]=='*')
                        {
                            gameover();
                            break;
                        }
                        arr[inix][iniy] = ' ';
                        --inix;
                        arr[inix][iniy] = 'C';
                        display(arr, inix, iniy);
                    }
                    break;
                case 's':
                    if (inix < height - 1) {
                        if (arr[inix + 1][iniy] == '.') {
                            count++;
                        }
                        if(arr[inix+1][iniy]=='|'||arr[inix+1][iniy]=='_')
                        {
                            break;
                        }
                        if(arr[inix+1][iniy]=='*')
                        {
                            gameover();
                            break;
                        }
                        arr[inix][iniy] = ' ';
                        ++inix;
                        arr[inix][iniy] = 'C';
                        display(arr, inix, iniy);
                    }
                    break;
                case 'd':
                    if (iniy < width - 1) {
                        if (arr[inix][iniy + 1] == '.') {
                            count++;
                        }
                         if(arr[inix][iniy+1]=='_'|| arr[inix][iniy+1]=='|')
                        {
                            break;
                        }
                        if(arr[inix][iniy+1]=='*')
                        {
                            gameover();
                            break;
                        }
                        arr[inix][iniy] = ' ';
                        ++iniy;
                        arr[inix][iniy] = 'C';
                        display(arr, inix, iniy);
                    }
                    break;
                case 'a':
                    if (iniy > 0) {
                        if (arr[inix][iniy - 1] == '.') {
                            count++;
                        }
                         if(arr[inix][iniy-1]=='_'||arr[inix][iniy-1]=='|')
                        {
                            break;
                        }
                        if(arr[inix][iniy-1]=='*')
                        {
                            gameover();
                            break;
                        }
                        arr[inix][iniy] = ' ';
                        --iniy;
                        arr[inix][iniy] = 'C';
                        display(arr, inix, iniy);
                    break;
                }
            }
                    checkLevelCompletion(arr);
        }
    }
}
void checkLevelCompletion(char arr[][width]) {
    int n;
    switch(level){
        case 1:
            n=25;
            break;
        case 2:
            n=35;
            break;
        case 3:
            n=65;
    }
    if (dotCount >= n) {
        level++;
        dotCount = 0;
        system("clear");
        cout << "Level " << level << " started!" << endl;
        sleep(2);  // Pause for 2 seconds to show the level change message
        // Reset player position and generate new level
        int inix = height / 2;
        int iniy = width / 2;
        assigner(arr, 5);      // Customize the number of obstacles for Level 2
        generateRandomDots(arr, 40);  // Customize the number of dots for Level 2
        display(arr, inix, iniy);
       checkmove('w', inix, iniy, arr, dotCount);  // Dummy move to start the game
    }
}
void chooselevel(char arr[][width],int& inix,int& iniy,char move,int numofobstacles,int dotstowin){
    assigner(arr,numofobstacles);
    inix=height/2;
    iniy=width/2;
    arr[inix][iniy] = 'C';
    generateRandomDots(arr,dotstowin);
    display(arr,inix,iniy);
    checkmove(move,inix,iniy,arr,dotCount);
}
int main() {
    char area[height][width];
    char movement;
    int inix = height / 2;
    int iniy = width / 2;
    gx=inix;
    gy=iniy;
    menu();
    system("clear");
    area[inix][iniy] = 'C'; // Set initial player position
    chooselevel(area,inix,iniy,movement,10,20);
    chooselevel(area,inix,iniy,movement,5,40);
}
//ghost banana hay.