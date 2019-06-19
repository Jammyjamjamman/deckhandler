 %module deckhandler
 %{
 /* Includes the header in the wrapper code */
 #include "deckhandler.h"
 %}
 
 /* Parse the header file to generate wrappers */
 %include "deckhandler.h" 

 %inline %{
void deck_dh_set(st_deck_dh deck, st_card_info_dh card, int i) {
   deck.card[i] = card;
}

st_card_info_dh deck_dh_get(st_deck_dh deck, int i) {
   return deck.card[i];
}

const char *get_card_face(st_card_info_dh card) {
   return faces[card.face_val-1];
}

const char *get_card_suit(st_card_info_dh card) {
   return suits[card.suit];
}

void seed(int seed) {
   srand(seed);
}
%}
