#include <SFML/Graphics.hpp>
#include <time.h>
#include<bits/stdc++.h>
#include <sstream>
#include <string>
using namespace sf;
using namespace std;
#define yval 211.9393258426966
#define xval 47.75344563552833
#define X 99
#define Y 99



bool start = false;
int a[4][4],b[4][4]={0};
int sum=0;
int indexnikalo(int n)
{
    int count=0;
    while(n>0)
    {
        n/=2;
        count++;
    }
    return count-1;
}

bool checkwin()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j]==2048)
            {
                return true;
            }
        }

    }

    return false;
}

int getMovesLeft()
{	
	int left=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(b[i][j]==1){
				if(i+1<4 && (a[i][j]==a[i+1][j] || b[i+1][j]==0)) left++;
				if(j+1<4 && (a[i][j]==a[i][j+1] || b[i][j+1]==0)) left++;
			}
		}
	}
	return left;
}

int hasEmptyCell()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(b[i][j]==0)
            {
                return 1;
            }
        }

    }
	return 0;
}
	
bool gameOver()
{
	//cout<<getMovesLeft()<<" "<<hasEmptyCell()<<"\n";
	if(hasEmptyCell()==0 && getMovesLeft()==0)
	{
		return true;
	}
	else return false;
}

void dwn()
{

    for(int j=0;j<4;j++)
    {
        for(int i=2;i>=0;i--)
            {
                if(b[i][j]){
                if(b[i+1][j]==1)
                {
                    if(a[i][j]==a[i+1][j])
                    {
                        a[i+1][j]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                        
                    }

                    else
                    {
                        continue;
                    }
                }

                else
                {
                    int k;
                    for(k=i+1;k<4;k++)
                    {
                        if(b[k][j]==1)
                            break;
                    }

                    if(a[i][j]==a[k][j])
                    {
                        a[k][j]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                        
                    }

                    else
                    {
                        a[k-1][j]=a[i][j];
                        a[i][j]=0;
                        b[i][j]=0;
                        b[k-1][j]=1;
                    }
                }
            }
        }
    }
    

}   

void upw()
{

    for(int j=0;j<4;j++)
    {
        for(int i=1;i<4;i++)
            {
                if(b[i][j]){
                if(b[i-1][j]==1)
                {
                    if(a[i][j]==a[i-1][j])
                    {
                        a[i-1][j]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                        
                    }

                    else
                    {
                        continue;
                    }
                }

                else
                {
                    int k;
                    for(k=i-1;k>=0;k--)
                    {
                        if(b[k][j]==1)
                            break;
                    }

                    if(a[i][j]==a[k][j])
                    {
                        a[k][j]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                        
                    }

                    else
                    {
                        a[k+1][j]=a[i][j];
                        a[i][j]=0;
                        b[i][j]=0;
                        b[k+1][j]=1;
                    }
                }
            }
        }
    }

}

void right()
{
    for(int i=0;i<4;i++)
    {
        for(int j=2;j>=0;j--)
            {
                if(b[i][j]){
                if(b[i][j+1]==1)
                {
                    if(a[i][j]==a[i][j+1])
                    {
                        a[i][j+1]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                        
                    }

                    else
                    {
                        continue;
                    }
                }

                else
                {
                    int k;
                    for(k=j+1;k<4;k++)
                    {
                        if(b[i][k]==1)
                            break;
                    }

                    if(a[i][j]==a[i][k])
                    {
                        a[i][k]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                       
                    }

                    else
                    {
                        a[i][k-1]=a[i][j];
                        a[i][j]=0;
                        b[i][j]=0;
                        b[i][k-1]=1;
                    }
                }
            }
        }
    }
}

void left()
{

    for(int i=0;i<4;i++)
    {
        for(int j=1;j<4;j++)
            {
                if(b[i][j]){
                if(b[i][j-1]==1)
                {
                    if(a[i][j]==a[i][j-1])
                    {
                        a[i][j-1]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                        
                    }

                    else
                    {
                        continue;
                    }
                }

                else
                {
                    int k;
                    for(k=j-1;k>=0;k--)
                    {
                        if(b[i][k]==1)
                            break;
                    }

                    if(a[i][j]==a[i][k])
                    {
                        a[i][k]=a[i][j]*2;
                        sum+= a[i][j]*2;
                        a[i][j]=0;
                        b[i][j]=0;
                        
                    }

                    else
                    {
                        a[i][k+1]=a[i][j];
                        a[i][j]=0;
                        b[i][j]=0;
                        b[i][k+1]=1;
                    }
                }
            }
        }
    }
}

void rdmghusa()
{
    srand(time(0));
    int x=rand()%4, y =rand()%4;
    while(b[x][y]!=0)
    {
        x = rand()%4;
        y = rand()%4;
    }

    a[x][y] = pow(2,rand()%2+1);
    b[x][y] = 1;

}

void init()
{
    srand(time(0));
    if(!start){
        
        int x = rand()%4, y =rand()%4;
        start = true;
        
        a[x][y] = 2;
        b[x][y] = 1;
        
        int x1=x,y1=y;
        
        while(x==x1 && y==y1)
        {
            x1 = rand()%4;
            y1 = rand()%4;
        }
        
        a[x1][y1] = pow(2,rand()%2+1);
        b[x1][y1] = 1;

        }
}

int main()
{
  
    //// RENDERING WINDOW  /////
    srand(time(0));
    RenderWindow window(VideoMode(480,640), "2048-Rahul Indra");
    Texture t,t1[11];
    t.loadFromFile("images/panel.jpg");
    t1[0].loadFromFile("images/2.jpg");
    t1[1].loadFromFile("images/4.jpg");
    t1[2].loadFromFile("images/8.jpg");
    t1[3].loadFromFile("images/16.jpg");
    t1[4].loadFromFile("images/32.jpg");
    t1[5].loadFromFile("images/64.jpg");
    t1[6].loadFromFile("images/128.jpg");
    t1[7].loadFromFile("images/256.jpg");
    t1[8].loadFromFile("images/512.jpg");
    t1[9].loadFromFile("images/1024.jpg");
    t1[10].loadFromFile("images/2048.jpg");
    Sprite panel(t);
    
    vector <Sprite> num;
    
    for(int i=0;i<11;i++)
    num.push_back(Sprite(t1[i]));
    init();
    //// RENDERING WINDOW  /////

    
    while(window.isOpen())
    { 
        	window.clear(Color::White);
			if(checkwin())
			{
				////WINNER////
				Text text;
         	    Font f;
        	    f.loadFromFile("Xcelsion.ttf");
          	    text.setFont(f);
        	    text.setCharacterSize(24);
				text.setColor(Color::Black);
				text.setString(" Winner winner\nChicken dinner!");
				text.move(80,280);				           					window.draw(text);

				Event e;
				while(window.pollEvent(e))
          	    {
              	  if(e.type== Event::Closed)
                    window.close();
				}
				window.display();
			}
            else if(gameOver())
           	{	
				Text text;
         	    Font f;
        	    f.loadFromFile("Xcelsion.ttf");
          	    text.setFont(f);
        	    text.setCharacterSize(24);
				text.setColor(Color::Black);
				text.setString("\t\tGameOver!\nPress any key to exit");
				text.move(12,280);				           					window.draw(text);
				
				Event e;
				while(window.pollEvent(e))
          	    {
              	  if(e.type== Event::Closed)
                    window.close();
              	  if(e.type==Event::KeyPressed){
		    		window.close();		
					//add reset functionality here
					}
				}
				window.display();
			}
			
			else{	
            //// SCORE /////

            Text text;
            Font f;
            f.loadFromFile("hey.TTF");
            ostringstream str1; 
            str1 << sum;
            string score = str1.str(); 
            text.setString(score);
            text.setFont(f);
            text.setCharacterSize(24);
            text.setColor(Color::White);
            text.move(322.47852760736197,58.454545454545);

            //// SCORE /////

            Event e;
            while(window.pollEvent(e))
            {
                if(e.type== Event::Closed)
                    window.close();
                if(e.type==Event::KeyPressed){
                if(e.key.code==Keyboard::Up) 
                    {upw();rdmghusa();}
                else if(e.key.code==Keyboard::Left) {left();rdmghusa();}
                else if(e.key.code==Keyboard::Right) {right();rdmghusa();}
                else if(e.key.code==Keyboard::Down) {dwn();rdmghusa();}
                }
            }    
            
            //// PRINT PANEL //////
            window.clear(Color::White);
            window.draw(panel);
            window.draw(text);
            // cout << sum <<endl;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    // cout << a[i][j] << " ";
                   if(b[i][j]==1)
                    {
                        num[indexnikalo(a[i][j])-1].setPosition(xval+X*j,yval+Y*i);
                        window.draw(num[indexnikalo(a[i][j])-1]);
                    }

                }
                // cout << endl;
            }


            //// PRINT PANEL //////
            
            window.display();
		}            
    
    }
        
    return 0;
}
