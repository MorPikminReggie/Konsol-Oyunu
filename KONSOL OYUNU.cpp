#include <iostream>
#include <Windows.h>
#include <random>
#include <fstream>
#include <ctime>
using namespace std;
int xsize = 18;
int ysize = 18;
bool wait = false;
bool gecilemezlik = true;
bool dead = false;
bool disable = false;
bool olmech = false;
bool win = false;
int playerx;
int playery;
int x;
int y;
int ax;
int ay;
int highscore;
int xr = 0;
int yr = 0;
int keyx = -1;
int keyy = -1;
int score = 0;
int death();
void nextstage();
void olmecslair();
int main()
{
    srand(time(0));
    x = rand() % (xsize - 1) + 1;
    y = rand() % (ysize - 1) + 1;
    playerx = 1;
    playery = 1;
    cout << "   _____ _    _ ___    __   _____ _____  ______ _     _    _ _   _ _  ___     __\n";
    cout << "  / ____| |  | |\\ \\   / /  / ____|  __ \\|  ____| |   | |  | | \\ | | |/ \\ \\   / /\n";
    cout << " | |  __| |  | | \\ \\_/ /  | (___ | |__) | |__  | |   | |  | |  \\| | ' / \\ \\_/ /  \n";
    cout << " | | |_ | |  | |  \\   /    \\___ \\|  ___/|  __| | |   | |  | | . ` |  <   \\   /  \n";
    cout << " | |__| | |__| |   | |     ____) | |    | |____| |____ |__| | |\\  | . \\   | |   \n";
    cout << "  \\_____|\\____/    |_|    |_____/|_|    |______|______\\____/|_| \\_|_|\\_\\  |_|   \n";
    system("pause");
    while (1)
    {
        if (wait == false)
        {
            system("cls");
            for (int i = 0; i <= ysize; i++)
            {
                for (int j = 0; j <= xsize; j++)
                {
                    if (i == 0 || i == ysize || j == 0 || j == xsize)
                    {
                        if (i == ysize && j == xsize - 1)
                        {
                            cout << " /";
                        }
                        else
                        {
                            cout << " 0";
                        }
                    }
                    else if (i == playery && j == playerx)
                    {
                        cout << " P";
                    }
                    else if (not(x == playerx && y == playerx) && (i == y && j == x))
                    {
                        if (olmech == true)
                        {
                            cout << " $";
                        }
                        else
                        {
                            cout << " O";
                        }
                        
                    }
                    else if (i == ay && j == ax-2)
                    {
                        cout << " -";
                    }
                    else if (i == ay && j == ax-1)
                    {
                        cout << "-.";
                    }
                    else if (i == ay && j == ax)
                    {
                        cout << " A";
                    }
                    else if (not(keyx == playerx && keyy == playerx) && (i == keyy && j == keyx))
                    {
                        cout << " *";
                    }
                    else if ((i == xr))
                    {
                        if (i == yr && j == 2)
                        {
                            cout << " |";
                        }
                        else
                        {
                            cout << " X";
                        }
                    }
                    else
                    {
                        cout << "  ";
                    }
                    if (j == xsize)
                    {
                        cout << endl;
                    }
                }
            }
            cout << "---------------------------" << endl << " SCORE = " << score << endl;
            cout << "---------------------------" << endl << " HIGHEST SCORE = " << highscore << endl;
            wait = true;
        }
        else {

            if (GetAsyncKeyState(VK_RIGHT))
            {
                if (playerx + 1 == x && playery == y)
                {
                    x++;
                    if (x >= xsize && (disable == false || olmech == true))
                    {
                        srand(time(0));
                        x = rand() % (xsize - 1) + 1;
                        y = rand() % (ysize - 1) + 1;
                        if (olmech == true)
                        {
                            score += 5;
                        }
                        else
                        {
                            score++;
                        }
                    }
                }
                if (playerx + 1 == keyx && playery == keyy)
                {
                    keyx++;
                    if (keyy == yr && keyx == 2)
                    {
                        gecilemezlik = false;
                    }
                }
                if (playerx + 1 == xr && playery == yr && gecilemezlik == true)
                {
                    playerx--;
                }
                playerx++;
                if (win == false && olmech == true && dead == true)
                {
                    cout << "'YOU LIVED WITH GREED, NOW YOU WILL DIE BECAUSE OF THE GREED.'\n";
                    death();
                    cout << "YOU WERE SHOT DEAD BY THE MAN ON THE MOON.";
                }
                wait = false;
                if (playerx >= xsize)
                {
                    death();
                }
                if (score < 20)
                {
                    Sleep(100 - (score * 5));
                }
            }
            else if (GetAsyncKeyState(VK_LEFT))
            {
                if (playerx - 1 == x && playery == y)
                {
                    x--;
                    if (x <= 0 && (disable == false || olmech == true))
                    {
                        srand(time(0));
                        x = rand() % (xsize - 1) + 1;
                        y = rand() % (ysize - 1) + 1;
                        if (olmech == true)
                        {
                            score += 5;
                        }
                        else
                        {
                            score++;
                        }
                    }
                }
                if (playerx - 1 == keyx && playery == keyy)
                {
                    keyx--;
                    if (keyy == yr && keyx == 2)
                    {
                        gecilemezlik = false;
                    }
                }
                if (playerx - 1 == xr && playery == yr && gecilemezlik == true)
                {
                    playerx++;
                }
                playerx--;
                if (win == false && olmech == true && dead == true)
                {
                    cout << "'YOU LIVED WITH GREED, NOW YOU WILL DIE BECAUSE OF THE GREED.'\n";
                    death();
                    cout << "YOU WERE SHOT DEAD BY THE MAN ON THE MOON.";
                }
                wait = false;
                if (playerx <= 0)
                {
                    death();
                }
                if (score < 20)
                {
                    Sleep(100 - (score * 5));
                }
            }
            else if (GetAsyncKeyState(VK_UP))
            {
                if (playery - 1 == y && playerx == x)
                {
                    y--;
                    if (y <= 0 && (disable == false || olmech == true))
                    {
                        srand(time(0));
                        x = rand() % (xsize - 1) + 1;
                        y = rand() % (ysize - 1) + 1;
                        if (olmech == true)
                        {
                            score += 5;
                        }
                        else
                        {
                            score++;
                        }
                    }
                }
                if (playery - 1 == keyy && playerx == keyx)
                {
                    keyy--;
                    if (keyy == yr && keyx == 2)
                    {
                        gecilemezlik = false;
                    }
                }
                if (playery - 1 == yr && playery == xr && gecilemezlik == true)
                {
                    playery++;
                }
                playery--;
                if (win == false && olmech == true && dead == true)
                {
                    cout << "'YOU LIVED WITH GREED, NOW YOU WILL DIE BECAUSE OF THE GREED.'\n";
                    death();
                    cout << "YOU WERE SHOT DEAD BY THE MAN ON THE MOON.";
                }
                wait = false;
                if (playery <= 0)
                {
                    death();
                }
                if (score < 20)
                {
                    Sleep(100 - (score * 5));
                }

            }
            else if (GetAsyncKeyState(VK_DOWN))
            {
                if (playery + 1 == y && playerx == x)
                {
                    y++;
                    if (y >= ysize && (disable == false||olmech==true))
                    {
                        srand(time(0));
                        x = rand() % (xsize - 1) + 1;
                        y = rand() % (ysize - 1) + 1;
                        if (olmech == true)
                        {
                            score += 5;
                        }
                        else
                        {
                            score++;
                        }
                    }
                }
                if (playery + 1 == keyy && playerx == keyx)
                {
                    keyy++;
                    if (keyy == yr && keyx == 2)
                    {
                        gecilemezlik = false;
                    }
                }
                if (playery + 1 == yr && gecilemezlik == true)
                {
                    playery--;
                }
                playery++;
                wait = false;
                if (playerx == xsize - 1 && playery == ysize && win == false && olmech==false)
                {
                    nextstage();
                }
                else if (playery == yr + 1 && win == false && olmech == true && dead == true)
                {
                    cout << "'YOU LIVED WITH GREED, NOW YOU WILL DIE BECAUSE OF THE GREED.'\n";
                    death();
                    cout << "YOU WERE SHOT DEAD BY THE MAN ON THE MOON.";
                }
                else if(playery == yr && win == false && olmech == true && dead==false)
                {
                    ax = playerx+3;
                    ay = playery;
                    dead = true;
                }
                else if (playerx == xsize - 1 && playery == ysize && win == true && olmech==false)
                {
                    cout << "YOU ARE FREE WITH " << score << " MONEY" << endl;
                    if (highscore < score)
                    {
                        highscore = score;
                    }
                    cout << "YOUR HIGHEST SCORE WAS " << highscore << endl;
                    cout << "YET, IT DOESN'T SEEM ENOUGH TO YOU. YOU CONTINUE TO YOUR JOURNEY." << endl;
                    system("pause");
                    playerx = 1;
                    playery = 1;
                    keyy = -1;
                    keyx = -1;
                    xr = -1;
                    yr = -1;
                    gecilemezlik = false;
                    disable = false;
                    win = false;
                    system("cls");
                    cout << "YOU FIND A MYSTERIOUS CAVE, POSSIBLY ONE THAT HAS GOLD.\n";
                    cout << "AS A RESULT, YOU GO THERE, FOR THE ADVENTURE AND OF COURSE FOR THE MONEY";
                    olmecslair();
                }
                else if (playerx == xsize - 1 && playery == ysize && win == false && olmech == true)
                {
                    system("cls");
                    cout << "TAKE ME TO THE MOOOON!11!1!\n";
                    system("pause");
                    xsize = 12;
                    ysize = 12;
                    xr = 4;
                    yr = 4;
                    keyy = 3;
                    keyx = 2;
                    playerx = 2;
                    playery = 2;
                    disable = true;
                    x = 6;
                    y = 6;
                }
                else if (playery >= ysize)
                {
                    death();
                }
                if (score < 20)
                {
                    Sleep(100 - (score * 5));
                }
            }
        }
    }
}
int death()
{
    cout << " YOU DIED" << endl;
    cout << " YOUR SCORE WAS " << score << endl;
    cout << " YOUR HIGHEST SCORE WAS " << score << endl;
    system("pause");
    playerx = 1;
    playery = 1;
    score = 0;
    keyy = -1;
    keyx = -1;
    xr = -1;
    yr = -1;
    ax = -1;
    ay = -1;
    xsize = 18;
    ysize = 18;
    gecilemezlik = false;
    disable = false;
    win = false;
    olmech = false;
    dead = false;
    return 0;
}
void nextstage()
{
    cout << "---------------------------" << endl << " YOU GOT CAUGHT WHEN YOU WERE QUITTING" << endl;
    system("pause");
    system("cls");
    xsize = 16;
    ysize = 16;
    playerx = 1;
    playery = 1;
    xr = 8;
    yr = 8;
    x = -1;
    y = -1;
    keyx = 4;
    keyy = 2;
    gecilemezlik = true;
    disable = true;
    win = true;
}
void olmecslair()
{
    olmech = true;
    xsize = 12;
    ysize = 12;
    x = rand() % (xsize - 1) + 1;
    y = rand() % (xsize - 1) + 1;
    playerx = 2;
    playery = 2;
    disable = false;
}