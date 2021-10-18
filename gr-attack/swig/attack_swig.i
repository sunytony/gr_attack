/* -*- c++ -*- */

#define ATTACK_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "attack_swig_doc.i"

%{
#include "attack/random_periodic_source.h"
#include "attack/modified_RAPP.h"
%}

%include "attack/random_periodic_source.h"
GR_SWIG_BLOCK_MAGIC2(attack, random_periodic_source);

%include "attack/modified_RAPP.h"
GR_SWIG_BLOCK_MAGIC2(attack, modified_RAPP);

