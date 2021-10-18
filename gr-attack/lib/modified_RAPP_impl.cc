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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>
#include <gnuradio/io_signature.h>
#include "modified_RAPP_impl.h"

namespace gr {
  namespace attack {

    modified_RAPP::sptr
    modified_RAPP::make(float LinearGain, float PhaseGain, float Smoothness, float PhaseSmoothness, float OutputSL, float PhaseSaturation)
    {
      return gnuradio::get_initial_sptr
        (new modified_RAPP_impl(LinearGain, PhaseGain, Smoothness, PhaseSmoothness, OutputSL, PhaseSaturation));
    }

	modified_RAPP::sptr modified_RAPP::make(){
		return gnuradio::get_initial_sptr(new modified_RAPP_impl(0,0,0,0,0,0));
	}
    /*
     * The private constructor
     */
    modified_RAPP_impl::modified_RAPP_impl(float LinearGain, float PhaseGain, float Smoothness, 
                        float PhaseSmoothness, float OutputSL, float PhaseSaturation)
      : gr::sync_block("modified_RAPP",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex))),
              d_lineargain(LinearGain),
              d_phasegain(PhaseGain),
              d_smoothness(Smoothness),
              d_phasesmoothness(PhaseSmoothness),
              d_outputSL(OutputSL),
              d_phasesaturation(PhaseSaturation)
    {
      message_port_register_in(pmt::mp("params"));
      set_msg_handler(pmt::mp("params"), boost::bind(&modified_RAPP_impl::set_params, this, boost::placeholders::_1));
    }

    /*
     * Our virtual destructor.
     */
    modified_RAPP_impl::~modified_RAPP_impl()
    {
    }

    int
    modified_RAPP_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      // Do <+signal processing+>
      for(int i=0; i<noutput_items;i++){
        gr_complex x = in[i];
        float absX = real(x)*real(x) + imag(x)*imag(x);
        float linGainX = absX * pow(10, d_lineargain/20);
        float yAM = linGainX / ( pow((1 + pow((linGainX/d_outputSL), (2*d_smoothness))), (1 / (2*d_smoothness))));
        float yPM = ((pow(absX, d_smoothness)) * d_phasegain) / (pow((1 + absX / d_phasesaturation), d_phasesmoothness));
        out[i] = ( yAM * exp(sqrt(-1) * (std::arg(x) + yPM))); 
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

    void modified_RAPP_impl::set_params(pmt::pmt_t msg){
      float Smoothness = pmt::to_double(pmt::dict_ref(msg, pmt::intern("Smoothness"), pmt::PMT_NIL));
      float PhaseSmoothness = pmt::to_double(pmt::dict_ref(msg, pmt::intern("PhaseSmoothness"), pmt::PMT_NIL));

      d_smoothness = Smoothness;
      d_phasesmoothness = PhaseSmoothness;
    }
  } /* namespace attack */
} /* namespace gr */

