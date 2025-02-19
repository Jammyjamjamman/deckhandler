/*
 * example-01.c
 *
 * This file is part of the deckhandler library
 * <https://github.com/theimpossibleastronaut/deckhandler>
 *
 * Copyright 2018 Andy <andy400-dev@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "deckhandler.h"

int main (int argc, char *argv[])
{
  /* declare a deck using type "st_deck_dh" (defined in deckhandler.h) */
  st_deck_dh* deck_a = (st_deck_dh*)malloc (sizeof (st_deck_dh));
  if (deck_a == NULL)
  {
    fprintf (stderr, "Malloc is unable to allocate memory\n");
    exit (EXIT_FAILURE);
  }

  /* initialize the deck */
  deck_init_dh (deck_a);

  int deals_num = 0;
  int deals_max = 3;

  /* random generator used by deck_shuffle_dh() */
  srand (time (NULL));

  do
  {
    /* shuffle the deck */
    printf ("\n\nShuffling...\n");
    deck_shuffle_dh (deck_a);

    /* show each card in the deck */
    int deal;
    for (deal = 0; deal < CARDS_IN_DECK; deal++)
    {
      /* The "faces" and "suits" arrays are initialized in deckhandler.c */
      printf ("%s of %s\n",
              faces[deck_a->card[deal].face_val - 1],
              suits[deck_a->card[deal].suit]);
    }
  }while (deals_num++ < deals_max);

  free (deck_a);
  return 0;
}
