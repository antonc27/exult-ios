/*  Copyright (C) 2016  The Exult Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  There is a very minor flag, only checked by Edrin, that changes his
 *  response when asked about his dreams. It should have been set once he
 *  sees Siranush for the last time, as he is summoned just prior to the
 *  Dream Crystal being broken by her.
 *  This code checks if the Dream Realm has been completed, and if so it
 *  sets flag 531 (0x213). In testing you must ask about his dreams in two
 *  conversations. In the first he checks for and sets flag 243 (0xF3) 
 *  when he speaks of her. Only after does he check for flag 531 (0x213).
 *
 *  2016-07-12 Written by Knight Captain
 */

void Edrin object#(0x410) () // NPC 16
{
	if (event == STARTED_TALKING) // DoubleClick would also work here.
	{
		if (gflags[0x02DB]) // 731 Dream_Realm_Complete is not defined in si_flags.uc yet.
            {
            gflags[EDRIN_KNOWS_SIRANUSH_IS_REAL] = true; // 531, 0x213 is only checked by Edrin.
            }
    }
    Edrin.original();
}