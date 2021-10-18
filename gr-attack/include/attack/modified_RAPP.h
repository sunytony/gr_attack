/* -*- c++ -*- */
/*
 * Copyright 2021 gr-attack author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ATTACK_MODIFIED_RAPP_H
#define INCLUDED_ATTACK_MODIFIED_RAPP_H

#include <attack/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace attack {

    /*!
     * \brief <+description of block+>
     * \ingroup attack
     *
     */
    class ATTACK_API modified_RAPP : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<modified_RAPP> sptr;

      static sptr make(float LinearGain, float PhaseGain, float Smoothness, float PhaseSmoothness, float OutputSL, float PhaseSaturation);
      static sptr make();
	  /*!
       * \brief Return a shared_ptr to a new instance of attack::modified_RAPP.
       *
       * To avoid accidental use of raw pointers, attack::modified_RAPP's
       * constructor is in a private implementation
       * class. attack::modified_RAPP::make is the public interface for
       * creating new instances.
       */
    };

  } // namespace attack
} // namespace gr

#endif /* INCLUDED_ATTACK_MODIFIED_RAPP_H */

