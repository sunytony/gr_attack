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

#ifndef INCLUDED_ATTACK_RANDOM_PERIODIC_SOURCE_IMPL_H
#define INCLUDED_ATTACK_RANDOM_PERIODIC_SOURCE_IMPL_H

#include <attack/random_periodic_source.h>
#include <foo/random_periodic_msg_source.h>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>

namespace gr {
  namespace attack {

    class random_periodic_source_impl : public gr::foo::random_periodic_msg_source, public random_periodic_source
    {
     private:
      // Nothing to declare in this block.
      void run(random_periodic_source_impl *instance);
			int d_msg_len;
			int d_nmsg_total;
			int d_nmsg_left;
			unsigned int d_seed;
			bool d_debug;
			bool d_quit;
			bool d_finished;
			long d_interval;
			boost::thread *d_thread;
			gr::thread::mutex d_mutex;
			boost::mt19937 d_rng;
			boost::uniform_int<> d_brange;
			boost::variate_generator< boost::mt19937, boost::uniform_int<> > d_randbytes;
     public:
      random_periodic_source_impl(int msg_len,
					long interval, int num_msg,
					bool quit, bool debug, int seed);
			virtual ~random_periodic_source_impl();

      void set_nmsg(int nmsg);
			int get_nmsg();

			void set_delay(long delay);
			long get_delay();

			void start_tx();
			void stop_tx();
			pmt::pmt_t generate_msg();
			bool is_running();
    };

  } // namespace attack
} // namespace gr

#endif /* INCLUDED_ATTACK_RANDOM_PERIODIC_SOURCE_IMPL_H */

