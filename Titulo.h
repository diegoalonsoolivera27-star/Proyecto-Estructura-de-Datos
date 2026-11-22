#ifndef TITULO_H
#define TITULO_H

#include <cstdlib>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

void menu(ALLEGRO_DISPLAY *, int, int, ALLEGRO_FONT *);

void titulo(ALLEGRO_DISPLAY *display, int realWidth, int realHeight, ALLEGRO_FONT *font, ALLEGRO_FONT *font2){
    // empieza la cola y registra cualquier evento
    ALLEGRO_EVENT_QUEUE *start = al_create_event_queue();
    al_register_event_source(start, al_get_keyboard_event_source());

    double tiempo = al_get_time();
    bool corriendo=true, visible=true;

    // posiciones para transición
    int lineHeight = al_get_font_line_height(font);
    int totalHeight = lineHeight * 2 + 40;
    int startY = realHeight/2 - totalHeight/2 + 500;
    int centroX = realWidth / 2;

    while (corriendo){
        int lineHeight = al_get_font_line_height(font); // obtiene la altura de una linea de texto
        int totalHeight = lineHeight * 2 + 40; // 40 de espacio
        int startY = realHeight/2 - totalHeight/2 + 500; // posición vertical inicial para centrar el texto
        int centroX = realWidth / 2; // posición horizontal para centrar el texto

        ALLEGRO_EVENT evento;
        al_wait_for_event_timed(start, &evento, 0.05); // espera un evento durante 0.05 segundos 
                                                        // para que el bucle no se ejecute demasiado rápido
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN){ // si se presiona una tecla
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){ // |
                al_destroy_event_queue(start);
                al_destroy_display(display);
                exit(0);//cierra el programa al presionar ESCAPE por control
            } else {
                corriendo = false; // cualquier otra tecla comienza el juego
            }   
        }
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_text(font, color.negro, centroX, startY, ALLEGRO_ALIGN_CENTRE, "8 PUZZLE");

        // parpadeo cada 0.5 segundos
        if(al_get_time() - tiempo > 1){
            visible = !visible; // va intercalando mediante negaciones
            tiempo = al_get_time();
        }

        if(visible)
            al_draw_text(font2, color.negro, centroX, startY + lineHeight - 300, ALLEGRO_ALIGN_CENTRE, "press any key to start");

        al_flip_display();
    }

    // Transición
    for (float i = 0; i <= 1; i += 0.05){
        al_clear_to_color(al_map_rgb(255, 255, 255)); // dibuja la pantalla en blanco
        al_draw_text(font, color.negro, centroX, startY, ALLEGRO_ALIGN_CENTRE, "8 PUZZLE"); // Dibuja los textos del título
        if (visible)
            al_draw_text(font2, color.negro, centroX, startY + lineHeight - 300, ALLEGRO_ALIGN_CENTRE, "press any key to start");
        
        al_draw_filled_rectangle(0, 0, realWidth, realHeight, al_map_rgba_f(i, i, i, i)); // Se dibuja un cuadro que se vuelve opaco poco a poco
        al_flip_display();
        al_rest(0.02);
    }
    al_destroy_event_queue(start);
    menu(display, realWidth, realHeight, font2);
}

#endif