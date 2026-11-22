#ifndef MENU_H
#define MENU_H

#include <cstdlib>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

void modoManual();
void modoInteligente();

void menu(ALLEGRO_DISPLAY *display, int realWidth, int realHeight, ALLEGRO_FONT *font){
    ALLEGRO_EVENT_QUEUE *cola = al_create_event_queue();
    al_register_event_source(cola, al_get_keyboard_event_source());
    al_register_event_source(cola, al_get_mouse_event_source());

    // tamaño y posición de los botones
    int ancho = al_get_text_width(font, "MODO INTELIGENTE") + 200;
    int alto = al_get_font_line_height(font) + 120;
    int x1 = realWidth/2 - ancho/2;
    int x2 = x1 + ancho;
    int y1 = realHeight/2 - alto - 30;   // botón manual
    int y2 = y1 + alto;
    int y3 = realHeight/2 + 30;          // botón inteligente
    int y4 = y3 + alto;
    int centroX = realWidth/2;

    // Transición de aparición
    for (float i = 1; i >= 0; i -= 0.05){
        al_clear_to_color(al_map_rgb(255, 255, 255)); // dibuja la pantalla en blanco
        al_draw_rectangle(x1, y1, x2, y2, color.negro, 5); // Dibuja los rectámgulos con texto del menú
        al_draw_rectangle(x1, y3, x2, y4, color.negro, 5);
        al_draw_text(font, color.negro, centroX, y1 + 60, ALLEGRO_ALIGN_CENTRE, "MODO MANUAL");
        al_draw_text(font, color.negro, centroX, y3 + 60, ALLEGRO_ALIGN_CENTRE, "MODO INTELIGENTE");
        al_draw_filled_rectangle(0, 0, realWidth, realHeight, al_map_rgba_f(i, i, i, i)); // empieza en opaco y se vuelve transparente
        al_flip_display();
        al_rest(0.02);
    }

    while (true){
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_rectangle(x1, y1, x2, y2, color.negro, 5);
        al_draw_rectangle(x1, y3, x2, y4, color.negro, 5);
        al_draw_text(font, color.negro, centroX, y1 + 60, ALLEGRO_ALIGN_CENTRE, "MODO MANUAL");
        al_draw_text(font, color.negro, centroX, y3 + 60, ALLEGRO_ALIGN_CENTRE, "MODO INTELIGENTE");
        al_flip_display();

        ALLEGRO_EVENT evento;
        al_wait_for_event(cola, &evento);

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
            al_destroy_event_queue(cola);
            al_destroy_display(display);
            exit(0);
        }
        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            int mx = evento.mouse.x, my = evento.mouse.y;
            if (mx >= x1 && mx <= x2){
                if (my >= y1 && my <= y2){
                    for (float i = 0; i <= 1; i+= 0.05){
                        al_clear_to_color(al_map_rgb(255, 255, 255)); // dibuja la pantalla en blanco
                        al_draw_rectangle(x1, y1, x2, y2, color.negro, 5); // Dibuja los rectámgulos con texto del menú
                        al_draw_rectangle(x1, y3, x2, y4, color.negro, 5);
                        al_draw_text(font, color.negro, centroX, y1 + 60, ALLEGRO_ALIGN_CENTRE, "MODO MANUAL");
                        al_draw_text(font, color.negro, centroX, y3 + 60, ALLEGRO_ALIGN_CENTRE, "MODO INTELIGENTE");
                        al_draw_filled_rectangle(0, 0, realWidth, realHeight, al_map_rgba_f(i, i, i, i)); // empieza en opaco y se vuelve transparente
                        al_flip_display();
                        al_rest(0.02);
                    }    
                    modoManual();  // aquí se ejecuta el modo manual
                }
                if (my >= y3 && my <= y4){
                    for (float i = 0; i <= 1; i+= 0.05){
                        al_clear_to_color(al_map_rgb(255, 255, 255)); // dibuja la pantalla en blanco
                        al_draw_rectangle(x1, y1, x2, y2, color.negro, 5); // Dibuja los rectámgulos con texto del menú
                        al_draw_rectangle(x1, y3, x2, y4, color.negro, 5);
                        al_draw_text(font, color.negro, centroX, y1 + 60, ALLEGRO_ALIGN_CENTRE, "MODO MANUAL");
                        al_draw_text(font, color.negro, centroX, y3 + 60, ALLEGRO_ALIGN_CENTRE, "MODO INTELIGENTE");
                        al_draw_filled_rectangle(0, 0, realWidth, realHeight, al_map_rgba_f(i, i, i, i)); // empieza en opaco y se vuelve transparente
                        al_flip_display();
                        al_rest(0.02);
                    }
                    modoInteligente(); // aquí se ejecuta el modo inteligente
                }
            }
        }
    }
}

#endif