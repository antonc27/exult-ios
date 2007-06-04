/**
 **	Animate.h - Animated game objects.
 **
 **	Written: 7/27/2000 - JSF
 **/

/*
Copyright (C) 2000  Jeffrey S. Freedman

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef INCL_ANIMATE
#define INCL_ANIMATE	1

#include "iregobjs.h"
#include "miscinf.h"

/*
 *	A class for playing sound effects when certain objects are nearby.
 */
class Object_sfx : public Game_singletons
	{
	Game_object *obj;		// Object that caused the sound.
	SFX_info *sfx;
	int channel;			// ID of sound effect being played.
	int distance;			// Distance in tiles from Avatar.
	int dir;			// Direction (0-15) from Avatar.
	int last_sfx;		// For playing sequential sfx ranges.
	int repeat;
public:
					// Create & start playing sound.
	Object_sfx(Game_object *o)
		: obj(o), distance(0), channel(-1), last_sfx(-1)
		{
		sfx = Shapeinfo_lookup::get_sfx_info(obj->get_shapenum());
		if (sfx)
			{
			last_sfx = 0;
			if (!(sfx->rand || sfx->range > 1 || sfx->delay))
				repeat = -1;
			else
				repeat = 0;
			}
		}
	int get_sfxnum()
		{ return last_sfx; }
	int get_distance()
		{ return distance; }
	bool get_has_delay() const
		{ return sfx ? sfx->delay : false; }
	void update();	// Set to new object.
	void stop();
	};

/*
 *	An animator:
 */
class Animator : public Time_sensitive, public Game_singletons
	{
protected:
	Game_object *obj;		// Object we're controlling.
	unsigned char deltax, deltay;	// If wiggling, deltas from
					//   original position.
	bool animating;			// 1 if animation turned on.
	Object_sfx *objsfx;
	void start_animation();
public:
	Animator(Game_object *o) 
		: obj(o), deltax(0), deltay(0), animating(false)
		{
		objsfx = new Object_sfx(obj);
		}
	static Animator *create(Game_object *ob);
	~Animator();
	void want_animation()		// Want animation on.
		{
		if (!animating)
			start_animation();
		}
	void stop_animation()
		{
		animating = false;
		}
	int get_deltax()
		{ return deltax; }
	int get_deltay()
		{ return deltay; }
	virtual int get_framenum();
	};

/*
 *	Animate by going through frames.
 */
class Frame_animator : public Animator
	{
	Animation_info *aniinf;
	bool new_aniinf;
	char currpos;			// Current position in the animation.
	unsigned int delay;		// Rate of animation
	unsigned short last_shape;	// To check if we need to re init
	unsigned short last_frame;	// To check if we need to re init
	enum AniType				// Type of animation
	{
		FA_LOOPING = 0,
		FA_HOURLY = 1,
		FA_NON_LOOPING = 2,
		FA_RANDOM_LOOP = 3,
		FA_LOOP_RECYCLE = 4
	};
	void Initialize();
public:
	Frame_animator(Game_object *o);
	~Frame_animator()
		{
		if (new_aniinf)
			delete aniinf;
		}
	int get_next_frame();
					// For Time_sensitive:
	virtual void handle_event(unsigned long time, long udata);
	virtual int get_framenum()
		{
		return obj->get_framenum();
		}
	};

/*
 *	Just play SFX.
 */
class Sfx_animator : public Animator
	{
public:
	Sfx_animator(Game_object *o);
					// For Time_sensitive:
	virtual void handle_event(unsigned long time, long udata);
	};

/*
 *	Animate by going through frames, but only do the lower frames once.
 */
class Field_frame_animator : public Frame_animator
	{
	bool activated;			// Time to check for damage.
public:
	friend class Field_object;
	Field_frame_animator(Game_object *o);
					// For Time_sensitive:
	virtual void handle_event(unsigned long time, long udata);
	};

/*
 *	Animate by wiggling.
 */
class Wiggle_animator : public Animator
	{
public:
	Wiggle_animator(Game_object *o) : Animator(o)
		{  }
					// For Time_sensitive:
	virtual void handle_event(unsigned long time, long udata);
	};

/*
 *	An object that cycles through its frames, or wiggles if just one
 *	frame.  The base class is for those in U7chunks.
 */
class Animated_object : public Terrain_game_object
	{
	Animator *animator;		// Controls animation.
public:
	Animated_object(int shapenum, int framenum, unsigned int tilex, 
	       unsigned int tiley, unsigned int lft = 0);
	virtual ~Animated_object();
					// Render.
	virtual void paint();
					// +++++Needed on this one:
					// Get coord. where this was placed.
	virtual Tile_coord get_original_tile_coord() const
		{ return get_tile() + 
			Tile_coord(-animator->get_deltax(), 
				   -animator->get_deltay(), 0); }
	};

/*
 *	An object that cycles through its frames, or wiggles if just one
 *	frame.  This is the IREG version.
 */
class Animated_ireg_object : public Ireg_game_object
	{
	Animator *animator;		// Controls animation.
public:
	Animated_ireg_object(int shapenum, int framenum, unsigned int tilex, 
	       unsigned int tiley, unsigned int lft = 0);
	virtual ~Animated_ireg_object();
					// Render.
	virtual void paint();
					// Get coord. where this was placed.
	virtual Tile_coord get_original_tile_coord() const
		{ return get_tile() + 
			Tile_coord(-animator->get_deltax(), 
				   -animator->get_deltay(), 0); }

				// Write out to IREG file.
	virtual void write_ireg(DataSource* out);
	};

/*
 *	An object that cycles through its frames, or wiggles if just one
 *	frame.  This is the IFIX version.
 */
class Animated_ifix_object : public Ifix_game_object
	{
	Animator *animator;		// Controls animation.
public:
	Animated_ifix_object(int shapenum, int framenum, unsigned int tilex, 
	       unsigned int tiley, unsigned int lft = 0);
	virtual ~Animated_ifix_object();
					// Render.
	virtual void paint();
					// Get coord. where this was placed.
	virtual Tile_coord get_original_tile_coord() const
		{ return get_tile() + 
			Tile_coord(-animator->get_deltax(), 
				   -animator->get_deltay(), 0); }

	virtual void write_ifix(DataSource* ifix, bool v2);
	};
#endif


