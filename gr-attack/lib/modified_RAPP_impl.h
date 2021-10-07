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

#ifndef INCLUDED_ATTACK_MODIFIED_RAPP_IMPL_H
#define INCLUDED_ATTACK_MODIFIED_RAPP_IMPL_H

#include <attack/modified_RAPP.h>

namespace gr {
  namespace attack {

    class modified_RAPP_impl : public modified_RAPP
    {
     private:
      float d_lineargain;
      float d_phasegain;
      float d_smoothness;
      float d_phasesmoothness;
      float d_outputSL;
      float d_phasesaturation;

      void set_params(pmt::pmt_t msg);
      // Nothing to declare in this block.

     public:
      modified_RAPP_impl(float LinearGain, float PhaseGain, float Smoothness, float PhaseSmoothness, 
                          float OutputSL, float PhaseSaturation);
      ~modified_RAPP_impl();

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace attack
} // namespace gr

#endif /* INCLUDED_ATTACK_MODIFIED_RAPP_IMPL_H */

