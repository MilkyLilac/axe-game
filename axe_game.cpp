#include "raylib.h"
int main()
{ 
    //window dimensions
    int windowheightt {800};
    int windowidthh {800};
    
    //circle placements
    int circlex{windowheightt / 2};
    int circley{windowidthh / 2};
    int circle_radius{25};
    int speed{10};

    //circle edges
    int l_circle_x{circlex - circle_radius};
    int r_circle_x{circlex + circle_radius};
    int u_circle_y{circley - circle_radius};
    int d_circle_y{circley + circle_radius};


    
    

    //axe coordinates
    int axex{windowheightt / 2};
    int axey{0};
    int direction{10};
    int axe_length{50};

    //axe coordinates
    int l_axe_x {axex};
    int r_axe_x {axex + axe_length};
    int u_axe_y {axey};
    int d_axe_y {axey + axe_length};
    
    bool collision_with_axe = 
        (d_axe_y >= u_circle_y) && 
        (u_axe_y <= d_circle_y) && 
        (l_axe_x <= r_circle_x) &&
        (r_axe_x >= l_circle_x);


    InitWindow(windowidthh, windowheightt, "Ayoooo");

   SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (collision_with_axe && !IsKeyPressed(KEY_R))
        {
            DrawText("U R DEAD!", 175, 300, 100, RED);
            axey = 0; 
            circley = windowidthh / 2;
            circlex = windowheightt /2;

        }


        else
        {
        // Game logic begins

        //update edges
        l_circle_x = circlex - circle_radius;
        r_circle_x = circlex + circle_radius;
        u_circle_y = circley - circle_radius;
        d_circle_y = circley + circle_radius;
        l_axe_x = axex;
        r_axe_x = axex + axe_length;
        u_axe_y = axey;
        d_axe_y = axey + axe_length;
    
        collision_with_axe = ( d_axe_y >= u_circle_y && u_axe_y <= d_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x);

       
        DrawCircle(circlex, circley, circle_radius, PINK);
        DrawRectangle(axex, axey, axe_length, axe_length, PURPLE);


        axey += direction;
        if (axey > windowidthh || axey < 0)
        {
            direction = -direction; 
        }

        if (IsKeyDown(KEY_D) && circlex < windowheightt)
        {  
            circlex += speed; 
        }
        
        if (IsKeyDown(KEY_A) && circlex > 0)
        {
            circlex -= speed;
        }


         if (IsKeyDown(KEY_W) && circley > 0)
        {
            circley -= speed;
        }

        
        if (IsKeyDown(KEY_S) && circley < windowidthh)
        {
            circley += speed;
        }


           if (IsKeyDown(KEY_R))
        {
            axey = 0; 
            circley = windowidthh / 2;
            circlex = windowheightt /2;
        };


      // Game logic ends
        } 
        EndDrawing();
        

    }

}