#include "raylib.h"
using namespace std;

int main()
{
    //Window Dimensions
    int Width{500};
    int Height{350};
    InitWindow(Width, Height, "Joseph's Game");    

    //Circle Coordinates
    int Circle_X{Width/2};
    int Circle_Y{Height/2};
    int Circle_Radius{25};

    //Circle limits
    int Left_Circle_X{Circle_X - Circle_Radius};
    int Right_Circle_X{Circle_X + Circle_Radius};
    int Upper_Circle_Y{Circle_Y - Circle_Radius};
    int Bottom_Circle_Y{Circle_Y + Circle_Radius};

    //Rectangle Dimensions
    int Rectangle_Width{50};
    int Rectangle_Height{50};

    //Rectangle Coordinates
    int Rectangle_X{300};
    int Rectangle_Y{0};

    //Rectangle Limits
    int Left_Rectangle_X{Rectangle_X};
    int Right_Rectangle_X{Rectangle_X + Rectangle_Width};
    int Upper_Rectangle_Y{Rectangle_Y};
    int Bottom_Rectangle_Y{Rectangle_Y + Rectangle_Height};

    //Rectangle speed
    int Rectangle_Direction{20};

    

    //Game State
    bool Collision_With_Rectangle = 
                        (Bottom_Rectangle_Y >= Upper_Circle_Y) && 
                        (Upper_Rectangle_Y <= Bottom_Circle_Y) && 
                        (Right_Rectangle_X >= Left_Circle_X) && 
                        (Left_Rectangle_X <= Right_Circle_X);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(GREEN);

        if (Collision_With_Rectangle)
        {
            DrawText("Game Over!", 150, 150, 35, RED);
        }
        else
        {
            //Game Logic Starts

            //Update the Collisions
            Left_Circle_X = Circle_X - Circle_Radius;
            Right_Circle_X = Circle_X + Circle_Radius;
            Upper_Circle_Y = Circle_Y - Circle_Radius;
            Bottom_Circle_Y = Circle_Y + Circle_Radius;

            Left_Rectangle_X = Rectangle_X;
            Right_Rectangle_X = Rectangle_X + Rectangle_Width;
            Upper_Rectangle_Y = Rectangle_Y;
            Bottom_Rectangle_Y = Rectangle_Y + Rectangle_Height;

            //Update collision with Obstacle
            Collision_With_Rectangle = 
                        (Bottom_Rectangle_Y >= Upper_Circle_Y) && 
                        (Upper_Rectangle_Y <= Bottom_Circle_Y) && 
                        (Right_Rectangle_X >= Left_Circle_X) && 
                        (Left_Rectangle_X <= Right_Circle_X);

            //Start Game
            DrawCircle(Circle_X,Circle_Y,Circle_Radius,BLUE);
            DrawRectangle(Rectangle_X,Rectangle_Y,Rectangle_Width,Rectangle_Height,RED);

            //Player Movement
            if(IsKeyDown(KEY_D) && Circle_X < Width)
            {
                Circle_X += 10;
            }

            if(IsKeyDown(KEY_A) && Circle_X > 0)
            {
                Circle_X -= 10;
            }
            
            if(IsKeyDown(KEY_W) && Circle_Y > 0)
            {
                Circle_Y -= 10;
            }

            if(IsKeyDown(KEY_S) && Circle_Y < Height)
            {
                Circle_Y += 10;
            }

            //Move Obstacle
            Rectangle_Y += Rectangle_Direction;

            if(Rectangle_Y > Height || Rectangle_Y < 0)
            {
                Rectangle_Direction = -Rectangle_Direction;
            }

            //Game Logic Ends
        }
            EndDrawing();
    }
}