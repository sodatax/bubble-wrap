#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>

int main(){
    bn::core::init();
    bn::backdrop::set_color(bn::color(31,24,24));
    int color = 0;

    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(0, 0);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-20, 0);
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(0, 30);
    bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-20, 30);
    bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(-15, 35);
    bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(-10, 35);
    bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(-5, 35);


    while(true){
        bn::core::update();

        //pastel blue
        if(color == 1){
            bn::backdrop::set_color(bn::color(24,24,31));
        }
        //pastel green
        if(color ==2){
            bn::backdrop::set_color(bn::color(24,31,24));
        }
        //pastel red
        if(color ==3){
            bn::backdrop::set_color(bn::color(31,24,24));
        }

        //changes backdrop depending on key(s) pressed
        if(bn::keypad::a_pressed()){
            color = 1;
        }
        if(bn::keypad::b_pressed()){
            color = 2;
        } 
        if(bn::keypad::a_pressed() && bn::keypad::b_pressed()){
            color = 3;
        }

        //will temporarily change the backdrop color when L is held, then change back to previous color when released
        if(bn::keypad::l_held()){
            bn::backdrop::set_color(bn::color(31,0,0));
        }
        if(bn::keypad::l_released()){
            //pastel blue
            if(color == 1){
            bn::backdrop::set_color(bn::color(24,24,31));
            }
            //pastel green
            if(color ==2){
                bn::backdrop::set_color(bn::color(24,31,24));
            }
            //pastel red
            if(color ==3){
                bn::backdrop::set_color(bn::color(31,24,24));
            }
        }

        //will temporarily change the backdrop color when R is held, then change back to previous color when released
        if(bn::keypad::r_held()){
            bn::backdrop::set_color(bn::color(0,0,31));
        }
        if(bn::keypad::r_released()){
            //pastel blue
            if(color == 1){
            bn::backdrop::set_color(bn::color(24,24,31));
            }
            //pastel green
            if(color ==2){
                bn::backdrop::set_color(bn::color(24,31,24));
            }
            //pastel red
            if(color ==3){
                bn::backdrop::set_color(bn::color(31,24,24));
            }
        }
        
    }
}